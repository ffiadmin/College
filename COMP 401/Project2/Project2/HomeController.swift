//
//  HomeController.swift
//  Project2
//
//  Created by Oliver Spryn on 4/2/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import MapKit
import UIKit

class HomeController: UIViewController, UITextFieldDelegate {
    @IBOutlet weak var Button: UIButton!
    @IBOutlet weak var Input: UITextField!
    @IBOutlet weak var Map: MKMapView!
    var Operations: NSOperationQueue!
    var ZIP: ZIPData!
    let ZIPLength = 5
    
    func loadMap(zip: String) {
        var load = FetchZIP(zip: zip)
        load.completionBlock = {
            let loc = CLLocationCoordinate2D(latitude: CLLocationDegrees(load.Data.Latitude), longitude: CLLocationDegrees(load.Data.Longitude))
            let span = MKCoordinateSpanMake(0.25, 0.25)
            let reg = MKCoordinateRegionMake(loc, span)
            
            self.Map.setRegion(reg, animated: true)
            self.ZIP = load.Data
        }
        
        Operations.addOperation(load)
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        super.prepareForSegue(segue, sender: sender)
        let dest = segue.destinationViewController as! UITabBarController
        let bar = dest.viewControllers as! [UIViewController]
        var forecast = bar[0] as! ForecastController
        
        forecast.Delegate = self.ZIP
    }
    
    //StackOverflow [1]
    //Question [http://stackoverflow.com/q/12944789/663604] by Demasterpl [http://stackoverflow.com/users/693121/demasterpl]
    //Answer   [http://stackoverflow.com/a/16015013/663604] by Aje        [http://stackoverflow.com/users/2282398/aje]
    //StackOverflow [2]
    //Question [http://stackoverflow.com/q/433337/663604]   by Domness    [http://stackoverflow.com/users/53677/domness]
    //Answer   [http://stackoverflow.com/a/433498/663604]   by sickp      [http://stackoverflow.com/users/99532/sickp]
    func textField(textField: UITextField, shouldChangeCharactersInRange range: NSRange, replacementString string: String) -> Bool {
    //Allow only numberic values [1]
        if count(string) == 0 { //Allows backspace
            return true
        }
        
        if string.toInt() == nil {
            return false
        }
        
    //Limit the range [2]
        if range.length + range.location > count(textField.text) {
            return false
        }
        
        var newLength = count(textField.text) + count(string) - range.length
        
    //Load the map to the location of the ZIP code
        if newLength == ZIPLength {
            let data = (textField.text + string as NSString).dataUsingEncoding(NSUTF8StringEncoding)
            
            loadMap(textField.text + string)
            DocumentFileIO.write("zip.txt", contents: data!)
        }
        
        return newLength <= ZIPLength
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    //Let the view controller handle the maximum length of the text input
        Input.delegate = self
        
    //Ready this object for asynchronous RPC calls
        Operations = NSOperationQueue()
        Operations.name = "ZIP Fetcher"
        
    //Preload the ZIP code
        Input.text = DocumentFileIO.read("zip.txt")
        
        if !Input.text.isEmpty {
            loadMap(Input.text)
        }
        
    //Load the map background and apply a blur effect
        //let blur = UIBlurEffect(style: UIBlurEffectStyle.Light)
        //let effect = UIVisualEffectView(effect: blur)
        //effect.frame = view.frame
        //Map.addSubview(effect)
    }
}