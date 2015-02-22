//
//  TextController.swift
//  Program2
//
//  Created by Oliver Spryn on 2/21/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class TextController: UIViewController {
    var Delegate: IAdjust!
    
//IBOutlets to controls
    @IBOutlet weak var Red: UITextField!
    @IBOutlet weak var Green: UITextField!
    @IBOutlet weak var Blue: UITextField!
    
    @IBOutlet weak var Done: UIButton!
    @IBOutlet weak var Cancel: UIButton!
    
//Set from the segue
    var RedValue: Float = 0.0
    var GreenValue: Float = 0.0
    var BlueValue:Float = 0.0

    override func viewDidLoad() {
        super.viewDidLoad()

    //Set the values in the text box
        Red.text = String(format: "%f", RedValue)
        Green.text = String(format: "%f", GreenValue)
        Blue.text = String(format: "%f", BlueValue)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    @IBAction func DismissHandler(sender: UIControl) {
        adjustValues()
        
        if Red.isFirstResponder() {
            Red.resignFirstResponder()
        } else if Green.isFirstResponder() {
            Green.resignFirstResponder()
        } else if Blue.isFirstResponder() {
            Blue.resignFirstResponder()
        }
    }
    
    @IBAction func RedHandler(sender: UITextField) {
        adjustValues()
    }
    
    @IBAction func GreenHandler(sender: UITextField) {
        adjustValues()
    }
    
    @IBAction func BlueHandler(sender: UITextField) {
        adjustValues()
    }
    
    
    @IBAction func DoneHandler(sender: UIButton) {
        adjustValues()
        Delegate.done(self, apply: true)
    }
    
    @IBAction func CancelHandler(sender: UIButton) {
        adjustValues()
        Delegate.done(self, apply: false)
    }
    
    func adjustValues() {
    //Adjust red values
        RedValue = (Red.text as NSString).floatValue
        if RedValue > 1.0 { RedValue = 1.0 }
        if RedValue < 0.0 { RedValue = 0.0 }
        Red.text = String(format: "%f", RedValue)
        
    //Adjust green values
        GreenValue = (Green.text as NSString).floatValue
        if GreenValue > 1.0 { GreenValue = 1.0 }
        if GreenValue < 0.0 { GreenValue = 0.0 }
        Green.text = String(format: "%f", GreenValue)
        
    //Adjust blue values
        BlueValue = (Blue.text as NSString).floatValue
        if BlueValue > 1.0 { BlueValue = 1.0 }
        if BlueValue < 0.0 { BlueValue = 0.0 }
        Blue.text = String(format: "%f", BlueValue)
    }
}