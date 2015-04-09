//
//  ViewController.swift
//  Bundles
//
//  Created by Oliver Spryn on 3/31/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let fm = NSFileManager.defaultManager()
        let path = NSBundle.mainBundle().pathForResource("Source", ofType: "rtf")
        
        if fm.isReadableFileAtPath(path!) {
            let text = NSString(contentsOfFile: path!, encoding: NSUTF8StringEncoding, error: nil)
            let data = fm.contentsAtPath(path!)
            
            let lib = NSSearchPathForDirectoriesInDomains(.LibraryDirectory, .UserDomainMask, true)[0] as NSString
            let path = lib.stringByAppendingPathComponent("Destination.rtf")
            
            fm.createFileAtPath(path, contents: data, attributes: nil)
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

