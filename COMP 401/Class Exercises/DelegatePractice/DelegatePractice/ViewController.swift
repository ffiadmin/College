//
//  ViewController.swift
//  DelegatePractice
//
//  Created by Oliver Spryn on 2/12/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController, ChildDelegate {

    @IBOutlet weak var URLText: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if segue.identifier == "ChildSegue" {
            let child = segue.destinationViewController as ChildVC
            child.URL = URLText.text
            child.delegate = self
        }
    }
    
    func done(child: ChildVC) {
        NSLog("Done!")
        dismissViewControllerAnimated(true, completion: nil)
    }
}