//
//  ViewController.swift
//  iOS JSON
//
//  Created by Oliver Spryn on 3/24/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        var d = Downloader()
        d.run("http://api.kivaws.org/v1/loans/newest.json")
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

