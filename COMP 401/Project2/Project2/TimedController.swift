//
//  TimedController.swift
//  Project2
//
//  Created by Oliver Spryn on 4/16/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class TimedController: UIViewController, IWeatherProtocol {
    @IBOutlet weak var Conditions: UILabel!
    @IBOutlet weak var DatePicker: UIDatePicker!
    var Operations: NSOperationQueue!
    @IBOutlet weak var Summary: UILabel!
    @IBOutlet weak var Temperature: UILabel!
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
        var load = FetchWeather(latitude: ZIP.Latitude, longitude: ZIP.Longitude, time: date)
        load.completionBlock = {
            dispatch_async(dispatch_get_main_queue(), {
            //Conditions at selected time
                var cond  = load.Current.Forecast
                var start = advance(cond.startIndex, 0)
            
                self.Conditions.text = String(cond[start])
                self.Summary.text = load.Current.Forecast
                self.Temperature.text = String((load.Current.Temperature.description as NSString).intValue) + " F"
            })
        }
        
        Operations.addOperation(load)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    //Ready this object for asynchronous RPC calls
        Operations = NSOperationQueue()
        Operations.name = "Forecast Fetcher"
        
    //Get the ZIP data
        var fc = self.tabBarController?.viewControllers?[0] as! ForecastController
        ZIP = fc.ZIP
        
        fetchForecast(DatePicker.date)
    }
}