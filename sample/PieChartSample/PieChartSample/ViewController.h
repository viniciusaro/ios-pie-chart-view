//
//  ViewController.h
//  PieChartSample
//
//  Created by Vinícius Rodrigues on 26/06/2014.
//  Copyright (c) 2014 MyAppControls. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MCPieChartView.h"

@interface ViewController : UIViewController <MCPieChartViewDataSource, MCPieChartViewDelegate>

@property (strong, nonatomic) IBOutlet MCPieChartView *pieChartView;

@end
