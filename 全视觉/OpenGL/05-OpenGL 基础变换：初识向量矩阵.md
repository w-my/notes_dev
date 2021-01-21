# 基础变换：初识向量/矩阵（P90）

- 什么是向量
- 什么是矩阵
- 如果使用矩阵和向量来移动几何图形
- OpenGL 对于模型视图和投影矩阵的约定
- 什么是照相机，以及如何应用它的转换
- 如何将一个点光源位置转换到视点坐标系



## 向量（P91）

向量：总是用来表示带方向的量。有两个重要的值：方向 和 数量。

单位向量：长度为 1 的向量。

标准化：把一个向量缩放到 1。

math3d 库中，M3DVector3f 表示一 个三维向量 （X, Y, Z），M3DVector4f 表示一个四维向量（X, Y, Z, W）。典型情况下 W 坐标设为 1.0。X，Y 和 Z 值通过除以 W 来进行缩放。

定义成数组：

```c++
tyedef float M3DVector3f[3]
tyedef float M4DVector4f[4]
```

声明 三分量向量 和 四分量向量：

```c++
M3DVector3f vVector;
M3DVector4f vVectex = { 0.0f, 0.0f, 1.0f, 1.0f }；
```

声明 三分量顶点数组，例如生成一个三角形：

```c++
M3DVector3f vVerts[] = {
	-0.5f, 0.0f, 0.0f,
   0.5f, 0.0f, 0.0f,
   0.0f, 0.5f, 0.0f
};
```



#### 点乘

两个（三分量）单位向量之间的点乘运算将得到一个标量（只有一个值），它表示两个向量之间的夹角。要进行这种运算，这两个向量必须为单位长度，而返回的结果将在-1.0到+1.0范围之内。这个数字实际上就是这两个向量之间夹角的余弦值。在漫射光计算中，表面法向量和指向光源的向量之间大量进行着这种运算。

在 math3d 库中可以使用 m3dDotProduct3 函数来实现两个向量的点乘。

```objc
float m3dDotProduct3(const M3DVector3f u, const M3DVector3f v);
```

实际点乘结果是一个在 -1 和 +1 之间的值，它代表这两个单位向量之间夹角的余弦值。m3dGetAngleBetweenVectors3 是一个更高级一点的函数，实际上返回这个角的弧度值。

```objc
float m3dGetAngleBetweenVectors3(const M3DVector3f u, const M3DVector3f v);
```



#### 叉乘

另一种在两个向量之间进行的有用的数学操作是叉乘（cross product）。两个向量之间叉乘所得的结果是另外一个向量，这个新向量与原来两个向量定义的平面垂直。要进行叉乘，这两个向量都不必为单位向量。

在 math3d 库中可以使用 m3dCrossProduct3 函数对两个向量进行差乘并返回运算得到的结果向量。

```objc
void m3dCrossProduct3(M3DVector3f result, const M3DVector3f u, const M3DVector3f v);
```

和点乘不同，在进行叉乘时向量的顺序是非常重要的。V3是V2和V1进行叉乘得到的结果。如果调换V1和V2的顺序，那么结果得到的V3将会指向与原来相反的方向。从寻找三角形表面法线到构造变换矩阵，关于叉乘的应用数不胜数。



#### 矩阵

矩阵（matrix）是一种非常强大的数学工具，简化了求解变量之间有复杂关系的方程或方程组的过程。其中一个具有普遍性的例子和图形程序设计人员密切相关，就是坐标变换。例如，如果在空间中有一个点，由x，y和z坐标定义，将它围绕任意点沿任意方向旋转一定角度后，我们需要知道这个点现在的位置，就要用到矩阵。

一个矩阵只有一行或者一列也是合法的。只有一行或者一列数字可以更简单地称为向量。实际上，我们可以将矩阵看作一组列向量。

标量，就是一个普通的单独数据，用来表示大小和特定的量。

矩阵之间可以进行乘法和加法，也能与向量或者标量相乘。用一个点（向量）乘以一个矩阵（一次变换）结果得到一个新的变换点（向量）。

与此同时，math3d 库中有许多有用的矩阵函数和特性。GLTools源代码文件夹中的math3d.h和 math3d.cpp 中还提供了这个库的源代码。

在进行 3D 程序设计工作中，使用的几乎都是两种维度的矩阵，即 3x3 和 4x4 矩阵。在 math3d 库中也有这两种维度的矩阵数据类型：

```objc
typedef float M3DMatrix33f[9];
typedef float M3DMatrix44f[16];
```



## 变换（P95）

