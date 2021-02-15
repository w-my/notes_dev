# OpenGL Demo - 地板小球绕大球公转

```objc
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


GLShaderManager 	shaderManager;		// 着色器管理器
GLMatrixStack 		modelViewMatrix;	// 模型视图矩阵
GLMatrixStack		projectionMatrix;	// 投影矩阵
GLFrustum			viewFrustum;		// 视景体
GLGeometryTransform transformPipeline; 	// 几何图形变换管道

GLBatch				floorBatch; // 地板
GLTriangleBatch		torusBatch; // 大球
GLTriangleBatch		sphereBatch; // 小球

// 角色帧 照相机角色帧
GLFrame             cameraFrame;
//GLFrame  			objectFrame;

// 添加附加随机球
#define NUM_SPHERES 50
GLFrame spheres[NUM_SPHERES];

void SetupRC() {
	// 初始化
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	shaderManager.InitializeStockShaders();
	
//	objectFrame.MoveForward(5.0f);
	
	// 开启深度测试
	glEnable(GL_DEPTH_TEST);
	
	// 设置地板顶点数据
	floorBatch.Begin(GL_LINES, 324);
	for(GLfloat x = -20.0; x <= 20.0f; x+= 0.5) {
		floorBatch.Vertex3f(x, -0.55f, 20.0f);
		floorBatch.Vertex3f(x, -0.55f, -20.0f);
		
		floorBatch.Vertex3f(20.0f, -0.55f, x);
		floorBatch.Vertex3f(-20.0f, -0.55f, x);
	}
	floorBatch.End();
	
	// 设置大球模型
	gltMakeSphere(torusBatch, 0.4f, 40, 80);
	
	// 设置小球模型
	gltMakeSphere(sphereBatch, 0.1f, 26, 13);
	
	// 随机位置放置小球
	for (int i = 0; i < NUM_SPHERES; i++) {
		GLfloat x = ((GLfloat)((rand() % 400) - 200) * 0.1f);
		GLfloat z = ((GLfloat)((rand() % 400) - 200) * 0.1f);
		// 在y方向，将球体设置为0.0的位置，这使得它们看起来是漂浮在眼睛的高度
		// 对spheres数组中的每一个顶点，设置顶点数据
		spheres[i].SetOrigin(x, 0.0f, z);
	}
}

void RenderScene() {
	static GLfloat vFloorColor[] = { 0.0f, 0.5f, 0.0f, 1.0f };
	static GLfloat vTorusColor[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	static GLfloat vSphereColor[] = { 0.0f, 0.0f, 1.0f, 1.0f };
	
	static CStopWatch rotTimer;
	float yRot = rotTimer.GetElapsedSeconds() * 60.0f;
	
	// 清除颜色缓冲区和深度缓冲区
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// 加入观察者
	M3DMatrix44f mCamera;
	cameraFrame.GetCameraMatrix(mCamera);
	modelViewMatrix.PushMatrix(mCamera);
//	modelViewMatrix.PushMatrix(objectFrame);
	
	// 绘制地板
	shaderManager.UseStockShader(GLT_SHADER_FLAT,
								 transformPipeline.GetModelViewProjectionMatrix(),
								 vFloorColor);
	floorBatch.Draw();
	
	// 获取光源位置
	M3DVector4f vLightPos = { 0.0f, 10.0f, 5.0f, 1.0f };
	
	// 使大球位置平移（3.0）向屏幕里
	modelViewMatrix.Translate(0.0f, 0.0f, -3.0f);
	// 压栈（复制栈顶）
	modelViewMatrix.PushMatrix();
	// 大球自转
	modelViewMatrix.Rotate(yRot, 0.0f, 1.0f, 0.0f);
	// 指定合适的着色器（电光源着色器）
	shaderManager.UseStockShader(GLT_SHADER_POINT_LIGHT_DIFF,
								 transformPipeline.GetModelViewMatrix(),
								 transformPipeline.GetProjectionMatrix(),
								 vLightPos,
								 vTorusColor);
	torusBatch.Draw();
	// 绘制完毕则Pop
	modelViewMatrix.PopMatrix();
	
	// 画小球
	for (int i = 0; i < NUM_SPHERES; i++) {
		modelViewMatrix.PushMatrix();
		modelViewMatrix.MultMatrix(spheres[i]);
		shaderManager.UseStockShader(GLT_SHADER_POINT_LIGHT_DIFF,
									 transformPipeline.GetModelViewMatrix(),
									 transformPipeline.GetProjectionMatrix(),
									 vLightPos, vSphereColor);
		sphereBatch.Draw();
		modelViewMatrix.PopMatrix();
	}
	
	// 让一个小篮球围绕大球公转自转
	modelViewMatrix.Rotate(yRot * -2.0f, 0.0f, 1.0f, 0.0f);
	modelViewMatrix.Translate(0.8f, 0.0f, 0.0f);
	shaderManager.UseStockShader(GLT_SHADER_FLAT,
								 transformPipeline.GetModelViewProjectionMatrix(),
								 vSphereColor);
	sphereBatch.Draw();
	modelViewMatrix.PopMatrix();
	
	// 执行缓存区交换
	glutSwapBuffers();
	
	glutPostRedisplay();
}

void ChangeSize(int w, int h) {
	glViewport(0, 0, w, h);
	
	// 创建投影矩阵
	viewFrustum.SetPerspective(35.0f, float(w)/float(h), 1.0f, 100.0f);
	// viewFrustum.GetProjectionMatrix()  获取viewFrustum投影矩阵
	// 并将它载入到投影矩阵堆栈中
	projectionMatrix.LoadMatrix(viewFrustum.GetProjectionMatrix());
	
	// 设置变换管线以使用两个矩阵堆栈（变换矩阵modelViewMatrix ，投影矩阵projectionMatrix）
	// 初始化GLGeometryTransform 的实例transformPipeline.通过将它的内部指针设置为模型视图矩阵堆栈 和 投影矩阵堆栈实例，来完成初始化
	// 当然这个操作也可以在SetupRC 函数中完成，但是在窗口大小改变时或者窗口创建时设置它们并没有坏处。而且这样可以一次性完成矩阵和管线的设置。
	transformPipeline.SetMatrixStacks(modelViewMatrix, projectionMatrix);
}

void SpeacialKeys(int key,int x,int y){
	// 移动步长
	float linear = 0.1f;
	// 旋转度数
	float angular = float(m3dDegToRad(5.0f));
	
	if (key == GLUT_KEY_UP) {
		// MoveForward 平移
		cameraFrame.MoveForward(linear);
//		objectFrame.MoveForward(linear);
	}
	if (key == GLUT_KEY_DOWN) {
		cameraFrame.MoveForward(-linear);
//		objectFrame.MoveForward(-linear);
	}
	if (key == GLUT_KEY_LEFT) {
		// RotateWorld 旋转
		cameraFrame.RotateWorld(angular, 0.0f, 1.0f, 0.0f);
//		objectFrame.RotateWorld(angular, 0.0f, 1.0f, 0.0f);
	}
	if (key == GLUT_KEY_RIGHT) {
		cameraFrame.RotateWorld(-angular, 0.0f, 1.0f, 0.0f);
//		objectFrame.RotateWorld(-angular, 0.0f, 1.0f, 0.0f);
	}
}

int main(int argc, char *argv[]) {
	
	gltSetWorkingDirectory(argv[0]);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Geometry Test Program");
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
	
	return 0;
}
```

