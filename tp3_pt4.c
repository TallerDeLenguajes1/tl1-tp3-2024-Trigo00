#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
}typedef Cliente;

//Funciones

void cargarClientes(Cliente* n, int cantidad);
float calcularCosto(Producto prod);
void mostrarClientes(Cliente* n, int cantidad);
void liberarMemoria(Cliente* n, int cantidad);

int main(){

    srand(time(NULL));

    int cantClientes;
    Cliente* misClientes;

    do
    {
        printf("Ingrese la cantidad de clientes: ");
        scanf("%d", &cantClientes);
        if(cantClientes > 5){
            printf("No se esta permitido la atencion a mas de 5 clientes, vuelva a intentarlo.\n");
        }
    } while (cantClientes > 5);
    

    misClientes = malloc(sizeof(Cliente)*cantClientes);

    cargarClientes(misClientes, cantClientes);
    mostrarClientes(misClientes, cantClientes);
    liberarMemoria(misClientes, cantClientes);

    return 0;
}

void cargarClientes(Cliente* n, int cantidad){


    for(int i = 0; i < cantidad; i++){

        char nombreAux[50];

        n[i].ClienteID = i + 1;
        
        printf("\nIngrese su nombre: ");
        fflush(stdin);
        gets(nombreAux);

        n[i].NombreCliente = malloc(sizeof(char)*(strlen(nombreAux) + 1));
        strcpy(n[i].NombreCliente, nombreAux);

        n[i].CantidadProductosAPedir = 1 + rand() % 5;

        n[i].Productos = malloc(sizeof(Producto)*(n[i].CantidadProductosAPedir));

        for(int j = 0; j < n[i].CantidadProductosAPedir; j++){

            n[i].Productos[j].ProductoID = j + 1;

            n[i].Productos[j].Cantidad = 1 + rand() % 10;

            n[i].Productos[j].TipoProducto = TiposProductos[rand()%4];

            n[i].Productos[j].PrecioUnitario = (1000 + rand() % 9001)/100;

        }
    }

}


float calcularCosto(Producto prod){

    float total = (prod.Cantidad) * (prod.PrecioUnitario);

    return total;

}

void mostrarClientes(Cliente* n, int cantidad){

    for(int i = 0; i < cantidad; i++){

        float totalP = 0;

        printf("\n\nID Cliente: %d", n[i].ClienteID);
        printf("\nNombre cliente: %s", n[i].NombreCliente);
        printf("\nCantidad de productos pedidos: %d", n[i].CantidadProductosAPedir);

        for(int j = 0; j < n[i].CantidadProductosAPedir; j++){
            printf("\n\nProducto Nro %d", j + 1);
            printf("\nID del producto: %d", n[i].Productos[j].ProductoID);
            printf("\nCantidad: %d", n[i].Productos[j].Cantidad);
            printf("\nTipo de producto: %s", n[i].Productos[j].TipoProducto);
            printf("\nPrecio Unitario: $%.2f", n[i].Productos[j].PrecioUnitario);
            totalP += calcularCosto(n[i].Productos[j]);
        }
        printf("\n\nTotal a pagar: $%.2f", totalP);

    }

}

void liberarMemoria(Cliente* n, int cantidad){

    for(int i = 0; i < cantidad; i++){
        free(n[i].NombreCliente);
        free(n[i].Productos);
    }
    free(n);

}
