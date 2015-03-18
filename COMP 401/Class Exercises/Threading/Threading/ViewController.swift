//
//  ViewController.swift
//  Threading
//
//  Created by Oliver Spryn on 3/17/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBAction func Tap(sender: UIButton) {
        var queue = NSOperationQueue.mainQueue()
        queue.addOperationWithBlock({
            NSLog("Tapped the button!")
        })
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

