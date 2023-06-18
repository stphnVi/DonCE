#include "constants.h"

SDL_Texture *tileTexturesFruits[NUM_TILE_TYPES];

void initializeTilemap(TilemapDynamic *tilemapDynamic)
{
    memset(tilemapDynamic->tiles, 0, sizeof(tilemapDynamic->tiles));
}

/*String a esperar por el server (pos: 7:9 - tile: 1 - action: 1 o 0)

tiles

-> Banano:1
-> Granada:2
-> manzana:3

*/

void setDynamicTile(TilemapDynamic *tilemapDynamic, SDL_Renderer *renderer, char *fruit)
{
    char *token;
    char *value;
    int y;
    int x;
    int tileID;
    int action;
    int cont = 0;

    // Buscar y leer los números utilizando sscanf()
    if (sscanf(strstr(fruit, "pos:") + 4, "%d:%d", &x, &y) != 2)
    {
        printf("Error al leer la posición.\n");
    }

    if (sscanf(strstr(fruit, "tile:") + 5, "%d", &tileID) != 1)
    {
        printf("Error al leer el tile.\n");
    }

    if (sscanf(strstr(fruit, "accion:") + 7, "%d", &action) != 1)
    {
        printf("Error al leer la acción.\n");
    }

    tileTexturesFruits[0] = LoadTexture(renderer, "./Assets/sprites/static/00-apple.png");
    tileTexturesFruits[1] = LoadTexture(renderer, "./Assets/sprites/static/01-banana.png");
    tileTexturesFruits[2] = LoadTexture(renderer, "./Assets/sprites/static/02-granade.png");

    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
    {
        if (action == 0)
        { // elimina tile
            tilemapDynamic->tiles[x][y] = -1;
        }
        else
        {
            tilemapDynamic->tiles[x][y] = tileID;
        }
    }

    SDL_Texture *texture = tileTexturesFruits[tileID];
    if (tileID >= 0 && texture != NULL)
    {
        SDL_Rect destRect;
        destRect.x = x * TILE_SIZE;
        destRect.y = y * TILE_SIZE;
        destRect.w = TILE_SIZE;
        destRect.h = TILE_SIZE;

        SDL_RenderCopy(renderer, texture, NULL, &destRect);
    }
}

void destroyFruitsTextures()
{
    for (int i = 0; i < NUM_TILE_TYPES; i++)
    {
        if (tileTexturesFruits[i] != NULL)
        {
            SDL_DestroyTexture(tileTexturesFruits[i]);
            tileTexturesFruits[i] = NULL;
        }
    }
}