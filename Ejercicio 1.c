//Joel De Jesus Ayala Peguero
#include <stdio.h>
#include <stdlib.h>

void grupoAdy(int, int[]);

int main()
{
    int tam = 0;
    do{
        system("CLS");
        printf("Ingresa el tama%co del arreglo (N > 3): ",164);
        scanf("%d",&tam);
        if(tam < 3)
        {
            printf("\nError\a, Ingresa tama%co v%clido!\n", 164, 160);
            system("PAUSE");
        }
    }while(tam<3);

    int arr[tam];

    for(int i=0; i<tam; i++)
    {
        printf("\nIngresa la pisici%cn [%d]: ", 162, i+1);
        scanf("%d",&arr[i]);
    }
    system("PAUSE");

    grupoAdy(tam, arr);

    return 0;
}

void grupoAdy(int tam, int M[])
{
    for(int i=0; i<=tam-3; i++)
    {
        if((M[i] == M[i+1]+1 && M[i] == M[i+2]+2) || (M[i+1] == M[i]+1 && M[i+2] == M[i]+2) )
        {
            printf("\nGrupo adyacente: %d, %d y %d",M[i], M[i+1], M[i+2]);
        }
    }
}
