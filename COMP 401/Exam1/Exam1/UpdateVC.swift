//
//  UpdateVC.swift
//  Exam1
//
//  Created by Oliver Spryn on 2/24/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class UpdateVC: UIViewController {
    var DellingerDelegate: MainVC!
    @IBOutlet weak var TextField: UITextField!

    override func viewDidLoad() {
        super.viewDidLoad()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    @IBAction func AppendHandler(sender: UIButton) {
        DellingerDelegate.Done(self, append: true)
        
        if TextField.isFirstResponder() {
            TextField.resignFirstResponder()
        }
    }
    
    @IBAction func DismissHandler(sender: UIControl) {
        if TextField.isFirstResponder() {
            TextField.resignFirstResponder()
        }
    }
    
    @IBAction func ReplaceHandler(sender: UIButton) {
        DellingerDelegate.Done(self, append: false)
        
        if TextField.isFirstResponder() {
            TextField.resignFirstResponder()
        }
    }
}