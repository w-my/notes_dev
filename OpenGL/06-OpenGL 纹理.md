# 纹理

| 任务             | 使用的函数                                       |
| ---------------- | ------------------------------------------------ |
| 载入纹理图像     | glTexImage / glTexSubImage                       |
| 设置纹理贴图参数 | glTexParameter                                   |
| 管理多重纹理     | glGenTextures / glDeleteTextures / glBindTexture |
| 生成 Mip 贴图    | glGenerateMipmap                                 |
| 使用各向异性过滤 | glGet/gloatv / glTexParameter                    |
| 载入压缩纹理     | glCompressedTexImage / glCompressedTexSubImage   |

##### 函数

###### 数据存储

```objc
// 改变像素存储方式
void glPixelStorei(GLenum pname, GLint param);
// 恢复像素存储方式
void glPixelStoref(GLenum panme, GLfloat params);

// e.g.
// 参数1：GL_UNPACK_ALIGNMENT，指定 OpenGL 如何从数据缓存区中解包图像数据
// 参数2：表示参数 GL_UNPACK_ALIGNMENT 设置的值
// GL_UNPACK_ALIGNMENT 指内存中每个像素⾏起点的排列请求，允许设置为1 (byte排列)、2(排列为偶数byte的行)、4(字word排列)、8(⾏从双字节 边界开始)
glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
```

###### 从颜色缓冲区内容作为像素图直接读取

```objc
// 参数1: x 矩形左下角的窗口坐标
// 参数2: y 矩形左下角的窗口坐标
// 参数3: width 矩形的宽，以像素位单位
// 参数4: height 矩形的高，以像素位单位
// 参数5: format OpenGL的像素格式
// 参数6: type 解释参数pixels指向的数据，告诉OpenGL使用缓冲区中的什么数据类型来存储颜色分量
// 参数7: pixels 指向图形数据的指针
void glReadPixels(GLint x, GLint y, GLSizei width, GLSizei height, GLenum fromat, GLenum type, const void *pixels);

// 指定读取的缓存
glReadBuffer(mode);
// 指定写入的缓存
glWriteBuffer(mode);
```



##### 使用纹理

```c++
// 1.读取文件
void glReadPixels(GLint x,GLint y,GLSizei width,GLSizei height, GLenu m format, GLenum type,const void * pixels);
// 2.载入纹理
void glTexImage2D(GLenum target,GLint level,GLint internalformat,GLsizei width,GLsizei height,GLint border,GLenum format,GLenum type,void * data);
// 3.纹理对象
// 使用函数分配纹理对象
// 制定纹理对象的数量和指针（指针指向一个无符号整形数组，由纹理对象标识符填充）
void glGenTextures(GLsizei n,GLuint * textTures);
// 绑定纹理状态
// 参数target:GL_TEXTURE_1D、GL_TEXTURE_2D、GL_TEXTURE_3D
// 参数texture:需要绑定的纹理对象
void glBindTexture(GLenum target,GLunit texture);
// 删除绑定纹理对象
// 纹理对象 以及 纹理对象指针（指针指向一个无符号整形数组，由纹理对象标识符填充）
void glDeleteTextures(GLsizei n,GLuint *textures);
// 测试纹理对象是否有效
// 如果texture是一个已经分配空间的纹理对象，那么这个函数会返回GL_TRUE，否则会返回GL_FALSE
GLboolean glIsTexture(GLuint texture);
// 设置纹理的相关参数
// 放大/缩小过滤（邻近过滤，线性过滤）
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);

glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
// 设置x轴/y轴上环绕方式
// x,y,z,w
// s,t,r,q
glTextParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAR_S,GL_CLAMP_TO_EDGE); glTextParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAR_T,GL_CLAMP_TO_EDGE);
```



## Mip贴图(多级渐远纹理)

Mip贴图是一种功能强大的纹理技巧。它可以提高渲染性能同时可以改善场景的显示质量。

假设有一个包含上千物体的大房间，每个物体都有纹理。有些物体会很远，但其纹理会拥有与近处物体同样的高分辨率。由于远处的物体可能只产生很少的片段，OpenGL从高分辨率纹理中为这些片段获取正确的颜色值就很困难，因为它需要对一个跨过很大部分的片段只拾取一个纹理颜色。在小物体上就会产生不真实的感觉，而且使用高分辨率还浪费内存。

OpenGL使用一种叫做多级渐远纹理（Mipmap）的概念来解决这个问题，简单来说就是一系列的纹理图像，后一个纹理图像是前一个的二分之一。距观察者的距离超过一定的阈值，OpenGL会使用不同的多级渐远纹理，即最适合物体的距离的那个。同时也能保证性能非常好。

在创建完一个纹理后调用OpenGL的一个函数 `glGenerateMipmaps` ，就会自动创建一些列的多级渐远纹理。

`glTextParameteri()` 函数，`level` 参数在 `Mib` 贴图发挥作用，因为它指定图像数据用于哪个 `mip` 层。第一层是0，后面依次类推。如果 `Mib` 贴图未使用，那么只有第0层才会被加载。在默认情况下，为了能使用 `mip` 贴图，所有的 `mip` 层都要加载。可以通过设置 `GL_TEXTURE_BASE_LEVEL` 和 `GL_TEXTURE_MAX_LEVEL` 纹理参数设置需要使用的基层和最大层。

```c
// 设置mip贴图基层
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
// 设置mip贴图最大层
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
```

虽然可以通过设置 `GL_TEXTURE_BASE_LEVEL` 和 `GL_TEXTURE_MAX_LEVEL` 纹理参数控制哪些mip层被加载 。但是也可以使用 `GL_TEXTURE_MIN_LOD` 和 `GL_TEXTURE_MAX_LOD` 参数限制已加载的Mip层的使用范围。

#### 什么使用生成Mip贴图？

只有 minFilter 等于以下四种模式，才可以生成 Mip 贴图

- `GL_NEAREST_MIPMAP_NEAREST` 具有非常好的性能，并且闪烁现象非常弱
- `GL_LINEAR_MIPMAP_NEAREST` 常常用于对游戏进行加速，它使用了高质量的线性过滤器
- `GL_LINEAR_MIPMAP_LINEAR` `GL_NEAREST_MIPMAP_LINEAR` 过滤器在 Mip 层之间执行了一些额外的插值，以消除他们之间的过滤痕迹。
- `GL_LINEAR_MIPMAP_LINEAR` 三线性 Mip 贴图。纹理过滤的黄金准则，具有最高的精度。

