
#include "constants.h"

void runGame(SDL_Renderer *renderer)
{
    SDL_Texture *tileTextures[NUM_TILE_TYPES];
    TilemapDynamic tilemapDynamic;

    char str1[] = "pos: 7: 9 - tile: 0 - accion: 1";
    char str2[] = "pos: 7: 13 - tile: 1 - accion: 1";
    char str3[] = "pos: 5: 5 - tile: 2 - accion: 1";
    char str4[] = "pos: 7: 9 - tile: 0 - accion: 0";
    const char *cocoData = "speed:1000 - ID: 1 - accion: 1 - pos: ((2,3),(2,6),(2,7))";
    char score[] = "5000";

    // Cargar texturas para cada tipo de tile
    tileTextures[0] = LoadTexture(renderer, "./Assets/sprites/static/black.png");
    tileTextures[1] = LoadTexture(renderer, "./Assets/sprites/static/37-water.png");
    tileTextures[2] = LoadTexture(renderer, "./Assets/sprites/static/38-water2.png");
    tileTextures[3] = LoadTexture(renderer, "./Assets/sprites/static/41-grass1.png");
    tileTextures[4] = LoadTexture(renderer, "./Assets/sprites/static/42-grass2.png");
    tileTextures[5] = LoadTexture(renderer, "./Assets/sprites/static/43-grass3.png");
    tileTextures[6] = LoadTexture(renderer, "./Assets/sprites/static/39-dirt.png");
    tileTextures[7] = LoadTexture(renderer, "./Assets/sprites/static/57-vine1.png");
    tileTextures[8] = LoadTexture(renderer, "./Assets/sprites/static/58-vine2.png");
    tileTextures[10] = LoadTexture(renderer, "./Assets/sprites/static/36-longvine.png");
    tileTextures[11] = LoadTexture(renderer, "./Assets/sprites/static/40-brick.png");
    tileTextures[13] = LoadTexture(renderer, "./Assets/sprites/donkey_kong/16-tile000.png");
    tileTextures[14] = LoadTexture(renderer, "./Assets/sprites/donkey_jr/08-r004.png");

    int tilemap[MAP_WIDTH][MAP_HEIGHT] = {
        {0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2},
        {0, 0, 0, 11, 7, 8, 7, 7, 7, 7, 7, 8, 0, 0, 4, 2},
        {0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2},
        {0, 0, 0, 11, 8, 7, 8, 7, 8, 8, 7, 7, 0, 0, 4, 2},
        {0, 0, 0, 11, 0, 0, 0, 11, 0, 0, 11, 0, 0, 0, 4, 2},
        {0, 0, 0, 11, 0, 0, 0, 11, 0, 0, 11, 0, 0, 0, 5, 2},
        {0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 2},
        {0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 2},
        {0, 0, 0, 11, 7, 7, 8, 7, 7, 8, 0, 0, 3, 0, 0, 2},
        {0, 0, 0, 11, 11, 0, 0, 0, 0, 0, 0, 0, 4, 6, 6, 2},
        {0, 0, 0, 0, 11, 7, 7, 8, 7, 7, 0, 0, 4, 6, 6, 2},
        {0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 2},
        {0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 2},
        {0, 0, 0, 0, 11, 7, 7, 7, 7, 7, 8, 0, 0, 4, 6, 2},
        {0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 2},
        {0, 0, 0, 0, 11, 7, 7, 7, 7, 7, 0, 0, 3, 0, 0, 2},
        {0, 0, 0, 8, 7, 7, 7, 8, 11, 0, 0, 0, 4, 6, 6, 2},
        {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 5, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 3, 0, 0, 0, 2},
        {0, 0, 0, 8, 8, 7, 8, 7, 11, 0, 0, 4, 6, 6, 6, 2},
        {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 4, 6, 6, 6, 2},
        {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 5, 0, 0, 0, 2}

    };

    // manejo de eventos
    SDL_Event event;
    SDL_Rect characterRect;
    characterRect.x = 43; // Posición inicial del personaje
    characterRect.y = 559;
    characterRect.w = 43; // Ancho del personaje
    characterRect.h = 43;
    int prevX = characterRect.x;
    int prevY = characterRect.y;
    initializeTilemap(&tilemapDynamic);
    loadCharacterTextures(renderer);

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

        //                                   ___________________________________
        //__________________________________/  obtener coordenadas del personaje

        int characterTileX, characterTileY;
        getCharacterTileCoordinates(characterRect, &characterTileX, &characterTileY);
        // printf("Personaje en el tile (%d, %d)\n", characterTileX, characterTileY);

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

        //                                                 _________________________________
        //_______________________________________________/  Mover jugador

        moveCharacter(&characterRect, &prevX, &prevY, tilemap, renderer);
        // Dibujar el tilemap dinámico

        //                                                   __________________________________________________________
        //_________________________________________________/  Dibujar frutas  ej:(pos: 7:9 - tile: 1 - action: 1 o 0)

        setDynamicTile(&tilemapDynamic, renderer, str1);
        setDynamicTile(&tilemapDynamic, renderer, str2);
        setDynamicTile(&tilemapDynamic, renderer, str3);
        setDynamicTile(&tilemapDynamic, renderer, str4);

        //                                                    ___________________
        //__________________________________________________/  Dibujar Cocodrilos
        // addCocodrile(renderer, cocoData, tilemap);
        // actualizar ventana
        SDL_RenderPresent(renderer);
    }

    // Liberar texturas
    destroyCharacterTextures();
    destroyFruitsTextures();

    for (int i = 0; i < NUM_TILE_TYPES; i++)
    {
        SDL_DestroyTexture(tileTextures[i]);
    }
}