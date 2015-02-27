//
//  GameRepository.swift
//  Project 1 Starter - Swift
//
//  Created by Brian Dellinger on 2/3/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import Foundation

class GameRepository {
    var games = [Game]()
    
    func loadData() {
        games.removeAll(keepCapacity: false)
        let json = String(contentsOfFile: NSBundle.mainBundle().pathForResource("games", ofType: "json")!, encoding: NSUTF8StringEncoding, error: nil)
        
        let jsonData = json?.dataUsingEncoding(NSUTF8StringEncoding, allowLossyConversion: true)
        var error : NSError?
        
        let jsonObj : AnyObject? = NSJSONSerialization.JSONObjectWithData(jsonData!, options: NSJSONReadingOptions.AllowFragments, error: &error)
        
        if let e = error {
            NSLog("Error reading JSON: \(e)")
            return
        }
        
        var formatter = NSDateFormatter()
        formatter.dateFormat = "MM-dd-yyyy"
        
        for dict in (jsonObj as [NSDictionary]) {
            
            let home = dict["home"] as Int
            let away = dict["away"] as Int
            let date : NSDate = formatter.dateFromString(dict["date"] as String)!
            let location = dict["location"] as NSDictionary
            let name = location["name"]! as String
            let latitude = location["latitude"] as NSString
            let longitude = location["longitude"] as NSString
            
            let loc : Location = Location(name: name, latitude: latitude.doubleValue, longitude: longitude.doubleValue)
            
            var game  = Game(home: home, away: away, date: date, location: loc)
            
            games.append(game)
        }
    }
}