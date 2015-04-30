//
//  ViewController.swift
//  Motion
//
//  Created by Oliver Spryn on 4/28/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import CoreLocation
import UIKit

class ViewController: UIViewController, CLLocationManagerDelegate {
    var Location: CLLocationManager!
    @IBOutlet weak var Output: UILabel!
    
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
    }
}