大多数 3D 图形其实是使用 3D 概念和术语来描述物体，然后这些 3D 数据被 “压扁” 到一个 2D 的计算机屏幕上。这种将 3D 数据转化成 2D 数据的处理过程叫做投影（projection）。正投影和透视投影，正交变换和透视变换。变换还允许旋转对象、移动对象、甚至伸展、收缩和扭曲。

OpenGL 变换术语：

| 变换     | 应用                                           |
| -------- | ---------------------------------------------- |
| 视图     | 指定观察者或照相机的位置                       |
| 模型     | 在场景中移动物体                               |
| 模型视图 | 描述视图和模型变换的二元性                     |
| 投影     | 改变视景体的大小或重新设置它的形状             |
| 视口     | 这是一种伪变换，只是对窗口上的最终输出进行缩放 |



#### 视觉坐标

视觉坐标是相对于观察者的视角而言的，无论可能进行何种变换，我们都可以将它们视为“绝对的”屏幕坐标。这样，视觉坐标就表示一个虚拟的固定坐标系，它通常作为参考坐标系使用。

利用 OpenGL 进行 3D 绘制时，就会使用笛卡尔坐标系。如果不进行任何变换，那么使用的坐标系将与视觉坐标系相同。

x 正方向朝右； y 正方向朝上； z 正方向朝向观察者；



#### 视图变换

视图变换是应用到场景中的第一种变换。它用来确定场景中的有利位置。在默认情况下，透视投影中的观察点位于原点（0, 0, 0），并沿着z轴的负方向进行观察。观察点相对于视觉坐标系进行移动，来提供特定的有利位置。当观察点位于原点（0，0，0）时，就像在透视投影中一样，绘制在z坐标为正的位置的对象则位于观察者背后。
然而在正投影中，观察者被认为是在z轴正方向无穷远的位置，能够看到视景体中的任何东西。视图变换允许我们把观察点放在所希望的任何位置，并允许在任何方向上观察场景。确定视图变换就像在场景中放置照相机并让它指向某个方向。
从大局上考虑，在应用任何其他模型变换之前，必须先应用视图变换。这样做是因为，对于视觉坐标系而言，视图变换移动了当前的工作坐标系。所有后续变换随后都会基于新调整的坐标系进行。然后，在实际开始考虑如何进行这些变换时，就会更容易地看到这些变换是如何实现的了。



#### 模型变换

模型变换用于操纵模型和其中的特定对象。这些变换将对象移动到需要的位置，然后再对它们进行旋转和缩放。



#### 模型视图的二元性

实际上，视图和模型变换按照它们内部效果和对场景的最终外观来说是一样的。视图变换和模型变换一样，在场景中的对象常常在进行视图变换后单独进行模型变换。术语“模型视图”是指这两种变换在变换管线中进行组合，成为一个单独的矩阵，即模型视图矩阵。



#### 投影变换

投影变换将在模型视图变换之后应用到顶点上。这种投影实际上定义了视景体并创建了裁剪平面。裁剪平面是3D空间中的平面方程式，OpenGL用它来确定几何图形对于观察者来说是否可见。

##### 正投影

在正投影（或者说平行投影）中，所有多边形都是精确地按照指定的相对大小来在屏幕上绘制的。线和多边形使用平行线来直接映射到2D屏幕上，这就意味着，无论某个物体的位置有多远，它都会按照同样的大小来进行绘制，仅仅是平贴到屏幕上而已。典型情况下，这种投影用于渲染二维图像。

##### 透视投影

透视投影所显示的场景与现实生活中更加接近，而不是一张蓝图。透视投影的特点就是透视缩短（ foreshortening ），这种特性使得远处的物体看起来比近处同样大小的物体更小一些。3D空间中应该是平行的线可能在观察者看来不总是平行的。



#### 视口变换

当所有这些都讲述并完成后，就得到了一个场景的二维投影，它将被映射到屏幕上某处的窗口上。这种到物理窗口标的映射是最后要做的变换，称为视口变换。通常，颜色缓冲区和窗口像素之间存在一一对应关系，但情况也并非一定如此。在某些情况下，视口变换会将“规范化”设备坐标重新映射到窗口坐标上。图形硬件会做好这些事。



## 模型视图矩阵

模型视图矩阵式一个4x4矩阵，它表示一个变换后的坐标系，我们可以用来放置对象和确定对象的方向。我们为图元提供的顶点将作为一个单列矩阵（也就是一个向量）的形式来使用，并乘以一个模型视图矩阵来获得一个相对于视觉坐标系的经过变换的新坐标。

