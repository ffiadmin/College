//
//  FetchDeck.swift
//  Exam 2 Key
//
//  Created by Oliver Spryn on 4/21/15.
//  Copyright (c) 2015 Default. All rights reserved.
//

import UIKit

class Deck {
    var Name: String!
    var Votes: Int!
}

class FetchDeck: AsyncRPC {
    var Data: [Deck]!
    
    init(term: String) {
        super.init(url: "http://www.braineos.com/api/v1/search/\(term)/10")
        Data = [Deck]()
    }
    
    override func Process(data: NSData) {
        let JSON: Dictionary<String, AnyObject> = NSJSONSerialization.JSONObjectWithData(data, options: nil, error: nil) as! Dictionary<String, AnyObject>
        let cards: Array<Dictionary<String, AnyObject>> = JSON["items"] as! Array<Dictionary<String, AnyObject>>
        var deck: Deck! = nil
        
        for var i = 0; i < cards.count; ++i {
            deck = Deck()
            deck.Name = cards[i]["name"] as! String
            deck.Votes = cards[i]["deckVotes"] as! Int
            
            Data.append(deck)
        }
    }
}