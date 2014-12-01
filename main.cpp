//
// main.cpp
// CSI2372 Final Project
//
// December 1, 2014
//
// Julien Turcotte-Novosedlik & Nicholas Burgel
//

#include <iostream>
#include "gameboard.h"
#include "tilefactory.h"
#include "taketurn.h"
#include <limits>

using namespace std;

int main()
{
    vector<string> playerNames;
    const int n = 6;
    
    // Initialize the gameboard
    GameBoard<Tile, Player, n, n> game;
    TileFactory tf(n*n);
    Tile *t1;
    for (int i=0;i<n; i++){
        for (int j=0; j<n; j++){
            t1 = tf.next();
            t1->setRow(i);
            t1->setCol(j);
            game.add(*t1, i, j);
            
            
        }
    }
    
    
    // Get number of players
    cout << "Welcome to the Ruby Victory Board Game"<<endl;
    cout << "How Many Players Would Like To Play? ";
    bool play=true;
    int i;
    
    while(play){
        
        cin >> i;
        if(i<=0){
            cout<<"Please enter a number greater than 0:"<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if(cin.good()){
            
            play = false;
            
        }
        else{
            cout<<"Please enter a valid number:"<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    // Set Player's names
    bool unicName = true;
    for(int j=0; j<i; j++){
        cout << "Player "<<j+1<<"'s name: ";
        string n;
        cin >> n;
        for(int i = 0; i < playerNames.size(); i++){
            if(n == playerNames[i]){
                cout << "Player name taken! Choose another:"<<endl;
                unicName = false;
                
            }
        }
        
        // Only allow unique player names
        while(!unicName){
            cin >> n;
            for(int i = 0; i < playerNames.size(); i++){
                if(n == playerNames[i]){
                    cout << "Player name taken! Choose another:"<<endl;
                    
                }
                else{
                    unicName = true;
                }
                
            }
        }
        playerNames.push_back(n);
        Player p(n);
        
        p.setRow(0);
        p.setCol(0);
        
        game.addPlayer(p);
        
    }
    bool pause = false;
    bool saved = true;
    bool unpause = false;
    bool gameOn = true;
    string decision;
    bool decide = true;
    cout << "GAME START"<<endl;
    
    while(gameOn){
        for(auto pName : playerNames){
            /////////////////////////////PAUSE/////////////////////////////////////
            
            // Ask player to pause game
            while(decide){
                cout<<"Would you like to pause? [yes/no] ";
                cin>> decision;
                if(decision=="yes"){
                    pause=true;
                    decide = false;
                }
                else if(decision=="no"){
                    pause=false;
                    decide = false;
                }
                else{
                    cout<<"Invalid Selection. Available options [yes/no] "<<endl;
                    
                }
                
            }
            
            // Pause Actions
            while(pause){
                
                // Save Game
                if(saved){
                    saved = true;
                    ofstream myfile ("save.txt");
                    
                    if(myfile.is_open()){
                        myfile << game;
                        
                        myfile.close();
                        
                    }
                    else{
                        cout << "Unable to save to file";
                    }
                    decide = true;
                    
                    // Ask player to resume game
                    while(decide){
                        cout<<"Would you like to resume? [yes/no] ";
                        cin>> decision;
                        if(decision=="yes"){
                            pause=false;
                            decide = false;
                        }
                        else if(decision=="no"){
                            pause=true;
                            decide = false;
                        }
                        else{
                            cout<<"Invalid Selection. Available options [yes/no]"<<endl;
                            
                        }
                        
                    }
                    
                    if(!pause){
                        unpause = true;
                    }
                }
            }
            
            if(unpause){
                string line;
                ifstream myfile2 ("save.txt");
                if (myfile2.is_open())
                {
                    
                    
                    myfile2 >> game;
                    myfile2.close();
                }
                else{
                    cout << "Unable to save to file";
                }
                unpause = false;
            }
            decide = true;
            
            //////////////////////////MAIN LOOP//////////////////////////////////////
            cout<<"****************"<<endl;
            cout<<game.getPlayer(pName).getName()<<"'s TURN"<<endl;
            cout<<"****************"<<endl;
            cout<<"================"<<endl;
            cout<<"=Pre-Turn Stats="<<endl;
            cout<<"================"<<endl;
            
            game.getPlayer(pName).print();
            
            
            while(!takeTurn<n>(game, pName));{
                
                if(game.win(pName)){
                    cout<<"Player: "<<pName<<" WINS!"<<endl;
                    gameOn = false;
                    break;
                }
            }
        }
    }
    return 0;
}
