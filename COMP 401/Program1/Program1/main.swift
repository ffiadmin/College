//
//  Program Number: 1
//  Created by: Oliver Spryn
//  Created on: 2/4/15
//  Time to Completon: 1 hour
//  Purpose:
//  
//      Create a program which demonstrates various features of
//      classes, protocols, propertie, ande methods within Swift
//      and apply those principles to a simple example.
//

import Foundation

println("Good morning! Would you be interested in a second breakfast?")

protocol Person {
    var name: String { get set }
    var volume: Double { get set }
    var weight: Double { get set }
}

class Hobbit: Person {
//Conform to Person
    var name: String = ""
    var weight: Double = 0.0
    var volume: Double = 0.0 {
        didSet {
            if(volume <= 0.0) {
                volume = 1.0
            }
        }
        
        willSet {
            if(newValue <= 0.0) {
                println("\(name) is now having an existentialist crisis")
                println("Yep, we're rejecting this one")
            }
        }
    }
    
//Add in Hobbit properties!
    var density: Double {
        get {
            return weight/volume
        }
    }
    
    var meals:[String] = []
    
    
//Add in Hobbit actions
    init() {
        meals = ["First breakfast", "Second breakfast", "Huge lunch", "Fancy dinner"]
    }
    
    func eat(meal: Int) -> Void {
        let index = meal - 1
        
        if(index < meals.count && index >= 0) {
            println("\(name) is eating: \(meals[index])")
            
            meals.removeAtIndex(index)
            ++weight
        } else if(index < 0) {
            println("Breakfasts should come first")
        } else {
            println("Sorry, no midnight snacks")
        }
    }
}

class Wizard {
    class func setOffFireworks() {
        println("The wizard set off fireworks")
    }
}

//Make hobbits eat!
var bilbo = Hobbit()
bilbo.name = "Bilbo"
bilbo.weight = 170 //lbs
bilbo.volume = 500 //in^3 ?????? (Is that huge?)

bilbo.eat(1) //So, always one since I'm told to remove the meal from the array, thus changing its indexed location
println("\(bilbo.name) is now \(bilbo.density) lbs/in^3")
bilbo.eat(1)
println("\(bilbo.name) is now \(bilbo.density) lbs/in^3")
bilbo.eat(1)
println("\(bilbo.name) is now \(bilbo.density) lbs/in^3")
bilbo.eat(1)
println("\(bilbo.name) is now \(bilbo.density) lbs/in^3")

bilbo.volume = 0.0
println("\(bilbo.name) is now \(bilbo.density) lbs/in^3")
println("This guy is dense!")

Wizard.setOffFireworks()