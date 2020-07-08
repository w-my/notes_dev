# 基础渲染

- OpenGL 渲染基础框架
- 如何使用7中 OpenGL 几何图元
-  如何使用存储着色器
- 如何使用 uniform 值和属性
- 如何使用 GLBatch 帮助类传递几何图形
- 如何执行深度测试和背面消除
- 如何绘制透明或混合几何图形
- 如何绘制抗锯齿点、线和多边形



## 基础图形管线

OpenGL 中的图元只不过是顶点的集合以预定义的方式结合在一起。例如，一个单独的点是一个图元。三角形则是由3个顶点组成的图元。



#### 客户机 -- 服务器

管线分为两部分：客户机端 和 服务器端。

客户端是存储在 CPU 存储器中的，并且在应用程序中执行，或者在主系统内存的驱动程序中执行。驱动程序将渲染命令与数据组合起来，并发送到服务器执行。服务器回跨越一些系统总线，实际上，它就是图形加速卡上的硬件和内存。



#### 着色器

着色器必须从源代码中编译和链接到一起才能使用。最终准备就绪的着色器程序随后在第一阶段构成顶点着色器，在第二阶段构成片着色器。

我们可通过 属性、uniform值、和 纹理 来为着色器提供数据。

##### 属性

属性就是一个对每个顶点都要作改变的数据元素。属性值可以是浮点数、整数或布尔数据。属性总是以四维向量的形式进行内部存储。如一个顶点位置可能存储为一个 x 值、一个 y 值 和 一个 z 值，OpenGL会将第四个分量（w分量）设为1。

##### Uniform 值

属性是一种对于整个批次的属性都取统一值的单个值，是不变的。Uniform 值通常设置后就发出渲染一个图元批次的命令。Uniform 变量最常见的应用是在顶点渲染中设置变换矩阵。

##### 纹理

从顶点着色器和片段着色器中都可以对纹理值进行采样和筛选。典型情况下，片段着色器对一个纹理进行采样，并在一个三角形的表面上应用图形数据。任何大型浮点数据块都可以通过一种方式传递给着色器。

##### 输出（Out）

输出数据是作为一个阶段着色器的输出定义的，而在后续阶段的着色器则是作为输入（In）定义的。



## 坐标系

#### 正投影

在正投影中，所有在这个空间范围内的所有东西都会被显示在屏幕上，而不存在照相机或视点坐标系的概念。

```c++
GLFrustum::Setorthographic(GLfloat xMin, GLfloat xMax, 
                           GLfloat yMin, GLfloat yMax, 
                           GLfloat zMin, GLfloat zMax);
```

#### 透视投影

透视投影会进行透视除法对距离观察者很远的对象进行缩放和收缩。在投影到屏幕之后，是视景体背面与视景体正面的宽度测量标准不同。

```c++
GLFrustum::SetPerspective(float fFov, float fAspect, float fNear, float fFar)
```



## 使用存储着色器

在 OpenGL 核心框架中，并没有提供任何内建渲染管线，在提交一个几何图形进行渲染之前，必须制定一个着色器。存储着色器由 GLTools 的 C++ 类 GLShaderManager 进行管理。

#### 初始化

```c++
GLShaderManager shaderManager;
shaderManager.InitializeStockShaders();
```



#### 属性

| 标识符                 | 描述                          |
| ---------------------- | ----------------------------- |
| GLT_ATTRIBUTE_VERTEX   | 3 分量 (x, y, z) 顶点位置     |
| GLT_ATTRIBUTE_COLOR    | 4 分量 (r, g, b, a) 颜色值    |
| GLT_ATTRIBUTE_NORMAL   | 3 分量 (x, y, z) 表面法线     |
| GLT_ATTRIBUTE_TEXTURE0 | 第一对 2 分量 (s, t) 纹理坐标 |
| GLT_ATTRIBUTE_TEXTURE1 | 第二对 2 分量 (s, t) 纹理坐标 |



#### Uniform 值

```c++
GLShaderManager::UseStockShader(GLenum shader, ......);
```

##### 单元着色器

单元（Identity）着色器只是简单的使用默认的笛卡尔坐标系（坐标范围是 -1.0~1.0）。所有片段都应用同一种颜色，几何图形为实心和未渲染的。

使用属性：GLT_ATTRIBUTE_VERTEX

使⽤场景：绘制默认 OpenGL 坐标系（-1, 1）下图形。图形所有片段都会以⼀种颜⾊填充。

```c++
GLShaderManager::UseStockShader(GLT_SHADER_IDENTITY, 
                                GLfloat vColor[4]); // 颜色值
```

##### 平面着色器

平面（Flat）着色器将统一着色器进行了扩展，允许为几何图形变换指定一个 4x4 变化矩阵。

