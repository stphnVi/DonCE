#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_main.h>
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

// Función para inicializar el Tilemap
void initializeTilemap(TilemapDynamic *tilemap);

// Función para establecer un tile en el Tilemap
void setDynamicTile(TilemapDynamic *tilemap, SDL_Renderer *renderer, int x, int y, int tile);

void printTilemap(TilemapDynamic *tilemapDynamic);

#endif // CONSTANTS_H

#endif // USER_H

#endif // SCREEN_H

#endif // LOAD_TEXTURE_H