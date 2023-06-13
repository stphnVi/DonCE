// user.h
#ifndef USER_H
#define USER_H
#define MAP_WIDTH 22
#define MAP_HEIGHT 16
#include <SDL2/SDL.h>

void moveCharacter(SDL_Rect *characterRect, int *prevX, int *prevY, int map[MAP_WIDTH][MAP_HEIGHT]);

#endif // USER_H
