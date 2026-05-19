
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void llenar_arr(int *, int);
void mostrar_arr(int *, int);
int verificar_fila(int *, int);
int verificar_columna(int *, int);
int verificar_subcuadro(int *, int);

int main()
{
	int n;
	do{
		printf("\nIngresa la dimension del sudoku (4, 9, 16): ");
		scanf("%d",&n);
		if(n != 4 && n != 9 && n != 16)
		{
			printf("\n\n\aError!, Ingresa una dimension valida\n");
			system("PAUSE");
			system("CLS");
		}
	}while(n != 4 && n != 9 && n != 16);

	int arreglo[n][n];
	llenar_arr(&arreglo[0][0],n);
	mostrar_arr(&arreglo[0][0],n);

	system("PAUSE");
	if(verificar_fila(&arreglo[0][0],n) == 1 && verificar_columna(&arreglo[0][0],n) == 1 && verificar_subcuadro(&arreglo[0][0],n) == 1)
	{
		printf("El sudoku es v%clido!\a\n",160);
	}
	else
		printf("\nEl sudoku no es v%clido\n",160);

    return 0;
}

int verificar_subcuadro(int *arr, int tam)
{
	int subcuadro = sqrt(tam);

	for(int i=0; i<tam; i+=subcuadro) //i+=subcuadro equivale a i=i+subcuadro.
	{
		for(int j=0; j<tam; j+=subcuadro) ////j+=subcuadro equivale a j=j+subcuadro.
		{
			for(int x=0; x<subcuadro; x++)
			{
				for(int y=0; y<subcuadro; y++)
				{
					for(int x2=0; x2<subcuadro; x2++)
					{
						for(int y2=0; y2<subcuadro; y2++)
						{
							if(x2 == x && y2 == y)
								continue;
							if(*(arr+(i+x)*tam+(j+y)) == *(arr+(i+x2)*tam+(j+y2)))
							{
								printf("\nFallo en el subcuadro\n");
								return 0;
							}
						}
					}
				}
			}
		}
	}
	return 1;
}

//retorna 1 si es valido y 0 si no lo es.
int verificar_columna(int *arr, int tam)
{
	for(int i=0; i<tam; i++)
	{
		for(int j=0; j<tam; j++)
		{
			for(int k=j+1; k<tam; k++)
			{
				if( *(arr + j*tam + i) == *(arr + k*tam + i))
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

//retorna 1 si es valido y 0 si no lo es.
int verificar_fila(int *arr, int tam)
{
	for(int i=0; i<tam; i++)
	{
		for(int j=0; j<tam; j++)
		{
			for(int k=j+1; k<tam; k++)
			{
				if( *(arr + i*tam + j) == *(arr + i*tam + k))
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

void mostrar_arr(int *arr, int tam)
{
	printf("\nEste es el sudoku (%dx%d): \n", tam,tam);

	for(int i=0; i<tam; i++)
	{
		for(int j=0; j<tam; j++)
		{
			printf("%d ", *(arr + i*tam + j));
		}
		printf("\n");
	}
}

void llenar_arr(int *arr, int tam)
{
	printf("\nIngresa numeros del sudoku (%dx%d):\n", tam,tam);

	for(int i=0; i<tam; i++)
	{
		for(int j=0; j<tam; j++)
		{
			printf("Valor [%d][%d]: ", i+1, j+1);
			scanf("%d", (arr + i*tam + j) );
		}
		printf("\n");
	}
}
