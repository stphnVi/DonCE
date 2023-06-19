#include "constants.h"
/*
String a esperar por el server (speed: 1000 - id: 1 - kremlim: 1 o 0 - posX : 2:2:2:2 - posY : 1:2:3:4)

-> Speed: se maneja por cambios en el delay de SDL
-> ID cocodrilo: azul-> 1 rojo-> 0
-> posX : 2:2:2:2
-> posY : 1:2:3:4

*/
SDL_Texture *kremlimTextures[NUM_TILE_TYPES];

void loadKremlimTextures(SDL_Renderer *renderer)
{
    // red kremlim up
    kremlimTextures[0] = LoadTexture(renderer, "./Assets/sprites/red_crocodile/31-tile003.png");
    kremlimTextures[1] = LoadTexture(renderer, "./Assets/sprites/red_crocodile/32-tile004.png");

    // red kremlim down
    kremlimTextures[2] = LoadTexture(renderer, "./Assets/sprites/red_crocodile/35-tile005.png");
    kremlimTextures[3] = LoadTexture(renderer, "./Assets/sprites/red_crocodile/56-tile004.png");
}

void destroykremlimTexturess()
{
    for (int i = 0; i < NUM_TILE_TYPES; i++)
    {
        SDL_DestroyTexture(kremlimTextures[i]);
    }
}

void addkremlim(SDL_Renderer *renderer, const char *kremlimData, int map[MAP_WIDTH][MAP_HEIGHT])
{
    printf("entra coco.\n");

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
    printf("Color: %s\n", color);
    printf("Inicio: %d\n", inicio);
    printf("Velocidad: %d\n", velocidad);
}

void kremlimRed(SDL_Renderer *renderer, int x, int *yCoordinates, int numCoordinates)
{
    // Renderizar el enemigo en la posición inicial
    kremlimTextures[0] = LoadTexture(renderer, "./Assets/sprites/blue_crocodile/25-tile001.png");

    // Bucle para realizar el movimiento del cocodrilo
    for (int i = 0; i < numCoordinates; i++)
    {
        // Renderizar el cocodrilo en la posición actual
        SDL_Texture *texture = kremlimTextures[0]; // Usar la textura correcta
        if (texture != NULL)
        {
            SDL_Rect destRect;
            destRect.x = x * TILE_SIZE;
            destRect.y = yCoordinates[i] * TILE_SIZE;
            destRect.w = TILE_SIZE;
            destRect.h = TILE_SIZE;

            SDL_RenderCopy(renderer, texture, NULL, &destRect);
        }

        // Delay para controlar la velocidad de movimiento
        SDL_Delay(1000); // Ajusta el valor según la velocidad deseada
    }
}