使用属性：GLT_ATTRIBUTE_VERTEX

使⽤场景：在绘制图形时**,** 可以应⽤用变换（模型 / 投影变化）。

```c++
GLShaderManager::UseStockShader(GLT_SHADER_FLAT, 
                                GLfloat mvp[16], // 允许变化的4*4矩阵
                                GLfloat vColor[4]); // 颜⾊值
```

##### 上色着色器

这种着色器唯一的 Uniform 值就是在几何图形中应用的变换矩阵。

使用属性：GLT_ATTRIBUTE_VERTEX、GLT_ATTRIBUTE_COLOR

使用场景：在绘制图形时，可以应⽤用变换（模型 / 投影变化）颜色将会平滑地插入到顶点之间（称为平滑着⾊）。

```c++
GLShaderManager::UseStockShader(GLT_SHADER_SHADED, 
                                GLfloat mvp[16]); // 允许变化的4*4矩阵
```

##### 默认光源着色器

这种着色器创造出一种错觉，类似于由位于观察者位置的单漫射光所产生的效果。是对象产生阴影和光照的效果。

使用属性：GLT_ATTRIBUTE_VERTEX、GLT_ATTRIBUTE_NORMAL

使用场景：在绘制图形时，可以应用变换（模型 / 投影变化）这种着⾊器会使绘制的图形产⽣阴影和光照的效果。

```c++
GLShaderManager::UserStockShader(GLT_SHADER_DEFAULT_LIGHT, 
                                 GLfloat mvMatrix[16], // 模型4*4矩阵
                                 GLfloat pMatrix[16], // 投影4*4矩阵
                                 GLfloat vColor[4]); // 颜色值
```

##### 点光源着色器

点光源着色器和默认光源着色器很相似，但是光源位置可能是特定的。

使用属性：GLT_ATTRIBUTE_VERTEX、GLT_ATTRIBUTE_NORMAL

使用场景：在绘制图形时，可以应用变换（模型 / 投影变化）这种着⾊器会使绘制的图形产⽣阴影和光照的效果。

```c++
GLShaderManager::UserStockShader(GLT_SHADER_POINT_LIGHT_DIEF,
                                 GLfloat mvMatrix[16], // 模型4*4矩阵
                                 GLfloat pMatrix[16], // 投影4*4矩阵
                                 GLfloat vLightPos[3], // 点光源的位置
                                 GLfloat vColor[4]); // 漫反射颜⾊值
```

##### 纹理替换矩阵着色器

着色器通过给定的模型视图投影矩阵，使用绑定到 nTextureUnit 指定的纹理单元的纹理对几何图形进行变换。

使用属性：GLT_ATTRIBUTE_VERTEX、GLT_ATTRIBUTE_NORMAL

使用场景：在绘制图形时，可以应用变换（模型 / 投影变化）这种着色器通过给定的模型视图投影矩阵。使⽤纹理单元来进行颜色填充。其中每个像素点的颜色是从纹理中获取。

```c++
GLShaderManager::UserStockShader(GLT_SHADER_TEXTURE_REPLACE,
                                 GLfloat mvMatrix[16], // 模型4*4矩阵
                                 GLint nTextureUnit); // 纹理单元
```

##### 纹理调整着色器

这种着色器将一个基本色乘以一个取自纹理单元 nTextureUnit 的纹理。将颜色与纹理进行颜色混合后才填充到片段中。

使用属性：GLT_ATTRIBUTE_VERTEX、GLT_ATTRIBUTE_TEXTURE0

使用场景：在绘制图形时，可以应用变换（模型 / 投影变化）这种着色器通过给定的模型视图投影矩阵。

```c++
GLShaderManager::UserStockShader(GLT_SHADER_TEXTURE_MODULATE,
                                 GLfloat mvMatrix[16], // 模型4*4矩阵
                                 GLfloat vColor[4], // 颜⾊色值
                                 GLint nTextureUnit); // 纹理单元
```

##### 纹理光源着色器

这种着色器将一个纹理通过漫反射照明计算进行调整（相乘），光线在视觉空间中的位置是给定的。

使用属性：GLT_ATTRIBUTE_VERTEX、GLT_ATTRIBUTE_NORMAL、GLT_ATTRIBUTE_TEXTURE0

使用场景：在绘制图形时，可以应用变换（模型 / 投影变化）这种着色器通过给定的模型视图投影矩阵。

```c++
GLShaderManager::UserStockShader(GLT_SHADER_TEXTURE_POINT_LIGHT_DIEF,
                                 G Lfloat mvMatrix[16], // 模型4*4矩阵
                                 GLfloat pMatrix[16], // 投影4*4矩阵
                                 GLfloat vLightPos[3], // 点光源位置
                                 GLfloat vBaseColor[4], // 颜⾊值（几何图形的基本⾊）
                                 GLint nTextureUnit); // 纹理单元
```



