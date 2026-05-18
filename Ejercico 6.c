#include <stdio.h>
#include <stdlib.h>

void llenar_matriz(int*, int);
void mostrar_matriz(int*, int);
void sumar_matrices(int*, int*, int*, int);
void restar_matrices(int*, int*, int*, int);

int main()
{
	int dim;
	do
	{
		printf("\nIngresa la dimension de la matriz (cuadrada): ");
		scanf("%d",&dim);
		if(dim < 3)
		{
			printf("\nError\a\nIngresa valor mayor que tres (3): ");
			system("PAUSE");
			system("CLS");
		}
	}while(dim<3);

	int arrA[dim][dim], arrB[dim][dim], arrC[dim][dim];

	llenar_matriz(&arrA[0][0], dim);
	llenar_matriz(&arrB[0][0], dim);
	//llenar_matriz(&arrC[0][0], dim);

	mostrar_matriz(&arrA[0][0], dim);
	mostrar_matriz(&arrB[0][0], dim);
	//mostrar_matriz(&arrC[0][0], dim);

	sumar_matrices(&arrA[0][0], &arrB[0][0], &arrC[0][0], dim);

	mostrar_matriz(&arrA[0][0], dim);
	mostrar_matriz(&arrB[0][0], dim);
	mostrar_matriz(&arrC[0][0], dim);

	restar_matrices(&arrA[0][0], &arrB[0][0], &arrC[0][0], dim);

	mostrar_matriz(&arrC[0][0], dim);


	return 0;
}

void restar_matrices(int *A, int *B, int *C, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			*(C + (i*n) + j) = (*(A + (i*n) + j)) - (*(B + (i*n) + j));
		}
	}
}

void sumar_matrices(int *A, int *B, int *C, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			*(C + (i*n) + j) = (*(A + (i*n) + j)) + (*(B + (i*n) + j));
		}
	}
}


void mostrar_matriz(int *arr, int n)
{
	for(int i=0; i<n; i++)
	{
		printf("\n");
		for(int j=0; j<n; j++)
		{
			printf("%d ", *(arr + i*n + j));
		}
	}
}

void llenar_matriz(int *arr, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("\nIngresa la posicion [%d][%d]: ",i+1, j+1);
			scanf("%d", arr + i*n + j);
		}
	}
}
