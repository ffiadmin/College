//
//  ViewController.swift
//  Motion
//
//  Created by Oliver Spryn on 4/28/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import CoreLocation
import CoreMotion
import UIKit

class ViewController: UIViewController, CLLocationManagerDelegate {
    @IBOutlet weak var Output: UILabel!
    
    /*
    //Location
    
    var Location: CLLocationManager!
    
    func locationManager(manager: CLLocationManager!, didChangeAuthorizationStatus status: CLAuthorizationStatus) {
        Location.desiredAccuracy = kCLLocationAccuracyBest
        Location.startUpdatingLocation()
    }
    
    func locationManager(manager: CLLocationManager!, didUpdateLocations locations: [AnyObject]!) {
        var data: [CLLocation] = locations as! [CLLocation]
        var first = data[0]
        
        Output.text = "\(first.coordinate.latitude) \(first.coordinate.longitude)"
    }
    
    override func viewDidDisappear(animated: Bool) {
        Location.stopUpdatingLocation()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        Location = CLLocationManager()
        Location.delegate = self
        Location.requestAlwaysAuthorization()
    }*/
    
    var Motion: CMMotionManager!
    
    override func viewDidDisappear(animated: Bool) {
        super.viewDidDisappear(animated)
        Motion.stopDeviceMotionUpdates()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        var ops = NSOperationQueue.mainQueue()
        
        Motion = CMMotionManager()
        Motion.startDeviceMotionUpdates()
        Motion.startAccelerometerUpdatesToQueue(ops, withHandler: {
            (data: CMAccelerometerData!, error: NSError!) in
            
            self.Output.layer.position.x = self.Output.layer.position.x + CGFloat(data.acceleration.x)
            self.Output.layer.position.y = self.Output.layer.position.y - CGFloat(data.acceleration.y)
        })
    }
}