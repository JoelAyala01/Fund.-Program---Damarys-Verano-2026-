#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.c>

#define CANT_CATEGORIAS 3 //Tres temas fijos.
#define CANT_FRASES 4 //Cuatro frases por tema.
#define LARGO 50 //Longitud maximo de la frase.

void menu(int *);
void enmascararFrase(char *, char *);
int calcularVidas(char *);
void mostrar_datos_empezar(char *, int);


int main()
{
    srand(time(NULL));
    char bancoFrases[CANT_FRASES * CANT_CATEGORIAS][LARGO] =
    {
        "Baseball", "Futbol", "Tenis", "Atletismo", //Deportes 0-4
        "Endgame", "Ice age", "Better man", "F1",   //Peliculas 4-8
        "Estados Unidos", "Australia", "Japon", "Republica Dominicana" //Paises 8-11
    };

    int opcion;
    int indiceCategoria = -1;
    menu(&opcion);

    switch(opcion)
    {
    case 1: //Deportes
        indiceCategoria = 0; //De 0 hasta 3, recorriendo las cuatro de deportes.
        printf("\nElegiste Deportes, perfecto.\n\n  Buscando deporte...\n");
        Sleep(1700);
        break;
    case 2: //Peliculas
        indiceCategoria = 4; //De 4 a 8, 4 de deportes + 4 de las peliculas.
        printf("\nElegiste Peliculas, perfecto.\n\n  Buscando peliculas...\n");

        break;
    case 3: //Paises
        indiceCategoria = 8; //De 8 hasta fin, 4 deportes + 4 peliculas + 4 paises.
        printf("\nElegiste Paises, perfecto.\n\n  Buscando paises...\n");

        break;
    default:
        printf("\n\n===V U E L V E  P R O N T O ===\n\n");
        break;
    }

    if(indiceCategoria != -1) //ELigio una categoria valida
    {
        int r = rand()%CANT_FRASES; /*Esto elije al azar un numero del 0 al 3
        	indicando cual de las cuatro palabras se eligio. */
        int indiceFinal = indiceCategoria + r; /*Calcula el \\la posicion dentro de la categoria. */

        char fraseReal[LARGO];
        char fraseMascara[LARGO];

        //Copia la frase del banco de frases al arreglo.
        strcpy(fraseReal,bancoFrases[indiceFinal]);

        //Enmascarar la frase:
        enmascararFrase(fraseReal,fraseMascara); //Le paso la frase elegida, y devuelve la cadena ya "oculta".

        //Calcular vidas:
        int vidas = calcularVidas(fraseReal);

        //Mostrar datos para empezar el juego
        /*
        clrscr();
        printf("============================================\n");
        printf("   JUEGO INICIADO: CATEGORIA SELECCIONADA   \n");
        printf("============================================\n\n");

        printf("Frase a adivinar: %s\n", fraseMascara);
        printf("Tienes %d oportunidades para ganar.\n", vidas);
        printf("\nPresiona una tecla para girar la ruleta...\n");
        getch();
        */
        mostrar_datos_empezar(fraseMascara,vidas);
    }

    //Final del main
    return 0;
}

void mostrar_datos_empezar(char *fraseMascara, int vidas)
{
	clrscr();
        printf("============================================\n");
        printf("   JUEGO INICIADO: CATEGORIA SELECCIONADA   \n");
        printf("============================================\n\n");

        printf("Frase a adivinar: %s\n", fraseMascara);
        printf("Tienes %d oportunidades para ganar.\n", vidas);
        printf("\nPresiona una tecla para girar la ruleta...\n");
        getch();
}


int calcularVidas(char *frase)
{
    int letrasVistas[256] = {0}; //Cadena para marcas las letras ya contadas.
    int conteoUnicas = 0;
    int len = strlen(frase);
    //Contar letras unicas
    for(int i=0; i<len; i++)
    {
        unsigned char letra = frase[i];
        //Solo contamos si es una letra y no es espacio.
        if(letra != ' ')
        {
            //SI en la posicion de esa letra hay un 0, es nueva.
            if(letrasVistas[letra] == 0)
            {
                letrasVistas[letra] = 1; //Se marca como vista.
                conteoUnicas++; //Aumenta el contador.
            }
        }
    }

    //Generar multiplicador 'n' (entre 3 y 6).
    //Formula: rand() % (max - min + 1) + min
    int n = (rand() % 4) + 3;

    //Retornar el total de vidas
    return n * conteoUnicas;
}//fin


void enmascararFrase(char *original, char *mascara)
{
    //Aqui se configura la cadena que se mostrara como ocual con asteriscos.
    int len = strlen(original);
    for(int i=0; i<len; i++)
    {
        //Si es un espacio se deja asi mismo.
        if(original[i] == ' ')
        {
            mascara[i] = ' ';
        }
        //Si es una letra se pone un asterisco.
        else
        {
            mascara[i] = '*';
        }
    }
    //Cuando llega al final (len: tamaño de la cadena) se pone el nulo para que termine ahi.
    mascara[len] = '\0';
}

/**/
void menu(int *opcion)
{
    do //Menu
    {
        printf("\n  Bienvenidos al Juego del ahorcado: \n");
        printf("\nSeleccione una categoria: \n");
        printf("\n1. Deportes\n2. Peliculas\n3. Paises\n\n");
        printf("Elige una opcion [0 para salir]: ");
        scanf("%d",opcion); //Leo la opcion.
        if(*opcion>3 || *opcion<0) //Si la opcion (esta fuera de rango) es mayor que las opciones o menor que 0, donde cero termina el programa.
            printf("\n  Opcion invalida, seleccione de nuevo!\n");
        Sleep(500);
        clrscr();
    }
    while(*opcion > 3 || *opcion < 0);
}
