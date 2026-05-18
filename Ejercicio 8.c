#include <stdio.h>
#include <stdlib.h>
void llenar_matriz(int *, int, int);
void mostrar_matriz(int *, int, int);
void trasponer_matriz(int *, int *, int, int);

int main()
{
    int m, n;
    printf("Ingresa filas (m): "); scanf("%d", &m);
    printf("Ingresa columnas (n): "); scanf("%d", &n);

    int arr[m][n];   // matriz original m x n
    int T[n][m];     // transpuesta n x m (filas y columnas invertidas)

    llenar_matriz(&arr[0][0], m, n);

    trasponer_matriz(&arr[0][0], &T[0][0], m, n);

    printf("\n== Matriz original ==");
    mostrar_matriz(&arr[0][0], m, n);

    printf("\n== Matriz transpuesta ==");
    mostrar_matriz(&T[0][0], n, m);  // n filas, m columnas

    return 0;
}

// Llena una matriz de m filas y n columnas
void llenar_matriz(int *arr, int m, int n)
{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            printf("\nIngresa [%d][%d]: ", i+1, j+1);
            scanf("%d", arr + i*n + j);  // posicion = fila*cols + col
        }
}

// Muestra una matriz de m filas y n columnas
void mostrar_matriz(int *arr, int m, int n)
{
    for(int i=0; i<m; i++)
    {
        printf("\n");
        for(int j=0; j<n; j++)
            printf("%d ", *(arr + i*n + j));
    }
}

// Transpone arr (m x n) en T (n x m)
// A[i][j] de la original va a T[j][i]
void trasponer_matriz(int *arr, int *T, int m, int n)
{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            *(T + j*m + i) = *(arr + i*n + j);
            // T[j][i] = arr[i][j]
            // T tiene m columnas, arr tiene n columnas
}
