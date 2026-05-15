//Joel De Jesus Ayala Peguero
#include <stdio.h>
#include <stdlib.h>

void invertir_val(int, int[]);
void llenar(int, int[]);

int main()
{
    int tam = 0;

    do
    {
        printf("\nIngresa el tama%co del arreglo: ",164);
        scanf("%d",&tam);
        if(tam < 2)
            printf("\n\aError!, ingresa valor v%clido...\n", 160);
        //system("PAUSE");
        system("CLS");
    }
    while(tam < 2);

    int arreglo[tam];

    llenar(tam, arreglo);
    invertir_val(tam,arreglo);

    return 0;
}

void llenar(int tam, int M[])
{
    for(int i=0; i<tam; i++)
    {
        printf("\nIngresa Valor [%d]: ",i+1);
        scanf("%d",&M[i]);
    }
}

void invertir_val(int tam, int M[])
{
    int temp;
    for(int i=0; i<tam; i++)
    {
        printf("\nValores originales [%d]: ",M[i]);
    }
    printf("\n");
    //system("PAUSE");
    system("CLS");
    for(int i=0; i<tam/2; i++)
    {
        temp = M[i];
        M[i] = M[tam-1-i]; /*Tam-1-i porque: tam-1 esta accediendo al ultimo indice (recuerda que
						     en un arreglo de 4, el ultimo indice es el 3 [0,1,2,3], por lo que
						     hay que quitarle uno, y luego ir moviendose hacia atras con i)*/
        M[tam-1-i] = temp;
    }

    printf("\nValores: \n");
    for(int i=0; i<tam; i++)
    {
        printf("\n[%d]", M[i]);
    }
}
