# GLKit

**GLKit** 框架的设计⽬标是为了简化基于 **OpenGL / OpenGL ES** **的应⽤开发 **。它的出现加快 **OpenGL ES**或 **OpenGL** 应⽤程序开发。 使⽤数学库，背景纹理加载，预先创建的着色器效果，以及标准视图和视图控制器来实现渲染循环。

**GLKit** 框架提供了功能和类，可以减少创建新的基于着⾊器的应⽤程序所需的工作量，或者⽀持依赖早期版本的 **OpenGL ES** 或 **OpenGL** 提供的固定函数顶点或⽚段处理的现有应⽤程序。

**GLKView** 提供绘制场所（**View**）

**GLKViewController** （扩展于标准的 **UIKit** 设计模式。用于绘制视图内容的管理与呈现。）

 ```objc
- (void)viewDidLoad {
  [super viewDidLoad];
  // 创建OpenGL ES上下文并将其分配给从故事板加载的视图
  GLKView *view = (GLKView *)self.view;
  view.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
  // 配置视图创建的渲染缓冲区
	view.drawableColorFormat = GLKViewDrawableColorFormatRGBA8888;
	view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
	view.drawableStencilFormat = GLKViewDrawableStencilFormat8;
	// 启⽤用多重采样
	view.drawableMultisample = GLKViewDrawableMultisample4X;
}
 ```

```objc
- (void)drawRect:(CGRect)rect {
	// 清除帧缓冲区
	glClearColor(0.0f，0.0f，0.1f，1.0f); 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// 使⽤用先前配置的纹理理，着⾊色器器和顶点数组绘制 
  glBindTexture(GL_TEXTURE_2D，_planetTexture); 		
  glUseProgram(_diffuseShading); 
  glUniformMatrix4fv(_uniformModelViewProjectionMatrix，1,0，_modelViewProjectionMatrix.m); 
  glBindVertexArrayOES(_planetMesh); 
  glDrawElements(GL_TRIANGLE_STRIP，256，GL_UNSIGNED_SHORT);
}
```

## GLKit 功能

- 加载纹理
- 提供高性能的数学运算
- 提供常见的着色器
- 提供视图以及视图控制器

#### GLKit 纹理加载

**GLKTextureInfo** 创建 **OpenGL** 纹理信息。

- **name**：**OpenGL** 上下文中纹理名称
- **target**：纹理理绑定的⽬目标
- **height**：加载的纹理高度
- **width**：加载纹理的宽度
- **textureOrigin**：加载纹理中的原点位置
- **alphaState**：加载纹理中 **alpha** 分量状态
- **containsMipmaps**：布尔值，加载的纹理是否包含 **mip** 贴图

**GLKTextureLoader** 简化从各种资源文件中加载纹理。

- 从 **URL** 加载纹理
  **- textureWithContentsOfURL:options:error:** 从 **URL** 加载2D纹理图像并从数据创建新纹理；
  **- textureWithContentsOfURL:options:queue:completionHandler:** 从URL异步加载2D纹理图像，并根据数据创建新纹理；

- 从内存中表示创建纹理
  **+ textureWithContentsOfData:options:errer:** 从内存空间加载2D纹理图像，并根据数据创建新纹理；
  **- textureWithContentsOfData:options:queue:completionHandler:** 从内存空间异步加载2D纹理图像，并从数据中创建新纹理；

- 从 **CGImages** 创建纹理
  **- textureWithCGImage:options:error:** 从Quartz图像加载2D纹理图像并从数据创建新纹理；
  **- textureWithCGImage:options:queue:completionHandler:** 从Quartz图像异步加载2D纹理图像，并根据数据创建新纹理；

- 从 **URL** 加载多维创建纹理
  **+ cabeMapWithContentsOfURL:options:errer:** 从单个URL加载⽴方体贴图纹理图像，并根据数据创建新纹理；
	**- cabeMapWithContentsOfURL:options:queue:completionHandler:** 从单个URL异步加载⽴方体贴图纹理图像，并根据数据创建新纹理

- 从文件加载多维数据创建纹理
	**+ cubeMapWithContentsOfFile:options:errer:** 从单个⽂件加载⽴方体贴图纹理对象，并从数据中创建新纹理；
	**- cubeMapWithContentsOfFile:options:queue:completionHandler:** 从单个文件异步加载⽴方体贴图纹理理对象,并从数据中创建新纹理;
	**+ cubeMapWithContentsOfFiles:options:errer:** 从一系列文件中加载⽴方体贴图纹理图像，并从数据总创建新纹理；
	**-  cubeMapWithContentsOfFiles:options:options:queue:completionHandler:** 从一系列⽂件异步加载⽴方体贴图纹理图像，并从数据中创建新纹理；

