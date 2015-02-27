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

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    @IBAction func RefreshHandler(sender: UIBarButtonItem) {
        Offset()
    }
    
    func Offset() {
    //Get the date offset
        let now = NSDate()
        let offset = NSCalendar.currentCalendar().components(
            .CalendarUnitSecond | .CalendarUnitMinute | .CalendarUnitHour |
            .CalendarUnitDay | .CalendarUnitMonth | .CalendarUnitYear,
            fromDate: now,
            toDate: First,
            options: nil
        )
        
    //Set the label
        var value = ""
        
        value = "\(offset.year) year"
        if offset.year != 1 { value += "s" }
        
        value += " \(offset.month) month"
        if offset.month != 1 { value += "s" }
        
        value += " \(offset.day) day"
        if offset.day != 1 { value += "s" }
        
        value += " \(offset.hour) hour"
        if offset.hour != 1 { value += "s" }
        
        value += " \(offset.minute) minute"
        if offset.minute != 1 { value += "s" }
        
        value += " \(offset.second) second"
        if offset.second != 1 { value += "s" }
        
        Indicator.text = value
    }
}