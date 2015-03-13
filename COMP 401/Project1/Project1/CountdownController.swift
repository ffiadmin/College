//
//  CountdownController.swift
//  Project1
//
//  Created by Oliver Spryn on 2/22/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class CountdownController: UIViewController {
    var First:NSDate!
    @IBOutlet weak var Indicator: UILabel!
    
    func Offset() {
    //Get the date offset
        let now = NSDate()
        let offset = NSCalendar.currentCalendar().components(
            .CalendarUnitSecond | .CalendarUnitMinute | .CalendarUnitHour |
            .CalendarUnitDay,
            fromDate: now,
            toDate: First,
            options: nil
        )
        
    //Set the label
        var value = ""
        
        value += "Day"
        if offset.day != 1 { value += "s" }
        value += ": \(offset.day) "
        
        value += "Hour"
        if offset.hour != 1 { value += "s" }
        value += ": \(offset.hour) "
        
        value += "Minute"
        if offset.day != 1 { value += "s" }
        value += ": \(offset.minute) "
        
        value += "Second"
        if offset.day != 1 { value += "s" }
        value += ": \(offset.second)"
        
        Indicator.text = value
    }
    
    @IBAction func RefreshHandler(sender: UIBarButtonItem) {
        Offset()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    //Get the first game from the repository
        let g = GameRepository()
        g.loadData()
        
        let games = sorted(g.games, {
            (this: Game, that: Game) -> Bool in
            return this.date.compare(that.date) == .OrderedAscending
        })
        
    //Save the first game's date
        First = games[0].date
        
    //Fire off the countdown!!!
        Offset()
    }
}