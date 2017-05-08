/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Events.cpp
 * Author: Stiggandr
 * 
 * Created on May 7, 2017, 4:06 PM
 */

#include "Events.h"
#include <iostream>

Events::Events() {
}

Events::Events(int Index){
    switch(Index) {
        case 0: 
            name = "Zombie Invasion";
            desc = "The living dead! Or did their netflix just get cut off?";
            ethics = 2;
            faith = 0;
            science = 0;
            pop = 10;
            break;
        case 1: 
            name = "Dark Night of the Soul";
            desc = "No we're not talking about batman...";
            ethics = 0;
            faith = 2;
            science = 0;
            pop = 10;
            break;
        case 2:
            name = "Alien Invasion";
            desc = "The greyskins come!";
            ethics = 0;
            faith = 0;
            science = 2;
            pop = 10;
            break;
        case 3:
            name = "Them";
            desc = "Giant ants are on their way to wreck your day.";
            ethics = 1;
            faith = 0;
            science = 1;
            pop = 10;
            break;
        case 4:
            name = "Proof of Gods";
            desc = "And they're not very benevolent... ";
            ethics = 0;
            faith = 1;
            science = 1;
            pop = 10;
            break;
        case 5:
            name = "Stock Market Crash";
            desc = "The happening is real. Ron Paul tried to warn you.";
            ethics = 1;
            faith = 1;
            science = 0;
            pop = 10;
            break;
        case 6:
            name = "Hungry Hungry Locusts";
            desc = "They eat everything in sight. Almost as bad as teenagers.";
            ethics = 1;
            faith = 0;
            science = 1;
            pop = 10;
            break;
        case 7:
            name = "Reverse in the magnetosphere";
            desc = "It's like Y2K... but actually a crisis.";
            ethics = 0;
            faith = 0;
            science = 3;
            pop = 10;
            break;
        case 8:
            name = "R'lyeh Rises";
            desc = "And with it all the horrors of early 1900s Boston";
            ethics = 0;
            faith = 3;
            science = 0;
            pop = 10;
            break;
        case 9:
            name = "PostModern Evolution";
            desc = "Why do we need values anyway?";
            ethics = 3;
            faith = 0;
            science = 0;
            pop = 10;
            break;
        default: 
            name = "Mystery Card";
            desc = "How you got this, no one knows. But either way. You lose. lol...";
            ethics = 500;
            faith = 500;
            science = 500;
            pop = 100;
            break;
    }
}

void Events::display(){
    std::cout<<name<<std::endl;
    std::cout<<desc<<std::endl;
    std::cout<<"Science Requirement: "<<science<<"// Faith Requirement: "<<faith<<"// Ethics Requirement: "<<ethics<<"// Population lost on Fail: "<<pop<<std::endl<<"---------------------"<<std::endl;
}

int Events::getScience(){
    return science;
}
int Events::getFaith(){
    return faith;
}
int Events::getEthics(){
    return ethics;
}
int Events::getPop(){
    return pop;
}