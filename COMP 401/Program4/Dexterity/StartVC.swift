//
//  StartVC.swift
//  Dexterity
//
//  Created by Brian Dellinger on 4/11/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import UIKit

class StartVC: UIViewController {
    @IBOutlet weak var Scores: UITextView!

    /*
    // Only override drawRect: if you perform custom drawing.
    // An empty implementation adversely affects performance during animation.
    override func drawRect(rect: CGRect) {
        // Drawing code
    }
    */
    
    //TODO: Add any needed code for handling high scores
    override func viewDidLoad() {
        super.viewDidLoad()
        
    }
    
    override func viewDidAppear(animated: Bool) {
        var text = "High Scores\n"
        let scores = DocumentFileIO.read()
        
        for var i = 0; i < scores.count; ++i {
            text += "\(scores[i])\n"
        }
        
        Scores.text = text
    }
}