## 图形绘制

OpenGL 在计算机屏幕上的绘制，我们关心的不是物理屏幕坐标和像素，而是视景体中的位置坐标。将这些点、线和三角形从创建的 3D 控件投影到计算机屏幕上的 2D 图形则是着色器程序和光栅化硬件所要完成的工作。



#### 7种基本图元

| 图元              | 描述                                                         |
| ----------------- | ------------------------------------------------------------ |
| GL_POINTS         | 每个顶点在屏幕上都是单独点                                   |
| GL_LINES          | 每⼀对顶点定义一个线段                                       |
| GL_LINE_STRIP     | 一个从第一个顶点依次经过每一个后续顶点而绘制的线条           |
| GL_LINE_LOOP      | 和 GL_LINE_STRIP 相同，但是最后一个顶点和第一个顶点连接了起来 |
| GL_TRIANGLES      | 每 3 个顶点定义⼀个新的三⻆形                                |
| GL_TRIANGLE_STRIP | 共用一个条带 (strip) 上的顶点的一组三角形                    |
| GL_TRIANGLE_FAN   | 以一个圆点为中心呈扇形排列，共⽤相邻顶点的一组三角形         |



#### 点

```c++
// 设置点的大小
void glPointSize(GLfloat size);
// 
GLfloat sizes[2]; // 存储支持的点大小范围（包含了最小值和最大值 0.5~256.0）
GLfloat step; // 存储支持的点大小增量（包含了最小步长 0.125）
// 获取支持的点的大小范围和步长（增量）
glGetFloatV(GL_POINT_SIZE_RANGE, sizes);
glGetFloatV(GL_POINT_SIZE_GRANULARITY, &step);
```

还可以通过使用程序点大小模式来设置点大小

```c++
glEnable(GL_PROGRAM_POINT_SIZE);
```



#### 线

一条线段是在两个顶点之间绘制的，所以一批线段应该包括偶数个顶点，每个顶点都是线段的端点。

改变线段宽度的唯一方式是使用函数：glLineWidth。

```c++
void glLineWidth(GLfloat width);
```



#### 线带

线带（line strip）连续地从一个顶点到下一个顶点绘制线段，以形成一个真正连接点的线条。



#### 线环

线环（line loop）是线带的一种简单扩展，在线带的基础上额外增加一条连接着一批次中最后一个点和第一个点的线段。



#### 单独的三角形

三角形是存在的最简单的实体多边形。而现在三角形已经是 OpenGL 中支持的唯一一种多边形了。

##### 环绕

逆时针环绕的多边形是正面的，逆时针环绕的多边形是背面的。

通过不同的环绕，可以为多边形的正面和背面设置不同的物理特征，也可以隐藏一个多边形的背面，或者给它设置一种不同的颜色和反射属性。纹理图像在背面三角形中也是相反的。

OpenGL 中默认逆时针方向环绕的多边形是正面的。但可以通过函数修改：

```c++
glFrontFace(GL_CW);
```

GL_CW 参数告诉 OpenGL 顺时针环绕的多边形被认为是正面的。使用 GL_CCW 参数使正面恢复默认的逆时针环绕。



#### 三角形带

使用 GL_TRIANGLE_STRIP 图元绘制一串相连的三角形，可以节省大量时间。



#### 三角形扇

使用 GL_TRIANGLE_FAN 创建一组围绕一个中心点的相连三角形。第一个顶点会构成扇形的原点。



#### 一个简单批次容器

GLTools 库中的一个简单容器类 GLBatch。这个类可以作为图元简单批次的容器使用，而且它知道在使用 GLShaderManager 支持的任意存储着色器时如何对图元进行渲染。使用 GLBatch 类，首先对批次进行初始化，告诉这个类代表那种图元，其中包括定点数，以及（可选）一组或两组纹理坐标。

```c++
void GLBatch::Begin(GLenum primitive, GLuint nVerts, GLuint nTextureUnits=0);
```

然后，至少要复制一个由 3 分量（x, y, z）顶点组成的数组。

```c++
void GLBatch::CopyVertexData3f(GLfloat *vVerts);
```

还可以选择复制表面发现、颜色和纹理坐标。

```c++
void GLBatch::CopyNormalDataf(GLfloat *vNorms);
void GLBatch::CopyColorData4f(GLfloat *vColors);
void GLBatch::CopyTexCoordData2f(GLfloat *vTexCoords, GLuint uiTextureLayer);
```

最后调用 End 完成数据复制，并且将设置内部标记，以通知这个类包含哪些属性。

```c++
void GLBatch::End(void);
```

一旦调用 End 函数，就不能再增加新的属性了。



#### 正面和背面剔除

