#ifndef TILEFACTORY_H_INCLUDED
#define TILEFACTORY_H_INCLUDED

//////////////////////////////TF//////////////////////////////

#include <iostream>
#include <math.h>
#include <vector>
#include <cstdlib>
#include "tile.h"

using namespace std;


class TileFactory{

    int nTiles;

    vector<Tile*> tiles;

    vector<int> tilesIndex;

    public:

    TileFactory();
    TileFactory(int _nTiles);
    static TileFactory *get(int _nTiles);
    Tile* next();
    void print();
};



#endif // TILEFACTORY_H_INCLUDED
