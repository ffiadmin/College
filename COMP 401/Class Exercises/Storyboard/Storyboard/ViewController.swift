//
//  ViewController.swift
//  Storyboard
//
//  Created by Oliver Spryn on 2/10/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var on = true
    
    @IBOutlet weak var Label: UILabel!
    @IBOutlet weak var Button: UIButton!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func TapHandler(sender: UIButton) {
        if(!on) {
            Label.textColor = UIColor.blackColor()
            Label.text = "Flashlight On"
            view.backgroundColor = UIColor.whiteColor()
            on = true
        } else {
            Label.textColor = UIColor.whiteColor()
            Label.text = "Flashlight Off"
            view.backgroundColor = UIColor.blackColor()
            on = false
        }
    }

}