对正面和背面三角形进行区分的原因之一就是为了进行剔除。背面剔除能够极大地提高性能，并且修正一些问题。

开启表面剔除：

```c++
glEnable(GL_CULL_FACE);
```

关闭表面剔除：

```c++
glDisable(GL_CULL_FACE);
```

设置 正面 或 背面 剔除：

```c++
// mode：GL_FRONT、GL_BACK 或 GL_FRONT_AND_BACK
void glCullFace(GLenum mode);
```

消除不透明物体内部几何图形：

```c++
glCullFace(GL_BACK);
glEnable(GL_CULL_FACE);
```

在某些情况下，剔除实体几何体的正面也是非常有用的，例如在需要显示某些图形内部渲染的时候。在渲染透明对象时，经常会对一个对象进行两次渲染，第一次开启透明并剔除正面，第二次则消除背面。这样就在渲染正面之前渲染了背面。



#### 深度测试

深度测试时另一种高效消除影藏表面的技术。它的概念很简单：在绘制一个像素时，将一个值（称为 z 值）分配给它，这个值表示它到观察者的距离。当然，当另外一个像素需要在屏幕上的同样位置进行绘制时，新像素的 z 值将与已经存储的像素的 z 值进行比较。如果新像素的 z 值比较大，那它距离观察者就比较近，则原来的像素就会被新的像素覆盖。

使用 GLUT 设置 OpenGL 窗口时，用如下方式申请一个颜色缓冲区 和 一个深度缓冲区。

```c++
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTR);
```

启用深度测试

```c++
glEnable(GL_DEPTH_TEST);
```



#### 多边形模式

在默认情况下，多边形是作为实心图形绘制的，但可以通过将多边形指定为显示轮廓或只有点（只显示顶点）来改变。

函数 `glPolygonMode` 允许将多边形渲染成实体、轮廓或只有点。

```c++
// face: GL_FRONT、GL_BACK 或 GL_FRONT_AND_BACK
// mode: GL_FILL（默认值）、GL_LINE 或 GL_POINT
void glPolygonMode(GLenum face, GLenum mode);
// e.g. 实现线框渲染
glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
// e.g. 绘制成点模式
glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
```



#### 多边形偏移

问题：如果在实体图形的同一位置绘制线框，会遇到 z-fighting（z 冲突）问题。

解决：使用 glPolygonOffset 函数调节片段的深度值，这样就能使深度值产生偏移而并不实际改变 3D 控件中的物理位置。

```c++
void glPolygonOffset(GLfloat factor, GLfloat units);
```

应用到片段上的总偏移可以通过下面的方程式表示。

```
// DZ：深度值（z 值）
// r：是使深度缓冲区值产生变化的最小值
Depth Offset = (DZ x factor) + (r x units)
```



#### 裁剪

另一种提高渲染性能的方法只刷新屏幕上发生变化的部分。OpenGL 允许我们在将要进行渲染的窗口中指定一个裁剪框。裁剪框默认与窗口同样大小，并且不会进行裁剪测试。

```c++
glEnable(GL_SCISSOR_TEST);
```

指定裁剪窗口坐标（像素）：

```c++
// x, y： 指定裁剪框的左下角
// width, height：指定裁剪框的尺寸
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
```

##### 获取一组重叠的彩色三角形

```c++
void RenderScene() {
    
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    glScissor(100, 100, 600, 400);
    glEnable(GL_SCISSOR_TEST);
    glClear(GL_COLOR_BUFFER_BIT);
    
  	// ......
  
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
    glScissor(200, 200, 400, 200);
    glClear(GL_COLOR_BUFFER_BIT);
    
  	// ......
  
    glDisable(GL_SCISSOR_TEST);
    
    glutSwapBuffers();
}
```



## 混合

使用混合

```c++
glEnable(GL_BLEND);
```

#### 组合颜色

已经存储在颜色缓冲区中的颜色值叫作 `目标颜色`，这个颜色值包含了单独的红、绿、蓝以及一个可选的 alpha 值。

作为当前渲染命令的结果进入颜色缓冲区的颜色称为 `源颜色`，它可能与目标颜色进行交互，也可能不与之进行交互。

源颜色和目标颜色的组合方式是由 `混合方程式` 控制的

```c++
// Cf：最终计算产生的颜色
// Cs：源颜色
// Cd：目标颜色
// S：源
// D：目标混合因子
Cf = (Cs * S) + (Cd * D)
```

设置混合因子

```c++
// S 和 D 都是枚举值
glBlendFunc(GLenum S, GLenum D);
```

如下为混合函数可使用的值。其下标表示标题、目标和颜色。

**penGL 混合因子**

