//
//  ForecastControllerViewController.swift
//  Project2
//
//  Created by Oliver Spryn on 4/15/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ForecastController: UIViewController, IWeatherProtocol, UITableViewDelegate, UITableViewDataSource {
    @IBOutlet weak var Conditions: UIImageView!
    var Load: FetchWeather!
    var Observed = false
    var Operations: NSOperationQueue!
    @IBOutlet weak var Summary: UILabel!
    @IBOutlet weak var Table: UITableView!
    @IBOutlet weak var Temperature: UILabel!
    var ZIP: ZIPData!
    
    deinit {
        Load.removeObserver(self, forKeyPath: "Current")
    }
    
    func fetchForecast() {
        if Observed {
            Load.removeObserver(self, forKeyPath: "Current")
            Observed = false
        }
        
        Load = FetchWeather(latitude: ZIP.Latitude, longitude: ZIP.Longitude)
        Load.completionBlock = {
            dispatch_async(dispatch_get_main_queue(), {
            //Current conditions
                self.Conditions.image = UIImage(named: self.Load.Current.Icon)
                self.Summary.text = self.Load.Current.Forecast
                self.Temperature.text = String((self.Load.Current.Temperature.description as NSString).intValue) + " F"
                
            //The week ahead
                self.Table.reloadData()
            });
        }
        
        if !Observed {
            Load.addObserver(self, forKeyPath: "Current", options: NSKeyValueObservingOptions.New, context: nil)
            Observed = true
        }
        
        Operations.addOperation(self.Load)
    }
    
    override func observeValueForKeyPath(keyPath: String, ofObject object: AnyObject, change: [NSObject : AnyObject], context: UnsafeMutablePointer<Void>) {
        self.Conditions.image = UIImage(named: self.Load.Current.Icon)
        self.Summary.text = self.Load.Current.Forecast
        self.Temperature.text = String((self.Load.Current.Temperature.description as NSString).intValue) + " F"
    }
    
    func queryAPI() {
        fetchForecast()
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        var dateFormat = NSDateFormatter()
        dateFormat.dateFormat = "EEE"
        
        var cell = Table.dequeueReusableCellWithIdentifier("cell", forIndexPath: indexPath) as! ForecastDay
        cell.Day.text = dateFormat.stringFromDate(Load.Days[indexPath.row].Date)
        cell.High.text = String(stringInterpolationSegment: Int(Load.Days[indexPath.row].TempMax)) + " F"
        cell.Icon.image = UIImage(named: Load.Days[indexPath.row].Icon)
        cell.Low.text = String(stringInterpolationSegment: Int(Load.Days[indexPath.row].TempMin)) + " F"
        
        return cell
    }
    
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        let alert = UIAlertView(title: "Summary", message: Load.Days[indexPath.row].Forecast, delegate: self, cancelButtonTitle: "OK")
        alert.show()
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Load.Days.count
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    //Start the API query loop
        NSTimer.scheduledTimerWithTimeInterval(60.0, target: self, selector: "queryAPI", userInfo: nil, repeats: true)

    //Ready this object for asynchronous RPC calls
        Operations = NSOperationQueue()
        Operations.name = "Forecast Fetcher"
        
        fetchForecast()
        
    //Register this class as the one to provide the tavble with information
        Table.dataSource = self
        Table.delegate = self
    }
}