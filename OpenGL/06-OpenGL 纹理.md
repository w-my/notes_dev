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

```c
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









