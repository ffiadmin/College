//
//  RoundOverVC.swift
//  Dexterity
//
//  Created by Brian Dellinger on 4/11/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import UIKit

// NO CHANGES NEEDED IN THIS FILE
protocol RoundOverDelegate {
    func victory(sender: RoundOverVC)
    func defeat(sender: RoundOverVC)
}

class RoundOverVC: UIViewController {
    
    var delegate : RoundOverDelegate!
    var victory = true
    var message = ""

    @IBOutlet var textField : UILabel!
    
    @IBAction func doneTap() {
        if victory {
            delegate.victory(self)
        } else
        {
            delegate.defeat(self)
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        
        textField.text = message
        
    }
}
