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

###### 载入纹理

```objc

```











