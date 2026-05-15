#include <stdio.h>
#include <stdlib.h>

int mayoritario (int [], int);
int llenar_arr(int [], int);


int main()
{
    int n = 0;

    do
    {
        printf("\nIngresa el tama%co del arreglo (n>3): ",164);
        scanf("%d",&n);

        if(n < 3)
            printf("\nError!\a, ingrese otro valor...\n");
        system("PAUSE");
        system("CLS");
    }
    while(n < 3);

    int arreglo[n];

    llenar_arr(arreglo, n);
    if(mayoritario(arreglo, n) == 1)
    {
        printf("\nEL arreglo es mayoritario!");
    }
    else
        printf("\nEL arreglo NO es mayoritario!");

    return 0;
}

int llenar_arr(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\nIngresa el valor [%d]: ",i+1);
        scanf("%d",(arr+i));
    }
}

int mayoritario (int arr[], int tam)
{
    int cont = 0;
    for(int i=0; i<tam; i++)
    {
        for(int j=0; j<tam; j++)
        {
            if(*(arr+i) == *(arr+j)) /*arr -> es un puntero a la primera posicion del array
            así que si agrupamos eso entro de un parentesis y agregamos un * delante, tal que
            (arr+i) -> es la direccion, y *(arr+i) indica que accede al valor en esa direccion.
			Nota: arr[i] es lo mismo que *(arr+i) */
            {
                cont++;
            }
        }

        if(cont > tam/2)
        {
            return 1;
        }
        else
			cont = 0;
    }
    return 0;
}

