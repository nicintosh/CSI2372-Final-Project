//
// taketurn.h
// CSI2372 Final Project
//
// December 1, 2014
//
// Julien Turcotte-Novosedlik & Nicholas Burgel
//

#ifndef TAKETURN_H_INCLUDED
#define TAKETURN_H_INCLUDED



template <const int N>
bool takeTurn(GameBoard<Tile, Player, N, N>&game, const std::string& pName){
try{
    bool valid = true;

    cout << "Current location: ";
    const string name = game.getTile(pName).getConstName();
    cout<<name<<" ("<<game.getPlayer(pName).getRow()<<","<<game.getPlayer(pName).getCol()<<") "<<endl;
    cout << "Move where? Possible options are [up/down/left/right]: ";
    Move m;
    cin >> m;

    const Tile* t = &game.move(m, pName);
    Tile* action =  const_cast<Tile*>(t);
    Tile t2 = *(t);
    while(valid){
        if(t2.getCol()==-1){
            cout << "Move where? ";
            Move m;
            cin >> m;
            t = &game.move(m, pName);
            t2 = *(t);
        }
        else{
            valid = false;
        }
    }
    Player j = game.getPlayer(pName);

    if(j.canAct()){

        int row = j.getRow();
        int col = j.getCol();
        int *r = &row;
        int *c = &col;
        game.getCoordinate(t2, r, c);

        bool makeAction;
        string decision;
        bool decide=true;

        if(action->canAct(j)){

            while(decide){
                cout<<"Take Action? [yes/no]";
                cin>> decision;
                if(decision=="yes"){
                    makeAction=true;
                    decide = false;
                }
                else if(decision=="no"){
                    makeAction=false;
                    decide = false;
                }
                else{
                    cout<<"Invalid Selection. Available options [yes/no]"<<endl;

                }

            }
        }
        else{
            cout<<"No valid action available"<<endl;
            cout<<"Ending turn"<<endl;
            makeAction = false;
        }
        if(makeAction){
            vector<Player> opL = game.getPlayers(*(t));
            if (j.getGold() >= opL.size()&&opL.size()>1){

                for (auto op : opL){
                    if(j.getName()!=op.getName()){
                    j.pay(op);
                    game.setPlayer(op);
                    }

              }
            }
            j.eat();
            t->action(j);

            string test = t2.getName();
            if(test=="Gem Merchant"){
              Tile *t3 = const_cast<Tile*>(t);
              Gmerch *merch = dynamic_cast<Gmerch*>(t3);
              merch->incGems();

            }
            game.setPlayer(j);
            }
        }

cout<<"================="<<endl;
cout<<"=Post-Turn Stats="<<endl;
cout<<"================="<<endl;
j.print();

return true;
}
catch ( std::istream::failure e ) {
    cout<< "Incorrect key pressed";
    cin.clear();
}

return false;
}


#endif // TAKETURN_H_INCLUDED
