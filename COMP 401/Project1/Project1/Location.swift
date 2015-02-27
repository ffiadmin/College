//
//  Location.swift
//  Project 1 Starter - Swift
//
//  Created by Brian Dellinger on 2/3/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import Foundation

class Location {
    let name : String
    let latitude : Double
    let longitude : Double
    
    init(name: String, latitude: Double, longitude: Double) {
        self.name = name
        self.latitude = latitude
        self.longitude = longitude
    }
}