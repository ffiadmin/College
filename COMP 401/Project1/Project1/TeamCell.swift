//
//  TeamCellTableViewCell.swift
//  Project1
//
//  Created by Oliver Spryn on 3/13/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class TeamCell: UITableViewCell {
    @IBOutlet weak var Flag: UIImageView!
    var Image:String!
    @IBOutlet weak var Label: UILabel!
    var Text:String!
    
    func apply() {
        Flag.image = UIImage(named: Image)
        Label.text = Text
    }
}