- **GLKView** 使⽤ **OpenGL ES** 绘制内容的视图默认实现

  **初始化视图**

  ​	**- initWithFrame:context:** 初始化新视图

  **代理**

  ​	**delegate** 视图的代理

  **配置帧缓存区对象**

  ​	**drawableColorFormat** 颜⾊渲染缓存区格式

  ​	**drawableDepthFormat** 深度渲染缓存区格式

  ​	**drawableStencilFormat** 模板渲染缓存区的格式

  ​	**drawableMultisample** 多重采样缓存区的格式

  **帧缓存区属性**

  ​	**drawableHeight** 底层缓存区对象的⾼高度(以像素为单位)

  ​	**drawableWidth** 底层缓存区对象的宽度(以像素为单位)

  **绘制视图的内容**

  ​	**context** 绘制视图内容时使用的 **OpenGL ES** 上下文

  ​	**- bindDrawable** 将底层 **FrameBuffer** 对象绑定到 **OpenGL ES**

  ​	**enableSetNeedsDisplay** 布尔值，指定视图是否响应使得视图内容⽆效的消息

  ​	**- display** 立即重绘视图内容

  ​	**snapshot** 绘制视图内容并将其作为新图像对象返回

  **删除视图 FrameBuffer 对象**

  ​	**- deleteDrawable** 删除与视图关联的可绘制对象

  **绘制视图的内容**

  ​	**- glkView:drawInRect:** 绘制视图内容 (必须实现代理)

- **GLKViewDelegate** 用于 **GLKView** 对象回调⽅法

  **更新**

  ​	**- (void) update** 更新视图内容

  ​	**- (void) glkViewControllerUpdate:**

  **配置帧速率**

  ​	**preferredFramesPerSecond** 视图控制器调⽤视图以及更新视图内容的速率

  ​	**framesPerSencond** 视图控制器调⽤视图以及更新其内容的实际速率

  **配置 GLKViewController 代理**

  ​	**delegate** 视图控制器的代理

- **GLKViewController** 管理 **OpenGL ES** 渲染循环的视图控制器

  **控制帧更新**

  ​	**paused** 布尔值，渲染循环是否已暂停

  ​	**pausedOnWillResignActive** 布尔值，当前程序重新激活动状态时视图控制器是否自动暂停渲染循环

  ​	**resumeOnDidBecomeActive** 布尔值，当前程序变为活动状态时视图控制是否⾃动恢复呈现循环

  **获取有关 View 更新信息**

  ​	**frameDisplayed** 视图控制器自创建以来发送的帧更新数

  ​	**timeSinceFirstResume** 自视图控制器一次恢复发送更新事件以来经过的时间量

  ​	**timeSinceLastResume** 自上次视图控制器恢复发送更新事件以来更新的时间量

  ​	**timeSinceLastUpdate** 自上次视图控制器调用委托⽅法以及经过的时间量

  ​	**glkViewControllerUpdate:**

  ​	**timeSinceLastDraw** 自上次视图控制器调⽤视图 **display** 方法以来经过的时间量

- **GLKViewControllerDelegate** 渲染循环回调方法

  **处理更新事件**

  ​	**- glkViewControllerUpdate:** 在显示每个帧之前调⽤

   **暂停/恢复通知**

  ​	**- glkViewController:willPause:** 在渲染循环暂停或恢复之前调⽤

- **GLKBaseEffect** 一种简单光照/着色系统，用于基于着色器 **OpenGL** 渲染

  **命名 Effect**

  ​	**label** 给 **Effect** (效果) 命名

  **配置模型视图转换**

  ​	**transform** 绑定效果时应⽤于顶点数据的模型视图，投影和纹理变换

  **配置光照效果**

  ​	**lightingType** 用于计算每个⽚段的光照策，**GLKLightingType**

  ​	**GLKLightingType**

  ​		**GLKLightingTypePerVertex** 表示在三⻆形中每个顶点执行光照计算，然后在三角形进行插值；

  ​		**GLKLightingTypePerPixel** 表示光照计算的输入在三角形内插⼊，并且在每个片段执行光照计算

  **配置光照**

  ​	**lightModelTwoSided** 布尔值，表示为基元的两侧计算光照

  ​	**material** 计算渲染图元光照使⽤的材质属性

  ​	**lightModelAmbientColor** 环境颜色，应⽤效果渲染的所有图元

  ​	**light0** 场景中第一个光照属性

  ​	**light1** 场景中第二个光照属性

  ​	**light2** 场景中第三个光照属性	

  **配置纹理理**

  ​	**texture2d0** 第一个纹理属性

  ​	**texture2d1** 第二个纹理属性

  ​	**textureOrder** 纹理应用于渲染图元的顺序

  **配置雾化**

  ​	**fog** 应⽤于场景的雾属性

  **配置颜⾊信息**

  ​	**colorMaterialEnable** 布尔值，表示计算光照与材质交互时是否使⽤颜⾊顶点属性

  ​	**useConstantColor** 布尔值，指示是否使用常量颜⾊

  ​	**constantColor** 不提供每个顶点颜色数据时使用常量颜⾊

  **准备绘制效果**

  ​	**- prepareToDraw** 准备渲染效果

   

