//
// gameboard.cpp
// CSI2372 Final Project
//
// December 1, 2014
//
// Julien Turcotte-Novosedlik & Nicholas Burgel
//

#include <vector>
#include "gameboard.h"

/* Constructor that sets number of players
 * 
 * Requires inputs:
 *      int num: Number of players
 */
template<typename T, typename J, int R, int C> GameBoard<T, J, R, C>::GameBoard(int num){
    
    for(int i = 0; i < num; i++){
        players.push_back(J());
    }
    
}

/* Function to add a player to game
 *
 * Requires inputs:
 *      J& player: Player to be added
 *
 * Outputs:
 *      null
 */
template<typename T, typename J, int R, int C> void GameBoard<T, J, R, C>::addPlayer(J& player){
    
    players.push_back(player);
    
}

/* Function to print the coordinate of a specified tile
 *
 * Requires inputs:
 *      const T& tile: Tile to retrive coordinate of
 *      int *row: Pointer to row
 *      int *col: Pointer to column
 *
 * Outputs:
 *      void
 */
template<typename T, typename J, int R, int C> void GameBoard<T, J, R, C>::getCoordinate(const T& tile, int *row, int *col) const{
    
    tile.print();
    cout<<" ("<<*(row)<<","<<*(col)<<")"<<endl;
    
}

/* Function to add a specified tile a a specified coordinate
 *
 * Requires inputs:
 *      const T& tile: Tile to be added
 *      int row: row to add tile to
 *      int col: column to add tile to
 *
 * Outputs:
 *      null
 */
template<typename T, typename J, int R, int C> void GameBoard<T, J, R, C>::add(const T& tile, int row, int col){
    const T *t = &tile;
    gb[row][col]=t;
    
    
    
}

/* Reset a specified player
 *
 * Requires inputs:
 *      J player: Player to be reset
 *
 * Outputs:
 *      null
 */
template<typename T, typename J, int R, int C> void GameBoard<T, J, R, C>::setPlayer(J player){
    for(int i = 0; i < players.size(); i++){
        if(player.getName()==players[i].getName()){
            players.erase(players.begin()+i);
        }
    }
    players.push_back(player);
    
    
}

/* Function to retrive a tile from a specified coordinate
 *
 * Requires inputs:
 *      int row: row of tile to get
 *      int col: column of tile to get
 *
 * Outputs:
 *      const T&: reference to tile
 */
template<typename T, typename J, int R, int C> const T& GameBoard<T, J, R, C>::getTile(int row, int col) const{
    const T *t = gb[row][col];
    return *(t);
    
}

/* Function to get players at a specified tile
 *
 * Requires inputs:
 *      const T& tile: Tile to check for players
 *
 * Outputs:
 *      std::vector<J>: vector of players at tile
 */
template<typename T, typename J, int R, int C> std::vector<J> GameBoard<T, J, R, C>::getPlayers(const T& tile) const{
    vector<J> tilePlayers;
    for(int i=0; i < players.size(); i++){
        int row = tile.getRow();
        int col = tile.getCol();
        if(row==players[i].getRow()&&col==players[i].getCol()){
            tilePlayers.push_back(players[i]);
        }
    }
    return tilePlayers;
    
}

/* Function to get the tile a specified player is on
 *
 * Requires inputs:
 *      const std::string& playerName: name of player to get tile of
 *
 * Outputs:
 *      const T&: Tile that player is on
 */
template<typename T, typename J, int R, int C> const T& GameBoard<T, J, R, C>::getTile(const std::string& playerName) const{
    for(int i = 0; i < players.size(); i++){
        if(playerName==players[i].getConstName()){
            J p = players[i];
            int row = p.getRow();
            int col = p.getCol();
            return *gb[row][col];
        }
    }
    
    
}

/* Function to return the player of a specifed name
 *
 * Requires inputs:
 *      const std::string& playerName: name of player to be returned
 *
 * Outputs:
 *      J: player object
 */
template<typename T, typename J, int R, int C> J GameBoard<T, J, R, C>::getPlayer(const std::string& playerName){
    
    for(int i=0; i < players.size(); i++){
        
        if(playerName == players[i].getName()){
            J p = players[i];
            
            
            return p;
        }
        
    }
}

/* Function to check if player has won
 *
 * Requires inputs:
 *      const std::string& playerName: name of player to check for win
 *
 * Outputs:
 *      boolean: true if player has won
 */
template<typename T, typename J, int R, int C> bool GameBoard<T, J, R, C>::win(const std::string& playerName){
    J p = getPlayer(playerName);
    int ruby=p.getRuby();
    if(ruby==5){
        return true;
    }
    else{
        return false;
    }
}

/* Function to move a player up, down, right or left
 *
 * Requires inputs:
 *      enum Move move: direction of player movement
 *      const std::string& playerName: name of player to be moved
 *
 * Outputs:
 *      const T&: Tile the player was moved to
 */
template<typename T, typename J, int R, int C> const T& GameBoard<T, J, R, C>::move(enum Move move, const std::string& playerName){
    
    J p = getPlayer(playerName);
    outofbounds.setCol(-1);
    outofbounds.setRow(-1);
    
    int row, col;
    row = p.getRow();
    col = p.getCol();
    T t;
    switch(move){
        
        case Move::up:
            if(row-1>=0){
                p.setRow(row-1);
                setPlayer(p);
                return *gb[row-1][col];
            }
            else{
                cout<<"Move invalid. Unable to move up. Region out of bounds."<<endl;
                return outofbounds;
            }
            break;
        case Move::down:
            if(row+1<R){
                p.setRow(row+1);
                setPlayer(p);
                
                return *gb[row+1][col];
            }
            else{
                
                cout<<"Move invalid. Unable to move down. Region out of bounds."<<endl;
                return outofbounds;
                
            }
        case Move::left:
            if(col-1>=0){
                p.setCol(col-1);
                setPlayer(p);
                return *gb[row][col-1];
            }
            else{
                cout<<"Move invalid. Unable to move left. Region out of bounds."<<endl;
                return outofbounds;
            }
            
        case Move::right:
            if(col+1<C){
                p.setCol(col+1);
                setPlayer(p);
                return *gb[row][col+1];
            }
            else{
                cout<<"Move invalid. Unable to move right. Region out of bounds."<<endl;
                return outofbounds;
            }
            
    }
    
    
    
    
}

/* Function to retrive the movement input
 *
 * Requires inputs:
 *      istream& is: reference to inputstream
 *      Move& m: reference to set move being made
 *
 * Outputs:
 *      null
 */
istream& operator>> (istream& is, Move& m){
    string val;
    
    if(is>>val){
        if(val=="up"){
            m = Move::up;
        }
        else if(val=="down"){
            m = Move::down;
        }
        else if(val=="left"){
            m = Move::left;
        }
        else if(val=="right"){
            m = Move::right;
        }
        else{
            cout << "Invalid Selection" <<endl;
            cin >> m;
        }
    }
    return is;
}