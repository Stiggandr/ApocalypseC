/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerCard.h
 * Author: Stiggandr
 *
 * Created on May 7, 2017, 4:06 PM
 */

#include <string>

#ifndef PLAYERCARD_H
#define PLAYERCARD_H

class PlayerCard {
public:
    PlayerCard();
    PlayerCard(int);
    
    void display();
    void detail();
    std::string getName();
    void useCard(int *S, int *F, int *E);
private:
    int science, faith, ethics, pop;
    std::string desc, name;
};

#endif /* PLAYERCARD_H */

