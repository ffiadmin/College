//
//  FromTable.swift
//  TableView
//
//  Created by Oliver Spryn on 2/19/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class FromTable: UIViewController {

    @IBOutlet weak var Picker: UIDatePicker!
    @IBOutlet weak var Back: UIButton!
    @IBOutlet weak var Label: UILabel!
    var Delegate: ITable!
    var Text = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        Label.text = Text
        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func Back(sender: UIButton) {
        Delegate.done(self)
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
