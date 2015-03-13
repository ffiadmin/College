//
//  ScheduleController.swift
//  Project1
//
//  Created by Oliver Spryn on 2/24/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ScheduleController: UITableViewController {
    var Flags:[String] = []
    var Games:[Game] = []
    var Path = NSIndexPath()
    var Teams:[String] = []

    override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 1
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        var dest = segue.destinationViewController as ScheduleDetailController
        dest.Latitude = Games[Path.row].location.latitude
        dest.Longitude = Games[Path.row].location.longitude
        dest.Tooltip = Games[Path.row].location.name
    }
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> ScheduleCell {
        let format = NSDateFormatter()
        format.dateFormat = "MM-dd-yyyy"
        
        let cell = tableView.dequeueReusableCellWithIdentifier("ScheduleCell", forIndexPath: indexPath) as ScheduleCell
        cell.ImageAway = Flags[Games[indexPath.row].away]
        cell.ImageHome = Flags[Games[indexPath.row].home]
        cell.TextAway = Teams[Games[indexPath.row].away]
        cell.TextHome = Teams[Games[indexPath.row].home]
        cell.Time = format.stringFromDate(Games[indexPath.row].date)
        cell.apply()
        
        return cell
    }

    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Games.count
    }
    
    override func tableView(tableView: UITableView, willSelectRowAtIndexPath indexPath: NSIndexPath) -> NSIndexPath? {
        Path = indexPath
        return indexPath
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    //Save the names of each team
        let t = TeamRepository()
        t.loadData()
        
        for var i = 0; i < t.teams.count; ++i {
            Flags.append(t.teams[i].image)
            Teams.append(t.teams[i].name)
        }
        
    //Save the games array
        let g = GameRepository()
        g.loadData()
        
        Games = sorted(g.games, {
            (this: Game, that: Game) -> Bool in
            return this.date.compare(that.date) == .OrderedAscending
        })
    }
}