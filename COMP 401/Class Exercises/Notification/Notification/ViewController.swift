//
//  ViewController.swift
//  Notification
//
//  Created by Oliver Spryn on 4/7/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let center = NSNotificationCenter.defaultCenter()
        center.addObserver(self, selector: "Listener:", name: nil, object: nil)
    }

    func Listener(note: NSNotification) {
        println(note.name)
    }
    
    override func viewWillDisappear(animated: Bool) {
        super.viewWillDisappear(animated)
        
        let center = NSNotificationCenter.defaultCenter()
        center.removeObserver(self)
    }
}

