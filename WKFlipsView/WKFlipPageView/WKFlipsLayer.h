//
//  WKFlipsLayer.h
//  WKFlipsView
//
//  Created by 秦 道平 on 13-12-13.
//  Copyright (c) 2013年 秦 道平. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import <CoreText/CoreText.h>
#import "WK.h"
#pragma makr - WKFlipsLayerView
///翻页的状态
typedef enum WKFlipsLayerViewRunState:NSUInteger{
   ///禁止
    WKFlipsLayerViewRunStateStop=0,
    ///拖动翻页中
    WKFlipsLayerViewRunStateDragging=1,
    ///翻页动画中
    WKFlipsLayerViewRunStateAnimation=2,
}WKFlipsLayerViewRunState;
typedef enum WKFlipsLayerDragAtPosition:NSUInteger{
    ///拖动上面的
    WKFlipsLayerDragAtPositionTop=0,
    ///拖动底部的
    WKFlipsLayerDragAtPositionBottom=1,
}WKFlipsLayerDragAtPosition;
@class WKFlipsLayer;
@class WKFlipsView;
///用来放那些WKFlipsLayer
@interface _WKFlipsLayerView:UIView{
    ///正在被拖动的页面
    WKFlipsLayer* _dragging_layer;
    ///正在被拖动的页面的位置，上面的，还是下面的
    WKFlipsLayerDragAtPosition _dragging_position;
}
///使用flipsView
-(id)initWithFlipsView:(WKFlipsView*)flipsView;
///翻页的状态
@property (nonatomic,assign) WKFlipsLayerViewRunState runState;
///引用flipsView
@property (nonatomic,assign) WKFlipsView* flipsView;
///重建所有页面
-(void)buildLayers;
#pragma mark - FlipAnimation
-(void)flipToPageIndex:(int)pageIndex;
-(void)flipToPageIndex:(int)pageIndex completion:(void(^)(BOOL completed))completionBlock;
#pragma mark - Drag
///开始拖动
-(void)dragBegan;
///拖动结束
-(void)dragEnded;
///正在拖动
-(void)draggingWithTranslation:(CGPoint)translation;
@end
#pragma mark - WKFlipsLayer
@interface WKFlipsLayer : CATransformLayer{
    CGFloat _rotateDegree;
}

@property (nonatomic,retain) CALayer* frontLayer;
@property (nonatomic,retain) CALayer* backLayer;
-(id)initWithFrame:(CGRect)frame;
@property (nonatomic,assign) CGFloat rotateDegree;
///动画设置翻转角度
-(void)setRotateDegree:(CGFloat)rotateDegree duration:(CGFloat)duration afterDelay:(NSTimeInterval)delay completion:(void(^)())completion;
///画出来测试用的文字
-(void)drawWords:(NSString*)words onPosition:(int)position;
@end