如下一个包含单个顶点数据的矩阵乘以模型视图矩阵后得到新的视觉坐标。顶点数据实际上是4个元素，其中包含一个附加值W，它表示一个缩放因子。默认情况下着个值被设置为1.0，而我们很少去改动它。

> [X Y Z W] [ 4x4M ] = [X0 Y0 Z0 W0]



#### 矩阵的构造

OpenGL并不是将一个 4x4 矩阵表示为一个浮点值的二维数组，而是将它表示为一个由16个浮点值组成的单个数组。这种方式与许多数学库都不同，这些数学库都使用二维数组的方式。例如，OpenGL会采用的是下面两个例子中的第一个。

```objc
GLfloat matrix[16]; // Nice OpenGL friendly matrix
GLfloat matrix[4][4]; // Popular， but not as efficient for OpenGL
```

真正的奥妙在于，这16个值表示了空间中的一个特定位置，以及相对于视觉坐标系的3个轴上的方向。这4列中每一列都代表一个由4个元素组成的向量。前3列的前3个元素只是方向向量，它们表示空间中x轴、y轴和z轴上的方向（在这里用向量来表示一个方向）。对于大多数应用来说，这3个向量相互之间总是成90°角，并且通常为单位长度（除非我们还应用了缩放或裁剪）。这种情况的数学术语叫做标准正交（向量为单位长度）或者正交（向量不是单位长度）。

最奇妙的是，如果有一个包含一个不同坐标系的位置和方向的4x4矩阵，然后用一个表示原来坐标系的向量（表示为一个列矩阵或向量）乘以这个矩阵，得到的结果是一个转换到新坐标系下的新向量。这就意味着，空间中任何位置和任何想要的方向都可以由一个4x4矩阵唯一确定，并且如果用一个对象的所有向量乘以这个矩阵，那么我就将整个对象变换到了空间中的给定位置和方向！

##### 单位矩阵

单位矩阵中除了对角线上的一组元素之外，其他元素均为0。将一个向量乘以一个单位矩阵，就相当于用这个向量乘以1，不会发生任何改变。

```objc
// OpenGL 中单位矩阵
GLfloat m[] = {
	1.0f, 0.0f, 0.0f, 0.0f, // X Column
	0.0f, 1.0f, 0.0f, 0.0f, // Y Column
	0.0f, 0.0f, 1.0f, 0.0f, // Z Column
	0.0f, 0.0f, 0.0f, 1.0f  // Translation
};
// 或者使用 math3d 的 M3DMatrix44f 类型：
M3DMatrix44f m = {
	1.0f, 0.0f, 0.0f, 0.0f, // X Column
	0.0f, 1.0f, 0.0f, 0.0f, // Y Column
	0.0f, 0.0f, 1.0f, 0.0f, // Z Column
	0.0f, 0.0f, 0.0f, 1.0f  // Translation
};
// 在 math3d 库中还有一个快捷函数 m3dLoadIdentity44，这个函数初始化一个空单位矩阵
void m3dLoadIdentity44(M3DMatrix44f m);
```

##### 平移

一个平移矩阵仅仅是将顶点沿着3个坐标轴中的一个或多个进行平移。

```objc
void m3dTranslationMatrix44(M3DMatrix44f m, float x, float y, float z);
```

##### 旋转

将一个对象沿着3个坐标轴中的一个或者任意向量进行旋转。

```objc
m3dRotationMatrix44(M3DMatrix44f m， float angle， float x， float y， float z);
```

在这里，我们围绕一个由X、y和z变量指定的向量来进行旋转。旋转的角度沿逆时针方向按照弧度计算，由变量angle 指定。在最简单的情况下，旋转只是围绕坐标系的一个坐标轴（x、y或z）进行旋转。
还可以围绕任意一个由X、y和z变量指定的向量来进行旋转。要表示这个旋转轴，我们只要绘制一条从原点到由（x，y，z）表示的点的线段就可以了。举例来说，下面的代码创建一个旋转矩阵，可以使顶点沿着任意由（1，1，1）指定的轴旋转45°。

```objc
M3DMatrix44f m;
m3dRotationMatrix(m3dDegToRad(45.0), 1.0f, 1.0f, 1.0f);
```

math3d 中的宏 m3dDegToRad。这个宏将角度值转换为弧度值。

##### 缩放 

使用 math3d 库创建缩放矩阵

```objc
M3DMatrix44f m;
void m3dScaleMatrix44(M3DMatrix44f m, float xScale, float yScale, float zScale);
```

##### 综合变换

