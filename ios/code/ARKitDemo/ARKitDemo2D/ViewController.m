//
//  ViewController.m
//  ARKitDemo2D
//
//  Created by WTW on 2020/2/16.
//  Copyright © 2020 WTW. All rights reserved.
//

/*
 SceneKit  3D 引擎
 SpriteKit 2D 引擎
 */

#import "ViewController.h"
#import "Scene.h"

@interface ViewController () <ARSKViewDelegate>

// ARSKView是ARKit框架中负责展示2D AR的预览视图
@property (nonatomic, strong) IBOutlet ARSKView *sceneView;

@end


@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Set the view's delegate
    // 设置场景视图代理
    self.sceneView.delegate = self;
    
    // Show statistics such as fps and node count
    // 显示帧率
    self.sceneView.showsFPS = YES;
    // 显示界面节点 (游戏中一个角色对应一个节点)
    self.sceneView.showsNodeCount = YES;
    
    // Load the SKScene from 'Scene.sks'
    // 加载 2D 场景
    Scene *scene = (Scene *)[SKScene nodeWithFileNamed:@"Scene"];
    
    // Present the scene
    // AR 预览视图展现场景 (这点和3D 视图加载有区别)
    [self.sceneView presentScene:scene];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    // Create a session configuration
    // //创建设备追踪设置
    ARWorldTrackingConfiguration *configuration = [ARWorldTrackingConfiguration new];

    // Run the view's session
    // 开始启动 AR
    [self.sceneView.session runWithConfiguration:configuration];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    // Pause the view's session
    [self.sceneView.session pause];
}

#pragma mark - ARSKViewDelegate

//点击界面会调用，类似于touch begin方法  anchor是2D坐标的瞄点
- (SKNode *)view:(ARSKView *)view nodeForAnchor:(ARAnchor *)anchor {
    // Create and configure a node for the anchor added to the view's session.
    // 创建节点（节点可以理解为AR将要展示的2D图像）
    // 2D ARKit支持加载emoji表情符号图片
    SKLabelNode *labelNode = [SKLabelNode labelNodeWithText:@"👽"];
    //显示在屏幕中心
    labelNode.horizontalAlignmentMode = SKLabelHorizontalAlignmentModeCenter;
    labelNode.verticalAlignmentMode = SKLabelVerticalAlignmentModeCenter;
    return labelNode;
}

- (void)session:(ARSession *)session didFailWithError:(NSError *)error {
    // Present an error message to the user
    
}

- (void)sessionWasInterrupted:(ARSession *)session {
    // Inform the user that the session has been interrupted, for example, by presenting an overlay
    
}

- (void)sessionInterruptionEnded:(ARSession *)session {
    // Reset tracking and/or remove existing anchors if consistent tracking is required
    
}

@end
