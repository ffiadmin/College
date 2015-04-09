//
//  HomeController.swift
//  Project2
//
//  Created by Oliver Spryn on 4/2/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import MapKit
import UIKit

class HomeController: UIViewController {
    @IBOutlet weak var Map: MKMapView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let blur = UIBlurEffect(style: UIBlurEffectStyle.Light)
        let effect = UIVisualEffectView(effect: blur)
        effect.frame = view.frame
        Map.addSubview(effect)
    }
}