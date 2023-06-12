#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define TILE_SIZE 32

SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *imagePath);

int main(int argc, char *argv[])
{
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_GetError();
        return 1;
    }

    // Crear ventana
    SDL_Window *window = SDL_CreateWindow("Tilemap Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        SDL_GetError();
        return 1;
    }

    // Crear renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        SDL_GetError();
        return 1;
    }

    // Cargar textura del BMP
    SDL_Texture *texture = LoadTexture(renderer, "./DKMap.bmp");
    if (texture == NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    int tilemap[MAP_WIDTH][MAP_HEIGHT] = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};

    // Limpiar la pantalla
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Dibujar el tilemap
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            int tileIndex = tilemap[x][y];

            // Calcular las coordenadas de destino del tile
            SDL_Rect destRect = {x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE};

            // Dibujar el tile en el renderer
            SDL_RenderCopy(renderer, texture, NULL, &destRect);
        }
    }

    // Presentar el renderer en la ventana
    SDL_RenderPresent(renderer);

    SDL_Delay(2000); // Esperar 2 segundos

    // Liberar recursos
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *imagePath)
{
    SDL_Surface *surface = IMG_Load(imagePath);
    if (surface == NULL)
    {
        IMG_GetError();
        return NULL;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL)
    {
        SDL_GetError();
        SDL_FreeSurface(surface);
        return NULL;
    }

    SDL_FreeSurface(surface);
    return texture;
}