```c
if(minFilter == GL_LINEAR_MIPMAP_LINEAR ||
         minFilter == GL_LINEAR_MIPMAP_NEAREST ||
         minFilter == GL_NEAREST_MIPMAP_LINEAR ||
         minFilter == GL_NEAREST_MIPMAP_NEAREST)
// 纹理生成所有的Mip层
// 参数：GL_TEXTURE_1D、GL_TEXTURE_2D、GL_TEXTURE_3D
glGenerateMipmap(GL_TEXTURE_2D);
```

#### glGenerateMipmap 函数解析

> 目的：为纹理对象生成一组完整的 mipmap
>
> void glGenerateMipmap(GLenum target)；
> 参数：指定将生成mipmap的纹理对象绑定到的活动纹理单元的纹理目标.GL_TEXTURE_1D、GL_TEXTURE_2D、GL_TEXTURE_3D
>
> 描述：glGenerateMipmap计算从零级数组派生的一组完整的mipmap数组。无论先前的内容如何，最多包括1x1维度纹理图像的数组级别都将替换为派生数组。零级纹理图像保持不变（原图）。
>
> ​		派生的mipmap数组的内部格式都与零级纹理图像的内部格式相匹配。通过将零级纹理图像的宽度和高度减半来计算派生数组的尺寸，然后将每个阵列级别的尺寸减半，直到达到1x1尺寸纹理图像。



## Mip贴图过滤

| 常量                      | 描述                                                       |
| ------------------------- | ---------------------------------------------------------- |
| GL_NEAREST                | 在Mip基层上执行最邻近过滤                                  |
| GL_LINEAR                 | 在Mip基层执行线性过滤                                      |
| GL_NEAREST_MIPMAP_NEAREST | 在最邻近Mip层，并执行最邻近过滤                            |
| GL_NEAREST_MIPMAP_LINEAR  | 在Mip层之间执行线性插补，并执行最邻近过滤                  |
| GL_LINEAR_MIPMAP_NEAREST  | 选择最邻近Mip层，并执行线性过滤                            |
| GL_LINEAR_MIPMAP_LINEAR   | 在Mip层之间执行线性插补，并执行线性过滤，又称三线性Mip贴图 |

**一个常见的错误是，将放大过滤的选项设置为多级渐远纹理过滤选项之一。这样没有任何效果，因为多级渐远纹理主要是使用在纹理被缩小的情况下的：纹理放大不会使用多级渐远纹理，为放大过滤设置多级渐远纹理的选项会产生一个 `GL_INVALID_ENUM` 错误代码。**

```c
// GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER(缩小过滤器)，GL_NEAREST（最邻近过滤）
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
// GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER(缩小过滤器)，GL_LINEAR（线性过滤）
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
// GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER(缩小过滤器)，GL_NEAREST_MIPMAP_ NEAREST（选择最邻近的Mip层，并执行最邻近过滤）
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPM AP_NEAREST);
// GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER(缩小过滤器)，GL_NEAREST_MIPMAP_ LINEAR（在Mip层之间执行线性插补，并执行最邻近过滤）
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPM AP_LINEAR);
// GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER(缩小过滤器)，GL_NEAREST_MIPMAP_L INEAR（选择最邻近Mip层，并执行线性过滤）
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMA P_NEAREST);
// GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER(缩小过滤器)，GL_LINEAR_MIPMAP_LI NEAR（在Mip层之间执行线性插补，并执行线性过滤，又称为三线性过滤）
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMA P_LINEAR);
```



## 各向异性过滤

各向异性纹理过滤（ Anisotropic texture filtering ）并不是OpenGL和性规范中的一部分。但它是一种得到广泛使用的扩展。可以极大的提高纹理过滤操作的质量。

前面的两种基本过滤，最邻近过滤（GL_NEAREST）和线性过滤（GL_LINEAR）。当一个纹理贴图被过滤时，OpenGL使用的纹理坐标来判断一个特定的几何片段在纹理的什么地方。然后，紧邻这个位置的纹理单使用 `GL_NEAREST` 和 `GL_LINEAR` 过滤操作进行采样。

当我们从一个角度倾斜地观察这个几何图形时，对周围纹理单元进行常规采样，会导致一些纹理信息丢失（看上去显得模糊）。

为了更加逼真和准确的采样应该沿着包含纹理的平面方向进行延伸。如果我们进行处理纹理过滤时，考虑了观察角度，那么这个过滤方法就叫“各向异性过滤”。

在Mip贴图纹理过滤模型中，或者其他所有的基本纹理过滤我们都可以应用各向异性过滤。

**应用各向异性过滤，需要2个步骤。**

- 第一，查询得到支持的各向异性过滤的最大数量，可以使用 `glGetFloatv` 函数，并以`GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT` 参数

```c
GLfloat flargest;
glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT,&fLargest);
```

- 第二，可以使用 `glTexParameter` 函数以及 `GL_TEXTURE_MAX_ANISOTROPY_EXT` ，设置各向异性过滤数据。

```c
// 设置纹理参数（各向异性采样）
glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAX_ANISOTROPY_EXT,fLargest);
// 设置各向同性过滤，参数为1.0表示（各向同性采样）
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 1.0f);
```

**注意：**

各向异性过滤所应用的数量越大，沿着最大变化方向（沿最强的观察点）所采样的纹理单元就越多。值1.0表示常规的纹理过滤（各向同性过滤）。

各向异性过滤，是会增加额外的工作，包括其他纹理单元。很可能对性能造成影响。但是，在现代硬件上，应用这个特性对速度造成影响不大。

最重要的是，目前它已经成为流行游戏、动画和模拟程序的一个标准特性。



## 金字塔案例

