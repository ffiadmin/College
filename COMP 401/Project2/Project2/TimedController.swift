//
//  TimedController.swift
//  Project2
//
//  Created by Oliver Spryn on 4/16/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class TimedController: UIViewController {
    @IBOutlet weak var Conditions: UILabel!
    @IBOutlet weak var DatePicker: UIDatePicker!
    var Operations: NSOperationQueue!
    @IBOutlet weak var Summary: UILabel!
    @IBOutlet weak var Temperature: UILabel!
    var Weather: Now!
    var ZIP: ZIPData!
    
    @IBAction func dateChanged(sender: UIDatePicker) {
    //Reset the interface
        Conditions.text = "-"
        Summary.text = "Summary"
        Temperature.text = "- F"
        
    //Load the new data
        fetchForecast(sender.date)
    }
    
    func fetchForecast(date: NSDate) {
        var load = FetchWeather(latitude: 37.8267, longitude: -122.423, time: date)
        load.completionBlock = {
        //Conditions at selected time
            var cond  = load.Current.Forecast
            var start = advance(cond.startIndex, 0)
            
            self.Conditions.text = String(cond[start])
            self.Summary.text = load.Current.Forecast
            self.Temperature.text = String((load.Current.Temperature.description as NSString).intValue) + " F"
        }
        
        Operations.addOperation(load)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    //Ready this object for asynchronous RPC calls
        Operations = NSOperationQueue()
        Operations.name = "Forecast Fetcher"
        
        fetchForecast(DatePicker.date)
    }
}