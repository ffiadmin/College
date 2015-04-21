//
//  ForecastControllerViewController.swift
//  Project2
//
//  Created by Oliver Spryn on 4/15/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ForecastController: UIViewController, UITableViewDelegate {
    @IBOutlet weak var Conditions: UILabel!
    var Delegate: ZIPData!
    var Load: FetchWeather!
    var Observed = false
    var Operations: NSOperationQueue!
    @IBOutlet weak var Summary: UILabel!
    @IBOutlet weak var Table: UITableView!
    @IBOutlet weak var Temperature: UILabel!
    
    deinit {
        Load.removeObserver(self, forKeyPath: "Current")
    }
    
    func fetchForecast() {
        if Observed {
            Load.removeObserver(self, forKeyPath: "Current")
            Observed = false
        }
        
        Load = FetchWeather(latitude: Delegate.Latitude, longitude: Delegate.Longitude)
        Load.completionBlock = {
        //Current conditions
            var cond  = self.Load.Current.Forecast
            var start = advance(cond.startIndex, 0)
            
            self.Conditions.text = String(cond[start])
            self.Summary.text = self.Load.Current.Forecast
            self.Temperature.text = String((self.Load.Current.Temperature.description as NSString).intValue) + " F"
            
        //The week ahead
            //Table.beginUpdates()
            //Table.insertR
        }
        
        if !Observed {
            Load.addObserver(self, forKeyPath: "Current", options: NSKeyValueObservingOptions.New, context: nil)
            Observed = true
        }
        
        Operations.addOperation(self.Load)
    }
    
    override func observeValueForKeyPath(keyPath: String, ofObject object: AnyObject, change: [NSObject : AnyObject], context: UnsafeMutablePointer<Void>) {
        var cond  = self.Load.Current.Forecast
        var start = advance(cond.startIndex, 0)
        
        self.Conditions.text = String(cond[start])
        self.Summary.text = self.Load.Current.Forecast
        self.Temperature.text = String((self.Load.Current.Temperature.description as NSString).intValue) + " F"
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        let dest = segue.destinationViewController as! TimedController
        dest.Weather = Load.Current
        dest.ZIP = Delegate
    }
    
    func queryAPI() {
        fetchForecast()
        
        let note = UILocalNotification()
        note.fireDate = NSDate(timeIntervalSinceNow: 1)
        note.alertAction = "NOTICE"
        note.alertBody = "The forecast was updated"
        
        UIApplication.sharedApplication().scheduleLocalNotification(note)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    //Use this to configure the table contents
        Table.delegate = self
        
    //Start the API query loop
        NSTimer.scheduledTimerWithTimeInterval(60.0, target: self, selector: "queryAPI", userInfo: nil, repeats: true)

    //Ready this object for asynchronous RPC calls
        Operations = NSOperationQueue()
        Operations.name = "Forecast Fetcher"
        
        fetchForecast()
    }
}