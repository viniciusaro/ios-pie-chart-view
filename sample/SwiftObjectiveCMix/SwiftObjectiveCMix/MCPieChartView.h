//
//  MCPercentageDoughnutView.h
//  PercentageDoughnutView
//
//  Created by Vinícius Rodrigues on 5/12/2013.
//  Copyright (c) 2013 MyAppControls. All rights reserved.
//

#import "MCCore.h"

@class MCPieChartView;

typedef enum {
    MCPieChartViewTextStyleRealValue,
    MCPieChartViewTextStylePercentage
} MCPieChartViewTextStyle;

@protocol MCPieChartViewDataSource <NSObject>

@required
- (NSInteger)numberOfSlicesInPieChartView:(MCPieChartView*)pieChartView;
- (CGFloat)pieChartView:(MCPieChartView*)pieChartView valueForSliceAtIndex:(NSInteger)index;

@optional
- (UIImage*)pieChartView:(MCPieChartView*)pieChartView imageForSliceAtIndex:(NSInteger)index;
- (UIColor*)pieChartView:(MCPieChartView*)pieChartView colorForSliceAtIndex:(NSInteger)index;
- (UIColor*)pieChartView:(MCPieChartView*)pieChartView colorForTextAtIndex:(NSInteger)index;
- (NSString *)pieChartView:(MCPieChartView*)pieChartView textForSliceAtIndex:(NSInteger)index;

@end

@protocol MCPieChartViewDelegate <NSObject>

@optional
- (void)pieChartView:(MCPieChartView*)pieChartView didSelectSliceAtIndex:(NSInteger)index;

@end

@interface MCPieChartView : MCNewCustomLayeredView

@property (nonatomic, assign) id<MCPieChartViewDataSource>dataSource;
@property (nonatomic, assign) id<MCPieChartViewDelegate>delegate;

@property (strong, nonatomic) UIFont *font;
@property (strong, nonatomic) UIColor *textColor;
@property (strong, nonatomic) UIColor *selectedTextColor;
@property (strong, nonatomic) UIColor *sliceColor;
@property (strong, nonatomic) UIColor *selectedSliceColor;
@property (strong, nonatomic) UIColor *borderColor;

@property (nonatomic) BOOL showText;

//percentage = 0 -> center | = 1 -> border
@property (nonatomic) CGFloat textDistancePercentageFromCenter;

//percentage of the radius that the stroke will occupy
@property (nonatomic) CGFloat borderPercentage;
@property (nonatomic) MCPieChartViewTextStyle textStyle;

@end
