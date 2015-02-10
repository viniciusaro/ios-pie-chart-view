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

/*
 Defines the number of slices in the pie chart
 */
- (NSInteger)numberOfSlicesInPieChartView:(MCPieChartView*)pieChartView;

/*
 Defines the value of each slice in the pie chart.
 The control calculates the area of each slice based on the values sum
 */
- (CGFloat)pieChartView:(MCPieChartView*)pieChartView valueForSliceAtIndex:(NSInteger)index;

@optional

/*
 Defines an image for each slice. Pass nil if no image is wanted.
 */
- (UIImage*)pieChartView:(MCPieChartView*)pieChartView imageForSliceAtIndex:(NSInteger)index;

/*
 Defines the color for each slice. If this method is implemented the value set to the
 property sliceColor is ignored.
 */
- (UIColor*)pieChartView:(MCPieChartView*)pieChartView colorForSliceAtIndex:(NSInteger)index;

/*
 Defines the color for the text on each slice. If this method is implemented the value set to the
 property textColor is ignored.
 */
- (UIColor*)pieChartView:(MCPieChartView*)pieChartView colorForTextAtIndex:(NSInteger)index;

/*
 Defines the text for each slice. If this method is not implemented the text shown will be defined 
 by the value of each slice and the property textStyle. If the property showText is set to NO, 
 no text will be shwon.
 */
- (NSString *)pieChartView:(MCPieChartView*)pieChartView textForSliceAtIndex:(NSInteger)index;

@end

@protocol MCPieChartViewDelegate <NSObject>

@optional

/*
 Method called after a slice is selected
 */
- (void)pieChartView:(MCPieChartView*)pieChartView didSelectSliceAtIndex:(NSInteger)index;

@end

@interface MCPieChartView : MCNewCustomLayeredView

/*
 Pie chart data source
 */
@property (nonatomic, assign) id<MCPieChartViewDataSource>dataSource;

/*
 Pie chart delegate
 */
@property (nonatomic, assign) id<MCPieChartViewDelegate>delegate;

/*
 Defines the font of the text on the slices.
 */
@property (strong, nonatomic) UIFont *font;

/*
 Defines the textColor of the text on the slices. If the method
 - (NSString *)pieChartView:(MCPieChartView*)pieChartView textForSliceAtIndex:(NSInteger)index;
 is implemented, the value of this property will not be applied.
 */
@property (strong, nonatomic) UIColor *textColor;

/*
 Defines the textColor of the text on the slices when selected.
 */
@property (strong, nonatomic) UIColor *selectedTextColor;

/*
 Defines the color the slices. If the method
 - (UIColor*)pieChartView:(MCPieChartView*)pieChartView colorForSliceAtIndex:(NSInteger)index;
 is implemented, the value of this property will not be applied.
 */
@property (strong, nonatomic) UIColor *sliceColor;

/*
 Defines the color the slices when selected.
 */
@property (strong, nonatomic) UIColor *selectedSliceColor;

/*
 Defines the color of the border of the slices.
 */
@property (strong, nonatomic) UIColor *borderColor;

/*
 Defines weather the pie chart should display any kind of text on each slice.
 */
@property (nonatomic) BOOL showText;

/*
 Defines the distance from the center should the text on each slice be drawn.
 The default value is 0.6.
 a value equals 0 draws the text on the center of the pie chart
 a value equals 1 draws the text on the border of the pie chart
 */
@property (nonatomic) CGFloat textDistancePercentageFromCenter;

/*
 Defines the percentage of the radius that the border will occupy.
 borderPercentage = 0, no border
 borderPercentage = 1, all the slice area will be occupied by the border
 */
@property (nonatomic) CGFloat borderPercentage;

/*
 Defines how the text should be displayed.
 textStyle = MCPieChartViewTextStyleRealValue automatically sets the text equals to the 
 value of the slice (defined by - (CGFloat)pieChartView:(MCPieChartView*)pieChartView valueForSliceAtIndex:(NSInteger)index;)
 
 textStyle = MCPieChartViewTextStylePercentage automatically sets the text equals to the percentage
 of the area that the slice occupies.
 
 if the method
 - (NSString *)pieChartView:(MCPieChartView*)pieChartView textForSliceAtIndex:(NSInteger)index;
 is defined, the value of this property will not be applied.
 */
@property (nonatomic) MCPieChartViewTextStyle textStyle;

@end
