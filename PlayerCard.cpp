/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerCard.cpp
 * Author: Stiggandr
 * 
 * Created on May 7, 2017, 4:06 PM
 */

#include "PlayerCard.h"
#include <iostream>
#include<string>

PlayerCard::PlayerCard(int Index) {
    switch(Index){
        case 1:  
            name = "Secular Morals";
            desc = "Sure they may be more efficient, but your religious community is devistated...";
            ethics = 2;
            faith = -1;
            science = 0;
            break;
        case 2: 
            name = "Scientific Regulations";
            desc = "Activists march on the capitals of the world and demand more accountability of science!";
            ethics = 2;
            faith = 0;
            science = -1;
            break;
        case 3:  
            name = "neighborly Kindness";
            desc = "Nothing bad here... Just the rediscovery of Mayberry.";
            ethics = 1;
            faith = 0;
            science = 0;
            break;
        case 4: 
            name = "Dogmatic Pope";
            desc = "Seeking to restore the Catholic church to the glory of the middle ages... no wonder your ethics suffer";
            ethics = -1;
            faith = 2;
            science = 0;
            break;
        case 5:  
            name = "That's not evidence, show me the evidence.";
            desc = "Sometimes faith in the face of reality is good... sometimes your head's just in the sand.";
            ethics = 0;
            faith = 2;
            science = -1;
            break;
        case 6: 
            name = "Sign from Above";
            desc = "Even the scientists are stumped by this one. At least it helps the religious community.";
            ethics = 0;
            faith = 1;
            science = 0;
            break;
        case 7:  
            name = "Has science gone too far?";
            desc = "Destroying the environment? Cloning? Brains in Jars? who cares about morals, science must march on!";
            ethics = -1;
            faith = 0;
            science = 2;
            break;
        case 8: 
            name = "God Is Dead";
            desc = "Nietzsche said it along time ago, and the scientific communities been trying to prove it ever sense... This time they might just have done it.";
            ethics = 0;
            faith = -1;
            science = 2;
            break;
        case 9:  
            name = "AI revolution";
            desc = "At long last, general intelligence has been achieved on a computer... Nothing bad can come of this right?";
            ethics = 0;
            faith = 0;
            science = 1;
            break;
        case 10: 
            name = "Human ascension";
            desc = "The ideal of transhumanism is realized... at the cost of humanity?";
            ethics = -1;
            faith = -1;
            science = 3;
            break;
        default:  
            name = "Get good";
            desc = "This is a holder description";
            ethics = 1;
            faith = 1;
            science = 1;
            break;
    }
}

void PlayerCard::display() {
    std::cout<<name<<"// Science : +"<<science<<"// Faith : +"<<faith<<"// Ethics : +"<<ethics<<std::endl<<"---------------------"<<std::endl;
}

void PlayerCard::detail() {
    std::cout<<name<<std::endl;
    std::cout<<desc<<std::endl;
    std::cout<<"// Science : +"<<science<<"// Faith : +"<<faith<<"// Ethics : +"<<ethics<<std::endl<<"---------------------"<<std::endl;}

std::string PlayerCard::getName() {
    return name;
}
        
void PlayerCard::useCard(int *A, int *B, int *C) {
    *A = *A + science;
    *B = *B + faith;
    *C = *C + ethics;
}