#include "tilefactory.h"





TileFactory *TileFactory::get(int _nTiles){
        static TileFactory tf(_nTiles);
        return &tf;
    };

TileFactory::TileFactory(int _nTiles){
    nTiles = floor(_nTiles/14);
    int desert = _nTiles - (nTiles*13);

    for(int i = 0; i < nTiles; i++){
        tiles.push_back(new Restaurant());
}

for(int i = 0; i < nTiles; i++){
    tiles.push_back(new Smerchant());
}

for(int i = 0; i < nTiles; i++){
tiles.push_back(new Fmanu());
}

for(int i = 0; i < nTiles; i++){
tiles.push_back(new Jeweler());
}

for(int i = 0; i < nTiles; i++){
tiles.push_back(new CartM());
}

for(int i = 0; i < nTiles; i++){
tiles.push_back(new Smarket());
}

for(int i = 0; i < nTiles; i++){
tiles.push_back(new SPmarket());
}

for(int i = 0; i < nTiles; i++){
tiles.push_back(new Jmarket());
}

for(int i = 0; i < nTiles; i++){
tiles.push_back(new Fmarket());
}

for(int i = 0; i < nTiles; i++){
tiles.push_back(new Bmarket());
}

for(int i = 0; i < nTiles; i++){
tiles.push_back(new Casino());
}

for(int i = 0; i < nTiles; i++){
tiles.push_back(new Gmerch());
}

for(int i = 0; i < nTiles; i++){
tiles.push_back(new Palace());
}

for(int i = 0; i < desert; i++){
tiles.push_back(new Desert());
}

for(int i=0; i < _nTiles; i++){
tilesIndex.push_back(i);
}

};

Tile* TileFactory::next(){

    bool flag = true;
    int index;
    int value;

    index = rand()%tilesIndex.size();
    value = tilesIndex[index];
    tilesIndex.erase(tilesIndex.begin()+index);

return tiles[value];

}

void TileFactory::print(){

cout<< nTiles << endl;

}
