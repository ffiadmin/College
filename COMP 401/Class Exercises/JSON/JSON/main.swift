//
//  main.swift
//  JSON
//
//  Created by Oliver Spryn on 3/19/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import Foundation

println("Hello, World!")

//let str = NSString(contentsOfURL: NSURL(string: "http://api.kivaws.org/v1/loans/newest.json")!, encoding: NSUTF8StringEncoding, error: nil);
//NSLog(str!)

var d = Downloader()
d.run("http://api.kivaws.org/v1/loans/newest.json")