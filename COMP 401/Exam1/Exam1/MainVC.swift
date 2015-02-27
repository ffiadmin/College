//
//  MainVC.swift
//  Exam1
//
//  Created by Oliver Spryn on 2/24/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class MainVC: UIViewController, IDismiss {
    @IBOutlet weak var MainLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        var child = segue.destinationViewController as UpdateVC
        child.DellingerDelegate = self
    }
    
    func Done(controller: UpdateVC, append: Bool) {
        if append {
            var existing = MainLabel.text!
            existing += controller.TextField.text
            
            MainLabel.text = existing
        } else {
            MainLabel.text = controller.TextField.text
        }
        
        dismissViewControllerAnimated(true, completion: nil)
    }
}