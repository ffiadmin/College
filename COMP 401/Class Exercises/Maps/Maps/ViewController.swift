//
//  ViewController.swift
//  Maps
//
//  Created by Oliver Spryn on 3/10/15.
//  Copyright (c) 2015 Spryn. All rights reserved.
//

import MapKit
import UIKit

class ViewController: UIViewController {
    
    @IBOutlet var map: MKMapView!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let loc = CLLocationCoordinate2D(latitude: 41.155, longitude: -80.084)
        let span = MKCoordinateSpanMake(1, 1)
        let region = MKCoordinateRegionMake(loc, span)
        
        map.setRegion(region, animated: false)
        
        var pin = MKPointAnnotation()
        pin.coordinate = loc
        pin.title = "Look over here!"
        
        map.addAnnotation(pin)
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