```c++
#include "GLTools.h"
#include "GLShaderManager.h"
#include "GLFrustum.h"
#include "GLBatch.h"
#include "GLFrame.h"
#include "GLMatrixStack.h"
#include "GLGeometryTransform.h"

#ifdef __APPLE__
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

GLShaderManager		shaderManager;
GLMatrixStack		modelViewMatrix;
GLMatrixStack		projectionMatrix;
GLFrame				cameraFrame;
GLFrame             objectFrame;
GLFrustum			viewFrustum;

GLBatch             pyramidBatch;

//纹理变量，一般使用无符号整型
GLuint              textureID;

GLGeometryTransform	transformPipeline;
M3DMatrix44f		shadowMatrix;

//绘制金字塔
void MakePyramid(GLBatch& pyramidBatch)
{
    /*1、通过pyramidBatch组建三角形批次
      参数1：类型
      参数2：顶点数
      参数3：这个批次中将会应用1个纹理
      注意：如果不写这个参数，默认为0。
     */
    pyramidBatch.Begin(GL_TRIANGLES, 18, 1);
    
    /***前情导入
     
     1)设置法线
     void Normal3f(GLfloat x, GLfloat y, GLfloat z);
     Normal3f：添加一个表面法线（法线坐标 与 Vertex顶点坐标中的Y轴一致）
     表面法线是有方向的向量，代表表面或者顶点面对的方向（相反的方向）。在多数的关照模式下是必须使用。后面的课程会详细来讲法线的应用
     
     pyramidBatch.Normal3f(X,Y,Z);
     
     2)设置纹理坐标
     void MultiTexCoord2f(GLuint texture, GLclampf s, GLclampf t);
     参数1：texture，纹理层次，对于使用存储着色器来进行渲染，设置为0
     参数2：s：对应顶点坐标中的x坐标
     参数3：t:对应顶点坐标中的y
     (s,t,r,q对应顶点坐标的x,y,z,w)
     
     pyramidBatch.MultiTexCoord2f(0,s,t);
     
     3)void Vertex3f(GLfloat x, GLfloat y, GLfloat z);
      void Vertex3fv(M3DVector3f vVertex);
     向三角形批次类添加顶点数据(x,y,z);
      pyramidBatch.Vertex3f(-1.0f, -1.0f, -1.0f);
     
     
     4)获取从三点找到一个法线坐标(三点确定一个面)
     void m3dFindNormal(result,point1, point2,point3);
     参数1：结果
     参数2-4：3个顶点数据
     */
    
    //塔顶
    M3DVector3f vApex = { 0.0f, 1.0f, 0.0f };
    M3DVector3f vFrontLeft = { -1.0f, -1.0f, 1.0f };
    M3DVector3f vFrontRight = { 1.0f, -1.0f, 1.0f };
    M3DVector3f vBackLeft = { -1.0f,  -1.0f, -1.0f };
    M3DVector3f vBackRight = { 1.0f,  -1.0f, -1.0f };
    M3DVector3f n;
    
    //金字塔底部
    //底部的四边形 = 三角形X + 三角形Y
    //三角形X = (vBackLeft,vBackRight,vFrontRight)
    
    //1.找到三角形X 法线
    m3dFindNormal(n, vBackLeft, vBackRight, vFrontRight);
   
    //vBackLeft
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
    pyramidBatch.Vertex3fv(vBackLeft);
    
    //vBackRight
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
    pyramidBatch.Vertex3fv(vBackRight);
    
    //vFrontRight
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
    pyramidBatch.Vertex3fv(vFrontRight);
    
    
    //三角形Y =(vFrontLeft,vBackLeft,vFrontRight)
   
    //1.找到三角形X 法线
    m3dFindNormal(n, vFrontLeft, vBackLeft, vFrontRight);
    
    //vFrontLeft
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
    pyramidBatch.Vertex3fv(vFrontLeft);
    
    //vBackLeft
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
    pyramidBatch.Vertex3fv(vBackLeft);
    
    //vFrontRight
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
    pyramidBatch.Vertex3fv(vFrontRight);

    
    // 金字塔前面
    //三角形：（Apex，vFrontLeft，vFrontRight）
    m3dFindNormal(n, vApex, vFrontLeft, vFrontRight);
   
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 0.5f, 1.0f);
    pyramidBatch.Vertex3fv(vApex);
    
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
    pyramidBatch.Vertex3fv(vFrontLeft);

    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
    pyramidBatch.Vertex3fv(vFrontRight);
    
    //金字塔左边
    //三角形：（vApex, vBackLeft, vFrontLeft）
    m3dFindNormal(n, vApex, vBackLeft, vFrontLeft);
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 0.5f, 1.0f);
    pyramidBatch.Vertex3fv(vApex);
    
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
    pyramidBatch.Vertex3fv(vBackLeft);
    
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
    pyramidBatch.Vertex3fv(vFrontLeft);
    
    //金字塔右边
    //三角形：（vApex, vFrontRight, vBackRight）
    m3dFindNormal(n, vApex, vFrontRight, vBackRight);
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 0.5f, 1.0f);
    pyramidBatch.Vertex3fv(vApex);
    
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
    pyramidBatch.Vertex3fv(vFrontRight);
    
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
    pyramidBatch.Vertex3fv(vBackRight);
    
    //金字塔后边
    //三角形：（vApex, vBackRight, vBackLeft）
    m3dFindNormal(n, vApex, vBackRight, vBackLeft);
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 0.5f, 1.0f);
    pyramidBatch.Vertex3fv(vApex);
    
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
    pyramidBatch.Vertex3fv(vBackRight);
    
    pyramidBatch.Normal3fv(n);
    pyramidBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
    pyramidBatch.Vertex3fv(vBackLeft);
    
    //结束批次设置
    pyramidBatch.End();
}

// 将TGA文件加载为2D纹理。
bool LoadTGATexture(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode)
{
    GLbyte *pBits;
    int nWidth, nHeight, nComponents;
    GLenum eFormat;
    
    //1、读纹理位，读取像素
    //参数1：纹理文件名称
    //参数2：文件宽度地址
    //参数3：文件高度地址
    //参数4：文件组件地址
    //参数5：文件格式地址
    //返回值：pBits,指向图像数据的指针
    
    pBits = gltReadTGABits(szFileName, &nWidth, &nHeight, &nComponents, &eFormat);
    if(pBits == NULL)
        return false;
    
    //2、设置纹理参数
    //参数1：纹理维度
    //参数2：为S/T坐标设置模式
    //参数3：wrapMode,环绕模式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
    
    //参数1：纹理维度
    //参数2：线性过滤
    //参数3：wrapMode,环绕模式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
    

    //3.载入纹理
    //参数1：纹理维度
    //参数2：mip贴图层次
    //参数3：纹理单元存储的颜色成分（从读取像素图是获得）
    //参数4：加载纹理宽
    //参数5：加载纹理高
    //参数6：加载纹理的深度
    //参数7：像素数据的数据类型（GL_UNSIGNED_BYTE，每个颜色分量都是一个8位无符号整数）
    //参数8：指向纹理图像数据的指针
    
    glTexImage2D(GL_TEXTURE_2D, 0, nComponents, nWidth, nHeight, 0,
                 eFormat, GL_UNSIGNED_BYTE, pBits);
    
    //使用完毕释放pBits
    free(pBits);
    
    //只有minFilter 等于以下四种模式，才可以生成Mip贴图
    //GL_NEAREST_MIPMAP_NEAREST具有非常好的性能，并且闪烁现象非常弱
    //GL_LINEAR_MIPMAP_NEAREST常常用于对游戏进行加速，它使用了高质量的线性过滤器
    //GL_LINEAR_MIPMAP_LINEAR 和GL_NEAREST_MIPMAP_LINEAR 过滤器在Mip层之间执行了一些额外的插值，以消除他们之间的过滤痕迹。
    //GL_LINEAR_MIPMAP_LINEAR 三线性Mip贴图。纹理过滤的黄金准则，具有最高的精度。
    if(minFilter == GL_LINEAR_MIPMAP_LINEAR ||
       minFilter == GL_LINEAR_MIPMAP_NEAREST ||
       minFilter == GL_NEAREST_MIPMAP_LINEAR ||
       minFilter == GL_NEAREST_MIPMAP_NEAREST)
    //4.纹理生成所有的Mip层
    //参数：GL_TEXTURE_1D、GL_TEXTURE_2D、GL_TEXTURE_3D
    glGenerateMipmap(GL_TEXTURE_2D);
 
    return true;
}




void SetupRC()
{
    //1.
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f );
    shaderManager.InitializeStockShaders();
    
    //2.
    glEnable(GL_DEPTH_TEST);
    
    //3.
    //分配纹理对象 参数1:纹理对象个数，参数2:纹理对象指针
    glGenTextures(1, &textureID);
    //绑定纹理状态 参数1：纹理状态2D 参数2：纹理对象
    glBindTexture(GL_TEXTURE_2D, textureID);
    //将TGA文件加载为2D纹理。
    //参数1：纹理文件名称
    //参数2&参数3：需要缩小&放大的过滤器
    //参数4：纹理坐标环绕模式
    LoadTGATexture("stone.tga", GL_LINEAR_MIPMAP_NEAREST, GL_LINEAR, GL_CLAMP_TO_EDGE);
    
    //4.创造金字塔pyramidBatch
    MakePyramid(pyramidBatch);
    
    //5.
    /**相机frame MoveForward(平移)
    参数1：Z，深度（屏幕到图形的Z轴距离）
     */
    cameraFrame.MoveForward(-10);
}



// 清理…例如删除纹理对象
void ShutdownRC(void)
{
    glDeleteTextures(1, &textureID);
}

void RenderScene(void)
{
    //1.颜色值&光源位置
    static GLfloat vLightPos [] = { 1.0f, 1.0f, 0.0f };
    static GLfloat vWhite [] = { 1.0f, 1.0f, 1.0f, 1.0f };
    
    //2.清理缓存区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    //3.当前模型视频压栈
    modelViewMatrix.PushMatrix();
    
    //添加照相机矩阵
    M3DMatrix44f mCamera;
    //从camraFrame中获取一个4*4的矩阵
    cameraFrame.GetCameraMatrix(mCamera);
    //矩阵乘以矩阵堆栈顶部矩阵，相乘结果存储到堆栈的顶部 将照相机矩阵 与 当前模型矩阵相乘 压入栈顶
    modelViewMatrix.MultMatrix(mCamera);
    
    //创建mObjectFrame矩阵
    M3DMatrix44f mObjectFrame;
    //从objectFrame中获取矩阵，objectFrame保存的是特殊键位的变换矩阵
    objectFrame.GetMatrix(mObjectFrame);
    //矩阵乘以矩阵堆栈顶部矩阵，相乘结果存储到堆栈的顶部 将世界变换矩阵 与 当前模型矩阵相乘 压入栈顶
    modelViewMatrix.MultMatrix(mObjectFrame);
    
    //4.绑定纹理，因为我们的项目中只有一个纹理。如果有多个纹理。绑定纹理很重要
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    /*5.点光源着色器
     参数1：GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF（着色器标签）
     参数2：模型视图矩阵
     参数3：投影矩阵
     参数4：视点坐标系中的光源位置
     参数5：基本漫反射颜色
     参数6：图形颜色（用纹理就不需要设置颜色。设置为0）
     */
    shaderManager.UseStockShader(GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF,
                                 transformPipeline.GetModelViewMatrix(),
                                 transformPipeline.GetProjectionMatrix(),
                                 vLightPos, vWhite, 0);
    
    //pyramidBatch 绘制
    pyramidBatch.Draw();
    
    //模型视图出栈，恢复矩阵（push一次就要pop一次）
    modelViewMatrix.PopMatrix();
    
    //6.交换缓存区
    glutSwapBuffers();
}



void SpecialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)
        objectFrame.RotateWorld(m3dDegToRad(-5.0f), 1.0f, 0.0f, 0.0f);
    
    if(key == GLUT_KEY_DOWN)
        objectFrame.RotateWorld(m3dDegToRad(5.0f), 1.0f, 0.0f, 0.0f);
    
    if(key == GLUT_KEY_LEFT)
        objectFrame.RotateWorld(m3dDegToRad(-5.0f), 0.0f, 1.0f, 0.0f);
    
    if(key == GLUT_KEY_RIGHT)
        objectFrame.RotateWorld(m3dDegToRad(5.0f), 0.0f, 1.0f, 0.0f);
    
    glutPostRedisplay();
}





void ChangeSize(int w, int h)
{
    //1.设置视口
    glViewport(0, 0, w, h);
    
    //2.创建投影矩阵
    viewFrustum.SetPerspective(35.0f, float(w) / float(h), 1.0f, 500.0f);
  
    //viewFrustum.GetProjectionMatrix()  获取viewFrustum投影矩阵
    //并将其加载到投影矩阵堆栈上
    projectionMatrix.LoadMatrix(viewFrustum.GetProjectionMatrix());
    
    //3.设置变换管道以使用两个矩阵堆栈（变换矩阵modelViewMatrix ，投影矩阵projectionMatrix）
    //初始化GLGeometryTransform 的实例transformPipeline.通过将它的内部指针设置为模型视图矩阵堆栈 和 投影矩阵堆栈实例，来完成初始化
    //当然这个操作也可以在SetupRC 函数中完成，但是在窗口大小改变时或者窗口创建时设置它们并没有坏处。而且这样可以一次性完成矩阵和管线的设置。
    transformPipeline.SetMatrixStacks(modelViewMatrix, projectionMatrix);
}


int main(int argc, char* argv[])
{
    gltSetWorkingDirectory(argv[0]);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Pyramid");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
        return 1;
    }
    
    
    SetupRC();
    
    glutMainLoop();
    
    ShutdownRC();
    
    return 0;
}
```



