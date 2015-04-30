//
//  DocumentIO.swift
//  Dexterity
//
//  Created by Oliver Spryn on 4/28/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import UIKit

class DocumentFileIO: NSObject {
    class func read() -> [Int] {
        let fm = NSFileManager.defaultManager()
        let lib = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true)[0] as! NSString
        let path = lib.stringByAppendingPathComponent("highscores.txt")
        NSLog(path)
        
        if fm.isReadableFileAtPath(path) {
            let text = NSString(contentsOfFile: path, encoding: NSUTF8StringEncoding, error: nil)
            let data = String(text!)
            let array = data.componentsSeparatedByString(",")
            var out:[Int] = []
            
            for var i = 0; i < array.count; ++i {
                out.append(array[i].toInt()!)
            }
            
            return out
        }
        
        return []
    }
    
    class func add(contents: Int) {
        var read = DocumentFileIO.read()
        read.append(contents)
        DocumentFileIO.write(read)
    }
    
    class func write(contents: [Int]) {
        let fm = NSFileManager.defaultManager()
        let lib = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true)[0] as! NSString
        let path = lib.stringByAppendingPathComponent("highscores.txt")
        NSLog(path)
        
        var sorted = contents.sorted(>)
        var count = (5 < contents.count) ? 5 : contents.count
        var limited: [String] = []
        
        for var i = 0; i < count; ++i {
            limited.append(String(sorted[i]))
        }
        
        var joiner = ","
        var all = joiner.join(limited) as NSString
        
        fm.removeItemAtPath(path, error: nil)
        fm.createFileAtPath(path, contents: all.dataUsingEncoding(NSUTF8StringEncoding), attributes: nil)
    }
}