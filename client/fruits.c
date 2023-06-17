#include "constants.h"

SDL_Texture *tileTextures[NUM_TILE_TYPES];

void initializeTilemap(TilemapDynamic *tilemapDynamic)
{
    memset(tilemapDynamic->tiles, 0, sizeof(tilemapDynamic->tiles));
}

/*String a esperar por el server (pos: 7,9 - tile: 1 - action: 1 o 0)

tiles

-> Banano:1
-> Nispero:2
-> manzana:3

*/

void setDynamicTile(TilemapDynamic *tilemapDynamic, SDL_Renderer *renderer, int x, int y, int tileID)
{
    tileTextures[0] = LoadTexture(renderer, "./Assets/sprites/static/00-apple.png");
    tileTextures[1] = LoadTexture(renderer, "./Assets/sprites/static/01-banana.png");
    tileTextures[2] = LoadTexture(renderer, "./Assets/sprites/static/02-berries.png");

    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
    {
        tilemapDynamic->tiles[x][y] = tileID;
    }

    SDL_Texture *texture = tileTextures[tileID];
    if (tileID >= 0 && texture != NULL)
    {
        SDL_Rect destRect;
        destRect.x = x * TILE_SIZE;
        destRect.y = y * TILE_SIZE;
        destRect.w = TILE_SIZE;
        destRect.h = TILE_SIZE;

        SDL_RenderCopy(renderer, texture, NULL, &destRect);
    }

    // printf("Entra a dynamicTile: %s\n");
}

/*
void printTilemap(TilemapDynamic *tilemapDynamic)
{
    for (int i = 0; i < MAP_WIDTH; i++)
    {
        for (int j = 0; j < MAP_HEIGHT; j++)
        {
            printf("Entra  %s\n", tilemapDynamic->tiles[5][5]);
            // printf("%d ", tilemapDynamic->tiles[5][5]);
        }
        printf("\n");
    }
}


void setTile(TilemapDynamic *tilemap, int x, int y, int tile)
{
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
    {
        // Cargar la imagen PNG
        SDL_Surface *tileSurface = IMG_Load("./Assets/sprites/static/00-apple.png");
        if (tileSurface == NULL)
        {
            printf("No se pudo cargar la imagen: %s\n", SDL_GetError());
            return;
        }

        // Crear una textura a partir de la superficie cargada
        SDL_Texture *tileTexture = SDL_CreateTextureFromSurface(renderer, tileSurface);
        if (tileTexture == NULL)
        {
            printf("No se pudo crear la textura: %s\n", SDL_GetError());
            SDL_FreeSurface(tileSurface);
            return;
        }

        // Liberar la superficie, ya que no la necesitamos más
        SDL_FreeSurface(tileSurface);

        // Asignar la textura a la posición del tilemap
        tilemap->tiles[x][y] = tile;
    }
}


int getTile(TilemapMirror *tilemapMirror, int x, int y)
{
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
    {
        return tilemapMirror->tiles[x][y];
    }
    return -1;
}



*/