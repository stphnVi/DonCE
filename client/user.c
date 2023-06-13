#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include "user.h"
#define TILE_SIZE 43

// Incluir el archivo con las constantes del tilemap
// ...

void moveCharacter(SDL_Rect *characterRect, int *prevX, int *prevY, int map[MAP_WIDTH][MAP_HEIGHT])
{
    // Guardar las coordenadas actuales del personaje

    *prevX = characterRect->x;
    *prevY = characterRect->y;

    // Obtener la tecla presionada
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);

    // Mover el personaje tile por tile en función de la tecla presionada
    int moveSpeed = TILE_SIZE / 10;
    if (keystate[SDL_SCANCODE_UP] && characterRect->y > 0)
    {
        printf("tecla up: %d\n", characterRect->y);
        if (map[characterRect->x / TILE_SIZE][(characterRect->y - TILE_SIZE) / TILE_SIZE] == 0)
        {
            characterRect->y -= TILE_SIZE;
        }
    }
    else if (keystate[SDL_SCANCODE_DOWN] && characterRect->y < (MAP_HEIGHT - 1) * TILE_SIZE)
    {
        printf("tecla down: %d\n", characterRect->y);
        if (map[characterRect->x / TILE_SIZE][(characterRect->y + TILE_SIZE) / TILE_SIZE] == 0)
        {

            characterRect->y += TILE_SIZE;
        }
    }
    else if (keystate[SDL_SCANCODE_LEFT] && characterRect->x > 0)
    {
        if (map[(characterRect->x - TILE_SIZE) / TILE_SIZE][characterRect->y / TILE_SIZE] == 0)
        {
            characterRect->x -= TILE_SIZE;
        }
    }
    else if (keystate[SDL_SCANCODE_RIGHT] && characterRect->x < (MAP_WIDTH - 1) * TILE_SIZE)
    {
        if (map[(characterRect->x + TILE_SIZE) / TILE_SIZE][characterRect->y / TILE_SIZE] == 0)
        {
            characterRect->x += TILE_SIZE;
        }
    }
}
