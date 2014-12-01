//
// gameboard.h
// CSI2372 Final Project
//
// December 1, 2014
//
// Julien Turcotte-Novosedlik & Nicholas Burgel
//

#ifndef GAMEBOARD_H_INCLUDED
#define GAMEBOARD_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "tile.h"
using namespace std;

enum Move {up, down, left, right};

template<typename T, typename J, int R, int C>
class GameBoard{
    T outofbounds;
    const T* gb[R][C];
    std::vector<J> players;
    
public:
    
    // Constructors
    GameBoard(){};
    GameBoard(int num);
    
    // Gameboard Functions
    void add(const T& tile, int row, int col);
    const T& getTile(int row, int col) const;
    void getCoordinate(const T &tile, int *row, int*col) const;
    void setPlayer(J player);
    J getPlayer(const std::string& playerName);
    const T& getTile(const std::string& playerName) const;
    std::vector<J> getPlayers(const T& tile) const;
    const T& move(enum Move move, const std::string& playerName);
    void addPlayer(J& player);
    void removePlayer(int i);
    bool win(const std::string& playerName);
    
    // Output stream for the gameboard
    friend ostream& operator<<(ostream& s, GameBoard& bg){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++)
                
                s << *bg.gb[i][j];
            
        }
        for(int i = 0; i<bg.players.size();i++){
            s << bg.players[i];
        }
        
        return s;
    }
    friend istream& operator>>(istream& s, GameBoard& bg){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                T t2;
                const T* t3=&t2;
                s >> t2;
                
                
            }
        }
        for(int i = 0; i <bg.players.size();i++){
            
            s >> bg.players[i];
            
            
        }
        //cout<<k<<endl;
        return s;
    }
    
};

#endif // GAMEBOARD_H_INCLUDED
