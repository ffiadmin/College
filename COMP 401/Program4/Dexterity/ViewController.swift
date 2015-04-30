//
//  ViewController.swift
//  Dexterity
//
//  Created by Brian Dellinger on 4/9/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UIGestureRecognizerDelegate, RoundOverDelegate {
    var Draggers: [UIPanGestureRecognizer]!
    var numberViews = [UILabel]()
    var score = 0
    var max = 2
    
    @IBOutlet var scoreLabel : UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    //All the gesture recognizers!
        Draggers = [UIPanGestureRecognizer]()
        
    //Listen for round over
        let center = NSNotificationCenter.defaultCenter()
        center.addObserver(self, selector: "RoundOverHandler:", name: "RoundOver", object: nil)
        
    //Trigger round over
        Go()
        
        makeNumberViews()
        makeNumberViews()
    }
    
    func DragLabel(recog: UIPanGestureRecognizer) {
        let shift  = recog.translationInView(view)
        recog.view!.center = CGPoint(x: recog.view!.center.x + shift.x, y: recog.view!.center.y + shift.y)
        recog.setTranslation(CGPoint(x: 0, y: 0), inView: view)
    }
    
    func RoundOverHandler(note: NSNotification) {
        roundOver(note)
    }
    
    func Go() {
        let note = UILocalNotification()
        note.fireDate = NSDate(timeIntervalSinceNow: 5)
        note.alertAction = "Time's up slowpoke!"
        note.alertBody = "Were you too slow???"
        
        UIApplication.sharedApplication().scheduleLocalNotification(note)
    }
    
    // Create and reposition the repositionable views
    func makeNumberViews() {

        for i in 0..<numberViews.count {
            let x = Int(arc4random()) % (Int(view.frame.width) - 30)
            let y = (Int(arc4random()) % (Int(view.frame.height) - 60)) + 30
            
            numberViews[i].frame = CGRect(x: x, y: y, width: 30, height: 30)
        }
        
        let x = Int(arc4random()) % Int(view.frame.width)
        let y = Int(arc4random()) % Int(view.frame.height)

        var next = UILabel(frame: CGRect(x: x, y: y, width: 30, height: 30))
        next.text = "\(numberViews.count + 1)"
        next.userInteractionEnabled = true
        next.backgroundColor = UIColor.blueColor()
        next.textColor = UIColor.whiteColor()
        next.textAlignment = NSTextAlignment.Center
        view.addSubview(next)
        
        var drag = UIPanGestureRecognizer(target: self, action: "DragLabel:")
        drag.delegate = self
        next.addGestureRecognizer(drag)
        Draggers.append(drag)
        
        numberViews.append(next)
    }
    
    
    // Should be called when the NSNotification fires
    func roundOver(note: NSNotification) {
        var valid = true
        for i in 0..<(numberViews.count - 1) {
            if numberViews[i].frame.minY >= numberViews[i+1].frame.minY{
                valid = false
            }
        }
        
        if valid == true {
            let storyboard = UIStoryboard(name: "Main", bundle: nil)
            let vc = storyboard.instantiateViewControllerWithIdentifier("RoundOverVC") as! RoundOverVC
            vc.delegate = self
            vc.message = "Victory! Round \(numberViews.count)!"
            self.presentViewController(vc, animated: false, completion: nil)
        } else {
            let storyboard = UIStoryboard(name: "Main", bundle: nil)
            let vc = storyboard.instantiateViewControllerWithIdentifier("RoundOverVC") as! RoundOverVC
            vc.message = "Game over! You scored \(score) points!"
            vc.delegate = self
            vc.victory = false
            self.presentViewController(vc, animated: false, completion: nil)
        }
    }
    
    // Set a new round to go when the old one ends
    // TODO: Schedule necessary NSNotification; set up round for another go
    func victory(sender: RoundOverVC) {
        sender.dismissViewControllerAnimated(false, completion: nil)
        Go()
        
    //Update the score
        score += max++
        scoreLabel.text = "Score: \(score)"
        
    //Relocate the labels
        var v: UIView!
        var x = Int(arc4random()) % Int(view.frame.width)
        var y = Int(arc4random()) % Int(view.frame.height)
        
        for var i = 0; i < view.subviews.count; ++i {
            v = view.subviews[i] as! UIView
            v.frame = CGRect(x: x, y: y, width: 30, height: 30)
            
            x = Int(arc4random()) % Int(view.frame.width)
            y = Int(arc4random()) % Int(view.frame.height)
        }
        
        makeNumberViews()
    }
    
    
    // Dismiss all view controllers (except the original) in case of defeat
    // TODO: Handle high scores as needed.
    func defeat(sender: RoundOverVC) {
        sender.dismissViewControllerAnimated(false, completion: nil)
        self.dismissViewControllerAnimated(true, completion: nil)
        
        DocumentFileIO.add(score)
    }
    
    deinit {
        let center = NSNotificationCenter.defaultCenter()
        center.removeObserver(self)
    }
}

