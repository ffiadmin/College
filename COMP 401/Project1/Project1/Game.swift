//
//  Game.swift
//  Project 1 Starter - Swift
//
//  Created by Brian Dellinger on 2/3/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import Foundation

class Game {
    let home : Int
    let away : Int
    let date : NSDate
    let location : Location
    
    init(home : Int, away : Int, date : NSDate, location : Location) {
        self.home = home
        self.away = away
        self.date = date
        self.location = location
    }
}