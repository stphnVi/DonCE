#include "constants.h"
#include "src/texture.h"
#include <unistd.h>

SDL_Texture *characterTexture[NUM_TILE_TYPES];
int movementState = 0;
int dCount = 0;
int pTile = 0;

void loadCharacterTextures(SDL_Renderer *renderer)
{
    // derecha
    characterTexture[0] = LoadTexture(renderer, "./Assets/sprites/donkey_jr/05-r001-static.png");
    characterTexture[1] = LoadTexture(renderer, "./Assets/sprites/donkey_jr/06-r002.png");
    characterTexture[2] = LoadTexture(renderer, "./Assets/sprites/donkey_jr/04-r000.png");

    // izquierda
    characterTexture[3] = LoadTexture(renderer, "./Assets/sprites/donkey_jr/53-l002.png");
    characterTexture[4] = LoadTexture(renderer, "./Assets/sprites/donkey_jr/54-l001-static.png");
    characterTexture[5] = LoadTexture(renderer, "./Assets/sprites/donkey_jr/55-l000.png");

    // subir/bajar
    characterTexture[6] = LoadTexture(renderer, "./Assets/sprites/donkey_jr/10-r006.png");
    characterTexture[7] = LoadTexture(renderer, "./Assets/sprites/donkey_jr/09-r005.png");
}

void destroyCharacterTextures()
{
    for (int i = 0; i < NUM_TILE_TYPES; i++)
    {
        SDL_DestroyTexture(characterTexture[i]);
    }
}

void moveCharacter(SDL_Rect *characterRect, int *prevX, int *prevY, int map[MAP_WIDTH][MAP_HEIGHT], SDL_Renderer *renderer)
{
    // Guardar las coordenadas actuales del personaje
    *prevX = characterRect->x;
    *prevY = characterRect->y;

    int texture = (map[characterRect->x / TILE_SIZE][(characterRect->y - TILE_SIZE) / TILE_SIZE]);

    // Obtener la tecla presionada
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);

    // Mover el personaje tile por tile en función de la tecla presionada

    if (keystate[SDL_SCANCODE_UP] && characterRect->y > 0)
    {

        if (inVine = 1 && (texture == 7 || texture == 8))
        {
            characterRect->y -= TILE_SIZE;
            movementState = 6;
        }
    }

    else if (keystate[SDL_SCANCODE_DOWN] && characterRect->y < (MAP_HEIGHT - 1) * TILE_SIZE)
    {

        if (inVine = 1 && (texture == 7 || texture == 8 || texture == 11))
        {
            characterRect->y += TILE_SIZE;
            movementState = 7;
        }
    }
    // IZQUIERDA
    else if (keystate[SDL_SCANCODE_LEFT] && characterRect->x > 0)
    {

        if (texture == 0)
        {
            characterRect->x -= TILE_SIZE;
            movementState = 5;
        }
        else if ((texture == 8 || texture == 11 || texture == 7) && (inVine == 1))
        {
            dCount = *prevY;
            characterRect->y += TILE_SIZE;

            // printf("\ncuenta: %d", *prevY);
            while (dCount < 688)
            {
                // printf("\ncuenta: %d", dCount);
                characterRect->y += TILE_SIZE;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderCopy(renderer, characterTexture[movementState], NULL, characterRect);
                SDL_Delay(100);
                dCount = dCount + 43;
            }
        }
        else if (((map[(*prevX - 43) / TILE_SIZE][((*prevY) - TILE_SIZE) / TILE_SIZE]) == 0) && (texture == 8 || texture == 0 || texture == 7) && (inVine == 1))
        {
            characterRect->x -= TILE_SIZE;
            movementState = 5;
            inVine = 0;
        }

        // printf("\nActualtexturaDER : %d", texture);
        // printf("\nNewtexturaDER : %d", (map[characterRect->x + 43 / TILE_SIZE][(characterRect->y + 43 - TILE_SIZE) / TILE_SIZE]));
    }
    // DERECHA
    else if (keystate[SDL_SCANCODE_RIGHT] && characterRect->x < (MAP_WIDTH - 1) * TILE_SIZE)
    {
        pTile = *prevY + 43;

        // printf("\ncuenta 1 valor: %d", *prevY);
        // printf("\ncuenta 2 valor: %d", pTile);

        // printf("\ntexturaDER : %d", texture);
        if (texture == 0)
        {
            characterRect->x += TILE_SIZE;
            movementState = 2;
        }
        else if (((map[(*prevX + 43) / TILE_SIZE][((*prevY) - TILE_SIZE) / TILE_SIZE]) == 0) && (texture == 8 || texture == 0 || texture == 7) && (inVine == 1))
        {
            characterRect->x += TILE_SIZE;
            movementState = 2;
            inVine = 0;
        }
        else if ((texture == 8 || texture == 11 || texture == 7) && (inVine == 1))
        {
            dCount = *prevY;
            characterRect->y += TILE_SIZE;

            while (dCount < 688)
            {
                characterRect->y += TILE_SIZE;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderCopy(renderer, characterTexture[movementState], NULL, characterRect);
                SDL_Delay(100);
                dCount = dCount + 43;
            }

            printf("you are dead");
        }
    }
    else if (keystate[SDL_SCANCODE_SPACE] && characterRect->x < (MAP_WIDTH - 1) * TILE_SIZE)
    {
        if (texture == 0)
        {
            characterRect->y -= TILE_SIZE;
            movementState = 6;

            if (texture == 7 || texture == 8)
            {
                inVine = 1;
            }
        }
    }

    if (characterRect->x != prevX || characterRect->y != prevY)
    {
        SDL_Delay(100); // Pausar durante 100 milisegundos
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderCopy(renderer, characterTexture[movementState], NULL, characterRect);
}

// obtener posicion del jugador en el tile
int getTileCoordinates(int position)
{
    return position / TILE_SIZE;
}

void getCharacterTileCoordinates(SDL_Rect characterRect, int *tileX, int *tileY)
{
    *tileX = getTileCoordinates(characterRect.x);
    *tileY = getTileCoordinates(characterRect.y);
}