//
//  DocumentFileIO.swift
//  Project2
//
//  Created by Oliver Spryn on 4/15/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class DocumentFileIO: NSObject {
    class func read(name: String) -> String {
        let fm = NSFileManager.defaultManager()
        let lib = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true)[0] as! NSString
        let path = lib.stringByAppendingPathComponent(name)
        NSLog(path)
        
        if fm.isReadableFileAtPath(path) {
            let text = NSString(contentsOfFile: path, encoding: NSUTF8StringEncoding, error: nil)
            return String(text!)
        }
        
        return ""
    }
    
    class func path(name: String) -> String {
        let fm = NSFileManager.defaultManager()
        let lib = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true)[0] as! NSString
        let path = lib.stringByAppendingPathComponent(name)
        NSLog(path)
        
        if fm.isReadableFileAtPath(path) {
            return path
        } else {
            return ""
        }
    }
    
    class func write(name: String, contents: NSData) {
        let fm = NSFileManager.defaultManager()
        let lib = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true)[0] as! NSString
        let path = lib.stringByAppendingPathComponent(name)
        NSLog(path)
        
        fm.createFileAtPath(path, contents: contents, attributes: nil)
    }
}