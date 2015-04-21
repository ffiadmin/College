//
//  FetchZIP.swift
//  Project2
//
//  Created by Oliver Spryn on 4/14/15.
//  Copyright (c) 2015 Oliver Spryn. All rights reserved.
//

import UIKit

class ZIPData {
    var City: String!
    var Latitude: Float!
    var Longitude: Float!
}

class FetchZIP: AsyncRPC, NSXMLParserDelegate {
    var BaseURL = "http://www.stands4.com/services/v2/zip.php?uid=3924&tokenid=UAFrTDGWsc3g0pg1&zip="
    var Data: ZIPData!
    var DataElement: String!
    var XMLParser: NSXMLParser!
    var ZIP: String!
    
    init(zip: String) {
        super.init(url: BaseURL + zip)
        Data = ZIPData()
        ZIP = zip
    }
    
    func parser(parser: NSXMLParser, didStartElement elementName: String, namespaceURI: String?, qualifiedName qName: String?, attributes attributeDict: [NSObject : AnyObject]) {
        DataElement = elementName
    }
    
    func parser(parser: NSXMLParser, foundCharacters string: String?) {
        if DataElement == "location" {
            Data.City = string
        } else if DataElement == "latitude" {
            Data.Latitude = (string as NSString!).floatValue
        } else if DataElement == "longitude" {
            Data.Longitude = (string as NSString!).floatValue
        }
    }
    
    override func Process(data: NSData) {
        XMLParser = NSXMLParser(data: data)
        XMLParser.delegate = self
        XMLParser.parse()
    }
}