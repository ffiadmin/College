//
//  ScheduleCell.swift
//  Project1
//
//  Created by Oliver Spryn on 2/24/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ScheduleCell: UITableViewCell {
    @IBOutlet weak var FlagAway: UIImageView!
    @IBOutlet weak var FlagHome: UIImageView!
    @IBOutlet weak var LabelAway: UILabel!
    @IBOutlet weak var LabelHome: UILabel!
    @IBOutlet weak var LabelTime: UILabel!
    
    var ImageAway:String!
    var ImageHome:String!
    var TextAway:String!
    var TextHome:String!
    var Time:String!
    
    func apply() {
        FlagAway.image = UIImage(named: ImageAway)
        FlagHome.image = UIImage(named: ImageHome)
        
        LabelAway.text = TextAway
        LabelHome.text = TextHome
        LabelTime.text = Time
    }
}