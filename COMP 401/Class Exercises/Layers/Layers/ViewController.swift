//
//  ViewController.swift
//  Layers
//
//  Created by Oliver Spryn on 3/12/15.
//  Copyright (c) 2015 Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var rot:Double = 0.0
    var sub:CALayer!
    var timer:NSTimer!
    
    override func viewDidLoad() {
        super.viewDidLoad()
       
        var mainLayer = view.layer
        sub = CALayer()
        sub.anchorPoint = CGPoint(x: 0, y: 0)
        sub.backgroundColor = UIColor.redColor().CGColor
        sub.frame = CGRectMake(100, 200, 200, 50)
        
        mainLayer.addSublayer(sub)
        NSTimer.scheduledTimerWithTimeInterval(0.1, target: self, selector: "moveio", userInfo: nil, repeats: true)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    func moveio() {
        rot += 1.0
        sub.position.y += 1.0
        sub.setAffineTransform(CGAffineTransformMakeRotation(CGFloat(rot)))
    }
}