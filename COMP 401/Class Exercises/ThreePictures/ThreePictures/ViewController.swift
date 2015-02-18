//
//  ViewController.swift
//  ThreePictures
//
//  Created by Oliver Spryn on 2/10/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var images: [UIImage] = []
    @IBOutlet weak var ImageView: UIImageView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        var first = UIImage(named: "google_logo.jpg")
        var second = UIImage(named: "img_105691_yahoo-logo-large.jpg")
        var third = UIImage(named: "Microsoft-Logo-2012.jpg")
        
        images.append(first!)
        images.append(second!)
        images.append(third!)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func TapHandler(sender: UISegmentedControl) {
        ImageView.image = images[sender.selectedSegmentIndex]
    }

}

