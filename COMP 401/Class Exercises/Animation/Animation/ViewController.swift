//
//  ViewController.swift
//  Animation
//
//  Created by Oliver Spryn on 3/17/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var s:UIView!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        s = UIView(frame: CGRectMake(100, 0, 200, 400))
        s.backgroundColor = UIColor.redColor()
        view.addSubview(s)
    }
    
    override func viewDidAppear(animated: Bool) {
        UIView.animateWithDuration(3.0, animations: {
            self.s.backgroundColor = UIColor.blueColor()
            
            var p = self.s.center
            p.y += 200
            self.s.center = p
        })
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

