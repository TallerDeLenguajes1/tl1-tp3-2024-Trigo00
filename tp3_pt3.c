#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char** misNombres = malloc(sizeof(int *) * 5);
    char *nombre;
    for(int i = 0; i < 5; i++){        
        nombre = malloc(sizeof(char) * 50);
        printf("Ingrese su nombre: ");
        gets(nombre);
        nombre = (char*) realloc(nombre, sizeof(strlen(nombre)+ 1));
        misNombres[i] = nombre;

    }

    for(int i = 0; i < 5; i++){

        printf("\nNombre %d: %s", i + 1, misNombres[i]);

    }

    for(int i = 0; i < 5; i++){
        free(misNombres[i]);
    }
    free(misNombres);

    return 0;
}
