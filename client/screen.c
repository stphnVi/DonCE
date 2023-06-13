#include <SDL2/SDL.h>
#include "screen.h"
#include "load_texture.h"

#define TILE_SIZE 43
#define MAP_WIDTH 22
#define MAP_HEIGHT 16
#define NUM_TILE_TYPES 20

void runGame(SDL_Renderer *renderer)
{
    SDL_Texture *tileTextures[NUM_TILE_TYPES];

    // Cargar texturas para cada tipo de tile

    tileTextures[0] = LoadTexture(renderer, "./Assets/sprites/static/39-dirt.png");
    tileTextures[1] = LoadTexture(renderer, "./Assets/sprites/static/37-water.png");
    tileTextures[2] = LoadTexture(renderer, "./Assets/sprites/static/38-water2.png");
    tileTextures[3] = LoadTexture(renderer, "./Assets/sprites/static/41-grass1.png");
    tileTextures[4] = LoadTexture(renderer, "./Assets/sprites/static/42-grass2.png");
    tileTextures[5] = LoadTexture(renderer, "./Assets/sprites/static/43-grass3.png");
    tileTextures[6] = LoadTexture(renderer, "./Assets/sprites/static/black.png");

    tileTextures[7] = LoadTexture(renderer, "./Assets/sprites/static/57-vine1.png");
    tileTextures[8] = LoadTexture(renderer, "./Assets/sprites/static/58-vine2.png");
    tileTextures[10] = LoadTexture(renderer, "./Assets/sprites/static/36-longvine.png");
    tileTextures[11] = LoadTexture(renderer, "./Assets/sprites/static/40-brick.png");

    tileTextures[13] = LoadTexture(renderer, "./Assets/sprites/donkey_kong/16-tile000.png");
    tileTextures[14] = LoadTexture(renderer, "./Assets/sprites/donkey_jr/08-r004.png");

    int tilemap[MAP_WIDTH][MAP_HEIGHT] = {
        {6, 6, 6, 11, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 2},
        {6, 6, 6, 11, 7, 8, 7, 7, 7, 7, 7, 8, 7, 6, 4, 2},
        {6, 6, 13, 11, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 2},
        {6, 6, 6, 11, 8, 7, 8, 7, 8, 8, 7, 7, 7, 6, 4, 2},
        {6, 6, 6, 11, 6, 6, 6, 11, 6, 6, 11, 6, 6, 6, 4, 2},
        {6, 6, 14, 11, 6, 6, 6, 11, 7, 8, 11, 6, 6, 6, 5, 2},
        {6, 6, 6, 11, 6, 6, 6, 6, 6, 6, 11, 6, 6, 6, 6, 2},
        {6, 6, 6, 11, 6, 6, 6, 6, 6, 6, 11, 6, 6, 6, 6, 2},
        {6, 6, 6, 11, 7, 7, 8, 7, 7, 8, 7, 6, 3, 6, 6, 2},
        {6, 6, 6, 11, 11, 6, 6, 6, 6, 6, 6, 6, 4, 0, 0, 2},
        {6, 6, 6, 6, 11, 7, 7, 8, 7, 7, 8, 6, 4, 0, 0, 2},
        {6, 6, 6, 6, 11, 6, 6, 6, 6, 6, 6, 6, 5, 6, 6, 2},
        {6, 6, 6, 6, 11, 7, 7, 7, 7, 7, 8, 7, 6, 3, 6, 2},
        {6, 6, 6, 6, 11, 6, 6, 6, 6, 6, 6, 6, 6, 4, 0, 2},
        {6, 6, 6, 6, 11, 6, 6, 6, 6, 6, 6, 6, 6, 5, 6, 2},
        {6, 6, 6, 6, 11, 7, 7, 7, 7, 7, 8, 6, 3, 6, 6, 2},
        {6, 6, 6, 8, 7, 7, 7, 8, 11, 6, 6, 6, 4, 0, 0, 2},
        {6, 6, 6, 6, 6, 6, 6, 6, 11, 6, 6, 6, 5, 6, 6, 2},
        {6, 6, 6, 6, 6, 6, 6, 6, 11, 8, 6, 3, 6, 6, 6, 2},
        {6, 6, 6, 8, 8, 7, 8, 7, 11, 6, 6, 4, 0, 0, 0, 2},
        {6, 6, 6, 6, 6, 6, 6, 6, 11, 6, 6, 4, 0, 0, 0, 2},
        {6, 6, 6, 6, 6, 6, 6, 6, 11, 6, 6, 5, 6, 6, 6, 2},
    };

    SDL_Event event;
    int quit = 0;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Dibujar el tilemap
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            for (int x = 0; x < MAP_WIDTH; x++)
            {
                int tileIndex = tilemap[x][y];

                // Calcular las coordenadas de destino del tile
                int tilePosX = x * TILE_SIZE;
                int tilePosY = y * TILE_SIZE;

                // Dibujar el tile en el renderer
                SDL_Rect destRect = {tilePosX, tilePosY, TILE_SIZE, TILE_SIZE};
                SDL_RenderCopy(renderer, tileTextures[tileIndex], NULL, &destRect);
            }
        }

        SDL_RenderPresent(renderer);
    }

    // Liberar texturas
    for (int i = 0; i < NUM_TILE_TYPES; i++)
    {
        SDL_DestroyTexture(tileTextures[i]);
    }
}
