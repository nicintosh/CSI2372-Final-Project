//
//  tile.cpp
//  CSI2372FinalProject
//
//  Created by Nick Burgel on 2014-11-24.
//  Copyright (c) 2014 Nick & Julien. All rights reserved.
//

#include "tile.h"

bool Tile::operator==(const Tile &t) {
    bool isTile = false;

    if (&t==this) {
        isTile = true;
    }

    return isTile;
}

ostream& operator <<(ostream& s, const Tile& t) {
    s     << t.name <<"&"
          << t.desc<<"&"
          << t.row<< " "
          << t.col<< " "
          << t.gems<<"\n";
    return s;
}
istream& operator >>(istream& i, Tile& t) {
    string test;
    getline(i,test,'&');
    t.name = test;
    getline(i,test,'&');
    t.desc = test;
    i >> t.row
      >> t.col
      >> t.gems;
    return i;
}


///////////////////////////////////////////////
//
// Action Functions
//
///////////////////////////////////////////////
bool Tile::action(Player& player) const{
return true;
}
bool Tile::canAct(Player& player){
return true;
}
Tile::~Tile(){
}
// A desert tile has no action
bool Desert::action(Player &player) const{
    return false;
}
bool Desert::canAct(Player &player){
    return false;
}
// A resaurant tile gives a player 10 food
bool Restaurant::canAct(Player& player){
    return true;
}

bool Restaurant::action(Player &player) const{
    player.setFood(10);
    return true;
}
// A spice mercant tile trades 3 spice for 2 gold
bool Smerchant::canAct(Player& player){
bool canBuy = false;
    int cartSpace = player.getCartSpace();
    int item = player.getSpice();
    int gold = player.getGold();

    if (gold>=2) {
        canBuy = true;
}
return canBuy;
}
bool Smerchant::action(Player &player) const{

    bool canBuy = false;
    int cartSpace = player.getCartSpace();
    int item = player.getSpice();
    int gold = player.getGold();

    if (gold>=2) {
        canBuy = true;

        player.setGold(gold-2);

        if (cartSpace >= 3) {
            player.setSpice(item+3);
        } else {
            player.setSpice(item+cartSpace);
        }

    }

    return canBuy;
}

// A Fabric Manufacture trades 3 fabric for 2 gold
bool Fmanu::canAct(Player &player){

    bool canBuy = false;
    int cartSpace = player.getCartSpace();
    int item = player.getFabric();
    int gold = player.getGold();

    if (gold>=2) {
        canBuy = true;
    }
    return canBuy;
}
bool Fmanu::action(Player &player) const{

    bool canBuy = false;
    int cartSpace = player.getCartSpace();
    int item = player.getFabric();
    int gold = player.getGold();

    if (gold>=2) {
        canBuy = true;

        player.setGold(gold-2);

        if (cartSpace >= 3) {
            player.setFabric(item+3);
        } else {
            player.setFabric(item+cartSpace);
        }

    }

    return canBuy;
}

// A jeweler trades 3 jewlery for 2 gold
bool Jeweler::canAct(Player &player){

    bool canBuy = false;
    int cartSpace = player.getCartSpace();
    int item = player.getJewel();
    int gold = player.getGold();

    if (gold>=2) {
        canBuy = true;
    }


    return canBuy;
}
bool Jeweler::action(Player &player) const{

    bool canBuy = false;
    int cartSpace = player.getCartSpace();
    int item = player.getJewel();
    int gold = player.getGold();

    if (gold>=2) {
        canBuy = true;

        player.setGold(gold-2);

        if (cartSpace >= 3) {
            player.setJewel(item+3);
        } else {
            player.setJewel(item+cartSpace);
        }

    }

    return canBuy;
}

// A cart manufacturare trades 3 cart spaces for 7 gold
bool CartM::canAct(Player &player){

    bool canBuy = false;
    int cart = player.getCart();
    int gold = player.getGold();

    if (gold>=7) {
        canBuy = true;
    }
    return canBuy;
}

bool CartM::action(Player &player) const{

    bool canBuy = false;
    int cart = player.getCart();
    int gold = player.getGold();

    if (gold>=7) {
        canBuy = true;

        player.setGold(gold-7);
        player.setCart(cart+3);
    }

    return canBuy;
}

// A small market trades 1 spice, 1 jewel and 1 fabric for 8 gold
bool Smarket::canAct(Player &player){

    bool canSell = false;
    int spice = player.getSpice();
    int jewel = player.getJewel();
    int fabric = player.getFabric();
    int gold = player.getGold();

    if ((spice>0)&&(jewel>0)&&(fabric>0)) {
        canSell = true;
    }

    return canSell;
}


bool Smarket::action(Player &player) const{

    bool canSell = false;
    int spice = player.getSpice();
    int jewel = player.getJewel();
    int fabric = player.getFabric();
    int gold = player.getGold();

    if ((spice>0)&&(jewel>0)&&(fabric>0)) {
        canSell = true;

        player.setGold(gold+8);
        player.setSpice(spice-1);
        player.setJewel(jewel-1);
        player.setFabric(fabric-1);
    }

    return canSell;
}

// A spcice market trades 3 spice for 6 gold
bool SPmarket::canAct(Player &player){

    bool canSell = false;
    int item = player.getSpice();
    int gold = player.getGold();

    if (item>=3) {
        canSell = true;
    }

    return canSell;
}

bool SPmarket::action(Player &player) const{

    bool canSell = false;
    int item = player.getSpice();
    int gold = player.getGold();

    if (item>=3) {
        canSell = true;

        player.setGold(gold+6);
        player.setSpice(item-3);
    }

    return canSell;
}