| 函数                        | RGB 混合因子             | Alpha 混合因子 |
| --------------------------- | ------------------------ | -------------- |
| GL_ZERO                     | (0, 0, 0)                | 0              |
| GL_ONE                      | (1, 1, 1)                | 1              |
| GL_SRC_COLOR                | (Rs, Gs, Bs)             | As             |
| GL_ONE_MINUS_SRC_COLOR      | (1, 1, 1) - (Rs, Gs, Bs) | 1 - As         |
| GL_DST_COLOR                | (Rd, Gd, Bd)             | Ad             |
| GL_ONE_MINUS_DST_COLOR      | (1, 1, 1) - (Rd, Gd, Bd) | 1 - Ad         |
| GL_SRC_ALPHA                | (As, As, As)             | As             |
| GL_ONE_MINUS_SRC_ALPHA      | (1, 1, 1) - (As, As, As) | 1 - As         |
| GL_DST_ALPHA                | (Ad, Ad, Ad)             | Ad             |
| GL_ONE_MINUS_DST_ALPHA      | (1, 1, 1) - (Ad, Ad, Ad) | 1 - Ad         |
| GL_CONSTANT_COLOR           | (Rc, Gc, Bc)             | Ac             |
| GL_ONE_MINUS_CONSTANT_COLOR | (1, 1, 1) - (Rc, Gc, Bc) | 1 - Ac         |
| GL_CONSTANT_ALPHA           | (Ac, Ac, Ac)             | Ac             |
| GL_ONE_MINUS_CONSTANT_ALPHA | (1, 1, 1) - (Ac, Ac, Ac) | 1 - Ac         |
| GL_SRC_ALPHA_SATURATE       | (f, f, f)*               | 1              |

*其中 f=min(As, 1 - Ad)



P82



















## 实例：点 线 线段 线环 金字塔 六边形 圆环

