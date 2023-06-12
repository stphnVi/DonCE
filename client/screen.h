#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>

SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *imagePath);
void DrawTile(SDL_Renderer *renderer, SDL_Texture *texture, int tileX, int tileY);
void runGame(SDL_Renderer *renderer);

#endif // SCREEN_H
