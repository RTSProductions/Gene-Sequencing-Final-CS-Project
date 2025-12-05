#ifndef TILE_H
#define TILE_H

struct Tile 
{
    char color;
    int playerOccupying = 0;
};

// types:
// orange - O (finish)
// gray - Y (start)
// green - G
// blue - B
// pink - P
// brown - T
// red - R
// purple - U

// what the player types mean
// 0 - no one
// 1 - player one is on the tile
// 2 - player two is on the tile
// 3 both players are on the tile




#endif