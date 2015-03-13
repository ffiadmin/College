//
//  ViewController.swift
//  TImer
//
//  Created by Oliver Spryn on 3/12/15.
//  Copyright (c) 2015 Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var colors = [UIColor.blueColor(), UIColor.brownColor()]
    var selected = 0;
    var timer:NSTimer!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        timer = NSTimer.scheduledTimerWithTimeInterval(1.0, target: self, selector: "flipOut", userInfo: nil, repeats: true)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    func flipOut() {
        view.backgroundColor = colors[selected]
        selected = (selected == 0) ? 1 : 0
    }
    
    @IBAction func killHandler(sender: UIButton) {
        timer.invalidate();
    }
}