利用矩阵相乘来实现两种变换叠加的效果。不过矩阵相乘的运算顺序会影响结果，例如一个旋转矩阵乘以一个平移矩阵，与用一个平移矩阵乘以一个旋转矩阵是不通的。

Math3d 库函数 m3dMatrixMultiply44 用来将两个矩阵相乘并返回运算结果。

```objc
void m3dMatrixMultiply44(M3DMatrix44f product, const M3DMatrix44f a, const M3DMatrix44f b);
```



#### 运用模型视图矩阵

```objc
/**
 * GLTools.h 头文件中包含了大部分 GLTools 中类似 C 语言的独立函数；
 * GLShaderManager.h 移入了 GLTools 着色器管理器（Shader Manager）类。没有着色器，我们就不能在 OpenGL（核心框架）进行着色。着色器管理器不仅允许我们创建并管理着色器，还提供一组“存储着色器”（Stock Shader），它们能够进行一些初步䄦基本的渲染操作；
 */
#include <GLTools.h>
#include <GLShaderManager.h>

/**
 * 在 Mac 系统下，`#include<glut/glut.h>`；
 * 在 Windows 和 Linux 上，使用 freeglut 的静态库版本并且需要添加 FREEGLUT_STATIC 处理器宏；
 */
#ifdef __APPLE__
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

// 简单的批次容器，是GLTools的一个简单的容器类。
GLBatch batch;
// 声明一个着色器管理器实例
GLShaderManager shaderManager;

// blockSize 边长
GLfloat blockSize = 0.2f;
// 正方形的4个点坐标
GLfloat vVerts[] = {
	-blockSize, -blockSize, 0.0f,
	blockSize, -blockSize, 0.0f,
	blockSize, blockSize, 0.0f,
	-blockSize, blockSize, 0.0f
};

GLfloat xPos, yPos;


/// 供 GLUT 库在窗口维度改变时调用
/// @param w 窗口宽
/// @param h 窗口高
void ChangeSize(int w, int h) {
	// x,y 参数代表窗口中视图的左下角坐标
	glViewport(0, 0, w, h);
}

/// 设置渲染环境（Rendering Context）
void SetupRC() {
	// 设置清屏颜色（背景颜色）
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
	
	// 没有着色器，在 OpenGL 核心框架中是无法进行任何渲染的。初始化一个渲染管理器。
	shaderManager.InitializeStockShaders();
	
	batch.Begin(GL_TRIANGLE_FAN, 4);
	batch.CopyVertexData3f(vVerts);
	batch.End();
}

void RenderScene(void) {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	
	GLfloat vRed[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	
	M3DMatrix44f mFinalTransform, mTranslationMatrix, mRotationMatrix;
	
	m3dTranslationMatrix44(mTranslationMatrix, xPos, yPos, 0.0f);
	
	static float yRot = 0.0f;
	yRot += 0.5f;
	m3dRotationMatrix44(mRotationMatrix, m3dDegToRad(yRot), 0.0f, 0.0f, 1.0f);
	
	m3dMatrixMultiply44(mFinalTransform, mTranslationMatrix, mRotationMatrix);
	
	shaderManager.UseStockShader(GLT_SHADER_FLAT, mFinalTransform, vRed);
	
	batch.Draw();
	
	glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
	GLfloat stepSize = 0.025f;
	
	if (key == GLUT_KEY_UP) {
		yPos += stepSize;
	}
	if (key == GLUT_KEY_DOWN) {
		yPos -= stepSize;
	}
	if (key == GLUT_KEY_LEFT) {
		xPos -= stepSize;
	}
	if (key == GLUT_KEY_RIGHT) {
		xPos += stepSize;
	}
	
	glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	// 设置当前工作目录
	gltSetWorkingDirectory(argv[0]);
	
	// 传输命令行参数并初始化 GLUT 库
	glutInit(&argc, argv);
	/** 设置显示模式
	 * GLUT_DOUBLE 双缓冲窗口，是指绘图命令实际上是离屏缓存区执行的，然后迅速转换成窗口视图，这种方式，经常用来生成动画效果；
	 * GLUT_RGBA RGBA 颜色模式；
	 * GLUT_DEPTH 深度测试，位标志将一个深度缓冲区分配为显示的一部分，因此我们能够执行深度测试；
	 * GLUT_STENCIL 模板缓冲区，确保有一个可用的模板缓冲区；
	 */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	// 设置窗口大小、窗口标题
	glutInitWindowSize(500, 400);
	glutCreateWindow("Square");
	// 注册重塑函数
	glutReshapeFunc(ChangeSize);
	// 注册显示函数
	glutDisplayFunc(RenderScene);
	// 注册特殊函数
	glutSpecialFunc(specialKeys);
	
	/**
	 * 初始化一个 GLEW 库,确保 OpenGL API 对程序完全可用；
	 * 在试图做任何渲染之前，要检查确定驱动程序的初始化过程中没有任何问题；
	 */
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
	}
	
	// 设置渲染环境（Rendering Context）
	SetupRC();
	
	glutMainLoop();
	
	return 0;
}
```



## GLTriangleBatch

GLBatch 类，是了解决容纳一个顶点列表并将它们作为一个特定类型的图元批次来进行渲染。

GLTriangleBatch 类，是专门作为三角形的容器。每个顶点都可以有一个表面法线，以进行光照计算和纹理坐标。



#### 使用三角形批次类

为对象创建一个事件：

```objc
GLTriangBatch myCoolObject;
```

通知容器最多打算使用的顶点数，以开始创建网格：

```objc
myCoolObject.BeginMesh(200);
```

添加三角形。AddTriangle 成员函数接受一个包含3个顶点的数组，一个包含3个法线的数组，以及一个包含3个纹理坐标的数组。

```objc
void GLTriangleBatch::AddTriangle(M3DVector3f verts[3], M3DVector3f vNorms[3], M3DVector2f vTexCoords[3])
```

添加三角形时，调用 End。

```objc
myCoolObject.End();
```

然后选择想要的存储着色器并调用 Draw 函数。

```objc
myCoolObject.Draw();
```



#### 绘制 球体/环/圆柱/锥/磁盘

objectFrame+CameraFrame

```objc
#include "GLTools.h"
#include "GLMatrixStack.h"
#include "GLFrame.h"
#include "GLFrustum.h"
#include "GLGeometryTransform.h"

