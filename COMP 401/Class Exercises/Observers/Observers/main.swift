//
//  main.swift
//  Observers
//
//  Created by Oliver Spryn on 3/31/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import Foundation

class Bank: NSObject {
    dynamic var balance: Int = 1
    
    override init() {
        super.init()
        
        addObserver(self, forKeyPath: "balance",
            options: NSKeyValueObservingOptions.New | NSKeyValueObservingOptions.Old,
            context: nil)
    }
    
    deinit {
        removeObserver(self, forKeyPath: "balance")
    }
    
    override func observeValueForKeyPath(keyPath: String, ofObject object: AnyObject, change: [NSObject : AnyObject], context: UnsafeMutablePointer<Void>) {
        print("Balance changed! ")
        
        if change[NSKeyValueChangeNewKey] as Int > change[NSKeyValueChangeOldKey] as Int {
            println("It went up to $\(change[NSKeyValueChangeNewKey]!). :)")
        } else {
            println("It went down to $\(change[NSKeyValueChangeNewKey]!). :(")
        }
    }
    
    func setValue(bal: Int) {
        balance = bal
    }
}

var bank = Bank()
bank.setValue(100)
bank.setValue(20)
bank.setValue(2000000)