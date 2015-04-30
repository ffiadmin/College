//
//  ViewController.swift
//  Gestures
//
//  Created by Oliver Spryn on 4/23/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UIGestureRecognizerDelegate {
    var Index = 0;
    @IBOutlet var IView: UIImageView!
    let images = [UIImage(named: "Black-Horse.jpg"), UIImage(named: "horse-1179-1920x1200.jpg")]

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        IView.image = images[Index]
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func HandleTap(recog: UITapGestureRecognizer) {
        Index = (++Index) % 2
        IView.image = images[Index]
    }
    
    @IBAction func HandlePan(recog: UIPanGestureRecognizer) {
        let shift  = recog.translationInView(view)
        recog.view!.center = CGPoint(x: recog.view!.center.x + shift.x, y: recog.view!.center.y + shift.y)
        recog.setTranslation(CGPoint(x: 0, y: 0), inView: view)
    }
    
    @IBAction func HandlePinch(recog: UIPinchGestureRecognizer) {
        recog.view!.transform = CGAffineTransformScale(recog.view!.transform, recog.scale, recog.scale)
        recog.scale = 1
    }
}

