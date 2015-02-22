//
//  SliderController.swift
//  Program2
//
//  Created by Oliver Spryn on 2/21/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class SliderController: UIViewController, IAdjust {
//IBOutlets to controls
    @IBOutlet weak var RedSlider: UISlider!
    @IBOutlet weak var GreenSlider: UISlider!
    @IBOutlet weak var BlueSlider: UISlider!
    
//The values of the sliders
    var Red:Float = 0.0
    var Green:Float = 0.0
    var Blue:Float = 0.0
    
//Handlers for the sliders
    @IBAction func RedHandler(sender: UISlider) {
        Red = sender.value
        setBackground()
    }
    
    @IBAction func GreenHandler(sender: UISlider) {
        Green = sender.value
        setBackground()
    }
    
    @IBAction func BlueHandler(sender: UISlider) {
        Blue = sender.value
        setBackground()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    //Retain the values of the sliders
        Red = RedSlider.value
        Green = GreenSlider.value
        Blue = BlueSlider.value
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        let child = segue.destinationViewController as TextController
        child.RedValue = RedSlider.value
        child.GreenValue = GreenSlider.value
        child.BlueValue = BlueSlider.value
        child.Delegate = self
    }
    
    func setBackground() {
        view.backgroundColor = UIColor(red: CGFloat(Red), green: CGFloat(Green), blue: CGFloat(Blue), alpha: 1.0)
    }
    
    func done(data: TextController, apply: Bool) {
        if apply {
            RedSlider.value = data.RedValue
            GreenSlider.value = data.GreenValue
            BlueSlider.value = data.BlueValue
            
            Red = data.RedValue
            Green = data.GreenValue
            Blue = data.BlueValue
            setBackground()
        }
        
        dismissViewControllerAnimated(true, completion: nil)
    }
}