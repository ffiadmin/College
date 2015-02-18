//
//  ChildVC.swift
//  DelegatePractice
//
//  Created by Oliver Spryn on 2/12/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

protocol ChildDelegate {
    func done(child: ChildVC)
}

class ChildVC: UIViewController {
    @IBOutlet weak var Browser: UIWebView!
    var URL: String! = "http://microsoft.com"
    var delegate: ChildDelegate!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = UIColor.grayColor()
        
        var str = NSURL(string: URL)
        var u = NSURLRequest(URL: str!)
        Browser.loadRequest(u)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func Back() {
        delegate.done(self)
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}