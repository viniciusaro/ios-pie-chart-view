//
//  ViewController.swift
//  SwiftObjectiveCMix
//
//  Created by Vinícius Rodrigues on 15/03/2015.
//  Copyright (c) 2015 MyAppControls. All rights reserved.
//

import UIKit

class ViewController: UIViewController, MCPieChartViewDataSource {

    @IBOutlet weak var pieChart: MCPieChartView!
    var values: [CGFloat] = [20, 20, 30, 70]
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        pieChart.dataSource = self;
        pieChart.selectItemAtIndex(0);
        pieChart.borderPercentage = pieChart.borderPercentage*2;
    }

    func numberOfSlicesInPieChartView(pieChartView: MCPieChartView!) -> Int {
        return values.count;
    }
    
    func pieChartView(pieChartView: MCPieChartView!, valueForSliceAtIndex index: Int) -> CGFloat {
        return values[index];
    }
}

