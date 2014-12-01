//
// player.h
// CSI2372 Final Project
//
// December 1, 2014
//
// Julien Turcotte-Novosedlik & Nicholas Burgel
//

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED


#include <string>

using namespace std;

class Player{
    
    // Instance variables
    string name;
    int gold;
    int ruby;
    int Spice;
    int fabric;
    int jewel;
    int cart;
    int food;
    int row;
    int col;
    
public:
    
    // Constructor
    Player(string i):gold(5),ruby(0),Spice(1), fabric(1), jewel(1), food(10), cart(9), name(i){};
    
    // Player functions
    bool canAct() const;
    bool pay(Player& player);
    void eat();
    void print();
    void add();
    bool takeTurn = false;
    void setName(string nam);
    bool getTurn();
    void setRow(int i);
    void setCol(int i);
    void setGold(int i);
    void setSpice(int i);
    void setFabric(int i);
    void setJewel(int i);
    void setFood(int i);
    void setCart(int i);
    void setRuby(int i);
    void setTurn(bool i);
    friend ostream& operator<<(ostream& s, const Player& p);
    friend istream& operator>>(istream& s,Player& p);
    string getName();
    string getConstName() const;
    int getGold();
    int getRuby();
    int getRow();
    int getCol();
    int getRow() const;
    int getCol() const;
    int getSpice();
    int getFabric();
    int getJewel();
    int getFood();
    int getCart();
    int getCartSpace();
};


#endif // PLAYER_H_INCLUDED