// A jewel market trades 3 jewels for 6 gold
bool Jmarket::canAct(Player &player){

    bool canSell = false;
    int item = player.getJewel();
    int gold = player.getGold();

    if (item>=3) {
        canSell = true;
    }
    return canSell;
}

bool Jmarket::action(Player &player) const{

    bool canSell = false;
    int item = player.getJewel();
    int gold = player.getGold();

    if (item>=3) {
        canSell = true;

        player.setGold(gold+6);
        player.setJewel(item-3);
    }

    return canSell;
}

// A fabric market trades 3 fabric for 6 gold
bool Fmarket::canAct(Player &player){

    bool canSell = false;
    int item = player.getFabric();
    int gold = player.getGold();

    if (item>=3) {
        canSell = true;
    }

    return canSell;
}

bool Fmarket::action(Player &player) const{

    bool canSell = false;
    int item = player.getFabric();
    int gold = player.getGold();

    if (item>=3) {
        canSell = true;

        player.setGold(gold+6);
        player.setFabric(item-3);
    }

    return canSell;
}

// A black market trades 0-5 goods at random for 1 gold
bool Bmarket::canAct(Player &player){

    bool canBuy = false;
    int gold = player.getGold();

    if (gold>=1) {
        canBuy = true;
    }

       return canBuy;
}

bool Bmarket::action(Player &player) const{

    bool canBuy = false;
    int gold = player.getGold();

    if (gold>=1) {
        canBuy = true;
        player.setGold(gold-1);
        int item;

        // Generate a random number between 0 and 4 to determine good recieved

        int good = rand() % 5;

        // Generate a random number between 0 and 5 to determine number of goods recieved

        int numGoods = rand() % 6;

        int cartSpace = player.getCartSpace();

        if (cartSpace<numGoods) {
            numGoods = cartSpace;
        }

        switch (good) {
            case 0:
                item = player.getSpice();
                player.setSpice(item+numGoods);
                break;

            case 1:
                item = player.getFabric();
                player.setFabric(item+numGoods);
                break;

            case 2:
                item = player.getJewel();
                player.setJewel(item+numGoods);
                break;

            case 3:
                item = player.getRuby();
                player.setRuby(item+numGoods);
                break;

            default:
                break;
        }
    }
       return canBuy;
}

// A casino trades 1 gold for a chance at a good
// 2:5 odds loosing
// 3:10 odds 2 gold
// 2:10 odds 3 gold
// 1:10 odds 10 gold
bool Casino::canAct(Player &player){

    bool canPlay = false;
    int gold = player.getGold();
    if (gold>=1) {

        canPlay = true;
    }
    return canPlay;
}

bool Casino::action(Player &player) const{

    bool canPlay = false;
    int gold = player.getGold();
    if (gold>=1) {

        canPlay = true;

        int randInt = rand() % 10;

        if (randInt>=9) {
            player.setGold(gold+10);
        }
        else if (randInt>=8) {
            player.setGold(gold+3);
        }
        else if (randInt>=7) {
            player.setGold(gold+2);
        }
    }

    return canPlay;
}

// A Gem Merchant trades first ruby for 12 gold, second for 13 gold...ect
bool Gmerch::canAct(Player &player){
    bool canBuy = false;
    int gold = player.getGold();
    int gemCost = 12 + getGems();
    int cartSpace = player.getCartSpace();

    if ((gold>=gemCost)&&cartSpace>=1){
        canBuy = true;
    }
    return canBuy;
}

bool Gmerch::action(Player &player) const{
    bool canBuy = false;
    int gold = player.getGold();
    int gemCost = 12 + getGems();
    int cartSpace = player.getCartSpace();

    if ((gold>=gemCost)&&cartSpace>=1){


        canBuy = true;

        player.setGold(gold-gemCost);
        player.setRuby(player.getRuby()+1);


    }


    return canBuy;
}

// A palace trades 5 fabric, 5 spice and 5 jewels for 1 ruby
bool Palace::canAct(Player &player){
    bool canBuy = false;
    int gems = player.getRuby();
    int spice = player.getSpice();
    int fabric = player.getFabric();
    int jewel = player.getJewel();

    if ((spice>=5)&&(fabric>=5)&&(jewel>=5)) {
        canBuy = true;
    }
    return canBuy;
}

bool Palace::action(Player &player) const{
    bool canBuy = false;
    int gems = player.getRuby();
    int spice = player.getSpice();
    int fabric = player.getFabric();
    int jewel = player.getJewel();

    if ((spice>=5)&&(fabric>=5)&&(jewel>=5)) {
        canBuy = true;
        player.setRuby(gems+1);
        player.setSpice(spice-5);
        player.setFabric(fabric-5);
        player.setJewel(jewel-5);
    }



    return canBuy;
}

///////////////////////////////////////////////
//
// Clone Functions
//
///////////////////////////////////////////////

Tile* Desert::clone() {
    return new Desert(*this);
}

Tile* Restaurant::clone() {
    return new Restaurant(*this);
}

Tile* Smerchant::clone() {
    return new Smerchant(*this);
}

Tile* Fmanu::clone() {
    return new Fmanu(*this);
}

Tile* Jeweler::clone() {
    return new Jeweler(*this);
}

Tile* CartM::clone() {
    return new CartM(*this);
}

Tile* Smarket::clone() {
    return new Smarket(*this);
}

Tile* SPmarket::clone() {
    return new SPmarket(*this);
}

Tile* Jmarket::clone() {
    return new Jmarket(*this);
}

Tile* Fmarket::clone() {
    return new Fmarket(*this);
}

Tile* Bmarket::clone() {
    return new Bmarket(*this);
}

Tile* Casino::clone() {
    return new Casino(*this);
}

Tile* Gmerch::clone() {
    return new Gmerch(*this);
}

Tile* Palace::clone() {
    return new Palace(*this);
}

