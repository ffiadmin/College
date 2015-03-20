//
//  ViewController.swift
//  OperationQueuePractice
//
//  Created by Brian Dellinger on 3/12/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var Mutex:Bool = true
    @IBOutlet var imageView : UIImageView!
    @IBOutlet var indicator : UIActivityIndicatorView!
    var Loaded = 0
    var q: NSOperationQueue!
    
    var images  = [UIImage]()
    
    let imagePaths = ["http://imgsrc.hubblesite.org/hu/db/images/hs-2010-13-a-2048x1280_wallpaper.jpg",
        "http://imgsrc.hubblesite.org/hu/db/images/hs-2011-25-a-large_web.jpg",
        "http://imgsrc.hubblesite.org/hu/db/images/hs-2002-15-a-2048x1280_wallpaper.jpg",
        "http://imgsrc.hubblesite.org/hu/db/images/hs-2006-17-b-xlarge_web.jpg",
        "http://imgsrc.hubblesite.org/hu/db/images/hs-2006-01-a-2560x1024_wallpaper.jpg",
        "http://imgsrc.hubblesite.org/hu/db/images/hs-2003-28-a-2560x1024_wallpaper.jpg"]
        

    @IBAction func tap() {
        imageView.stopAnimating()
        Loaded = 0
        images.removeAll(keepCapacity: true)
        q.cancelAllOperations()
        
        
        for urlString in imagePaths {
            var op = Loader(url: urlString)
            
            op.completionBlock = {
                NSOperationQueue.mainQueue().addOperationWithBlock({
                    while(true) {
                        if(self.Mutex) {
                            self.Mutex = false
                            self.images.append(op.Img!)
                            ++self.Loaded
                            
                            if self.Loaded == self.imagePaths.count {
                                self.updateAnimationImages()
                            }
                            
                            self.Mutex = true
                            
                            break
                        } else {
                            //Try again
                        }
                    }
                })
            }
            
            q.addOperation(op)
        }
    }
    
    func updateAnimationImages() {
        indicator.stopAnimating()
        imageView.animationImages = self.images
        imageView.animationDuration = 4
        imageView.animationRepeatCount = 0
        imageView.startAnimating()
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        q = NSOperationQueue()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

