#include "constants.h"

SDL_Texture *tileTexturesFruits[NUM_TILE_TYPES];
int lianaF = 0;
int alturaF = 0;

typedef struct
{
    int keyA;
    int valueA;
} KeyValueA;

KeyValueA alturaMappings[] = {
    {1, 6},
    {2, 8},
    {3, 9},
    {4, 10}};

typedef struct
{
    int key;
    int value;
} KeyValue;

KeyValue lianaMappings[] = {
    {2, 3},
    {3, 8},
    {4, 10},
    {5, 13},
    {6, 15},
    {7, 16},
    {8, 19}};

void initializeTilemap(TilemapDynamic *tilemapDynamic)
{
    memset(tilemapDynamic->tiles, 0, sizeof(tilemapDynamic->tiles));
}

/*String a esperar por el server "crear:1(1, 3)"

tiles

-> manzana:0
-> Banano:1
-> Granada:2


*/

void setDynamicTile(TilemapDynamic *tilemapDynamic, SDL_Renderer *renderer, char *fruit)
{
    int global_id;
    int global_liana;
    int global_altura;
    char str1[] = "crear";

    // Copia el string de entrada para evitar modificar el original
    char *inputCopy = strdup(fruit);

    // Busca el tipo de operación ("crear" o "eliminar")
    char *operation = strtok(inputCopy, ":");
    int result = strcmp(str1, operation);
    if (operation == NULL)
    {
        printf("Error: No se encontró la operación.\n");
        return;
    }

    // Extrae el valor de id
    char *idStart = strtok(NULL, "(");
    if (idStart == NULL)
    {
        printf("Error: No se encontró el valor de id.\n");
        return;
    }
    int tileID = atoi(idStart);

    // Extrae el valor de liana
    char *lianaStart = strtok(NULL, ",");
    if (lianaStart == NULL)
    {
        printf("Error: No se encontró el valor de liana.\n");
        return;
    }
    int liana = atoi(lianaStart);

    // Extrae el valor de altura
    char *alturaStart = strtok(NULL, ")");
    if (alturaStart == NULL)
    {
        printf("Error: No se encontró el valor de altura.\n");
        return;
    }
    int altura = atoi(alturaStart);

    // Asigna los valores extraídos a las variables globales
    global_id = tileID;
    global_liana = liana;
    global_altura = altura;

    tileTexturesFruits[0] = LoadTexture(renderer, "./Assets/sprites/static/00-apple.png");
    tileTexturesFruits[1] = LoadTexture(renderer, "./Assets/sprites/static/01-banana.png");
    tileTexturesFruits[2] = LoadTexture(renderer, "./Assets/sprites/static/02-granade.png");

    lianaF = transformLiana(liana);
    alturaF = transformAltura(altura);

    if (lianaF >= 0 && lianaF < MAP_WIDTH && alturaF >= 0 && alturaF < MAP_HEIGHT)
    {
        if (result == 0)
        { // elimina tile

            tilemapDynamic->tiles[lianaF][alturaF] = tileID;
        }
        else
        {

            tilemapDynamic->tiles[lianaF][alturaF] = -1;
        }
    }

    SDL_Texture *texture = tileTexturesFruits[tileID];
    if (tileID >= 0 && texture != NULL)
    {
        SDL_Rect destRect;
        destRect.x = lianaF * TILE_SIZE;
        destRect.y = alturaF * TILE_SIZE;
        destRect.w = TILE_SIZE;
        destRect.h = TILE_SIZE;

        SDL_RenderCopy(renderer, texture, NULL, &destRect);
    }

    // Limpia la memoria utilizada por la copia del string
    free(inputCopy);
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

int transformLiana(int liana)
{
    int i;
    int numMappings = sizeof(lianaMappings) / sizeof(KeyValueA);

    for (i = 0; i < numMappings; i++)
    {
        if (liana == lianaMappings[i].key)
        {
            return lianaMappings[i].value;
        }
    }

    return liana; // Si no se encuentra una coincidencia, devolver el valor original
}

int transformAltura(int altura)
{
    int i;
    int numMappings = sizeof(alturaMappings) / sizeof(KeyValue);

    for (i = 0; i < numMappings; i++)
    {
        if (altura == alturaMappings[i].keyA)
        {
            return alturaMappings[i].valueA;
        }
    }

    return altura; // Si no se encuentra una coincidencia, devolver el valor original
}
