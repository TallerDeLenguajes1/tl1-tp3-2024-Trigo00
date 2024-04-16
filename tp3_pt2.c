#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarMatriz(int matriz[5][12]);
void mostrarPromedio(int matriz[5][12]);
void encontrarValores(int matriz[5][12]);

int main(){

    int matriz[5][12];

    srand(time(NULL));

    cargarMatriz(matriz);
    mostrarPromedio(matriz);
    encontrarValores(matriz);

    return 0;
}

void cargarMatriz(int matriz[5][12]){

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 12; j++){
            matriz[i][j] = 10000 + rand() % 40001;
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }

}

void mostrarPromedio(int matriz[5][12]){
    float suma = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 12; j++){
            suma += matriz[i][j];
        }
        suma = suma / 12;
        printf("\nLa ganancia en el anio %d, fue de $%.2f",i + 1, suma);
        suma = 0;
    }

}

void encontrarValores(int matriz[5][12]){
    float mayor = 0;
    float menor = 90000;
    int anioMayor, mesMayor;
    int anioMenor, mesMenor;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 12; j++){
            if(matriz[i][j] > mayor){
                mayor = matriz[i][j];
                anioMayor = i + 1;
                mesMayor = j + 1;
            }
            if(matriz[i][j] < menor){
                menor = matriz[i][j];
                anioMenor = i + 1;
                mesMenor = j + 1;
            }

        }
    }

    printf("\n\nEl valor maximo fue el %d/%d y fue de $%.2f", mesMayor, anioMayor, mayor);
    printf("\nEl valor minimo fue el %d/%d y fue de $%.2f", mesMenor, anioMenor, menor);

}