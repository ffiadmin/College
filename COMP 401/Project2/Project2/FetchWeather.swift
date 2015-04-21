//
//  FetchWeather.swift
//  Project2
//
//  Created by Oliver Spryn on 4/15/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class Day {
    var Date: NSDate!
    var Forecast: String!
    var TempMax: Float!
    var TempMin: Float!
}

class Now: NSObject {
    var Forecast: String!
    var Temperature: Float!
}

enum FetchType {
    case Forecast, Timed
}

class FetchWeather: AsyncRPC {
    var BaseURL = "https://api.forecast.io/forecast/2c9e2def7742a2881572c6b6a84e118f/"
    dynamic var Current: Now!
    var Days: [Day]!
    var Latitude: Float!
    var Longitude: Float!
    var Type: FetchType!
    
    init(latitude: Float, longitude: Float) {
        super.init(url: BaseURL + latitude.description + "," + longitude.description)
        Current = Now()
        Days = [Day]()
        Latitude = latitude
        Longitude = longitude
        Type = FetchType.Forecast
    }
    
    init(latitude: Float, longitude: Float, time: NSDate) {
        super.init(url: "\(BaseURL)\(latitude.description),\(longitude.description),\(Int(time.timeIntervalSince1970))")
        Current = Now()
        Days = [Day]()
        Latitude = latitude
        Longitude = longitude
        Type = FetchType.Timed
        
        NSLog("\(BaseURL)\(latitude.description),\(longitude.description),\(Int(time.timeIntervalSince1970))")
    }
    
    override func Process(data: NSData) {
        let JSON: Dictionary<String, AnyObject> = NSJSONSerialization.JSONObjectWithData(data, options: nil, error: nil) as! Dictionary<String, AnyObject>
        let current: Dictionary<String, AnyObject> = JSON["currently"] as! Dictionary<String, AnyObject>
        
    //Now
        Current.Forecast = current["summary"] as! String
        Current.Temperature = current["temperature"] as! Float
        
    //Weekly forecast
        if Type == FetchType.Forecast {
            let week: Dictionary<String, AnyObject> = JSON["daily"] as! Dictionary<String, AnyObject>
            let days: Array<Dictionary<String, AnyObject>> = week["data"] as! Array<Dictionary<String, AnyObject>>
            var cnt = days.count
            var day: Day! = nil
            
            for var i = 0; i < cnt; ++i {
                day = Day()
                day.Date     = NSDate(timeIntervalSince1970: NSTimeInterval(days[i]["time"] as! Int))
                day.Forecast = days[i]["summary"] as! String
                day.TempMax  = days[i]["temperatureMax"] as! Float
                day.TempMin  = days[i]["temperatureMin"] as! Float
                
                Days.append(day)
            }
        }
    }
}