#ifdef __APPLE__
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

GLShaderManager 	shaderManager;
GLMatrixStack		modelViewMatrix;
GLMatrixStack		projectionMatrix;
// 观察者位置
GLFrame				cameraFrame;
// 世界坐标位置
GLFrame				objectFrame;
// 视景体，用来构造投影矩阵
GLFrustum			viewFrustum;
// 三角形批次类
GLTriangleBatch		CC_Triangle;
// 球
GLTriangleBatch		sphereBatch;
// 环
GLTriangleBatch		torusBatch;
// 圆柱
GLTriangleBatch		cylinderBatch;
// 锥
GLTriangleBatch		coneBatch;
// 磁盘
GLTriangleBatch		diskBatch;

GLGeometryTransform	transformPormPipeline;
M3DMatrix44f		shadowMatrix;

GLfloat vGreen[] = { 0.0f, 1.0f, 0.0f, 1.0f };
GLfloat vBlack[] = { 0.0f, 0.0f, 0.0f, 1.0f };

int nStep = 0;


void setupRC() {
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
	
	shaderManager.InitializeStockShaders();
	
	glEnable(GL_DEPTH_TEST);
	
//	objectFrame.MoveForward(15.0f);
	cameraFrame.MoveForward(-15.0f);
	
	// 球
	/*
	  gltMakeSphere(GLTriangleBatch& sphereBatch, GLfloat fRadius, GLint iSlices, GLint iStacks);
	 参数1：sphereBatch，三角形批次类对象
	 参数2：fRadius，球体半径
	 参数3：iSlices，从球体底部堆叠到顶部的三角形带的数量；其实球体是一圈一圈三角形带组成
	 参数4：iStacks，围绕球体一圈排列的三角形对数
	 
	 建议：一个对称性较好的球体的片段数量是堆叠数量的2倍，就是iStacks = 2 * iSlices;
	 绘制球体都是围绕Z轴，这样+z就是球体的顶点，-z就是球体的底部。
	 */
	gltMakeSphere(sphereBatch, 3.0, 10, 20);
	
	// 环面
	/*
	 gltMakeTorus(GLTriangleBatch& torusBatch, GLfloat majorRadius, GLfloat minorRadius, GLint numMajor, GLint numMinor);
	 参数1：torusBatch，三角形批次类对象
	 参数2：majorRadius,甜甜圈中心到外边缘的半径
	 参数3：minorRadius,甜甜圈中心到内边缘的半径
	 参数4：numMajor,沿着主半径的三角形数量
	 参数5：numMinor,沿着内部较小半径的三角形数量
	 */
	gltMakeTorus(torusBatch, 3.0f, 0.75f, 15, 15);
	
	// 圆柱
	/*
	 void gltMakeCylinder(GLTriangleBatch& cylinderBatch, GLfloat baseRadius, GLfloat topRadius, GLfloat fLength, GLint numSlices, GLint numStacks);
	 参数1：cylinderBatch，三角形批次类对象
	 参数2：baseRadius,底部半径
	 参数3：topRadius,头部半径
	 参数4：fLength,圆形长度
	 参数5：numSlices,围绕Z轴的三角形对的数量
	 参数6：numStacks,圆柱底部堆叠到顶部圆环的三角形数量
	 */
	gltMakeCylinder(cylinderBatch, 2.0f, 2.0f, 3.0f, 15, 2);
	
	//锥
	/*
	 void gltMakeCylinder(GLTriangleBatch& cylinderBatch, GLfloat baseRadius, GLfloat topRadius, GLfloat fLength, GLint numSlices, GLint numStacks);
	 参数1：cylinderBatch，三角形批次类对象
	 参数2：baseRadius,底部半径
	 参数3：topRadius,头部半径
	 参数4：fLength,圆形长度
	 参数5：numSlices,围绕Z轴的三角形对的数量
	 参数6：numStacks,圆柱底部堆叠到顶部圆环的三角形数量
	 */
	//圆柱体，从0开始向Z轴正方向延伸。
	//圆锥体，是一端的半径为0，另一端半径可指定。
	gltMakeCylinder(coneBatch, 2.0f, 0.0f, 3.0f, 13, 2);
	
	// 磁盘
	/*
	void gltMakeDisk(GLTriangleBatch& diskBatch, GLfloat innerRadius, GLfloat outerRadius, GLint nSlices, GLint nStacks);
	 参数1:diskBatch，三角形批次类对象
	 参数2:innerRadius,内圆半径
	 参数3:outerRadius,外圆半径
	 参数4:nSlices,圆盘围绕Z轴的三角形对的数量
	 参数5:nStacks,圆盘外网到内围的三角形数量
	 */
	gltMakeDisk(diskBatch, 1.5f, 3.0f, 13, 3);
	
}

