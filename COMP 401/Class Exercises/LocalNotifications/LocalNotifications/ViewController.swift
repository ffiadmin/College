//
//  ViewController.swift
//  LocalNotifications
//
//  Created by Oliver Spryn on 4/9/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var TextField: UITextField!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func Done(sender: UIButton) {
        let note = UILocalNotification()
        note.fireDate = NSDate(timeIntervalSinceNow: 10)
        note.alertAction = "Whoot whoot"
        note.alertBody = TextField.text
        
        UIApplication.sharedApplication().scheduleLocalNotification(note)
        TextField.resignFirstResponder()
    }

}

