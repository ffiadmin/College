//
//  ViewController.swift
//  First Storyboard
//
//  Created by Oliver Spryn on 2/5/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
    //Red view
        var red: UIView = UIView(frame: CGRectMake(100, 100, 50, 50))
        red.backgroundColor = UIColor.redColor()
        view.addSubview(red)
        
    //Blue view
        var blue: UIView = UIView(frame: CGRectMake(300, 300, 50, 50))
        blue.backgroundColor = UIColor.blueColor()
        view.addSubview(blue)
        
    //Green view
        var green: UIView = UIView(frame: CGRectMake(25, 25, 50, 50))
        green.backgroundColor = UIColor.greenColor()
        red.addSubview(green)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