void drawWireFramedBatch(GLTriangleBatch * pBatch) {
	// -- 绘制图形 --
	// 平面着色器，绘制三角形
	shaderManager.UseStockShader(GLT_SHADER_FLAT, transformPormPipeline.GetModelViewProjectionMatrix(), vGreen);
	// 传过来的参数，对应不同的图形batch
	pBatch->Draw();
	
	
	// -- 绘制轮廓 --
	// 开启多边形偏移
	glEnable(GL_POLYGON_OFFSET_LINE);
	// 多边形模型（背面、线）将多边形背面设为线框模式
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	// 开启多边形偏移（设置偏移数量）
	glPolygonOffset(-1.0f, -1.0f);
	glLineWidth(1.0f);
	
	// 开启混合模式（颜色混合&抗锯齿混合）
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	// 设置颜色混合因子
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	// 平面着色器绘制线条
	shaderManager.UseStockShader(GLT_SHADER_FLAT, transformPormPipeline.GetModelViewProjectionMatrix(), vBlack);
	
	pBatch->Draw();
	
	// 恢复多边形模式和深度测试
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_POLYGON_OFFSET_LINE);
	glLineWidth(1.0f);
	glDisable(GL_BLEND);
	glDisable(GL_LINE_SMOOTH);
	
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	
//	modelViewMatrix.PushMatrix(objectFrame);
	
	//2.模型视图矩阵栈堆，压栈
	modelViewMatrix.PushMatrix();
	
	//3.获取摄像头矩阵
	M3DMatrix44f mCamera;
	//从camereaFrame中获取矩阵到mCamera
	cameraFrame.GetCameraMatrix(mCamera);
	//模型视图堆栈的 矩阵与mCamera矩阵 相乘之后，存储到modelViewMatrix矩阵堆栈中
	modelViewMatrix.MultMatrix(mCamera);
	
	//4.创建矩阵mObjectFrame
	M3DMatrix44f mObjectFrame;
	//从ObjectFrame 获取矩阵到mOjectFrame中
	objectFrame.GetMatrix(mObjectFrame);
	//将modelViewMatrix 的堆栈中的矩阵 与 mOjbectFrame 矩阵相乘，存储到modelViewMatrix矩阵堆栈中
	modelViewMatrix.MultMatrix(mObjectFrame);
	
	//3.判断你目前是绘制第几个图形
	switch(nStep) {
		case 0:
			drawWireFramedBatch(&sphereBatch);
			break;
		case 1:
			drawWireFramedBatch(&torusBatch);
			break;
		case 2:
			drawWireFramedBatch(&cylinderBatch);
			break;
		case 3:
			drawWireFramedBatch(&coneBatch);
			break;
		case 4:
			drawWireFramedBatch(&diskBatch);
			break;
	}
	
	modelViewMatrix.PopMatrix();
	
	glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
	// 移动世界坐标系
	if(key == GLUT_KEY_UP)
		objectFrame.RotateWorld(m3dDegToRad(-5.0), 1.0f, 0.0f, 0.0f);
	
	if(key == GLUT_KEY_DOWN)
		objectFrame.RotateWorld(m3dDegToRad(5.0), 1.0f, 0.0f, 0.0f);
	
	if(key == GLUT_KEY_LEFT)
		objectFrame.RotateWorld(m3dDegToRad(-5.0), 0.0f, 1.0f, 0.0f);
	
	if(key == GLUT_KEY_RIGHT)
		objectFrame.RotateWorld(m3dDegToRad(5.0), 0.0f, 1.0f, 0.0f);
	
	glutPostRedisplay();
}

