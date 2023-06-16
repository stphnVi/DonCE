#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_main.h>
#include <stdio.h>

// LOAD_TEXTURE_H
#ifndef LOAD_TEXTURE_H
#define LOAD_TEXTURE_H

SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *imagePath);

// SCREEN_H
#ifndef SCREEN_H
#define SCREEN_H
#define TILE_SIZE 43
#define MAP_WIDTH 22
#define MAP_HEIGHT 16
#define NUM_TILE_TYPES 20

void runGame(SDL_Renderer *renderer);

// USER_H
#ifndef USER_H
#define USER_H

void moveCharacter(SDL_Rect *characterRect, int *prevX, int *prevY, int map[MAP_WIDTH][MAP_HEIGHT]);
int getTileCoordinates(int position);
void getCharacterTileCoordinates(SDL_Rect characterRect, int *tileX, int *tileY);
#endif // USER_H

#endif // SCREEN_H

#endif // LOAD_TEXTURE_H