```c++
#include "GLTools.h" // 包含了大部分GLTool中类似C语言的独立函数
#include "GLMatrixStack.h" // 矩阵工具类，可用于加载单元矩阵/矩阵/矩阵相乘/压栈/出栈/缩放/平移/旋转
#include "GLFrame.h" // 矩阵工具类,表示位置.通过设置 vOrigin, vForward ,vUp
#include "GLFrustum.h" // 矩阵⼯具类,用来快速设置正/透视投影矩阵.完成坐标从3D->2D映射过程.
#include "GLBatch.h" // 三角形批次类,帮助类,利用它可以传输顶点/光照/纹理/颜色数据到存储着色器中.
#include "GLGeometryTransform.h" // 变换管道类,⽤来快速在代码中传输视图矩阵/投影矩阵/视图投影变换矩阵等.

#include <math.h> // 数学库

#ifdef __APPLE__
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

/*
 GLMatrixStack 变化管线使用矩阵堆栈

 GLMatrixStack 构造函数允许指定堆栈的最大深度、默认的堆栈深度为64.这个矩阵堆在初始化时已经在堆栈中包含了单位矩阵。
 GLMatrixStack::GLMatrixStack(int iStackDepth = 64);

 // 通过调用顶部载入这个单位矩阵
 void GLMatrixStack::LoadIndentiy(void);

 // 在堆栈顶部载入任何矩阵
 void GLMatrixStack::LoadMatrix(const M3DMatrix44f m);
*/

// 各种需要的类
GLShaderManager     shaderManager; // 存储着⾊器管理工具类
GLMatrixStack       modelViewMatrix; // 模型视图矩阵
GLMatrixStack       projectionMatrix; // 投影矩阵
GLFrame             cameraFrame; // 设置观察者视图坐标
GLFrame             objectFrame; // 设置图形环绕时,视图坐标
// 投影矩阵
GLFrustum           viewFrustum; // 设置图元绘制时的投影方式

// 容器类（7种不同的图元对应7种容器对象）
GLBatch             pointBatch;
GLBatch             lineBatch;
GLBatch             lineStripBatch;
GLBatch             lineLoopBatch;
GLBatch             triangleBatch;
GLBatch             triangleStripBatch;
GLBatch             triangleFanBatch;

// 几何变换的管道
GLGeometryTransform     transformPipeline; // 变换管道,存储投影/视图/投影视图变换矩阵

GLfloat vGreen[] = { 0.0f, 1.0f, 0.0f, 1.0f };
GLfloat vBlack[] = { 0.0f, 0.0f, 0.0f, 1.0f };


// 跟踪效果步骤
int nStep = 0;

/// ⾃自定义函数,设置你需要渲染的图形的 相关顶点数据/颜色数据等数据装备工作
void SetupRC() {
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    shaderManager.InitializeStockShaders();
    glEnable(GL_DEPTH_TEST);
    
    // 设置变换管线以使用两个矩阵堆栈
    transformPipeline.SetMatrixStacks(modelViewMatrix, projectionMatrix);
    cameraFrame.MoveForward(-15.0f);
    
    // 定义一些点，三角形形状。
    GLfloat vCoast[9] = {
        3, 3, 0, 0, 3, 0, 3, 0, 0
    };
    
    /*
    常见函数：
    void GLBatch::Begin(GLenum primitive,GLuint nVerts,GLuint nTextureUnits = 0);
     参数1：表示使用的图元
     参数2：顶点数
     参数3：纹理坐标（可选）
    // 复制顶点坐标
    void GLBatch::CopyVertexData3f(GLFloat *vNorms);
    // 结束，表示已经完成数据复制工作
    void GLBatch::End(void);
    */
    // 点
    pointBatch.Begin(GL_POINTS, 3);
    pointBatch.CopyVertexData3f(vCoast);
    pointBatch.End();
    
    // 线
    lineBatch.Begin(GL_LINES, 3);
    lineBatch.CopyVertexData3f(vCoast);
    lineBatch.End();
    
    // 线段
    lineStripBatch.Begin(GL_LINE_STRIP, 3);
    lineStripBatch.CopyVertexData3f(vCoast);
    lineStripBatch.End();
    
    // 线环
    lineLoopBatch.Begin(GL_LINE_LOOP, 3);
    lineLoopBatch.CopyVertexData3f(vCoast);
    lineLoopBatch.End();
    
    // 通过三角形创建金字塔
    GLfloat vPyramid[12][3] = {
        -2.0f, 0.0f, -2.0f,
        2.0f, 0.0f, -2.0f,
        0.0f, 4.0f, 0.0f,
        
        2.0f, 0.0f, -2.0f,
        2.0f, 0.0f, 2.0f,
        0.0f, 4.0f, 0.0f,
        
        2.0f, 0.0f, 2.0f,
        -2.0f, 0.0f, 2.0f,
        0.0f, 4.0f, 0.0f,
        
        -2.0f, 0.0f, 2.0f,
        -2.0f, 0.0f, -2.0f,
        0.0f, 4.0f, 0.0f
    };
    // GL_TRIANGLES 每3个顶点定义一个新的三角形
    triangleBatch.Begin(GL_TRIANGLES, 12);
    triangleBatch.CopyVertexData3f(vPyramid);
    triangleBatch.End();
    
    // 三角形扇形 -- 六边形
    GLfloat vPoints[100][3];
    int nVerts = 0;
    // 半径
    GLfloat r = 3.0f;
    // 远点（x, y, z）=（0, 0, 0）
    vPoints[nVerts][0] = 0.0f;
    vPoints[nVerts][1] = 0.0f;
    vPoints[nVerts][2] = 0.0f;
    
    // M3D_2PI 就是 2Pi 的意思，就是一个圆，绘制圆形
    for (GLfloat angle = 0; angle < M3D_2PI; angle += M3D_2PI / 6.0f) {
        // 数组下标自增（每自增1次就表示一个顶点）
        nVerts++;
        /*
         弧长=半径*角度,这里的角度是弧度制,不是平时的角度制
         既然知道了cos值,那么角度=arccos,求一个反三角函数就行了
         */
        //x点坐标 cos(angle) * 半径
        vPoints[nVerts][0] = float(cos(angle)) * r;
        //y点坐标 sin(angle) * 半径
        vPoints[nVerts][1] = float(sin(angle)) * r;
        //z点的坐标
        vPoints[nVerts][2] = -0.5f;
    }
    // 结束扇形 前面一共绘制7个顶点（包括圆心）
    // 添加闭合的终点
    // 课程添加演示：屏蔽177-180行代码，并把绘制节点改为7.则三角形扇形是无法闭合的。
    nVerts++;
    vPoints[nVerts][0] = r;
    vPoints[nVerts][1] = 0;
    vPoints[nVerts][2] = 0.0f;
    
    // GL_TRIANGLE_FAN 以一个圆心为中心呈扇形排列，共用相邻顶点的一组三角形
    triangleFanBatch.Begin(GL_TRIANGLE_FAN, 8);
    triangleFanBatch.CopyVertexData3f(vPoints);
    triangleFanBatch.End();
    
    
    // 三角形条带，一个小环或圆柱段
    // 顶点下标
    int iCounter = 0;
    // 半径
    GLfloat radius = 3.0f;
    // 从0度~360度，以0.3弧度为步长
    for(GLfloat angle = 0.0f; angle <= (2.0f*M3D_PI); angle += 0.3f)
    {
        // 获取圆形的顶点的X,Y
        GLfloat x = radius * sin(angle);
        GLfloat y = radius * cos(angle);
        
        // 绘制2个三角形（他们的x,y顶点一样，只是z点不一样）
        vPoints[iCounter][0] = x;
        vPoints[iCounter][1] = y;
        vPoints[iCounter][2] = -0.5;
        iCounter++;
        
        vPoints[iCounter][0] = x;
        vPoints[iCounter][1] = y;
        vPoints[iCounter][2] = 0.5;
        iCounter++;
    }
    
    // 关闭循环
    // 结束循环，在循环位置生成2个三角形
    vPoints[iCounter][0] = vPoints[0][0];
    vPoints[iCounter][1] = vPoints[0][1];
    vPoints[iCounter][2] = -0.5;
    iCounter++;
    
    vPoints[iCounter][0] = vPoints[1][0];
    vPoints[iCounter][1] = vPoints[1][1];
    vPoints[iCounter][2] = 0.5;
    iCounter++;
    
    // GL_TRIANGLE_STRIP 共用一个条带（strip）上的顶点的一组三角形
    triangleStripBatch.Begin(GL_TRIANGLE_STRIP, iCounter);
    triangleStripBatch.CopyVertexData3f(vPoints);
    triangleStripBatch.End();
}

void DrawViewFramedBatch(GLBatch *pBatch) {
    /*------------画绿色部分----------------*/
    /* GLShaderManager 中的Uniform 值——平面着色器
     参数1：平面着色器
     参数2：运行为几何图形变换指定一个 4 * 4变换矩阵
          --transformPipeline 变换管线（指定了2个矩阵堆栈）
     参数3：颜色值
    */
    shaderManager.UseStockShader(GLT_SHADER_FLAT, transformPipeline.GetModelViewProjectionMatrix(), vGreen);
    pBatch->Draw();
    
    /*-----------边框部分-------------------*/
    /*
        glEnable(GLenum mode); 用于启用各种功能。功能由参数决定
        参数列表：http://blog.csdn.net/augusdi/article/details/23747081
        注意：glEnable() 不能写在glBegin() 和 glEnd()中间
        GL_POLYGON_OFFSET_LINE  根据函数glPolygonOffset的设置，启用线的深度偏移
        GL_LINE_SMOOTH          执行后，过虑线点的锯齿
        GL_BLEND                启用颜色混合。例如实现半透明效果
        GL_DEPTH_TEST           启用深度测试 根据坐标的远近自动隐藏被遮住的图形（材料
     
     
        glDisable(GLenum mode); 用于关闭指定的功能 功能由参数决定
     
     */
    
    //画黑色边框
    //偏移深度，在同一位置要绘制填充和边线，会产生z冲突，所以要偏移
    glPolygonOffset(-1.0f, -1.0f);
    glEnable(GL_POLYGON_OFFSET_LINE);
    
    // 画反锯齿，让黑边好看些
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // 绘制线框几何黑色版 三种模式，实心，边框，点，可以作用在正面，背面，或者两面
    // 通过调用glPolygonMode将多边形正面或者背面设为线框模式，实现线框渲染
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // 设置线条宽度
    glLineWidth(2.5f);
    
    /* GLShaderManager 中的Uniform 值——平面着色器
    参数1：平面着色器
    参数2：运行为几何图形变换指定一个 4 * 4变换矩阵
        --transformPipeline.GetModelViewProjectionMatrix() 获取的
         GetMatrix函数就可以获得矩阵堆栈顶部的值
    参数3：颜色值（黑色）
    */
    shaderManager.UseStockShader(GLT_SHADER_FLAT, transformPipeline.GetModelViewProjectionMatrix(), vBlack);
    pBatch->Draw();
    
    // 复原原本的设置
    // 通过调用glPolygonMode将多边形正面或者背面设为全部填充模式
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDisable(GL_POLYGON_OFFSET_LINE);
    glLineWidth(1.0f);
    glDisable(GL_BLEND);
    glDisable(GL_LINE_SMOOTH);
}

/// 自定义函数.通过glutDisplayFunc(函数名)注册为显示渲染函数.
/// 当屏幕发⽣变化/或者开发者主动渲染会调用此函数,用来实现数据->渲染过程
void RenderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    // 压栈
    modelViewMatrix.PushMatrix();
    M3DMatrix44f mCamera;
    cameraFrame.GetCameraMatrix(mCamera);
    
    // 矩阵乘以矩阵堆栈的顶部矩阵，相乘的结果随后简存储在堆栈的顶部
    modelViewMatrix.MultMatrix(mCamera);
    
    M3DMatrix44f mObjectFrame;
    // 只要使用 GetMatrix 函数就可以获取矩阵堆栈顶部的值，这个函数可以进行2次重载。用来使用GLShaderManager 的使用。或者是获取顶部矩阵的顶点副本数据
    objectFrame.GetMatrix(mObjectFrame);
    
    // 矩阵乘以矩阵堆栈的顶部矩阵，相乘的结果随后简存储在堆栈的顶部
    modelViewMatrix.MultMatrix(mObjectFrame);
    
    /* GLShaderManager 中的 Uniform 值 -- 平面着色器
        参数1：平面着色器
        参数2：运行为几何图形变换指定一个 4 * 4变换矩阵
        --transformPipeline.GetModelViewProjectionMatrix() 获取的 GetMatrix 函数就可以获得矩阵堆栈顶部的值
        参数3：颜色值（黑色）
    */
    shaderManager.UseStockShader(GLT_SHADER_FLAT, transformPipeline.GetModelViewProjectionMatrix(), vBlack);
    
    switch (nStep) {
        case 0:
            glPointSize(4.0f);
            pointBatch.Draw();
            glPointSize(1.0f);
            break;
        case 1:
            glLineWidth(2.0);
            lineBatch.Draw();
            glLineWidth(1.0f);
            break;
        case 2:
            glLineWidth(4.0f);
            lineStripBatch.Draw();
            glLineWidth(1.0f);
            break;
        case 3:
            glLineWidth(4.0f);
            lineLoopBatch.Draw();
            glLineWidth(1.0f);
            break;
        case 4:
            DrawViewFramedBatch(&triangleBatch);
            break;
        case 5:
            DrawViewFramedBatch(&triangleFanBatch);
            break;
        case 6:
            DrawViewFramedBatch(&triangleStripBatch);
            break;
            
        default:
            break;
    }
    
    // 还原到以前的模型视图矩阵（单位矩阵）
    modelViewMatrix.PopMatrix();
    
    // 进行缓冲区交换
    glutSwapBuffers();
}

// 特殊键位处理（上、下、左、右移动）
void SpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        objectFrame.RotateWorld(m3dDegToRad(-5.0f), 1.0f, 0.0f, 0.0f);
    }
    if (key == GLUT_KEY_DOWN) {
        objectFrame.RotateWorld(m3dDegToRad(5.0f), 1.0f, 0.0f, 0.0f);
    }
    if (key == GLUT_KEY_LEFT) {
        objectFrame.RotateWorld(m3dDegToRad(-5.0f), 0.0f, 1.0f, 0.0f);
    }
    if (key == GLUT_KEY_RIGHT) {
        objectFrame.RotateWorld(m3dDegToRad(5.0f), 0.0f, 1.0f, 0.0f);
    }
    glutPostRedisplay();
}

// 根据空格次数。切换不同的“窗口名称”
void KeyPressFunc(unsigned char key, int x, int y) {
    if (key == 32) {
        nStep++;
        if (nStep > 6) {
            nStep = 0;
        }
    }
    switch (nStep) {
        case 0:
            glutSetWindowTitle("GL_POINTS");
            break;
        case 1:
            glutSetWindowTitle("GL_LINES");
            break;
        case 2:
            glutSetWindowTitle("GL_LINE_STRIP");
            break;
        case 3:
            glutSetWindowTitle("GL_LINE_LOOP");
            break;
        case 4:
            glutSetWindowTitle("GL_TRIANGLES");
            break;
        case 5:
            glutSetWindowTitle("GL_TRIANGLE_STRIP");
            break;
        case 6:
            glutSetWindowTitle("GL_TRIANGLE_FAN");
            break;
            
        default:
            break;
    }
    glutPostRedisplay();
}

/// 自定义函数.通过glutReshaperFunc(函数名)注册为重塑函数.
/// 当屏幕⼤小发生变化/或者第⼀次创建窗口时,会调用该函数调整窗口⼤小/视⼝⼤小.
void ChangeSize(int w, int h) {
    glViewport(0, 0, w, h);
    
    // 创建投影矩阵，并将它载入投影矩阵堆栈中
    viewFrustum.SetPerspective(35.0f, float(w)/float(h), 1.0f, 500.0f);
    projectionMatrix.LoadMatrix(viewFrustum.GetProjectionMatrix());
    
    // 调用顶部载入单元矩阵
    modelViewMatrix.LoadIdentity();
}

int main(int argc, char *argv[]) {
    gltSetWorkingDirectory(argv[0]);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowSize(800, 600);
    glutCreateWindow("GL_POINTS");
    // 注册回调函数（改变尺寸）
    glutReshapeFunc(ChangeSize);
    // 点击空格时调用函数
    glutKeyboardFunc(KeyPressFunc);
    // 特殊键位函数
    glutSpecialFunc(SpecialKeys);
    // 显示函数
    glutDisplayFunc(RenderScene);
    
    // 判断一下是否能初始化glew库，确保项目能正常使用OpenGL 框架
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
        return 1;
    }
    
    // 绘制
    SetupRC();
    
    // runloop运行循环
    glutMainLoop();
    
    return 0;
}
```


