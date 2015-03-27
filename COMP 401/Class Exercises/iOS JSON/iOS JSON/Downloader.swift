//
//  Downloader.swift
//  iOS JSON
//
//  Created by Oliver Spryn on 3/24/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class Downloader: NSObject, NSURLSessionDownloadDelegate {
    func run(u: String) {
        let URL = NSURL(string: u)
        let config = NSURLSessionConfiguration.defaultSessionConfiguration()
        let session = NSURLSession(configuration: config, delegate: self, delegateQueue: nil)
        let dtask = session.downloadTaskWithURL(URL!)
        dtask.resume()
    }
    
    func done(text: String) {
        NSLog("We are done! (From the *main-ish* thread, of course)")
        NSLog(text)
    }
    
    func URLSession(session: NSURLSession, downloadTask: NSURLSessionDownloadTask, didFinishDownloadingToURL location: NSURL) {
        //NSOperationQueue.mainQueue().addOperationWithBlock({
            //let text = NSString(contentsOfURL: location, encoding: NSUTF8StringEncoding, error: nil)
            //self.done(text!)
        //})
        
        var ld: Array<Loan> = Array<Loan>()
        var data = NSData(contentsOfURL: location)
        var JSON = NSJSONSerialization.JSONObjectWithData(data!, options: NSJSONReadingOptions.MutableContainers, error: nil) as Dictionary<String, AnyObject>
        var loans = JSON["loans"] as Array<Dictionary<String, AnyObject>>
        
        for loan in loans {
            var l = Loan()
            
            for (key, value) in loan {
                if key != "description" && l.respondsToSelector(Selector(key as String)) {
                    l.setValue(value, forKey: key)
                }
            }
            
            ld.append(l)
        }
        
        for l in ld {
            NSLog("\(l)")
        }
    }
    
    func URLSession(session: NSURLSession, downloadTask: NSURLSessionDownloadTask, didResumeAtOffset fileOffset: Int64, expectedTotalBytes: Int64) {
        
    }
    
    func URLSession(session: NSURLSession, downloadTask: NSURLSessionDownloadTask, didWriteData bytesWritten: Int64, totalBytesWritten: Int64, totalBytesExpectedToWrite: Int64) {
        NSLog("Bytes written: \(bytesWritten)")
    }
}