## GLKit 基础使用 图片纹理

```objc
#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

@interface ViewController : GLKViewController

@end
```

```objc
#import "ViewController.h"
#import <OpenGLES/ES3/gl.h>
#import <OpenGLES/ES3/glext.h>

@interface ViewController () {
	EAGLContext *context;
	GLKBaseEffect *cEffect;
}
@end

@implementation ViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
	
	// OpenGL ES 相关初始化
	[self setUpConfig];
	
	// 加载顶点/纹理坐标数据
	[self setUpVertexData];
	
	// 加载纹理数据(使用GLBaseEffect)
	[self setUpTexture];
}

#pragma mark -- OpenGL ES setUp

- (void)setUpTexture {
	// 获取纹理图片路径
	NSString *filePath = [[NSBundle mainBundle]pathForResource:@"a" ofType:@"jpg"];
	
	// 设置纹理参数
	// 纹理坐标原点是左下角,但是图片显示原点应该是左上角.
	NSDictionary *options = [NSDictionary dictionaryWithObjectsAndKeys:@(1), GLKTextureLoaderOriginBottomLeft, nil];
	
	GLKTextureInfo *textureInfo = [GLKTextureLoader textureWithContentsOfFile:filePath
																	  options:options error:nil];
	
	// 使用苹果GLKit 提供GLKBaseEffect 完成着色器工作(顶点/片元)
	cEffect = [[GLKBaseEffect alloc] init];
	cEffect.texture2d0.enabled = GL_TRUE;
	cEffect.texture2d0.name = textureInfo.name;
}

- (void)setUpVertexData {
	// 设置顶点数组(顶点坐标,纹理坐标)
	/*
	 纹理坐标系取值范围[0,1];原点是左下角(0,0);
	 故而(0,0)是纹理图像的左下角, 点(1,1)是右上角.
	 */
	GLfloat vertexData[] = {
		0.5, -0.5, 0.0f,    1.0f, 0.0f, // 右下
		0.5, 0.5, -0.0f,    1.0f, 1.0f, // 右上
		-0.5, 0.5, 0.0f,    0.0f, 1.0f, // 左上
		
		0.5, -0.5, 0.0f,    1.0f, 0.0f, // 右下
		-0.5, 0.5, 0.0f,    0.0f, 1.0f, // 左上
		-0.5, -0.5, 0.0f,   0.0f, 0.0f, // 左下
	};
 
	/*
	 顶点数组: 开发者可以选择设定函数指针，在调用绘制方法的时候，直接由内存传入顶点数据，也就是说这部分数据之前是存储在内存当中的，被称为顶点数组
	 顶点缓存区: 性能更高的做法是，提前分配一块显存，将顶点数据预先传入到显存当中。这部分的显存，就被称为顶点缓冲区
	 */
	
	// 开辟顶点缓存区
	// (1).创建顶点缓存区标识符ID
	GLuint bufferID;
	glGenBuffers(1, &bufferID);
	// (2).绑定顶点缓存区.(明确作用)
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	// (3).将顶点数组的数据copy到顶点缓存区中(GPU显存中)
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	
	// 打开读取通道.
	/*
	 (1)在iOS中, 默认情况下，出于性能考虑，所有顶点着色器的属性（Attribute）变量都是关闭的.
	 意味着,顶点数据在着色器端(服务端)是不可用的. 即使你已经使用glBufferData方法,将顶点数据从内存拷贝到顶点缓存区中(GPU显存中).
	 所以, 必须由glEnableVertexAttribArray 方法打开通道.指定访问属性.才能让顶点着色器能够访问到从CPU复制到GPU的数据.
	 注意: 数据在GPU端是否可见，即，着色器能否读取到数据，由是否启用了对应的属性决定，这就是glEnableVertexAttribArray的功能，允许顶点着色器读取GPU（服务器端）数据。
   
	(2)方法简介
	glVertexAttribPointer (GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* ptr)
   
	功能: 上传顶点数据到显存的方法（设置合适的方式从buffer里面读取数据）
	参数列表:
		index,指定要修改的顶点属性的索引值,例如
		size, 每次读取数量。（如position是由3个（x,y,z）组成，而颜色是4个（r,g,b,a）,纹理则是2个.）
		type,指定数组中每个组件的数据类型。可用的符号常量有GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT,GL_UNSIGNED_SHORT, GL_FIXED, 和 GL_FLOAT，初始值为GL_FLOAT。
		normalized,指定当被访问时，固定点数据值是否应该被归一化（GL_TRUE）或者直接转换为固定点值（GL_FALSE）
		stride,指定连续顶点属性之间的偏移量。如果为0，那么顶点属性会被理解为：它们是紧密排列在一起的。初始值为0
		ptr指定一个指针，指向数组中第一个顶点属性的第一个组件。初始值为0
	 */
	
	// 顶点坐标数据
	glEnableVertexAttribArray(GLKVertexAttribPosition);
	glVertexAttribPointer(GLKVertexAttribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (GLfloat *)NULL + 0);
	
	// 纹理坐标数据
	glEnableVertexAttribArray(GLKVertexAttribTexCoord0);
	glVertexAttribPointer(GLKVertexAttribTexCoord0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (GLfloat *)NULL + 3);
 
}

- (void)setUpConfig {
	// 初始化上下文&设置当前上下文
	/*
	 EAGLContext 是苹果iOS平台下实现OpenGLES 渲染层.
	 kEAGLRenderingAPIOpenGLES1 = 1, 固定管线
	 kEAGLRenderingAPIOpenGLES2 = 2,
	 kEAGLRenderingAPIOpenGLES3 = 3,
	 */
	context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
	// 判断context是否创建成功
	if (!context) {
		NSLog(@"Create ES context Failed");
		return;
	}
	// 设置当前上下文
	[EAGLContext setCurrentContext:context];
	
	// 获取GLKView & 设置context
	GLKView *view = (GLKView *)self.view;
	view.context = context;
	
	/* 配置视图创建的渲染缓存区.
	 
	 (1). drawableColorFormat: 颜色缓存区格式.
	 简介:  OpenGL ES 有一个缓存区，它用以存储将在屏幕中显示的颜色。你可以使用其属性来设置缓冲区中的每个像素的颜色格式。
	 
	 GLKViewDrawableColorFormatRGBA8888 = 0,
	 默认.缓存区的每个像素的最小组成部分（RGBA）使用8个bit，（所以每个像素4个字节，4*8个bit）。
	 
	 GLKViewDrawableColorFormatRGB565,
	 如果你的APP允许更小范围的颜色，即可设置这个。会让你的APP消耗更小的资源（内存和处理时间）
	 
	 (2). drawableDepthFormat: 深度缓存区格式
	 
	 GLKViewDrawableDepthFormatNone = 0,意味着完全没有深度缓冲区
	 GLKViewDrawableDepthFormat16,
	 GLKViewDrawableDepthFormat24,
	 如果你要使用这个属性（一般用于3D游戏），你应该选择GLKViewDrawableDepthFormat16
	 或GLKViewDrawableDepthFormat24。这里的差别是使用GLKViewDrawableDepthFormat16
	 将消耗更少的资源
	 
	 */
	
	// 配置视图创建的渲染缓存区.
	view.drawableColorFormat = GLKViewDrawableColorFormatRGBA8888;
	view.drawableDepthFormat = GLKViewDrawableDepthFormat16;
	
	// 设置背景颜色
	glClearColor(1, 0, 0, 1.0);
}

#pragma mark -- GLKViewDelegate
// 绘制视图的内容
/*
 GLKView对象使其OpenGL ES上下文成为当前上下文，并将其framebuffer绑定为OpenGL ES呈现命令的目标。然后，委托方法应该绘制视图的内容。
*/
- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect {
	//
	glClear(GL_COLOR_BUFFER_BIT);
	
	// 准备绘制
	[cEffect prepareToDraw];
	
	// 开始绘制
	glDrawArrays(GL_TRIANGLES, 0, 6);
	
}

- (void)didReceiveMemoryWarning {
	[super didReceiveMemoryWarning];
	// Dispose of any resources that can be recreated.
}

@end
```

