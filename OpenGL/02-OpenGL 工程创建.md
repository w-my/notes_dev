# OpenGL工程创建

1. 创建一个 `macOS` `Command Line Tool` 项目，语言选择 `C++`。

   或 创建删除原项目入口文件。如：AppDelegate、ViewController、main 文件，创建 main.cpp 文件。

   > main.cpp 文件的创建：创建一个 C++ File，命名为 `main` ，取消 `Also create a header file` 的勾选。

2. 引入系统资源库 `OpenGL.framework` `GLUT.framework` 

3. 下载 libGLTools 并解压到本地，然后直接拖入到工程，并配置 `Header Search path` 和 `Library Search Paths` 。 下载 libGLTools 的地址:

   https://pan.baidu.com/s/1IFWuDG_SGJnt0He-alSiPg 提取码：qbwh

   https://github.com/GhostClock/OpenGL/blob/master/source/libGLTools.zip

4. 在 `main.cpp` 文件中写入测试代码（M1芯片mac 需要选择 Rosetta运行）

## 渲染一个三角形

```c++
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
#include <glut/glut.h> // OpenGL Utility Toolkit
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

// 简单的批次容器，是GLTools的一个简单的容器类。
GLBatch batch;
// 声明一个着色器管理器实例
GLShaderManager shaderManager;


/// 供 GLUT 库在窗口维度改变时调用
/// @param w 窗口宽
/// @param h 窗口高
void changeSize(int w, int h) {
    // x,y 参数代表窗口中视图的左下角坐标
    glViewport(0, 0, w, h);
}

/// 设置渲染环境（Rendering Context）
void etupRC() {
    // 设置清屏颜色（背景颜色）
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    
    // 没有着色器，在 OpenGL 核心框架中是无法进行任何渲染的。初始化一个渲染管理器。
    shaderManager.InitializeStockShaders();
    
    // 指定顶点
    // 在OpenGL中，三角形是一种基本的3D图元绘图原素。
    GLfloat vVerts[] = {
        -0.5f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
    
    batch.Begin(GL_TRIANGLES, 3);
    batch.CopyVertexData3f(vVerts);
    batch.End();
}

void display(void) {
    /** 清除一个或者一组特定的缓存区
     * 缓冲区是一块存储图像信息的储存空间，红色、绿色、蓝色和 alpha 通常一起作为颜色缓存区或像素缓存区引用。
     * GL_COLOR_BUFFER_BIT 颜色缓存区：指示当前激活的用来进行颜色写入缓冲区
     * GL_DEPTH_BUFFER_BIT 深度缓存区：指示深度缓存区
     * GL_STENCIL_BUFFER_BIT 模板缓存区：指示模板缓冲区
     */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    // 设置一组浮点数来表示红色
    GLfloat vRed[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    // 传递到存储着色器，即 GLT_SHADER_IDENTITY 着色器，这个着色器只是使用指定颜色以默认笛卡尔坐标系在屏幕上渲染几何图形
    shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
    // 将几何图形提交到着色器
    batch.Draw();
    
    glutSwapBuffers();
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
    glutInitWindowSize(800, 600);
    glutCreateWindow("Triangle");
    // 注册重塑函数
    glutReshapeFunc(changeSize);
    // 注册显示函数
    glutDisplayFunc(display);
    /**
     * 初始化一个 GLEW 库,确保 OpenGL API 对程序完全可用；
     * 在试图做任何渲染之前，要检查确定驱动程序的初始化过程中没有任何问题；
     */
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
    }
    
    // 设置渲染环境（Rendering Context）
    setupRC();
    
    // 在开始设置OpenGL窗口的时候，我们指定要一个双缓冲区的渲染环境。这就意味着将在后台缓冲区进行渲染，渲染结束后交换给前台。这种方式可以防止观察者看到可能伴随着动画帧与动画帧之间的闪烁的渲染过程。缓冲区交换平台将以平台特定的方式进行。
    // 将后台缓冲区进行渲染，然后结束后交换给前台
    glutMainLoop();
    
    return 0;
}
```



