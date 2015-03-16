//
//  MCPercentageDoughnutView.m
//  PercentageDoughnutView
//
//  Created by Vinícius Rodrigues on 5/12/2013.
//  Copyright (c) 2013 MyAppControls. All rights reserved.
//

#import "MCPieChartView.h"
#import "MCNewCustomLayeredView+MCCustomLayeredViewSubclass.h"

#define LINE_PERCENTAGE 1

@interface MCPieChartView() {
    CGFloat sliceValuesSum;
    CGFloat angle;
}

@end

@implementation MCPieChartView

- (void)setDefaults
{
    [super setDefaults];
    
    self.backgroundColor                = [UIColor clearColor];
    self.allowsMultipleSelection        = NO;
    self.showText                       = YES;
    self.font                           = [UIFont systemFontOfSize:20];
    self.textColor                      = [MCUtil iOS7DarkGrayColorForLines];
    self.selectedTextColor              = [UIColor whiteColor];
    self.sliceColor                     = [MCUtil iOS7DefaultGrayColorForBackground];
    self.borderColor                    = [MCUtil iOS7LightGrayColorForLines];
    self.selectedSliceColor             = [MCUtil iOS7DefaultBlueColor];
    self.borderPercentage               = 0.002;
    self.textDistancePercentageFromCenter = 0.6;
}

- (void)willDrawSublayers
{
    sliceValuesSum = 0;
    angle = 0;
    
    for (int i = 0; i < [self.dataSource numberOfSlicesInPieChartView:self]; i++) {
        CGFloat value = fabs([self.dataSource pieChartView:self valueForSliceAtIndex:i]);
        sliceValuesSum += value;
    }
}

- (Class)classForSublayers {
    return [MCSliceLayer class];
}

- (MCNewCustomLayer*)itemForIndex:(NSInteger)index withReuseItem:(MCNewCustomLayer *)reuseItem
{
    CGFloat value       = [self.dataSource pieChartView:self valueForSliceAtIndex:index];
    CGFloat percentage  = (fabs(value)/sliceValuesSum);
    
    // using 360 as the max angle of the circle causes problems with
    // tangent calculations. Because of that, we are using the max angle as 359.99
    CGFloat angleAddition   = D_360*percentage;
    
    MCSliceLayer *slice                     = (MCSliceLayer*)[super itemForIndex:index withReuseItem:reuseItem];
    slice.linePercentage                    = LINE_PERCENTAGE;
    slice.fillColor                         = [self sliceBackgroundColorForSliceAtIndex:index].CGColor;
    slice.strokeColor                       = self.borderColor.CGColor;
    slice.selectedBackgroundColor           = self.selectedSliceColor;
    slice.textLabel.font                    = self.font;
    slice.selectedTextColor                 = self.selectedTextColor;
    slice.startAngle                        = DEG2RAD(angle);
    slice.endAngle                          = DEG2RAD(angle+angleAddition);
    slice.showText                          = self.showText;
    slice.textColor                         = [self textColorForSliceAtIndex:index];
    slice.strokePercentage                  = self.borderPercentage;
    slice.value                             = value;
    slice.textDistancePercentageFromCenter  = self.textDistancePercentageFromCenter;
    
    if ([self.dataSource respondsToSelector:@selector(pieChartView:imageForSliceAtIndex:)]) {
        slice.mainPathImage = [self.dataSource pieChartView:self imageForSliceAtIndex:index];
    }
    
    if ([self.dataSource respondsToSelector:@selector(pieChartView:textForSliceAtIndex:)]) {
        slice.textLabel.text = [self.dataSource pieChartView:self textForSliceAtIndex:index];
    }
    else {
        switch (self.textStyle) {
            case MCPieChartViewTextStyleRealValue:
                slice.textLabel.text = [NSString stringWithFormat:@"%.0f", value];
                break;
            case MCPieChartViewTextStylePercentage:
                slice.textLabel.text = [NSString stringWithFormat:@"%.0f%%", percentage*100];
                break;
        }
    }
    
    angle += angleAddition;

    return slice;
}


- (UIColor*)sliceBackgroundColorForSliceAtIndex:(NSInteger)index
{
    if ([self.dataSource respondsToSelector:@selector(pieChartView:colorForSliceAtIndex:)]) {
        return [self.dataSource pieChartView:self colorForSliceAtIndex:index];
    }
    else if (self.sliceColor) {
        return self.sliceColor;
    }
    else {
        return nil;
    }
}

- (UIColor*)textColorForSliceAtIndex:(NSInteger)index
{
    if ([self.dataSource respondsToSelector:@selector(pieChartView:colorForTextAtIndex:)]) {
        return [self.dataSource pieChartView:self colorForTextAtIndex:index];
    }
    else if (self.textColor) {
        return self.textColor;
    }
    else {
        return nil;
    }
}

#pragma mark Delegate Mapping Methods

- (void)customLayeredView:(MCNewCustomLayeredView *)customLayeredView
  didTouchMainPathOnLayer:(MCNewCustomLayer *)layer {
    
    NSInteger index = [self.containerLayer.sublayers indexOfObject:layer];
    
    if ([self.delegate respondsToSelector:@selector(pieChartView:didSelectSliceAtIndex:)]) {
        [self.delegate pieChartView:self didSelectSliceAtIndex:index];
    }

    if ([layer isKindOfClass:[MCSliceLayer class]]) {
        
        if (!self.allowsMultipleSelection) {
            for (MCSliceLayer *slice in self.containerLayer.sublayers) {
                if (![slice isEqual:layer]) {
                    slice.selectionStatus = MCNewCustomLayerSelectionStatusNotSelected;
                }
            }
        }
        
        MCSliceLayer *slice = (MCSliceLayer*)layer;
        slice.selectionStatus = 1-slice.selectionStatus;
    }
}

#pragma mark Data Source Mapping Methods

- (NSInteger)dataSourceNumberOfItemsInView:(MCNewCustomLayeredView *)view {
    return [self.dataSource numberOfSlicesInPieChartView:self];
}

@end
