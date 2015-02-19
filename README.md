# iOS Pie Chart View
The iOS Pie Chart is a great tool to present information in the form of a pie chart. The default appearance conforms to the iOS 7 flat design It has built in animation features for presenting, inserting, deleting and updating actions and it is fully customisable, accepting color changes, text and font customisation. All through properties attributes and delegate methods. The content is managed by a data source object following the built in Apple controls standards. 

Demo video: https://www.youtube.com/watch?v=J5TSjRZNefU

More info at: http://myappcontrols.binpress.com/product/ios-pie-chart/2119

![alt tag](http://myappcontrols.binpress.com/images/stores/store30934/piechart10.png)
 
## Installation
 
 Add all files from the src folder to your project
-Import as usual: #import "MCPieChartView.h"
+Import as usual: #import "MCColorPicker.h"
 Add QuartzCore.framework to your project
 
## Setup
 
MCPieChartView can be added to your view either from the Interface Builder or through code.
 
#### Interface Builder (Xcode 5):
 
 * Open the Storyboard or Xib file you want to add the pie chart to.
 * Drag a new UIView from the Object Library into your view controller.
 * Resize and position your new UIView as you wish (the pie chart will be drawn on the center of the new UIView).
 * Make sure the new UIView is selected and choose the Identity Inspector tab on Xcode's the Utilities view (on the right).
 * Change the class from UIView to MCPieChartView.
 * On the view controller's header file create an IBOutlet property of the type MCPieChartView and link it to the object you created on the Interface Builder.

#### Through Code:

```
CGRect frame = CGRectMake(x, y, width, height); 
MCPieChartView *pieChart = [[MCPieChartView alloc] initWithFrame:frame]; 
[self.view addSubview:pieChart];
```

## Example Usage
```
self.pieChartView.dataSource = self;
self.pieChartView.delegate = self;
self.pieChartView.animationDuration = 0.5;
self.pieChartView.sliceColor = [MCUtil flatWetAsphaltColor];
self.pieChartView.borderColor = [MCUtil flatSunFlowerColor];
self.pieChartView.selectedSliceColor = [MCUtil flatSunFlowerColor];
self.pieChartView.textColor = [MCUtil flatSunFlowerColor];
self.pieChartView.selectedTextColor = [MCUtil flatWetAsphaltColor];
self.pieChartView.borderPercentage = 0.01;
```

## Credits
Brought to you by [MyAppControls](http://www.binpress.com/profile/myappcontrols/30934) team.
