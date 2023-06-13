#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "load_texture.h"

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
