//
//  Clock.swift
//  Program3
//
//  Created by Oliver Spryn on 3/23/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class Clock: UIViewController {
    let Anchor = CGPointMake(0.0, 1.0)
    var Backface:CALayer!
    var ClockCenter:CGPoint!
    var Loc:CGRect!
    var MainLayer:CALayer!
    
    var Hour:CALayer!
    var Minute:CALayer!
    var Second:CALayer!
    
    func UpdateTime() {
    //Get the time
        let now = NSDate()
        let cal = NSCalendar.currentCalendar()
        let components = cal.components(.CalendarUnitSecond | .CalendarUnitMinute | .CalendarUnitHour, fromDate: now)
        let hour = components.hour
        let minute = components.minute
        let second = components.second
        
    //Rotate the seconds
        var rot = CGFloat((CGFloat(second) * (360.0 / 60.0))) * CGFloat((M_PI / 180.0))
        Second.setAffineTransform(CGAffineTransformMakeRotation(rot))
        
    //And... the minutes
        rot = CGFloat(((CGFloat(minute) + 1 * (CGFloat(second) / 60.0)) * (360.0 / 60.0))) * CGFloat((M_PI / 180.0))
        Minute.setAffineTransform(CGAffineTransformMakeRotation(rot))
        
    //And... the hours
        rot = CGFloat(((CGFloat(hour) + 1 * (CGFloat(minute) / 60.0)) * (360.0 / 12.0))) * CGFloat((M_PI / 180.0))
        Hour.setAffineTransform(CGAffineTransformMakeRotation(rot))
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        
    //Place the clock
        let screenWidth = UIScreen.mainScreen().bounds.width
        Loc = CGRectMake((screenWidth / 2) - (100 / 2), 100, 100, 100)

    //Save some info
        let ctx = UIGraphicsGetCurrentContext()
        ClockCenter = CGPointMake(Loc.origin.x + Loc.width / 2.0, Loc.origin.y + 9)
        MainLayer = self.view.layer
        
    //Create the background of the clock
        Backface = CALayer()
        var v =  ClockBackface(frame: Loc)
        view.addSubview(v)
        
    //Create the hands
        Hour = CALayer()
        Hour.anchorPoint = Anchor
        Hour.backgroundColor = UIColor.blackColor().CGColor
        Hour.frame = CGRectMake(ClockCenter.x, ClockCenter.y + 7, 1.0, Loc.height / 3.0)
        MainLayer.addSublayer(Hour)
        
        Minute = CALayer()
        Minute.anchorPoint = Anchor
        Minute.backgroundColor = UIColor.blackColor().CGColor
        Minute.frame = CGRectMake(ClockCenter.x, ClockCenter.y, 1.0, Loc.height / 2.5)
        MainLayer.addSublayer(Minute)
        
        Second = CALayer()
        Second.anchorPoint = Anchor
        Second.backgroundColor = UIColor.redColor().CGColor
        Second.frame = CGRectMake(ClockCenter.x, ClockCenter.y, 1.0, Loc.height / 2.5)
        MainLayer.addSublayer(Second)
        
    //Create a timer
        NSTimer.scheduledTimerWithTimeInterval(1.0, target: self, selector: "UpdateTime", userInfo: nil, repeats: true)
        UpdateTime()
    }
}