## 隧道

```c
#include "GLTools.h"
#include "GLShaderManager.h"
#include "GLFrustum.h"
#include "GLBatch.h"
#include "GLFrame.h"
#include "GLMatrixStack.h"
#include "GLGeometryTransform.h"

#ifdef __APPLE__
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

GLShaderManager		shaderManager;			//着色器管理器
GLMatrixStack		modelViewMatrix;		//模型视图矩阵
GLMatrixStack		projectionMatrix;		//投影矩阵
GLFrustum			viewFrustum;			//视景体
GLGeometryTransform	transformPipeline;		//几何变换管线

//4个批次容器类
GLBatch             floorBatch;//地面
GLBatch             ceilingBatch;//天花板
GLBatch             leftWallBatch;//左墙面
GLBatch             rightWallBatch;//右墙面

//深度初始值，-65。
GLfloat             viewZ = -65.0f;

// 纹理标识符号
#define TEXTURE_BRICK   0 //墙面
#define TEXTURE_FLOOR   1 //地板
#define TEXTURE_CEILING 2 //纹理天花板
#define TEXTURE_COUNT   3 //纹理个数

GLuint  textures[TEXTURE_COUNT];//纹理标记数组
//文件tag名字数组
const char *szTextureFiles[TEXTURE_COUNT] = { "brick.tga", "floor.tga", "ceiling.tga" };



//菜单栏选择
void ProcessMenu(int value)
{
    GLint iLoop;
    
    for(iLoop = 0; iLoop < TEXTURE_COUNT; iLoop++)
    {
        /**绑定纹理 glBindTexture
         参数1：GL_TEXTURE_2D
         参数2：需要绑定的纹理对象
         */
        glBindTexture(GL_TEXTURE_2D, textures[iLoop]);
        
        /**配置纹理参数 glTexParameteri
         参数1：纹理模式
         参数2：纹理参数
         参数3：特定纹理参数
         
         */
        switch(value)
        {
            case 0:
                //GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER(缩小过滤器)，GL_NEAREST（最邻近过滤）
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                break;
                
            case 1:
                //GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER(缩小过滤器)，GL_LINEAR（线性过滤）
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                break;
                
            case 2:
                //GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER(缩小过滤器)，GL_NEAREST_MIPMAP_NEAREST（选择最邻近的Mip层，并执行最邻近过滤）
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
                break;
                
            case 3:
                //GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER(缩小过滤器)，GL_NEAREST_MIPMAP_LINEAR（在Mip层之间执行线性插补，并执行最邻近过滤）
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
                break;
                
            case 4:
                //GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER(缩小过滤器)，GL_NEAREST_MIPMAP_LINEAR（选择最邻近Mip层，并执行线性过滤）
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
                break;
                
            case 5:
                //GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER(缩小过滤器)，GL_LINEAR_MIPMAP_LINEAR（在Mip层之间执行线性插补，并执行线性过滤，又称为三线性过滤）
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                break;
                
            case 6:
            
                //设置各向异性过滤
                GLfloat fLargest;
                //获取各向异性过滤的最大数量
                glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &fLargest);
                //设置纹理参数(各向异性采样)
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest);
                break;
        
            case 7:
                //设置各向同性过滤，数量为1.0表示(各向同性采样)
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 1.0f);
                break;
                
        }
    }
    
    //触发重画
    glutPostRedisplay();
}


//在这个函数里能够在渲染环境中进行任何需要的初始化，它这里的设置并初始化纹理对象
void SetupRC()
{
    //1.黑色的背景
    glClearColor(0.0f, 0.0f, 0.0f,1.0f);
    
    //2.初始化shaderManager
    shaderManager.InitializeStockShaders();
    
    
    GLbyte *pBytes;
    GLint iWidth, iHeight, iComponents;
    GLenum eFormat;
    GLint iLoop;

    //3.生成纹理标记
    /** 分配纹理对象 glGenTextures
     参数1：纹理对象的数量
     参数2：纹理对象标识数组
     */
    glGenTextures(TEXTURE_COUNT, textures);
    
    //4. 循环设置纹理数组的纹理参数
    for(iLoop = 0; iLoop < TEXTURE_COUNT; iLoop++)
    {
        /**绑定纹理对象 glBindTexture
         参数1：纹理模式，GL_TEXTURE_1D,GL_TEXTURE_2D,GL_TEXTURE_3D
         参数2：需要绑定的纹理对象
         */
        glBindTexture(GL_TEXTURE_2D, textures[iLoop]);
        
        /**加载tga文件
         参数1：纹理文件名称
         参数2：文件宽度变量地址
         参数3：文件高度变量地址
         参数4：文件组件变量地址
         参数5：文件格式变量地址
         返回值：pBytes，指向图像数据的指针
         */
        
        pBytes = gltReadTGABits(szTextureFiles[iLoop],&iWidth, &iHeight,
                                &iComponents, &eFormat);
        
        //加载纹理、设置过滤器和包装模式
        //GL_TEXTURE_MAG_FILTER（放大过滤器,GL_NEAREST(最邻近过滤)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        //GL_TEXTURE_MIN_FILTER(缩小过滤器),GL_NEAREST(最邻近过滤)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        //GL_TEXTURE_WRAP_S(s轴环绕),GL_CLAMP_TO_EDGE(环绕模式强制对范围之外的纹理坐标沿着合法的纹理单元的最后一行或一列进行采样)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        //GL_TEXTURE_WRAP_T(t轴环绕)，GL_CLAMP_TO_EDGE(环绕模式强制对范围之外的纹理坐标沿着合法的纹理单元的最后一行或一列进行采样)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        
        
        /**载入纹理 glTexImage2D
         参数1：纹理维度，GL_TEXTURE_2D
         参数2：mip贴图层次
         参数3：纹理单元存储的颜色成分（从读取像素图中获得）
         参数4：加载纹理宽度
         参数5：加载纹理的高度
         参数6：加载纹理的深度
         参数7：像素数据的数据类型,GL_UNSIGNED_BYTE无符号整型
         参数8：指向纹理图像数据的指针
         */
        glTexImage2D(GL_TEXTURE_2D, 0, iComponents, iWidth, iHeight, 0, eFormat, GL_UNSIGNED_BYTE, pBytes);
        
            /**为纹理对象生成一组完整的mipmap glGenerateMipmap
             参数1：纹理维度，GL_TEXTURE_1D,GL_TEXTURE_2D,GL_TEXTURE_2D
             */
            glGenerateMipmap(GL_TEXTURE_2D);
        
            //释放原始纹理数据，不在需要纹理原始数据了
            free(pBytes);
    }
    
    //5. 设置几何图形顶点/纹理坐标(上.下.左.右)
    GLfloat z;
    
    /*
     GLTools库中的容器类，GBatch，
     void GLBatch::Begin(GLenum primitive,GLuint nVerts,GLuint nTextureUnits = 0);
     参数1：图元枚举值
     参数2：顶点数
     参数3：1组或者2组纹理坐标
     */
    
    floorBatch.Begin(GL_TRIANGLE_STRIP, 28, 1);
    //参考PPT图6-10
    //Z表示深度，隧道的深度
    for(z = 60.0f; z >= 0.0f; z -=10.0f)
    {
        floorBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
        floorBatch.Vertex3f(-10.0f, -10.0f, z);
        
        floorBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
        floorBatch.Vertex3f(10.0f, -10.0f, z);
        
        floorBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
        floorBatch.Vertex3f(-10.0f, -10.0f, z - 10.0f);
        
        floorBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
        floorBatch.Vertex3f(10.0f, -10.0f, z - 10.0f);
    }
    floorBatch.End();
   
   //参考PPT图6-11
    ceilingBatch.Begin(GL_TRIANGLE_STRIP, 28, 1);
    for(z = 60.0f; z >= 0.0f; z -=10.0f)
    {
        ceilingBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
        ceilingBatch.Vertex3f(-10.0f, 10.0f, z - 10.0f);
        
        ceilingBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
        ceilingBatch.Vertex3f(10.0f, 10.0f, z - 10.0f);
        
        ceilingBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
        ceilingBatch.Vertex3f(-10.0f, 10.0f, z);
        
        ceilingBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
        ceilingBatch.Vertex3f(10.0f, 10.0f, z);
    }
    ceilingBatch.End();
    
    //参考PPT图6-12
    leftWallBatch.Begin(GL_TRIANGLE_STRIP, 28, 1);
    for(z = 60.0f; z >= 0.0f; z -=10.0f)
    {
        leftWallBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
        leftWallBatch.Vertex3f(-10.0f, -10.0f, z);
        
        leftWallBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
        leftWallBatch.Vertex3f(-10.0f, 10.0f, z);
        
        leftWallBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
        leftWallBatch.Vertex3f(-10.0f, -10.0f, z - 10.0f);
        
        leftWallBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
        leftWallBatch.Vertex3f(-10.0f, 10.0f, z - 10.0f);
    }
    leftWallBatch.End();
   
   //参考PPT图6-13
    rightWallBatch.Begin(GL_TRIANGLE_STRIP, 28, 1);
    for(z = 60.0f; z >= 0.0f; z -=10.0f)
    {
        rightWallBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
        rightWallBatch.Vertex3f(10.0f, -10.0f, z);
        
        rightWallBatch.MultiTexCoord2f(0, 0.0f, 1.0f);
        rightWallBatch.Vertex3f(10.0f, 10.0f, z);
        
        rightWallBatch.MultiTexCoord2f(0, 1.0f, 0.0f);
        rightWallBatch.Vertex3f(10.0f, -10.0f, z - 10.0f);
        
        rightWallBatch.MultiTexCoord2f(0, 1.0f, 1.0f);
        rightWallBatch.Vertex3f(10.0f, 10.0f, z - 10.0f);
    }
    rightWallBatch.End();
    
}

//关闭渲染环境
void ShutdownRC(void)
{
    //删除纹理
    glDeleteTextures(TEXTURE_COUNT, textures);
}


//前后移动视口来对方向键作出响应
void SpecialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)
        //移动的是深度值，Z
        viewZ += 0.5f;
    
    if(key == GLUT_KEY_DOWN)
        viewZ -= 0.5f;
    
    //更新窗口，即可回调到RenderScene函数里
    glutPostRedisplay();
}

//改变视景体和视口，在改变窗口大小或初始化窗口调用
void ChangeSize(int w, int h)
{
    //1.防止对0进行除法操作
    if(h == 0)
        h = 1;
    
    //2.将视口设置大小
    glViewport(0, 0, w, h);
    
    GLfloat fAspect = (GLfloat)w/(GLfloat)h;
    
    //3.生成透视投影
    viewFrustum.SetPerspective(80.0f,fAspect,1.0,120.0);
    projectionMatrix.LoadMatrix(viewFrustum.GetProjectionMatrix());
    transformPipeline.SetMatrixStacks(modelViewMatrix, projectionMatrix);
    
}

//调用，绘制场景
void RenderScene(void)
{
    //1.用当前清除色，清除窗口
    glClear(GL_COLOR_BUFFER_BIT);
    
    //2.模型视图压栈
    modelViewMatrix.PushMatrix();
    //Z轴平移viewZ 距离
    modelViewMatrix.Translate(0.0f, 0.0f, viewZ);
    
    //3.纹理替换矩阵着色器
    /*
     参数1：GLT_SHADER_TEXTURE_REPLACE（着色器标签）
     参数2：模型视图投影矩阵
     参数3：纹理层
     */
    shaderManager.UseStockShader(GLT_SHADER_TEXTURE_REPLACE, transformPipeline.GetModelViewProjectionMatrix(), 0);
    
    //4.绑定纹理
    /*
     参数1：纹理模式，GL_TEXTURE_1D、GL_TEXTURE_2D、GL_TEXTURE_3D
     参数2：需要绑定的纹理
     */
    glBindTexture(GL_TEXTURE_2D, textures[TEXTURE_FLOOR]);
    floorBatch.Draw();
    
    glBindTexture(GL_TEXTURE_2D, textures[TEXTURE_CEILING]);
    ceilingBatch.Draw();
    
    glBindTexture(GL_TEXTURE_2D, textures[TEXTURE_BRICK]);
    leftWallBatch.Draw();
    rightWallBatch.Draw();
    
    //5.pop
    modelViewMatrix.PopMatrix();
    
    //6.缓存区交换
    glutSwapBuffers();
}



int main(int argc, char *argv[])
{
    gltSetWorkingDirectory(argv[0]);
    
    // 标准初始化
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tunnel");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    
    // 添加菜单入口，改变过滤器
    glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("GL_NEAREST",0);
    glutAddMenuEntry("GL_LINEAR",1);
    glutAddMenuEntry("GL_NEAREST_MIPMAP_NEAREST",2);
    glutAddMenuEntry("GL_NEAREST_MIPMAP_LINEAR", 3);
    glutAddMenuEntry("GL_LINEAR_MIPMAP_NEAREST", 4);
    glutAddMenuEntry("GL_LINEAR_MIPMAP_LINEAR", 5);
    glutAddMenuEntry("Anisotropic Filter", 6);
    glutAddMenuEntry("Anisotropic Off", 7);
    
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
        return 1;
    }
    
    
    // 启动循环，关闭纹理
    SetupRC();
    glutMainLoop();
    ShutdownRC();
    
    return 0;
}
```



