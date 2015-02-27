//
//  ScheduleController.swift
//  Project1
//
//  Created by Oliver Spryn on 2/24/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ScheduleController: UITableViewController {
    var Path = NSIndexPath()
    var Teams:[String] = []

    override func viewDidLoad() {
        super.viewDidLoad()
        
    //Save the names of each team
        let t = TeamRepository()
        t.loadData()
        
        for var i = 0; i < t.teams.count; ++i {
            Teams.append(t.teams[i].name)
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }

    // MARK: - Table view data source

    override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 1
    }

    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Teams.count
    }

    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("ScheduleCell", forIndexPath: indexPath) as UITableViewCell
        cell.textLabel?.text = Teams[indexPath.row]

        return cell
    }
    
    override func tableView(tableView: UITableView, willSelectRowAtIndexPath indexPath: NSIndexPath) -> NSIndexPath? {
        Path = indexPath
        return indexPath
    }

    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        var i = 0
    }
}