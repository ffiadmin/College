//
//  Team.swift
//  Project 1 Starter - Swift
//
//  Created by Brian Dellinger on 2/3/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import Foundation

class Team {
    let idNum : Int
    let name : String
    let url : String
    let image : String
    
    init(idNum : Int, name: String, url: String, image: String) {
        self.idNum = idNum
        self.name = name
        self.url = url
        self.image = image
    }
    
}