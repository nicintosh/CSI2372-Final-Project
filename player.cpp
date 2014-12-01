//
// player.cpp
// CSI2372 Final Project
//
// December 1, 2014
//
// Julien Turcotte-Novosedlik & Nicholas Burgel
//

#include <iostream>
#include <string>
#include "player.h"


using namespace std;

/* Function to determine if player can move
 *
 * Requires inputs:
 *      null
 *
 * Outputs:
 *      boolean: true if player has food
 */
bool Player::canAct() const{
    if(food > 0){
        return true;
    }
    
    else{
        
        return false;
        
    }
    
}

/* Function to set players turn to active
 *
 * Requires inputs:
 *      bool i: set turn to active
 *
 * Outputs:
 *      null
 */
void Player::setTurn(bool i){
    takeTurn = i;
}

/* Function to see if it is players turn
 *
 * Requires inputs:
 *      null
 *
 * Outputs:
 *      boolean: true if it is players turn
 */
bool Player::getTurn(){
    return takeTurn;
}

/* Function to transfer 1 gold between players
 *
 * Requires inputs:
 *      Player& player: reference to player recieving gold
 *
 * Outputs:
 *      boolean: true if player has enough gold
 */
bool Player::pay(Player& player){
    
    if(gold > 0){
        
        gold--;
        player.add();
        return true;
        
    }
    
    else{
        
        return false;
        
    }
    
}

/* Function to add 1 gold to player
 *
 * Requires inputs:
 *      null
 *
 * Outputs:
 *      null
 */
void Player::add(){
    gold++;
}

/* Function to reduce players food
 *
 * Requires inputs:
 *      null
 *
 * Outputs:
 *      null
 */
void Player::eat(){
    
    if(food > 0){
        
        food--;
        
    }
    
}

/* Function to create output stream of current player stats
 *
 * Requires inputs:
 *      ostream& s: reference to output stream
 *      const Player& p: reference to player
 *
 * Outputs:
 *      ostream& reference to outputstream
 */
ostream& operator<<(ostream& s, const Player& p){
    
    s<< p.name << " "
    << p.gold << " "
    <<p.ruby << " "
    <<p.Spice << " "
    <<p.fabric << " "
    <<p.jewel << " "
    <<p.cart<< " "
    <<p.food << " "
    <<p.row << " "
    <<p.col<<"\n";
    return s;
    
}

/* Function to set player stats from input stream
 *
 * Requires inputs:
 *      istream& s: reference to inputstream
 *      Player& p: player to set stats to
 *
 * Outputs:
 *      istream&: reference to inputstream
 */
istream& operator>>(istream& s, Player& p){
    
    s >> p.name
    >> p.gold
    >> p.ruby
    >> p.Spice
    >> p.fabric
    >> p.jewel
    >> p.cart
    >> p.food
    >> p.row
    >> p.col;
    return s;
}

// Functions to get instance variable content
string Player::getName(){
    return name;
}
string Player::getConstName() const{
    return name;
}
int Player::getRow(){
    return row;
}
int Player::getRow() const{
    return row;
}
int Player::getFabric(){
    return fabric;
}
int Player::getFood(){
    return food;
}
int Player::getGold(){
    return gold;
}
int Player::getJewel(){
    return jewel;
}
int Player::getSpice(){
    return Spice;
}
int Player::getCol(){
    return col;
}
int Player::getCol() const{
    return col;
}
int Player::getCartSpace(){
    return cart-fabric-Spice-jewel-ruby;
}
int Player::getCart(){
    return cart;
}
int Player::getRuby(){
    return ruby;
}

//Functions to set instance variable values
void Player::setCart(int i){
    cart = i;
}
void Player::setCol(int i){
    col = i;
}
void Player::setRow(int i){
    row = i;
}
void Player::setGold(int i){
    gold = i;
}
void Player::setFabric(int i){
    fabric = i;
}
void Player::setFood(int i){
    food = i;
}
void Player::setJewel(int i){
    jewel = i;
}
void Player::setSpice(int i){
    Spice = i;
}
void Player::setName(string nam){
    name = nam;
}
void Player::setRuby(int i){
    ruby = i;
}

// Function to print instance variable content
void Player::print(){
    cout<<"Gold: "<< gold << endl;
    cout<<"Ruby: "<< ruby << endl;
    cout<<"Spice: "<< Spice << endl;
    cout<<"Fabric: "<< fabric << endl;
    cout<<"Jewel: "<< jewel << endl;
    cout<<"Cart Size: " <<cart << endl;
    cout<<"Food: "<< food << endl;
    cout<<"Cart Space: "<<cart - Spice - fabric - ruby - jewel << endl;
    
    
}
