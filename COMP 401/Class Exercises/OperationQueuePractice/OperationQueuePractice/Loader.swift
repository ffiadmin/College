//
//  Loader.swift
//  OperationQueuePractice
//
//  Created by Oliver Spryn on 3/17/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import UIKit

class Loader: NSOperation {
    var Img:UIImage!
    var URL:String!
    
    init(url:String) {
        URL = url
    }
    
    override func main() {
        let url = NSURL(string: URL)
        let data = NSData(contentsOfURL: url!)
        Img = UIImage(data: data!)
    }
}
