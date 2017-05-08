/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Stiggandr
 *
 * Created on May 7, 2017, 4:02 PM
 */

#include <cstdlib>
#include "Events.h"
#include "PlayerCard.h"
#include <cstdlib>
#include <iostream>       // std::cout
#include <fstream>        // std::ofstream
#include <deque>          // std::deque
#include <queue>          // std::queue
#include <climits>        // for limit checks
#include <limits>         //needed for PressEnter Function

using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    //declare all necessary variables
    int faith = 0, science = 0, ethics = 0, population = 100, year = 0, input;
    int hand[5];
    int timeline[5];
    bool end = false;
    
    //deal player hand
    cout<<"Dealing your hand now..."<<endl;
    
    for (int i = 0; i < 4; i++) {
        hand[i] = (rand() % 10)+1;
    };
    
    //deal event timeline. Only draw one event per turn. No dynamic application of structs to timeline 2d array.
    cout<<"Dealing the time line of events now..."<<endl;
           
    for (int i = 0; i <5; i++) {
        timeline[i] = rand() % 10;
    };
    
    cout<<"Your Scientists, Profits, and Philosphers all agree... The end is coming..."<<endl<<endl;
    
    while (!end){
        cout<<"The Year is "<<year + 2100<<"... The coming years hold the following misfortune:"<<endl;
        cout<<"The Times have stolen one point of ";
        int roll = rand() % 3;
        
        if (roll == 0) {
            cout<<"science"<<endl;
            --science;
        } else if (roll == 1) {
            cout<<"faith"<<endl;
            --faith;
        } else if (roll == 2) {
            cout<<"ethics"<<endl; 
            --ethics;
        }
        
        
        //make sure hand is full
        for (int i=0; i < 5; i++) {
            if (hand[i]==0){
            hand[i] = (rand() % 10)+1;
            PlayerCard card(hand[i]);
            cout<<"You've drawn the card "<<card.getName()<<" to fill up your hand."<<endl;
            }
        }
        //display Event cards in order
        for(int i = 0; i <5; i++) {
            Events upcoming(timeline[i]);
            cout<<"YEAR "<<2100+i<<": ";
            upcoming.display();
        }
        cout<<endl<<"You can make the following decrees:"<<endl;
        
        //display Player cards to play
        for(int i = 0; i <5; i++) {
            PlayerCard card(hand[i]);
            cout<<i+1<<": ";
            card.display();
        }
        cout<<"Your current stats are:"<<endl<<"Science: "<<science<<endl<<"Faith: "<<faith<<endl<<"Ethics: "<<ethics<<endl<<"population: "<<population<<endl;
        
        cout<<"Please input a card selection as integer 1-5, or quit: 6, Save: 7, Load: 8:" ;
        //user input in validation check
        while(true){ //infinite loop broken by good input
            //offer user input 
            
            cin>>input;
            
            //if good input and viable selection
            if (cin.good()&& input >0 && input <9) {
                switch(input){
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5: { //nest in block so it will not risk being in scope without being declared.
                        PlayerCard card(hand[input]);
                        cout<<"You've selected: "<<endl;
                        card.detail();
                        card.useCard(&science, &faith, &ethics);
                        cout<<"Your new stats are..."<<endl<<"Science: "<<science<<"// Faith: "<<faith<<"// Ethics: "<<ethics;
                        cout<<endl<<endl;
                        //remove that card from the players hand.
                        hand[input] = 0;
                        break;
                    }
                    case 6: 
                        cout<<"quit";
                        end = true;
                        break;
                    case 7: {
                        cout<<"Saving Game."<<endl;
                        ofstream savefile("save.txt");
                        if (savefile.is_open()) {
                            savefile<<science<<" "<<faith<<" "<<ethics<<" "<<population;
                            for(int i = 0; i <5; i++){
                                savefile<<hand[i]<<" ";
                            };
                            for(int i = 0; i <5; i++){
                                savefile<<timeline[i]<<" ";
                            };
                            savefile.close();
                        } else {
                            cout<<"could not find file to save game"<<endl;
                        }
                        cout<<"Please input a card selection as integer 1-5, or quit: 6, Save: 7, Load: 8:" ;
                        break; }
                    case 8: {
                        cout<<"Loading Game."<<endl;
                        ifstream savefile("save.txt");
                        if (savefile.is_open()){
                            savefile>>science>>faith>>ethics>>population;
                            for(int i = 0; i <5; i++){
                                savefile>>hand[i];
                            };
                            for(int i = 0; i <5; i++){
                                savefile>>timeline[i];
                            };
                        }
                        break; }
                    default: 
                        break;
                }
                //if a card was played break out of loop
                if(input >0 && input <6) {
                    //check if event passed or failed
                    Events event(timeline[0]);
                    //value round up 
                    bool pass = true;
                    cout<<"Science: "<<science<<" vs. "<<event.getScience()<<" ";
                    if (science >= event.getScience()) cout<<"PASS";
                    else {
                        cout<<"FAIL";
                        pass = false;
                    }
                    cout<<endl;
                    cout<<"Faith: "<<faith<<" vs. "<<event.getFaith()<<" ";
                    if (faith >= event.getFaith()) cout<<"PASS";
                    else {
                        cout<<"FAIL";
                        pass = false;
                    }
                    cout<<endl;
                    cout<<"Ethcis: "<<ethics<<" vs. "<<event.getEthics()<<" ";
                    if (ethics >= event.getEthics()) cout<<"PASS";
                    else {
                        cout<<"FAIL";
                        pass = false;
                    }
                    
                    if (pass == false) {
                        cout<<endl<<endl<<"You failed the check!"<<endl;
                        cout<<"population decreased from "<<population<<"million";
                        population = (population - event.getPop());
                        cout<<" to "<<population;
                    }
                    bool blank;
                    cout<<endl<<endl<<"confirm to continue";
                    
                    //clear cin
                    cin.clear();
                    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
                    //puase for user input
                    string input;
                    getline(cin, input);
                    
                    //update timeline
                    for(int i = 0; i < 5; i++) {
                        if (i==4) timeline[4] = rand() % 10;
                        else timeline[i] = timeline[i+1];
                    }
                    
                    break;
                }
                //if player quits 
                if (input == 6){
                    break;
                }
                //if player loads
                if(input == 8){
                    break;
                }
                
            } else { //if bad, clear cin and prompt proper input
                cout<<"Please enter an valid integer Value.";
                cin.clear();
                cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
            }
        }
        
        //confirm card selection. if the player doesn't want the card, continue
        
        //quit game condition check (must be before lose check)
        if (end == true) {
            cout<<endl<<endl<<"Thank you for playing!";
        }
        //lose game condition check
        if (population < 1) {
            end = true;
            cout<<endl<<"Ragnorok, Rapture, Apocalypse... Whatever you wish to call it, teh end has descended upon you.";
        };
    }
    
    return 0;
}
