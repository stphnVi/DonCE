#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_main.h>
#include <string.h>
#include <stdio.h>

// LOAD_TEXTURE
#ifndef LOAD_TEXTURE_H
#define LOAD_TEXTURE_H

SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *imagePath);

// SCREEN - tilemaps
#ifndef SCREEN_H
#define SCREEN_H
#define TILE_SIZE 43
#define MAP_WIDTH 22
#define MAP_HEIGHT 16
#define NUM_TILE_TYPES 30

void runGame(SDL_Renderer *renderer);

int tilemap[MAP_WIDTH][MAP_HEIGHT] = {
    {0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2},
    {0, 0, 0, 11, 7, 8, 7, 7, 7, 7, 7, 8, 7, 0, 4, 2},
    {0, 0, 13, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2},
    {0, 0, 0, 11, 8, 7, 8, 7, 8, 8, 7, 7, 7, 0, 4, 2},
    {0, 0, 0, 11, 0, 0, 0, 11, 0, 0, 11, 0, 0, 0, 4, 2},
    {0, 0, 14, 11, 0, 0, 0, 11, 7, 8, 11, 0, 0, 0, 5, 2},
    {0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 2},
    {0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 2},
    {0, 0, 0, 11, 7, 7, 8, 7, 7, 8, 7, 0, 3, 0, 0, 2},
    {0, 0, 0, 11, 11, 0, 0, 0, 0, 0, 0, 0, 4, 6, 6, 2},
    {0, 0, 0, 0, 11, 7, 7, 8, 7, 7, 8, 0, 4, 6, 6, 2},
    {0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 2},
    {0, 0, 0, 0, 11, 7, 7, 7, 7, 7, 8, 7, 0, 3, 0, 2},
    {0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 2},
    {0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 2},
    {0, 0, 0, 0, 11, 7, 7, 7, 7, 7, 8, 0, 3, 0, 0, 2},
    {0, 0, 0, 8, 7, 7, 7, 8, 11, 0, 0, 0, 4, 6, 6, 2},
    {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 5, 0, 0, 2},
    {0, 0, 0, 0, 0, 0, 0, 0, 11, 8, 0, 3, 0, 0, 0, 2},
    {0, 0, 0, 8, 8, 7, 8, 7, 11, 0, 0, 4, 6, 6, 6, 2},
    {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 4, 6, 6, 6, 2},
    {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 5, 0, 0, 0, 2}

};

// USER
#ifndef USER_H
#define USER_H

void moveCharacter(SDL_Rect *characterRect, int *prevX, int *prevY, int map[MAP_WIDTH][MAP_HEIGHT]);
int getTileCoordinates(int position);
void getCharacterTileCoordinates(SDL_Rect characterRect, int *tileX, int *tileY);

// FRUITS

#ifndef CONSTANTS_H
#define CONSTANTS_H

// Estructura del Tilemap
typedef struct
{
    int tiles[MAP_WIDTH][MAP_HEIGHT];
} TilemapDynamic;

void initializeTilemap(TilemapDynamic *tilemap);
void setDynamicTile(TilemapDynamic *tilemap, SDL_Renderer *renderer, char *fruit);
void printTilemap(TilemapDynamic *tilemapDynamic);

// SCORE
#ifndef SCORE_HS
#define SCORE_H

void setScore(SDL_Renderer *renderer, char *fruit);

#endif

#endif // CONSTANTS_H

#endif // USER_H

#endif // SCREEN_H

#endif // LOAD_TEXTURE_H