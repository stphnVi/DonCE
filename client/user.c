#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include "user.h"

void moveCharacter(SDL_Rect *characterRect, int *prevX, int *prevY)
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                if (characterRect->y - GRID_SIZE >= 0 && characterRect->y != *prevY)
                {
                    *prevY = characterRect->y;
                    characterRect->y -= GRID_SIZE;
                }
                break;

            case SDLK_DOWN:
                if (characterRect->y + GRID_SIZE <= 600 - characterRect->h && characterRect->y != *prevY)
                {
                    *prevY = characterRect->y;
                    characterRect->y += GRID_SIZE;
                }
                break;

            case SDLK_LEFT:
                if (characterRect->x - GRID_SIZE >= 0 && characterRect->x != *prevX)
                {
                    *prevX = characterRect->x;
                    characterRect->x -= GRID_SIZE;
                }
                break;

            case SDLK_RIGHT:
                if (characterRect->x + GRID_SIZE <= 1000 - characterRect->w && characterRect->x != *prevX)
                {
                    *prevX = characterRect->x;
                    characterRect->x += GRID_SIZE;
                }
                break;
            }
            break;

        case SDL_QUIT:
            exit(0);
            break;
        }
    }
}
