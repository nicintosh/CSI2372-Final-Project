//
//  tile.h
//  CSI2372FinalProject
//
//  Created by Nick Burgel on 2014-11-24.
//  Copyright (c) 2014 Nick & Julien. All rights reserved.
//

#ifndef __CSI2372FinalProject__tile__
#define __CSI2372FinalProject__tile__

#include <stdio.h>
#include <iostream>
#include "player.h"
#include <typeinfo>
#include <cstdlib>
#include <string>
#include <vector>

class Tile{
string name;
string desc;
int row;
int col;
int gems=0;

public:
    Tile(){};
    Tile(string i, string j):name(i),desc(j){};
    virtual bool action( Player& player ) const;
    virtual Tile* clone();
    virtual bool canAct(Player& player);
    virtual ~Tile();
    bool operator==(const Tile &t);
    friend ostream& operator<<(ostream& s, const Tile& t);
    friend istream& operator>>(istream& s, Tile& t);
    void print() const{
        cout << name<<": "<<desc;
    }
    void setRow(int i){
        row = i;
    }
    void setCol(int i){
        col = i;
    }
    int getRow(){
        return row;
    }
    int getRow() const{
        return row;
    }
    int getCol(){
        return col;
    }
    int getCol() const{
        return col;
    }
    string getName(){
        return name;
    }
    string getConstName() const{
        return name;
    }
    void incGems(){
    gems++;
    }
    int getGems() const{
    return gems;
    }
};

class Desert: public Tile{
string name;
public:
    Desert():Tile("Desert","No Actions"){};
    bool action(Player& player) const override;
    Tile* clone();
    bool canAct(Player& player);
};

class Restaurant: public Tile{

public:
    Restaurant():Tile("Restaurant","Restores food to 10"){};
    bool action(Player& player) const;
    Tile* clone();
    bool canAct(Player& player);
};

class Smerchant: public Tile{

public:
    Smerchant():Tile("Spice Merchant","Purchase 3 sacks(or less) of spices for 2 gold"){};
    bool action(Player& player) const override;
    Tile* clone();
    bool canAct(Player& player);
};

class Fmanu: public Tile{

public:
    Fmanu():Tile("Fabric Manufacturer","Purchase 3 rolls(or less) of fabric for 2 gold"){};
    bool action(Player& player) const;
    Tile* clone();
    bool canAct(Player& player);
};

class Jeweler: public Tile{

public:
    Jeweler():Tile("Jeweler","Purchase 3 pieces(or less) of jewelry for 2 gold"){};
    bool action(Player& player) const;
    Tile* clone();
    bool canAct(Player& player);
};

class CartM: public Tile{

public:
    CartM():Tile("Cart Manufacturer","Increase capacity of cart for 7 gold"){};
    bool action(Player& player) const;
    Tile* clone();
    bool canAct(Player& player);
};

class Smarket: public Tile{

public:
    Smarket():Tile("Small Market","Sell 1 roll of fabric, 1 jewel and 1 sack of spices for 8 gold"){};
    bool action(Player& player) const;
    Tile* clone();
    bool canAct(Player& player);
};

class SPmarket: public Tile{

public:
    SPmarket():Tile("Spice Market","Sell 3 sacks of spices for 6 gold"){};
    bool action(Player& player) const;
    Tile* clone();
    bool canAct(Player& player);
};

class Jmarket: public Tile{

public:
    Jmarket():Tile("Jewel Market","Sell 3 jewelry for 6 gold"){};
    bool action(Player& player) const;
    Tile* clone();
    bool canAct(Player& player);

};

class Fmarket: public Tile{

public:
    Fmarket():Tile("Fabric Market","Sell 3 rolls of fabric for 6 gold"){};
    bool action(Player& player) const;
    Tile* clone();
    bool canAct(Player& player);
};

class Bmarket: public Tile{

public:
    Bmarket():Tile("Black Market","Get 0-5 random items for 1 gold"){};
    bool action(Player& player) const;
    Tile* clone();
    bool canAct(Player& player);
};

class Casino: public Tile{

public:
    Casino():Tile("Casino","Gamble for 1 gold. 1/10 chance to win 10 gold, 2/10 chance to get 3 gold, 3/10 chance to get 2 gold"){};
    bool action(Player& player) const;
    Tile* clone();
    bool canAct(Player& player);
};

class Gmerch: public Tile{

public:
    Gmerch():Tile("Gem Merchant","Purchase a ruby for 12 gold. Price of ruby increases by 1 gold for each ruby sold"){};
    bool action(Player& player) const;
    Tile* clone();

    bool canAct(Player& player);

};

class Palace: public Tile{

public:
    Palace():Tile("Palace","Trade 5 fabric, jewels and spices for a ruby"){};
    bool action(Player& player) const;
    Tile* clone();
    bool canAct(Player& player);
};

#endif /* defined(__CSI2372FinalProject__tile__) */
