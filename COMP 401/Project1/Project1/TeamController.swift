//
//  TeamController.swift
//  Project1
//
//  Created by Oliver Spryn on 3/13/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class TeamController: UITableViewController {
    var Flags:[String] = []
    var Path = NSIndexPath()
    var Teams:[String] = []
    var URLs:[String] = []
    
    override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 1
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        var dest = segue.destinationViewController as WebController
        dest.Title = Teams[Path.row]
        dest.URL = URLs[Path.row]
    }
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> TeamCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("TeamCell", forIndexPath: indexPath) as TeamCell
        cell.Image = Flags[indexPath.row]
        cell.Text = Teams[indexPath.row]
        cell.apply()
        
        return cell
    }
    
    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Teams.count
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
        
    //Sort the teams
        t.teams.sort({ $0.name < $1.name })
        
        for var i = 0; i < t.teams.count; ++i {
            Flags.append(t.teams[i].image)
            Teams.append(t.teams[i].name)
            URLs.append(t.teams[i].url)
        }
    }
}