void keyPressFunc(unsigned char key, int x, int y) {
	if (key == 32) {
		nStep++;
		if (nStep > 4) nStep = 0;
	}
	
	switch (nStep) {
		case 0:
			glutSetWindowTitle("Sphere");
			break;
		case 1:
			glutSetWindowTitle("Torus");
			break;
		case 2:
			glutSetWindowTitle("Cylinder");
			break;
		case 3:
			glutSetWindowTitle("Cone");
			break;
		case 4:
			glutSetWindowTitle("Disk");
			break;
			
		default:
			break;
	}
	glutPostRedisplay();
}

void changeSize(int w, int h) {
	// 视窗
	glViewport(0, 0, w, h);
	// 透视投影
	viewFrustum.SetPerspective(35.0f, float(w)/float(h), 1.0f, 500.0f);
	// projectionMatrix 矩阵堆栈 加载透视投影矩阵
	projectionMatrix.LoadMatrix(viewFrustum.GetProjectionMatrix());
	// modelViewMatrix 矩阵堆栈 加载单元矩阵
	modelViewMatrix.LoadIdentity();
	// 通过 GLGeometryTransform 管理矩阵堆栈
	// 使用 transformPormPipeline 管道管理模型视图矩阵堆栈 和 投影矩阵堆栈
	transformPormPipeline.SetMatrixStacks(modelViewMatrix, projectionMatrix);
}


int main(int argc, char *argv[]) {
	
	gltSetWorkingDirectory(argv[0]);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(500, 400);
	glutCreateWindow("Geometry Test Program");
	
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
		return 1;
	}
	
	glutReshapeFunc(changeSize);
	glutDisplayFunc(renderScene);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyPressFunc);
	
	setupRC();
	
	glutMainLoop();
	return 0;
}
```



####  绘制 旋转球体

```objc
#include "GLTools.h"
#include "GLMatrixStack.h"
#include "GLFrame.h"
#include "GLFrustum.h"
#include "GLGeometryTransform.h"
#include "GLBatch.h"
#include "StopWatch.h"

#include <math.h>

#ifdef __APPLE__
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

GLShaderManager 	shaderManager;
// 视景体，用来构造投影矩阵
GLFrustum			viewFrustum;
GLTriangleBatch		sphereBatch;
GLGeometryTransform	transformPipeline;


void setupRC() {
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
	
	shaderManager.InitializeStockShaders();
	
	glEnable(GL_DEPTH_TEST);

	gltMakeSphere(sphereBatch, 0.4f, 10, 20);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}


void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	
	// 建立基于事件变化的动画
	static CStopWatch rotTimer;
	// 当前时间 * 60s
	float yRot = rotTimer.GetElapsedSeconds() * 60.0f;
	
	// 矩阵变量
	M3DMatrix44f mTranslate, mRotate, mModelView, mModelViewProjection;
	
	// 建立一个4*4矩阵变量，将球沿着Z轴负方向移动2.5个单位长度
	m3dTranslationMatrix44(mTranslate, 0.0f, 0.0f, -2.5f);
	// 创建一个4*4矩阵变量，将花托在Y轴上渲染yRot度，yRot根据经过时间设置动画帧率
	m3dRotationMatrix44(mRotate, m3dDegToRad(yRot), -1.0f, 1.0f, 0.0f);
	// 为mModerView 通过平移矩阵、旋转矩阵相乘，将结果添加到mModerView上
	m3dMatrixMultiply44(mModelView, mTranslate, mRotate);
	// 将投影矩阵乘以模型视图矩阵，将变化结果通过矩阵乘法应用到 mModelViewProjection 矩阵上
	// 注意顺序: 投影 * 模型 != 模型 * 投影
	m3dMatrixMultiply44(mModelViewProjection, viewFrustum.GetProjectionMatrix(), mModelView);
	
	GLfloat vBlack[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	
	shaderManager.UseStockShader(GLT_SHADER_FLAT, mModelViewProjection, vBlack);
	
	sphereBatch.Draw();
	
	glutSwapBuffers();
	glutPostRedisplay();
}

