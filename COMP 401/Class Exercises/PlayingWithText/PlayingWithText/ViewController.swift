//
//  ViewController.swift
//  PlayingWithText
//
//  Created by Oliver Spryn on 2/12/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var TextField: UITextField!
    
    @IBAction func DismissHandler(sender: UIButton) {
        if !TextField.isFirstResponder() {
            TextField.becomeFirstResponder()
        }
    }
    
    @IBAction func ResignHandler(sender: UIControl) {
        if TextField.isFirstResponder() {
            TextField.resignFirstResponder()
        }
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

