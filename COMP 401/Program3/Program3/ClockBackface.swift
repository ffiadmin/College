//
//  Backface.swift
//  Program3
//
//  Created by Oliver Spryn on 3/23/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ClockBackface: UIView {
    let Stroke:CGFloat = CGFloat(2.5)
    
    override func drawRect(rect: CGRect) {
        let center = CGPointMake(frame.size.height / 2.0, frame.size.width / 2.0)
        let fillColor:UIColor = UIColor.whiteColor()
        let radius = center.y - Stroke / 2.0
        let strokeColor:UIColor = UIColor.blackColor()
        
    //Draw the backface
        let ctx = UIGraphicsGetCurrentContext()
        CGContextAddArc(ctx, center.x, center.y, radius, 0.0, CGFloat(2.0 * M_PI), 1)
        CGContextSetFillColorWithColor(ctx, fillColor.CGColor)
        CGContextSetStrokeColorWithColor(ctx, strokeColor.CGColor)
        CGContextSetLineWidth(ctx, Stroke)
        CGContextStrokePath(ctx)
        
    //Draw the clock hands anchor
        CGContextAddArc(ctx, center.x, center.y, 1, 0, CGFloat(2.0 * M_PI), 1)
        CGContextSetLineWidth(ctx, Stroke)
        CGContextStrokePath(ctx)
        
    //Now the hour ticks
        drawHourTicks()
    }
    
    func drawHourTicks() {
        let length:CGFloat = CGFloat(10)
        let width:CGFloat = CGFloat(1)
        
        let center = CGPointMake(CGFloat((frame.size.width + 2.0 * Stroke) / 2.0), CGFloat((frame.size.height - 2.0 * Stroke) / 2.0))
        let radius = frame.size.width / 2.0
        let regPoint = CGPointMake(0, radius / length)
        var l:CALayer!
        var rot:CGFloat!
        
        for var i = 0; i < 12; ++i {
            l = CALayer()
            rot = CGFloat((CGFloat(i) * (360.0 / 12.0))) * CGFloat((M_PI / 180.0))
            
            l.anchorPoint = regPoint
            l.backgroundColor = UIColor.blackColor().CGColor
            l.frame = CGRectMake(center.x - Stroke, 0, width, length)
            l.setAffineTransform(CGAffineTransformMakeRotation(rot))
            
            layer.addSublayer(l)
        }
    }
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        self.backgroundColor = UIColor.clearColor()
    }

    required init(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}