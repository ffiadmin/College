//
//  ForecastDay.swift
//  Project2
//
//  Created by Oliver Spryn on 5/4/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ForecastDay: UITableViewCell {
    @IBOutlet weak var Day: UILabel!
    @IBOutlet weak var High: UILabel!
    @IBOutlet weak var Icon: UIImageView!
    @IBOutlet weak var Low: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
    }
    
    override func setSelected(selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)
    }
}