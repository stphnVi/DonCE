#include "constants.h"
#include "src/texture.h"
#include <unistd.h>

SDL_Texture *characterTexture[NUM_TILE_TYPES];
int movementState = 0;

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
    int psibleVine[5] = {1, 3, 5, 8, 10, 12, 15, 16, 19};
    int length = sizeof(psibleVine) / sizeof(psibleVine[0]);

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
        printf("entra %d %d", inVine, texture);
        if (inVine = 1 && (texture == 7 || texture == 8))
        {
            characterRect->y += TILE_SIZE;
            movementState = 7;
        }
    }
    else if (keystate[SDL_SCANCODE_LEFT] && characterRect->x > 0)
    {
        if (texture == 0)
        {
            characterRect->x -= TILE_SIZE;
            movementState = 5;
        }

        if (inVine = 1)
        {
            // fisicas
        }
    }
    else if (keystate[SDL_SCANCODE_RIGHT] && characterRect->x < (MAP_WIDTH - 1) * TILE_SIZE)
    {
        if (texture == 0)
        {
            characterRect->x += TILE_SIZE;
            movementState = 2;
        }
        if (inVine = 1)
        {
            // fisicas
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

void gravityCharacter()
{
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