void changeSize(int w, int h) {
	// 视窗
	glViewport(0, 0, w, h);
	// 透视投影
	viewFrustum.SetPerspective(35.0f, float(w)/float(h), 1.0f, 1000.0f);
}


int main(int argc, char *argv[]) {
	
	gltSetWorkingDirectory(argv[0]);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(500, 400);
	glutCreateWindow("Geometry Test Program");
	
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
		return 1;
	}
	
	glutReshapeFunc(changeSize);
	glutDisplayFunc(renderScene);
	
	setupRC();
	
	glutMainLoop();
	return 0;
}
```



## 投影矩阵

系统只能接受正负为1的单位坐标系。因此要使用不同的坐标系，就需要利用投影矩阵实现把想要的坐标系变换到单位坐标系中。



#### 正投影

```objc
GLFrustum::SetOrthographic(GLfloat xMin, GLfloat xMax, GLfloat yMin, GLfloat yMax, GLfloat zMin, GLfloat zMax);
```

#### 透视投影

```objc
GLFrustum::SetPerspective(float fFov, float fAspect, float fNear, float fFar);
```



## 变换管线

首先，我们的顶点将被视为一个1x4矩阵，其中前3个值为x，y和z坐标。第4个数字是一个缩放因子，如果需要的话我们可以手动进行设置。这就是w坐标，通常在默认情况下为1.0，我们很少会真正去直接修改这个值。然后，顶点将乘以模型视图矩阵，生成变换的视觉坐标。随后，视觉坐标再乘以投影矩阵，生成裁剪坐标。裁剪坐标值位于我们前面提到的+/-1.0单位坐标系内。将有效地将所有位于这个裁剪空间之外的数据消除掉。裁剪坐标随后再除以w坐标，生成规范化的设备坐标。其中w值可能会被投影矩阵或模型视图矩阵修改，这取决于所发生的变换。透视除法将作为图元装配过程的一部分进行。最后，坐标三元组将通过视口变换被映射到2D平面上。这项操作也是由一个矩阵来表示的，但不能直接指定或者修改这个矩阵。OpenGL将在内部根据指定的glViewport值来设置这个矩阵。

##### 矩阵堆栈

```objc
// 初始化矩阵堆栈，包含了单位矩阵，默认堆栈深度为64
GLMatrixStack::GLMatrixStack(int iStackDepth = 64);
// 可以通过调用在顶部载入这个单位矩阵
void GLMatrixStack::LoadIdentity(void);
// 或者可以在堆栈的顶部载入任何矩阵
void GLMatrixStack::LoadMatrix(const M3DMatrix44f m);
// 此外，还可以用一个矩阵乘以矩阵堆栈的顶部矩阵，相乘的到的结果随后将存储在堆栈的顶部
void GLMatrixStack::MultMatrix(const M3DMatrix33f);
// 最后，只要用 GetMatrix 函数就可以获得矩阵堆栈顶部的值，这个函数可以进行两次重载。
const M3DMatrix44f& GLMatrixStack::GetMatrix(void);
void GLMatrixStack::GetMatrix(M3DMatrix44f mMatrix);
```

##### 压栈与出栈

一个矩阵的真正价值在于通过压栈操作存储一个状态，然后通过出栈操作恢复这个状态。通过GLMatrixStack类，可以使用 PushMatrix 函数将矩阵压入堆栈来存储当前矩阵值。
这样做实际上是复制了当前矩阵值，并将新的值放入了堆栈的顶部。类似地，PopMatrix 将移除顶部矩阵，并恢复它下面的值。以上每种情况都有几次重载。

```objc
void GLMatrixStack::PushMatrix(void);
void PushMatrix(const M3DMatrix44f mMatrix);
void PushMatrix(GLFrame& frame);
void GLMatrixStack::PopMatrix(void);
```

##### 仿射变换

GLMatrixStack 类也内建了对创建旋转、平移和缩放矩阵的支持

```objc
void MatrixStack::Rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void MatrixStack::Translate(GLfloat x, GLfloat y, GLfloat z);
void MatrixStack::Scale(GLfloat x, GLfloat y, GLfloat z);
```



#### 管理管线



#### 照相机管理