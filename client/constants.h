// SCREEN - tilemaps
#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include <stdio.h>

#define TILE_SIZE 43
#define MAP_WIDTH 22
#define MAP_HEIGHT 16
#define NUM_TILE_TYPES 45

void runGame(SDL_Renderer *renderer);

#endif // SCREEN_H

// USER
#ifndef USER_H
#define USER_H

void moveCharacter(SDL_Rect *characterRect, int *prevX, int *prevY, int map[MAP_WIDTH][MAP_HEIGHT], SDL_Renderer *renderer);
int getTileCoordinates(int position);
void getCharacterTileCoordinates(SDL_Rect characterRect, int *tileX, int *tileY);
void loadCharacterTextures(SDL_Renderer *renderer);
void destroyCharacterTextures();

#endif // USER_H

// LOAD_TEXTURE
#ifndef LOAD_TEXTURE_H
#define LOAD_TEXTURE_H

SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *imagePath);

#endif // LOAD_TEXTURE_H

// FRUITS
#ifndef CONSTANTS_H
#define CONSTANTS_H

// Estructura del Tilemap
typedef struct
{
    int tiles[MAP_WIDTH][MAP_HEIGHT];
} TilemapDynamic;

void initializeTilemap(TilemapDynamic *tilemapDynamic);
void destroyFruitsTextures();
void setDynamicTile(TilemapDynamic *tilemapDynamic, SDL_Renderer *renderer, char *fruit);
void printTilemap(TilemapDynamic *tilemapDynamic);

#endif // CONSTANTS_H

// SCORE
#ifndef SCORE_HS
#define SCORE_H

void setScore(SDL_Renderer *renderer, char *fruit);

#endif // SCORE_H

// COCODRILES
#ifndef COCODRILES_H
#define COCODRILES_H

void addCocodrile(SDL_Renderer *renderer, const char *cocoData, int map[MAP_WIDTH][MAP_HEIGHT]);
void parseCoordinates(const char *data, int **coordinates, int *numCoordinates);

#endif // COCODRILES_H
