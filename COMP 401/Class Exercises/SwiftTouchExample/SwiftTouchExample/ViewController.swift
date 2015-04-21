//
//  ViewController.swift
//  SwiftTouchExample
//
//  Created by Brian Dellinger on 4/9/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet var imageview : UIImageView!
    @IBOutlet var segControl: UISegmentedControl!
    
    @IBAction func reset() {
        imageview.transform = CGAffineTransformIdentity
    }
    
    @IBAction func scale() {
        if multiplier() == 1 {
            imageview.transform = CGAffineTransformScale(imageview.transform, 1.1, 1.1)
        } else {
            imageview.transform = CGAffineTransformScale(imageview.transform, 0.9, 0.9)
        }
    }
    
    @IBAction func translate() {
        imageview.transform = CGAffineTransformTranslate(imageview.transform, CGFloat(5 * multiplier()), CGFloat(0))
    }
    
    @IBAction func rotate() {
        imageview.transform = CGAffineTransformRotate(imageview.transform, CGFloat(45.0 * (M_PI / 180.0)) * multiplier())
    }
    
    func multiplier() -> CGFloat {
        return segControl.selectedSegmentIndex == 0 ? 1 : -1
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        imageview.image = UIImage(named: "Avengers.jpg")
    }
}