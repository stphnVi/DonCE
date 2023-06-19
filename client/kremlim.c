#include "constants.h"
/*
String a esperar por el server 'crear:azul:1:1000'

-> color: azul rojo
-> posX : 1
-> valocidad: 1000

*/
SDL_Texture *kremlimTexture[NUM_TILE_TYPES];
int movementStatek = 0;

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
        SDL_DestroyTexture(kremlimTexture[i]);
    }
}

void loadKremlimTexturesK(SDL_Renderer *renderer)
{
    // rojo client\Assets\sprites\blue_crocodile\27-tile003.png
    kremlimTexture[0] = LoadTexture(renderer, "./Assets/sprites/red_crocodile/33-tile003.png");
    kremlimTexture[1] = LoadTexture(renderer, "./Assets/sprites/blue_crocodile/27-tile003.png");
}

void destroykremlimTexturesK()
{
    for (int i = 0; i < NUM_TILE_TYPES; i++)
    {
        SDL_DestroyTexture(kremlimTexture[i]);
    }
}

void addkremlim(SDL_Renderer *renderer, char *kremlimData, int map[MAP_WIDTH][MAP_HEIGHT], SDL_Rect *kremlimRect)
{
    // Guardar las coordenadas actuales del personaje
    char str1[] = "rojo";
    char *token;
    char *savePtr;
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

    printf("\nLiana parseada %d", inicio * TILE_SIZE);
    printf("\nVelocidad kremil %d", velocidad);
    printf("\n Y %d", kremlimRect->y);

    int result1 = strcmp(color, str1);
    if (result1 == 0)
    {

        kremlimRed(renderer, inicio, velocidad, map, kremlimRect);
    }
    else
    {
        kremlimBlue(renderer, inicio, velocidad, map, kremlimRect);
    }

    // Obtener la tecla presionada
}

void kremlimBlue(SDL_Renderer *renderer, int inicio, int velocidad, int map[MAP_WIDTH][MAP_HEIGHT], SDL_Rect *kremlimRect)
{

    kremlimRect->x = transformLianaK(inicio) * TILE_SIZE;
    kremlimRect->y += TILE_SIZE;
    movementStatek = 1;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderCopy(renderer, kremlimTexture[movementStatek], NULL, kremlimRect);
    SDL_Delay(100);
}

void kremlimRed(SDL_Renderer *renderer, int inicio, int velocidad, int map[MAP_WIDTH][MAP_HEIGHT], SDL_Rect *kremlimRect)
{
    // Mover el personaje tile por tile en función de la tecla presionada
    kremlimRect->x = transformLianaK(inicio) * TILE_SIZE;

    if (map[(kremlimRect->x) / 43][(kremlimRect->y) / 43] == 7)
    {
        printf("\npos baja %d", kremlimRect->y);
        printf("\npos baja map %d", map[transformLianaK(inicio)][(kremlimRect->y)]);
        kremlimRect->y += TILE_SIZE;
        movementStatek = 0;
    }
    else if (map[(kremlimRect->x) / 43][(kremlimRect->y) / 43] == 0)
    {
        printf("\npos sube %d", kremlimRect->y);
        printf("\npos baja map %d", map[transformLianaK(inicio)][(kremlimRect->y)]);
        kremlimRect->y -= TILE_SIZE;
        movementStatek = 0;
    }

    // Obtener la textura correspondiente al movimiento del cocodrilo
    // printf("\n Entra");

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderCopy(renderer, kremlimTexture[movementStatek], NULL, kremlimRect);
    SDL_Delay(100);
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
  kremlimRect->x = transformLianaK(inicio) * TILE_SIZE;

    if (map[transformLianaK(inicio)][(kremlimRect->y) - 43] == 11)
    {
        kremlimRect->y += TILE_SIZE;
        movementStatek = 0;
    }
    if (map[transformLianaK(inicio)][(kremlimRect->y) - 43] == 0)
    {
        kremlimRect->y -= TILE_SIZE;
        movementStatek = 0;
    }


     // UP
        kremlimRect->y -= TILE_SIZE;
        movementStatek = 6;
        // DOWN
        kremlimRect->y += TILE_SIZE;
        movementStatek = 7;
        // IZQ
        kremlimRect->x -= TILE_SIZE;
        movementStatek = 5;
        // DER
        // kremlimRect->x += TILE_SIZE;

*/