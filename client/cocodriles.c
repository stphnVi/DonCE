#include "constants.h"

/*String a esperar por el server (speed: 1000 - id: 1 - cocodrile: 1 o 0 - posX : 2:2:2:2 - posY : 1:2:3:4)

-> Speed: se maneja por cambios en el delay de SDL
-> ID cocodrilo: azul-> 1 rojo-> 0
-> posX : 2:2:2:2
-> posY : 1:2:3:4


void parseCoordinates(const char *data, int **coordinates, int *numCoordinates)
{
    // Contar la cantidad de elementos en el string
    *numCoordinates = 0;
    const char *ptr = data;
    while (*ptr)
    {
        if (*ptr == ':')
        {
            (*numCoordinates)++;
        }
        ptr++;
    }

    // Reservar memoria para el arreglo de coordenadas
    *coordinates = (int *)malloc(*numCoordinates * sizeof(int));

    // Obtener los elementos del string y almacenarlos en el arreglo de coordenadas
    int index = 0;
    char *token = strtok((char *)data, ":");
    while (token != NULL)
    {
        (*coordinates)[index++] = atoi(token);
        token = strtok(NULL, ":");
    }
}

void addCocodrile(SDL_Renderer *renderer, const char *cocoData, int map[MAP_WIDTH][MAP_HEIGHT])
{
    printf("entra coco.\n");

    // Encontrar la posición de "pos:" en la cadena de entrada
    const char *posStart = strstr(cocoData, "pos:");
    if (posStart == NULL)
    {
        printf("No se encontró la entrada pos.\n");
        return;
    }

    // Avanzar hasta el comienzo de la lista de posiciones
    posStart += 5; // Avanzar más allá de "pos: ("

    // Crear una copia de la cadena de posiciones para su manipulación
    char *posCopy = strdup(posStart);
    if (posCopy == NULL)
    {
        printf("Error al duplicar la cadena de posiciones.\n");
        return;
    }

    // Contar la cantidad de coordenadas en la lista de posiciones
    int numCoordinates = 0;
    char *token = strtok(posCopy, ",");
    while (token != NULL)
    {
        numCoordinates++;
        token = strtok(NULL, ",");
    }

    // Reservar memoria para posX y posY
    int *posX = (int *)malloc(numCoordinates * sizeof(int));
    int *posY = (int *)malloc(numCoordinates * sizeof(int));

    // Obtener los valores de posX y posY
    int index = 0;
    token = strtok(posStart, ",");
    while (token != NULL)
    {
        // Remover los paréntesis y extraer los valores de posX y posY
        char *openParenthesis = strchr(token, '(');
        char *comma = strchr(token, ',');
        char *closeParenthesis = strchr(token, ')');

        if (openParenthesis == NULL || comma == NULL || closeParenthesis == NULL)
        {
            printf("Error al procesar la coordenada: %s\n", token);
            free(posX);
            free(posY);
            free(posCopy);
            return;
        }

        *openParenthesis = '\0';
        *comma = '\0';
        *closeParenthesis = '\0';

        posX[index] = atoi(token);
        posY[index] = atoi(comma + 1);

        token = strtok(NULL, ",");
        index++;
    }

    // Imprimir los valores de posX y posY
    printf("posX: ");
    for (int i = 0; i < numCoordinates; i++)
    {
        printf("%d ", posX[i]);
    }
    printf("\nposY: ");
    for (int i = 0; i < numCoordinates; i++)
    {
        printf("%d ", posY[i]);
    }

    // Liberar la memoria asignada
    free(posX);
    free(posY);
    free(posCopy);
}


void cocodrileBlue(SDL_Renderer *renderer, int x, int *yCoordinates, int numCoordinates)
{
    // Renderizar el enemigo en la posición inicial
    tileTextures[0] = LoadTexture(renderer, "./Assets/sprites/blue_crocodile/25-tile001.png");

    // Bucle para realizar el movimiento del cocodrilo
    for (int i = 0; i < numCoordinates; i++)
    {
        // Renderizar el cocodrilo en la posición actual
        SDL_Texture *texture = tileTextures[0]; // Usar la textura correcta
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


*/