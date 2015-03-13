//
//  ScheduleDetailController.swift
//  Project1
//
//  Created by Oliver Spryn on 2/24/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import MapKit
import UIKit

class ScheduleDetailController: UIViewController {
    var Latitude:Double!
    var Longitude:Double!
    @IBOutlet weak var Map: MKMapView!
    var Tooltip:String!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        let loc = CLLocationCoordinate2D(latitude: Latitude, longitude: Longitude)
        let span = MKCoordinateSpanMake(1, 1)
        let region = MKCoordinateRegionMake(loc, span)
        Map.setRegion(region, animated: false)
        
        var pin = MKPointAnnotation()
        pin.coordinate = loc
        pin.title = Tooltip
        Map.addAnnotation(pin)
    }
}