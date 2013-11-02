#include "Assault.h"

/**
 * DEFAULT CONSTRUCTOR
 * 
 * This constructor assigns the member variables their values given to
 * this constructor.
 *
 * @access public
 * @param  Territory                color     The color of this terriory, as defined by the ENUM in Display.h
 * @param  Territory             continent The string name of the continent in which this territory resides
 * @return void
*/

Assault::Assault(Territory* attTerr, Territory* defTerr) {
    this->attTerr = attTerr;
    this->defTerr = defTerr;
}

/**
 * This function handles the attacking between territories.
 *
 * @access public
 * @return true if the defending territory was captured, false if it was not
*/

bool Assault::attack() {
    int a, d;
    while(true) {
        //gets number of attDice
        switch(attTerr->getNumTroops()) {
        case 0:
            // display something about error -- shouldn't happen
        case 1:
            // display error -- can't attack
            break;
        case 2:
            a=1;
            break;
        case 3:
            a=2;
            break;
        default:
            a=3;
            break;
        }

        // gets number of defDice
        switch(defTerr->getNumTroops()) {
        case 0:
            // error -- shouldn't happen
        case 1:
            d=1;
            break;
        default:
            d=2;
            break;
        }

        // get value of attDice
        for(a; a>0; a--)
            attDice.push_back(roll());

        // get value of defDice
        for(d; d>0; d--)
            defDice.push_back(roll());

        // sort dice
        sort(attDice.rbegin(), attDice.rend());
        sort(defDice.rbegin(), defDice.rend());

        int i=0;
        int attLosses = 0; //number of troops attacker looses in the battle
        int defLosses = 0;  //number of troops defender looses in the battle 
        while(i < attDice.size() && i < defDice.size()) {
            if(attDice[i] > defDice[i]) { //attacker wins
                defLosses++;
            }
            else {                        //defender wins
                attLosses++;
            }

            i++;
        }

        //Display dice rolls and final results

        attTerr->delTroop(attLosses);
        defTerr->delTroop(defLosses);

        attDice.clear();
        defDice.clear();

        if(defTerr->getNumTroops() == 0) { //checks if there are any troops on defTerr
            cout << defTerr->getName() << " has been conquered!" << endl;
            return true;
        }
        
		cout << "\n\nAfter the assault:\n";
		cout << "\t" << attTerr->getName() << " has " << attTerr->getNumTroops() << '\n';
		cout << "\t" << defTerr->getName() << " has " << defTerr->getNumTroops() << "\n\n";

		if (attTerr->getNumTroops() > 1) {
			char c;
			cout << "Would you like to attack again? (Y/N) :" ; 
			cin >> c;   //get if user would like to attack again if he can
			if(c=='n' || c =='N')
				break;
			cout << "\n\n";
		} else {
			break;
		}
    }
    return false;
}

/**
 * Moves troops from attackingTerr to conquered defendingTerr.
 *
 * @access public
 * @return void
*/

void Assault::terrAcquisition(vector<Territory*> &terr) {
    //check to see if that was the owner's last terr
    bool terrRemaining = false;     // holds if defTerr's owner has any other terr left
    for(int i = 0; i<terr.size(); i++) {
        if(defTerr->getOwner()->getColor() == terr[i]->getOwner()->getColor() && defTerr != terr[i]) {  //checks if player has another terr
            terrRemaining = true;                                              //sets true if the player does
            break;
        }
    }

    if(!terrRemaining) {
        attTerr->getOwner()->getHand()->receiveHand(attTerr->getOwner()->getHand()->flush());
        defTerr->getOwner()->isActive = false;
    }

    defTerr->setOwner(attTerr->getOwner());

    //attTerr->delTroop();
    //defTerr->addTroop();
    
    if(attTerr->getNumTroops()>1) {
        int t = -1;
        while(t >= attTerr->getNumTroops() || t <= 0) {
            cout << "There are " << attTerr->getNumTroops() << " troops on " << attTerr->getName() << " and " << defTerr->getNumTroops() << " troop on " << defTerr->getName() << ".\n";
            cout << "You can move up to " << attTerr->getNumTroops()-1 << " troops from " << attTerr->getName() << " to " << defTerr->getName() << ".\n\n";
            cout << "Enter the number of troops you would like to move: ";
            cin >> t;
        }
        attTerr->delTroop(t);
        defTerr->addTroop(t);
    }        
}

int Assault::roll() {
	return rand() % 5 + 1;
}