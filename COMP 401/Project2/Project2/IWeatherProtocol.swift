//
//  IWeatherProtocol.swift
//  Project2
//
//  Created by Oliver Spryn on 5/5/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

protocol IWeatherProtocol {
    var Operations: NSOperationQueue! { get set }
    var ZIP: ZIPData! { get set }
}