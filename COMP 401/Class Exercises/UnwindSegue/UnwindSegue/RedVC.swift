//
//  RedVC.swift
//  UnwindSegue
//
//  Created by Oliver Spryn on 3/10/15.
//  Copyright (c) 2015 Spryn. All rights reserved.
//

import UIKit

class RedVC: UIViewController {
    override func viewDidLoad() {
        super.viewDidLoad()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    @IBAction func backToRed(segue: UIStoryboardSegue) {
        NSLog("Unwound to red")
    }
}