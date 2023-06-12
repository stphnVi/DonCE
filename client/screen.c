#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "screen.h"

#define TILE_SIZE 32
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *imagePath)
{
    SDL_Surface *surface = IMG_Load(imagePath);
    if (surface == NULL)
    {
        printf("Error loading image: %s\n", IMG_GetError());
        return NULL;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL)
    {
        printf("Error creating texture: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return NULL;
    }

    SDL_FreeSurface(surface);
    return texture;
}

void DrawTile(SDL_Renderer *renderer, SDL_Texture *texture, int tileX, int tileY)
{
    SDL_Rect srcRect = {0, 0, TILE_SIZE, TILE_SIZE};
    SDL_Rect destRect = {tileX * TILE_SIZE, tileY * TILE_SIZE, TILE_SIZE, TILE_SIZE};
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}

void runGame(SDL_Renderer *renderer)
{
    SDL_Texture *mapTexture = LoadTexture(renderer, "DKMap.bmp");
    if (mapTexture == NULL)
    {
        return;
    }

    int map[MAP_WIDTH][MAP_HEIGHT] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

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

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);

        // Dibujar el tilemap
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            for (int x = 0; x < MAP_WIDTH; x++)
            {
                int tileIndex = map[x][y];
                DrawTile(renderer, mapTexture, x, y);
            }
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(mapTexture);
}
