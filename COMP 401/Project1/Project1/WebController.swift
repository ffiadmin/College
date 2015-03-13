//
//  WebController.swift
//  Project1
//
//  Created by Oliver Spryn on 3/13/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class WebController: UIViewController {
    var Title:String!
    var URL:String!
    @IBOutlet weak var Web: UIWebView!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        navigationItem.title = Title
        Web.loadRequest(NSURLRequest(URL: NSURL(string: URL)!))
    }
}