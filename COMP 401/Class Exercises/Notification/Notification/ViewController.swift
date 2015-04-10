//
//  ViewController.swift
//  Notification
//
//  Created by Oliver Spryn on 4/7/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var Button: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let center = NSNotificationCenter.defaultCenter()
        center.addObserver(self, selector: "Rotateo:", name: "UIWindowDidRotateNotification", object: nil)
        center.addObserver(self, selector: "Tappio:", name: "ButtonPressed", object: nil)
    }
    
    @IBAction func ButtonPressed(sender: UIButton) {
        let center = NSNotificationCenter.defaultCenter()
        center.postNotificationName("ButtonPressed", object: Button)
    }

    func Rotateo(note: NSNotification) {
        NSLog("Rotated!")
    }
    
    func Tappio(note: NSNotification) {
        NSLog("Button's been pressed!")
    }
    
    override func viewWillDisappear(animated: Bool) {
        super.viewWillDisappear(animated)
        
        let center = NSNotificationCenter.defaultCenter()
        center.removeObserver(self)
    }
}

