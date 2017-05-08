/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Events.h
 * Author: Stiggandr
 *
 * Created on May 7, 2017, 4:06 PM
 */

#include<string>

#ifndef EVENTS_H
#define EVENTS_H

class Events {
public:
    Events();
    Events(int);
    
    void display();
    int getScience();
    int getFaith();
    int getEthics();
    int getPop();
private:
    int science, faith, ethics, pop;
    std::string desc, name; 

};

#endif /* EVENTS_H */

