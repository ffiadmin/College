//
//  Downloader.swift
//  JSON
//
//  Created by Oliver Spryn on 3/24/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import Foundation

class Downloader: NSObject, NSURLSessionDownloadDelegate {
    func run(u: String) {
        let URL = NSURL(string: u)
        let config = NSURLSessionConfiguration.defaultSessionConfiguration()
        let session = NSURLSession(configuration: config, delegate: self, delegateQueue: nil)
        let dtask = session.downloadTaskWithURL(URL!)
        dtask.resume()
    }
    
    func done() {
        NSLog("We are done! (From the *main* thread, of course)")
    }
    
    func URLSession(session: NSURLSession, downloadTask: NSURLSessionDownloadTask, didFinishDownloadingToURL location: NSURL) {
        NSOperationQueue.mainQueue().addOperationWithBlock({
            let text = NSString(contentsOfURL: location, encoding: NSUTF8StringEncoding, error: nil)
            self.done()
        })
    }
    
    func URLSession(session: NSURLSession, downloadTask: NSURLSessionDownloadTask, didResumeAtOffset fileOffset: Int64, expectedTotalBytes: Int64) {
        
    }
    
    func URLSession(session: NSURLSession, downloadTask: NSURLSessionDownloadTask, didWriteData bytesWritten: Int64, totalBytesWritten: Int64, totalBytesExpectedToWrite: Int64) {
        NSLog("Bytes written: \(bytesWritten)")
    }
}