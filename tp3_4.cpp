#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

const char *TipoProducto[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto{
	int ProductoID;//Numerado en ciclo iterativo
	int Cantidad;// entre 1 y 10
	char *TipoProducto;//Algún valordel arreglo TiposProductos
	float PrecioUnitario;// entre 10 -100
}typedef producto;//tipo definido de dato



struct Cliente {
	int	ClienteID;// Numerado en el ciclo iterativo
	char *NombreCliente;// Ingresado por usuario
	int CantidadProductosAPedir;// (alteatorio entre 1 y 5)
	producto *Productos; //El tamaño de este arreglo depende de la variable// “CantidadProductosAPedir”
}typedef cliente;//tipo de dato

void cargarClientes(cliente *new_cliente, int cant, char *nombre){
	int cant_prod;
	for(int i = 0; i < cant; i++){
		(new_cliente + i)->ClienteID = i+1;
		printf("\nIngrese la cantidad de productos a pedir: ");
		scanf("%d", &cant_prod);fflush(stdin);
		(new_cliente + i)->CantidadProductosAPedir = cant_prod;
		
	}
}

void mostrarClientes(cliente *new_cliente, int cant){
	for(int i = 0; i < cant; i++){
		printf("ID: %d: ", (new_cliente + i)->ClienteID);
		printf("P. a Pedir: %d ", (new_cliente + i)->ClienteID);
		printf("\n");
	}
}

int main(){
	int cantCliente;
	char nombre[50];
	cliente *new_cliente;
	printf("Ingrese la cantidad de clientes: ");
	scanf("%d", &cantCliente);fflush(stdin);
	
	
	new_cliente = (cliente*)malloc(sizeof(cliente)*cantCliente);
	
	cargarClientes(new_cliente, cantCliente, nombre);
	mostrarClientes(new_cliente, cantCliente);
}


