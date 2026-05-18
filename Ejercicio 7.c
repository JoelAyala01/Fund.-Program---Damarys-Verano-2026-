#include <stdio.h>
#include <stdlib.h>

int es_simetrica(int *, int);
void llenar_matriz(int *, int);

int main()
{
	int dim;
	do{
		printf("\nIngresa la dimension de la matriz: ");
		scanf("%d",&dim);
		if(dim < 2)
		{
			printf("\nError\n\aIngresa valor mayor o igual a dos (2): ");
			system("PAUSE");
			system("CLS");
		}
	}while(dim < 2);

	int arr[dim][dim];

	llenar_matriz(&arr[0][0], dim);
	if(es_simetrica(&arr[0][0], dim) == 1)
	{
		printf("\n\nLa matriz es ASIMETRICA\n");
	}
	else
		printf("\n\nLa matriz es SIMETRICA\n");

	return 0;
}

int es_simetrica(int *arr, int dim)
{
	for(int i=0; i<dim; i++)
	{
		for(int j=0; j<dim; j++)
		{
			if( *(arr + i*dim + j) != *(arr + j*dim + i) )
			{
				return 1;
				//printf("\nLA matriz NO es simetrica!\a\n");
				//system("PAUSE");
				//break;
			}
		}
	}
	return 0;
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
