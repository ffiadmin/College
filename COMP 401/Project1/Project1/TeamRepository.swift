//
//  TeamRepository.swift
//  Project 1 Starter - Swift
//
//  Created by Brian Dellinger on 2/3/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import Foundation

class TeamRepository {
    var teams = [Team]()
    
    func loadData() {
        teams.removeAll(keepCapacity: false)
        let json = String(contentsOfFile: NSBundle.mainBundle().pathForResource("teams", ofType: "json")!, encoding: NSUTF8StringEncoding, error: nil)
        
        let jsonData = json?.dataUsingEncoding(NSUTF8StringEncoding, allowLossyConversion: true)
        var error : NSError?
        
        let jsonObj : AnyObject? = NSJSONSerialization.JSONObjectWithData(jsonData!, options: NSJSONReadingOptions.AllowFragments, error: &error)
        
        if let e = error {
            NSLog("Error reading JSON: \(e)")
            return
        }
        
        for dict in (jsonObj as [NSDictionary]) {
            
            let idNum = dict["id"] as Int
            let name = dict["name"] as String
            let url = dict["url"] as String
            let image = dict["image"] as String
            
            let team = Team(idNum: idNum, name: name, url: url, image: image)
            teams.append(team)
        }
    }
}