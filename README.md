# iOS Pie Chart View
The iOS Pie Chart is a great tool to present information in the form of a pie chart. The default appearance conforms to the iOS 7 flat design It has built in animation features for presenting, inserting, deleting and updating actions and it is fully customisable, accepting color changes, text and font customisation. All through properties attributes and delegate methods. The content is managed by a data source object following the built in Apple controls standards. 

Demo video: https://www.youtube.com/watch?v=J5TSjRZNefU

More info at: http://myappcontrols.binpress.com/product/ios-pie-chart/2119

![alt tag](http://myappcontrols.binpress.com/images/stores/store30934/piechart10.png)

## Installation

Add all files from the src folder to your project
Import as usual: #import "MCPieChartView.h"
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
CGRect frame = CGRectMake(x, y, width, height); MCPieChartView *pieChart = [[MCPieChartView alloc] initWithFrame:frame]; [self.view addSubview:pieChart];
```

## Documentation

Most of the properties are mnemonic and pretty straightforward to be used. Custom types can be easily explored on the interface files provided. 

**Main properties and methods**
```
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


**Other properties and methods**

/*
 Defines the duration of the animations.
 */
@property (nonatomic) NSTimeInterval animationDuration;

/*
 Defines weather the animations are enabled.
 */
@property (nonatomic) BOOL animationEnabled;

/*
 Defines the view should animate when is first drawn
 */
@property (nonatomic) BOOL animatesBegining;

//-------------------
/*
 Controlers that contain labels that can show numbers automatically (like the value of an item)
 can use this property to set the number of decimal places shown.
 */
@property (nonatomic) NSInteger decimalPlaces;

/*
 Defines weather multiple items can be selected at once.
 */
@property (nonatomic) BOOL allowsMultipleSelection;

/*
 Defines the bounds of the images shown at each item.
 MCNewCustomLayeredViewImageBoundsFullRect = the image will be drawn with the size of the controler's bouds and cliped to the bounds of the item
 MCNewCustomLayeredViewImageBoundsItemRect = the image will be drawn with the size of the item
 */
@property (nonatomic) MCNewCustomLayerImageBoundsStyle imageBoundsStyle;


// animation propertyes
@property (strong, nonatomic, readonly) NSMutableArray *layerCopies;
@property (nonatomic, readonly) BOOL firstDraw;


// custom layer management methods
/*
 Selects the item at the specified index
 */
- (void)selectItemAtIndex:(NSUInteger)index;

/*
 Deselects the item at the specified index
 */
- (void)deselectItemAtIndex:(NSUInteger)index;

/*
 Deselects all items
 */
- (void)deselectAllItems;


// drawing methods
/*
 Causes the control to redraw it self, calling all the data source methods
 to apply the new data.
 */
- (void)reloadData;

/*
 Animates the control
 */
- (void)animate;
```
