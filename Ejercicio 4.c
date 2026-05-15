#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void llenar_arr(int[], int);
void funcion(int, int[], int[]);
void mostrar(int, int[]);

int main()
{
	int n=0;
	do{
		printf("\nTama%co del arreglo (n>1): ",164);
		scanf("%d",&n);
		if(n<2)
		{
			printf("\a\nDebe ser mayor a 1\n");
		}
		system("PAUSE");
		system("CLS");
	}while(n<2);
	int X[n];
	int Y[n];
	system("CLS");

	llenar_arr(X,n);
	funcion(n,X,Y);
	mostrar(n,Y);

	printf("\n\nSoy el mejolll\n");
	system("PAUSE");
	return 0;
}

void mostrar(int tam, int arrY[])
{
	for(int i=0; i<tam; i++)
	{
		printf("\nValor [%d]: %d ",(i+1), *(arrY+i));
		printf("");
	}
}

void funcion(int n, int arrX[], int arrY[])
{
	for(int i=0; i<n; i++)
	{
		*(arrY+i) = (5 * pow(*(arrX+i),4) + pow(*(arrX+i),2) - 10);
	}
}

void llenar_arr(int arr[], int tam)
{
	for(int i=0; i<tam; i++)
	{
		printf("\nIngresa valor [%d]: ",i+1);
		scanf("%d",arr+i);
	}
	printf("\n\n\t\t ==Arreglo lleno==\a\n");
	system("PAUSE");
}