## 球体世界

```c
#include "GLTools.h"
#include "GLShaderManager.h"
#include "GLFrustum.h"
#include "GLBatch.h"
#include "GLMatrixStack.h"
#include "GLGeometryTransform.h"
#include "StopWatch.h"

#include <math.h>
#include <stdio.h>

#ifdef __APPLE__
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

//**4、添加附加随机球
#define NUM_SPHERES 50
GLFrame spheres[NUM_SPHERES];

GLShaderManager		shaderManager;			// 着色器管理器
GLMatrixStack		modelViewMatrix;		// 模型视图矩阵
GLMatrixStack		projectionMatrix;		// 投影矩阵
GLFrustum			viewFrustum;			// 视景体
GLGeometryTransform	transformPipeline;		// 几何图形变换管道

GLTriangleBatch		torusBatch;             // 花托批处理
GLBatch				floorBatch;             // 地板批处理

//**2、定义公转球的批处理（公转自转）**
GLTriangleBatch     sphereBatch;            //球批处理

//**3、角色帧 照相机角色帧（全局照相机实例）
GLFrame             cameraFrame;

//**5、添加纹理
//纹理标记数组
GLuint uiTextures[3];

bool LoadTGATexture(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode)
{

    GLbyte *pBits;
    int nWidth, nHeight, nComponents;
    GLenum eFormat;
    
    //1.读取纹理数据
    pBits = gltReadTGABits(szFileName, &nWidth, &nHeight, &nComponents, &eFormat);
    if(pBits == NULL)
        return false;
    
    //2、设置纹理参数
    //参数1：纹理维度
    //参数2：为S/T坐标设置模式
    //参数3：wrapMode,环绕模式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
    
    //参数1：纹理维度
    //参数2：线性过滤
    //参数3：wrapMode,环绕模式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
    
    //3.载入纹理
    //参数1：纹理维度
    //参数2：mip贴图层次
    //参数3：纹理单元存储的颜色成分（从读取像素图是获得）-将内部参数nComponents改为了通用压缩纹理格式GL_COMPRESSED_RGB
    //参数4：加载纹理宽
    //参数5：加载纹理高
    //参数6：加载纹理的深度
    //参数7：像素数据的数据类型（GL_UNSIGNED_BYTE，每个颜色分量都是一个8位无符号整数）
    //参数8：指向纹理图像数据的指针
    glTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGB, nWidth, nHeight, 0,
                 eFormat, GL_UNSIGNED_BYTE, pBits);
    
    //使用完毕释放pBits
    free(pBits);
    
    //只有minFilter 等于以下四种模式，才可以生成Mip贴图
    //GL_NEAREST_MIPMAP_NEAREST具有非常好的性能，并且闪烁现象非常弱
    //GL_LINEAR_MIPMAP_NEAREST常常用于对游戏进行加速，它使用了高质量的线性过滤器
    //GL_LINEAR_MIPMAP_LINEAR 和GL_NEAREST_MIPMAP_LINEAR 过滤器在Mip层之间执行了一些额外的插值，以消除他们之间的过滤痕迹。
    //GL_LINEAR_MIPMAP_LINEAR 三线性Mip贴图。纹理过滤的黄金准则，具有最高的精度。
    if(minFilter == GL_LINEAR_MIPMAP_LINEAR ||
       minFilter == GL_LINEAR_MIPMAP_NEAREST ||
       minFilter == GL_NEAREST_MIPMAP_LINEAR ||
       minFilter == GL_NEAREST_MIPMAP_NEAREST)
    //4.加载Mip,纹理生成所有的Mip层
    //参数：GL_TEXTURE_1D、GL_TEXTURE_2D、GL_TEXTURE_3D
    glGenerateMipmap(GL_TEXTURE_2D);
    
    
    return true;
}



void SetupRC()
{
    //1.设置清屏颜色到颜色缓存区
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    //2.初始化着色器管理器
    shaderManager.InitializeStockShaders();
    
    //3.开启深度测试/背面剔除
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    //4.设置大球球
    gltMakeSphere(torusBatch, 0.4f, 40, 80);
    
    //5.设置小球(公转自转)
    gltMakeSphere(sphereBatch, 0.1f, 26, 13);
    
    //6.设置地板顶点数据&地板纹理
    GLfloat texSize = 10.0f;
    floorBatch.Begin(GL_TRIANGLE_FAN, 4,1);
    floorBatch.MultiTexCoord2f(0, 0.0f, 0.0f);
    floorBatch.Vertex3f(-20.f, -0.41f, 20.0f);
    
    floorBatch.MultiTexCoord2f(0, texSize, 0.0f);
    floorBatch.Vertex3f(20.0f, -0.41f, 20.f);
    
    floorBatch.MultiTexCoord2f(0, texSize, texSize);
    floorBatch.Vertex3f(20.0f, -0.41f, -20.0f);
    
    floorBatch.MultiTexCoord2f(0, 0.0f, texSize);
    floorBatch.Vertex3f(-20.0f, -0.41f, -20.0f);
    floorBatch.End();
    
    //7.随机小球球顶点坐标数据
    for (int i = 0; i < NUM_SPHERES; i++) {
        
        //y轴不变，X,Z产生随机值
        GLfloat x = ((GLfloat)((rand() % 400) - 200 ) * 0.1f);
        GLfloat z = ((GLfloat)((rand() % 400) - 200 ) * 0.1f);
        
        //在y方向，将球体设置为0.0的位置，这使得它们看起来是飘浮在眼睛的高度
        //对spheres数组中的每一个顶点，设置顶点数据
        spheres[i].SetOrigin(x, 0.0f, z);
    }
    
    //8.命名纹理对象
    glGenTextures(3, uiTextures);
    
    //9.将TGA文件加载为2D纹理。
    //参数1：纹理文件名称
    //参数2&参数3：需要缩小&放大的过滤器
    //参数4：纹理坐标环绕模式
    glBindTexture(GL_TEXTURE_2D, uiTextures[0]);
    LoadTGATexture("marble.tga", GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, GL_REPEAT);
    
    
    glBindTexture(GL_TEXTURE_2D, uiTextures[1]);
    LoadTGATexture("marslike.tga", GL_LINEAR_MIPMAP_LINEAR,
                   GL_LINEAR, GL_CLAMP_TO_EDGE);
    
    
    glBindTexture(GL_TEXTURE_2D, uiTextures[2]);
    LoadTGATexture("moonlike.tga", GL_LINEAR_MIPMAP_LINEAR,
                   GL_LINEAR, GL_CLAMP_TO_EDGE);
    
   
}

//删除纹理
void ShutdownRC(void)
{
    glDeleteTextures(3, uiTextures);
}

// 屏幕更改大小或已初始化
void ChangeSize(int nWidth, int nHeight)
{
    //1.设置视口
    glViewport(0, 0, nWidth, nHeight);
    
    //2.设置投影方式
    viewFrustum.SetPerspective(35.0f, float(nWidth)/float(nHeight), 1.0f, 100.0f);
    
    //3.将投影矩阵加载到投影矩阵堆栈,
    projectionMatrix.LoadMatrix(viewFrustum.GetProjectionMatrix());
    modelViewMatrix.LoadIdentity();
    
    //4.将投影矩阵堆栈和模型视图矩阵对象设置到管道中
    transformPipeline.SetMatrixStacks(modelViewMatrix, projectionMatrix);
   
    
}

void drawSomething(GLfloat yRot)
{
    //1.定义光源位置&漫反射颜色
    static GLfloat vWhite[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    static GLfloat vLightPos[] = { 0.0f, 3.0f, 0.0f, 1.0f };
    
    //2.绘制悬浮小球球
    glBindTexture(GL_TEXTURE_2D, uiTextures[2]);
    for(int i = 0; i < NUM_SPHERES; i++) {
        modelViewMatrix.PushMatrix();
        modelViewMatrix.MultMatrix(spheres[i]);
        shaderManager.UseStockShader(GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF,
                                     modelViewMatrix.GetMatrix(),
                                     transformPipeline.GetProjectionMatrix(),
                                     vLightPos,
                                     vWhite,
                                     0);
        sphereBatch.Draw();
        modelViewMatrix.PopMatrix();
    }
    
    //3.绘制大球球
    modelViewMatrix.Translate(0.0f, 0.2f, -2.5f);
    modelViewMatrix.PushMatrix();
    modelViewMatrix.Rotate(yRot, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, uiTextures[1]);
    shaderManager.UseStockShader(GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF,
                                 modelViewMatrix.GetMatrix(),
                                 transformPipeline.GetProjectionMatrix(),
                                 vLightPos,
                                 vWhite,
                                 0);
    torusBatch.Draw();
    modelViewMatrix.PopMatrix();
    
    //4.绘制公转小球球（公转自转)
    modelViewMatrix.PushMatrix();
    modelViewMatrix.Rotate(yRot * -2.0f, 0.0f, 1.0f, 0.0f);
    modelViewMatrix.Translate(0.8f, 0.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, uiTextures[2]);
    shaderManager.UseStockShader(GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF,
                                 modelViewMatrix.GetMatrix(),
                                 transformPipeline.GetProjectionMatrix(),
                                 vLightPos,
                                 vWhite,
                                 0);
    sphereBatch.Draw();
    modelViewMatrix.PopMatrix();
    
}



//进行调用以绘制场景
void RenderScene(void)
{
    //1.地板颜色值
    static GLfloat vFloorColor[] = { 1.0f, 1.0f, 0.0f, 0.75f};
    
    //2.基于时间动画
    static CStopWatch	rotTimer;
    float yRot = rotTimer.GetElapsedSeconds() * 60.0f;
    
    //3.清除颜色缓存区和深度缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //4.压入栈(栈顶)
    modelViewMatrix.PushMatrix();
    
    //5.设置观察者矩阵
    M3DMatrix44f mCamera;
    cameraFrame.GetCameraMatrix(mCamera);
    modelViewMatrix.MultMatrix(mCamera);
    
    //6.压栈(镜面)
    modelViewMatrix.PushMatrix();
    
    //7.---添加反光效果---
    //翻转Y轴
    modelViewMatrix.Scale(1.0f, -1.0f, 1.0f);
    //镜面世界围绕Y轴平移一定间距
    modelViewMatrix.Translate(0.0f, 0.8f, 0.0f);
    
    //8.指定顺时针为正面
    glFrontFace(GL_CW);
  
    //9.绘制地面以外其他部分(镜面)
    drawSomething(yRot);
   
    //10.恢复为逆时针为正面
    glFrontFace(GL_CCW);
    
    //11.绘制镜面，恢复矩阵
    modelViewMatrix.PopMatrix();
    
    //12.开启混合功能(绘制地板)
    glEnable(GL_BLEND);
    //13. 指定glBlendFunc 颜色混合方程式
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    //14.绑定地面纹理
    glBindTexture(GL_TEXTURE_2D, uiTextures[0]);
    
    /*15.
     纹理调整着色器(将一个基本色乘以一个取自纹理的单元nTextureUnit的纹理)
     参数1：GLT_SHADER_TEXTURE_MODULATE
     参数2：模型视图投影矩阵
     参数3：颜色
     参数4：纹理单元（第0层的纹理单元）
     
     */
    shaderManager.UseStockShader(GLT_SHADER_TEXTURE_MODULATE,
                                 transformPipeline.GetModelViewProjectionMatrix(),
                                 vFloorColor,
                                 0);
    //开始绘制
    floorBatch.Draw();
    //取消混合
    glDisable(GL_BLEND);
    
    //16.绘制地面以外其他部分
    drawSomething(yRot);
    
    //17.绘制完，恢复矩阵
    modelViewMatrix.PopMatrix();
    
    //18.交换缓存区
    glutSwapBuffers();
    
    //19.提交重新渲染
    glutPostRedisplay();
    
    
    
}


//**3.移动照相机参考帧，来对方向键作出响应
void SpeacialKeys(int key,int x,int y)
{
    
    float linear = 0.1f;
    float angular = float(m3dDegToRad(5.0f));
    
    if (key == GLUT_KEY_UP) {
        
        //MoveForward 平移
        cameraFrame.MoveForward(linear);
    }
    
    if (key == GLUT_KEY_DOWN) {
        cameraFrame.MoveForward(-linear);
    }
    
    if (key == GLUT_KEY_LEFT) {
        //RotateWorld 旋转
        cameraFrame.RotateWorld(angular, 0.0f, 1.0f, 0.0f);
    }
    
    if (key == GLUT_KEY_RIGHT) {
        cameraFrame.RotateWorld(-angular, 0.0f, 1.0f, 0.0f);
    }
    
    
    
}


int main(int argc, char* argv[])
{
    gltSetWorkingDirectory(argv[0]);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    
    glutCreateWindow("OpenGL SphereWorld");
    
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);
    glutSpecialFunc(SpeacialKeys);
    
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
        return 1;
    }
    
    
    SetupRC();
    glutMainLoop();
    ShutdownRC();
    return 0;
}
```



