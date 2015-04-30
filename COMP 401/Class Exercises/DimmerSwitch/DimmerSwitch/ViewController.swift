//
//  ViewController.swift
//  DimmerSwitch
//
//  Created by Oliver Spryn on 4/23/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var Color: UIColor = UIColor(white: 1, alpha: 0)
    var Dec = 0.01
    var White = 1.0

    override func viewDidLoad() {
        super.viewDidLoad()
    }

    override func touchesBegan(touches: Set<NSObject>, withEvent event: UIEvent) {
        
    }
    
    override func touchesMoved(touches: Set<NSObject>, withEvent event: UIEvent) {
        White -= Dec;
        view.backgroundColor = UIColor(white: CGFloat(White), alpha: 1)
    }
    
    override func touchesEnded(touches: Set<NSObject>, withEvent event: UIEvent) {
        White = 1.0;
        view.backgroundColor = UIColor(white: CGFloat(White), alpha: 1)
    }
}