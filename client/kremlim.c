#include "constants.h"
/*
String a esperar por el server 'crear:azul:1:1000'

-> color: azul rojo
-> posX : 1
-> valocidad: 1000

*/
SDL_Texture *kremlimTextures[NUM_TILE_TYPES];

typedef struct
{
    int key;
    int value;
} KeyValueK;

KeyValueK lianaMappingsK[] = {
    {2, 3},
    {3, 8},
    {4, 10},
    {5, 13},
    {6, 15},
    {7, 16},
    {8, 19}};

void destroykremlimTexturess()
{
    for (int i = 0; i < NUM_TILE_TYPES; i++)
    {
        SDL_DestroyTexture(kremlimTextures[i]);
    }
}

void addkremlim(SDL_Renderer *renderer, const char *kremlimData, int map[MAP_WIDTH][MAP_HEIGHT])
{

    char str1[] = "rojo";
    char *token;
    char *savePtr;
    const char *inputString = "crear:azul:1:1000";
    char color[20];
    int inicio = 0;
    int velocidad = 0;

    // Copiar el kremlimData en una variable local porque strtok() modifica la cadena original
    char inputCopy[strlen(kremlimData) + 1];
    strcpy(inputCopy, kremlimData);

    // Obtener el primer token (crear:)
    token = strtok_r(inputCopy, ":", &savePtr);
    if (token != NULL)
    {
        // Obtener el segundo token (color)
        token = strtok_r(NULL, ":", &savePtr);
        if (token != NULL)
        {
            strcpy(color, token);

            // Obtener el tercer token (inicio)
            token = strtok_r(NULL, ":", &savePtr);
            if (token != NULL)
            {
                inicio = atoi(token);

                // Obtener el cuarto token (velocidad)
                token = strtok_r(NULL, ":", &savePtr);
                if (token != NULL)
                {
                    velocidad = atoi(token);
                }
            }
        }
    }
    int result = strcmp(str1, color);
    // rojo
    if (result == 1)

    {
        printf("\nDibujar kremil %d", inicio);
        kremlimRed(renderer, transformLianaK(inicio), velocidad, map);
    }
}

void kremlimRed(SDL_Renderer *renderer, int inicio, int velocidad, int map[MAP_WIDTH][MAP_HEIGHT])
{
    // Bucle para realizar el movimiento del cocodrilo

    kremlimTextures[0] = LoadTexture(renderer, "./Assets/sprites/red_crocodile/35-tile005.png");
    kremlimTextures[1] = LoadTexture(renderer, "./Assets/sprites/static/00-apple.png");

    // red kremlim down
    kremlimTextures[2] = LoadTexture(renderer, "./Assets/sprites/red_crocodile/35-tile005.png");
    kremlimTextures[3] = LoadTexture(renderer, "./Assets/sprites/red_crocodile/56-tile004.png");

    SDL_Texture *texture = kremlimTextures[0];
    printf("\nDibujar %d", inicio);

    if (texture != NULL)
    {
        printf("\nver nulo %d", inicio);
        SDL_Rect srcRect;  // Rectángulo de origen (si es necesario)
        SDL_Rect destRect; // Rectángulo de destino

        // Establecer las dimensiones y posición del rectángulo de destino
        destRect.x = inicio * TILE_SIZE;
        destRect.y = 5 * TILE_SIZE;
        destRect.w = TILE_SIZE;
        destRect.h = TILE_SIZE;

        SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
    }
}

int transformLianaK(int liana)
{
    int i;
    int numMappings = sizeof(lianaMappingsK) / sizeof(KeyValueK);

    for (i = 0; i < numMappings; i++)
    {
        if (liana == lianaMappingsK[i].key)
        {
            return lianaMappingsK[i].value;
        }
    }

    return liana; // Si no se encuentra una coincidencia, devolver el valor original
}

/*

for (int i = 0; i < MAP_HEIGHT; i++)
{

// Verificar si el tile es 7 o 8 para realizar la acción
// printf("\n textura %d ", map[inicio][i]);


if (map[inicio][i] == 7 || map[inicio][i] == 8)
{
// Obtener la textura correspondiente al movimiento del cocodrilo
// printf("\n Entra");
SDL_Texture *texture = kremlimTextures[0];

if (texture != NULL)
{
    SDL_Rect destRect;
    destRect.x = inicio * TILE_SIZE;
    destRect.y = i * TILE_SIZE;
    destRect.w = TILE_SIZE;
    destRect.h = TILE_SIZE;

    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}
}

*/

// Delay para controlar la velocidad de movimiento
// SDL_Delay(1000 / velocidad); // Ajusta el valor según la velocidad deseada