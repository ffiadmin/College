//
//  Cell.swift
//  TableView
//
//  Created by Oliver Spryn on 2/26/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class Cell: UITableViewCell {
    @IBOutlet weak var EventLabel: UILabel!
    @IBOutlet weak var DetailLabel: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
