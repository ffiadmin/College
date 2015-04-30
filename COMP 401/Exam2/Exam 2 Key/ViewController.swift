//
//  ViewController.swift
//  Exam 2 Key
//
//  Created by Brian Dellinger on 4/21/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var Data: [Deck]!
    var Operations: NSOperationQueue!
    @IBOutlet weak var SearchInput: UITextField!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        Data = [Deck]()
        Operations = NSOperationQueue()
        Operations.name = "Brian Dellinger"
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        var dest = segue.destinationViewController as! DeckVC
        dest.decks = Data
    }

    @IBAction func SearchHandler(sender: UIButton) {
        SearchInput.resignFirstResponder()
        
        var load = FetchDeck(term: SearchInput.text)
        load.completionBlock = {
            self.Data = load.Data
            self.view.backgroundColor = UIColor.greenColor()
        }
        
        Operations.addOperation(load)
    }
}