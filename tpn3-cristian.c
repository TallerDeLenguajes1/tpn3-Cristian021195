#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Producto{
	int productoID;
	int cantidad; //entre 1 y 10
	char *tipoProducto; //valor del arreglo TiposProductos
	float precioUnitario; //entre 10 - 100
}Producto;

typedef struct Cliente{
	int clienteID;
	char nombreCliente[20]; //ingresado por usuario
	int cantidadProductosAPedir; //aleatorio entre 1 y 5
	Producto *productos; //El tamaño de este arreglo depende de la variable “cantidadProductosAPedir”
}Cliente;

char tiposProductos[5][12]={"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

void cargarClientes(Cliente *pVenta, int n);
void cargarProductos(int n, Producto *productosComprados);
void mostrarTodo(Cliente *pVenta, int n);
float costoTotal(Producto prod);

int main(){
	srand(time(NULL));
	int clientes;
	do{
		printf("Ingrese la cantidad de clientes: "); scanf("%d",&clientes);fflush(stdin);
		if(clientes < 0){
			clientes *= -1;
		}
	}while(clientes > 5);if(clientes == 0) return 0;
	
	Cliente *venta = (Cliente *) malloc(clientes*sizeof(Cliente));
	
	cargarClientes(venta, clientes);
	system("CLS");
	mostrarTodo(venta, clientes);
	free(venta);
	return 0;
}

void cargarClientes(Cliente *venta, int n){
	Cliente clienteAct;
	for(int i = 0; i < n; i++){
		clienteAct.clienteID = i+1;
		printf("\nCLIENTE %d:\nIngrese el nombre del cliente: ",i+1); gets(clienteAct.nombreCliente);
		clienteAct.cantidadProductosAPedir = rand()%10 +1;		
		Producto *productosComprados = (Producto *) malloc(clienteAct.cantidadProductosAPedir*sizeof(Producto));
		cargarProductos(clienteAct.cantidadProductosAPedir, productosComprados);
		clienteAct.productos = productosComprados;
		
		*venta = clienteAct;
		venta++;
	}
}

void cargarProductos(int n, Producto *productosComprados){
	Producto productoAct;
	
	for(int i = 0; i < n; i++){
		productoAct.productoID = rand()%4;
		productoAct.tipoProducto = tiposProductos[productoAct.productoID];
		productoAct.cantidad = rand()%10 +1;
		productoAct.precioUnitario = rand()%91 +10 +(rand()%100)*0.01;
				
		*productosComprados = productoAct;
		productosComprados++;
	}
}

void mostrarTodo(Cliente *venta, int n){
	Cliente act;
	Producto actP;
	int i, j;
	float total, total_venta;
	total_venta = 0;
	
	printf("\n\n------------------***-----------------\nLISTADO DE VENTAS:\n---------------***--------------------");
	for(j = 0; j < n; j++){
		act = *venta;
		printf("\nCliente #%d:",act.clienteID);
		printf("\nNombre: %s",act.nombreCliente);
		printf("\nProductos Ordenados: %d",act.cantidadProductosAPedir);
		printf("\n-----------------------------------");
		total = 0;
		
		for(i = 0; i < act.cantidadProductosAPedir; i++){
			actP = act.productos[i];
			printf("\n\n  Producto #%d:",actP.productoID);
			printf("\n\tTipo de producto: %s",actP.tipoProducto);
			printf("\n\tCantidad: %d",actP.cantidad);
			printf("\n\tPrecio unitario: %.2f",actP.precioUnitario);
			printf("\n\tTotal: %.2f",costoTotal(actP));
			
			total += costoTotal(actP);
		}
		total_venta+=total;
		printf("\n\nTotal del cliente: %.2f",total);
		printf("\n\n-----------------------------------");		
		venta++;
	}printf("\n\n-------TOTAL VENTA: %.2f--------", total_venta);
}

float costoTotal(Producto prod){
	float total;
	total = prod.cantidad * prod.precioUnitario;
	return total;
}
