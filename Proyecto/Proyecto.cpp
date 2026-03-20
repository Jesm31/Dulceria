#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Header1.h"

int tt = 1;

FILE* ticketss[100];
struct tickets {
	int clave;
	char nombre[15];
	float precioU;
	int cantidad;
	float total;

}TA[100];

struct inventarioO {
	int clave;
	char nombre[15];
	float precio;
	int cantidad;
	char ingreso[12];
	char caducidad[10];
	char proveedor[15];
	char correo[25];
	char tel[15];
}AT[50];

void INICIALIZAR(struct inventario AA[50]);
void ALTA(struct inventario AA[50]);
void BAJA(struct inventario AA[50]);
void CAMBIO(struct inventario AA[50]);
void REPORTE_COMPLETO(struct inventario AA[50]);
void REPORTE_CADUCIDAD(struct inventario AA[50]);
void REPORTE_ORDENES(struct inventario AA[50]);
void REPORTE_VENTAS(struct inventario AA[50], struct ticket TT[1000]);
void REPORTE_PRECIO(struct inventario AA[50]);
void REPORTE_CANTIDAD(struct inventario AA[50]);
void VENTAS(struct inventario AA[50], struct ticket TT[10]);
void ARCHIVO_COMPLETO(struct inventario AA[50]);
void LEER_REGISTRO(struct inventario AA[50]);
void BINARIO(struct inventario AA[50]);

int opc, c=0;
char basura[20];

int main() {
	INICIALIZAR(A);

	printf("----------MENU----------\n\n");
	do{
	printf("\n================\n1.Inventario\n 2.Ventas\n 3.Archivos\n 4.Salir\n================\n");
	scanf_s("%i", &opc);
	
		switch (opc) {
			case 1:
				printf("1.Alta\n2.Baja\n3.Cambio\n4.Reportes\n5.Regresar\n");
				scanf_s("%i", &opc);
				switch (opc) {
				case 1:
					ALTA(A);
					break;
				case 2:
					BAJA(A);
					break;
				case 3:
					CAMBIO(A);
					break;
				case 4:
						printf("\n1.-Reporte Completo\n2.-Reporte por Caducidad\n3.-Reporte por Ordenes de compra\n4.-Reporte de Ventas del Dia\n5.-Reporte por precio\n6.-Reporte por cantidad\n7.-Regresar\n");
						scanf_s("%i", &opc);
						switch (opc) {
							case 1:
								REPORTE_COMPLETO(A);
								break;
							case 2:
								gets_s(basura);
								REPORTE_CADUCIDAD(A);
								break;
							case 3:
								REPORTE_ORDENES(A);
								break;
							case 4:
								REPORTE_VENTAS(A, T);
								break;
							case 5:
								REPORTE_PRECIO(A);
								break;
							case 6:
								REPORTE_CANTIDAD(A);
								break;
							case 7:
								break;
						}
					break;



				case 5:
					break;
					}
				break;
			case 2:
				VENTAS(A, T);
				break;
			case 3:
				printf("1.Generar archivo de registro\n2.Leer Archivo de Registro\n3.Crear archivo binario\n");
				scanf_s("%i", &opc);
				switch (opc) {
					case 1:
					ARCHIVO_COMPLETO(A);
					break;
					case 2:
					LEER_REGISTRO(A);
					break;
					case 3:
						BINARIO(A);


				}
	
				
				break;
			case 4:
				c = 1;
				break;

		}
	} while (c == 0);
	
	
}


/*void ALTA(struct inventario AA[50]) {
	int i = 0, j, n = 0, a = 0, k = 0, p = 0, h = 0;
	char basura[50];
	char correo[25];
	char* p1;
	char* p2;
	char* p3;
	char* p4;
	char ing[10];
	char cad[10];


	do {
		i++;
	} while (AA[i].clave != 9999);
	printf("Clave del nuevo producto: ");
	scanf_s(" %i", &AA[i].clave);
	fflush(stdin);
	for (j = 0; j < i;j++)
		if (AA[j].clave == AA[i].clave) {
			n = 1;
		}
	while (n == 1) {
		printf("Clave ya existente, ingrese una nueva: ");
		scanf_s("%i", &AA[i].clave);
		fflush(stdin);
		n = 0;
		for (j = 0; j < i;j++)
			if (AA[j].clave == AA[i].clave) {
				n = 1;
			}
	}
	n = 0;
	fflush(stdin);
	gets_s(basura);
	printf(" Nombre del nuevo producto: ");
	fflush(stdin);
	gets_s(AA[i].nombre);
	for (j = 0; j < i; j++)
		if (strcmp(AA[j].nombre, AA[i].nombre) == 0) {
			n = 1;
		}
	while (n == 1) {
		printf("Producto ya existente, ingrese nuevo nombre: ");
		gets_s(AA[i].nombre);
		n = 0;
		for (j = 0; j < i;j++)
			if (strcmp(AA[j].nombre, AA[i].nombre) == 0)
				n = 1;
	}
	printf("\nPrecio: ");
	scanf_s(" %f", &AA[i].precio);
	while (AA[i].precio <= 0) {
		printf("Precio invalido, ingrese de nuevo: ");
		scanf_s("%f", &AA[i].precio);
	}
	printf("Cantidad: ");
	scanf_s("%i", &AA[i].cantidad);
	while (AA[i].cantidad <= 0) {
		printf("Cantidad invalida, ingrese de nuevo: ");
		scanf_s("%i", &AA[i].cantidad);
	}
	gets_s(basura);
	printf("Fecha de ingreso(dd/mm/yy): ");
	gets_s(ing);

	while (ing[2] != '/' || ing[5] != '/' || strlen(ing) != 8) {
		printf("Fecha invalida, ingrese de nuevo: ");
		gets_s(ing);
	}
	strcpy_s(AA[i].ingreso, ing);


	//gets_s(basura);
	printf("\nFecha de caducidad(mm/yy): ");
	gets_s(cad);

	while (cad[2] != '/' || strlen(cad) != 5) {
		printf("Fecha invalida, ingrese de nuevo: ");
		gets_s(cad);

	}
	strcpy_s(AA[i].caducidad, cad);


	//gets_s(basura);
	printf("Proveedor: ");
	gets_s(AA[i].proveedor);
	//gets_s(basura);
	printf("Correo(gmail, outlook, hotmail o yahoo): ");
	gets_s(correo);
	

	char d1[] = "@gmail.com";
	char d2[] = "@yahoo.com";
	char d3[] = "@outlook.com";
	char d4[] = "@hotmail.com";

	p1 = strstr(correo,d1);
	p2 = strstr(correo,d2);
	p3 = strstr(correo,d3);
	p4 = strstr(correo,d4); 

	for (j = 0;j < 25;j++) {
		if (correo[j] == '@') {
			h++;
		}
	}

	while (p1 == NULL && p2==NULL && p3==NULL && p4==NULL ||h >1) {
		printf("\nCorreo invalido, ingrese de nuevo: \n");
		gets_s(correo);
		p1 = strstr(correo, d1);
		p2 = strstr(correo, d2);
		p3 = strstr(correo, d3);
		p4 = strstr(correo, d4);
		h = 0;
		for (j = 0;j < 25;j++) {
			if (correo[j] == '@') {
				h++;
			}
		}
	}
	strcpy_s(AA[i].correo, correo);


	//	gets_s(basura);
		printf("Telefono: ");
		gets_s(AA[i].tel);

		while ((strlen(AA[i].tel))!=10) {
			printf("Teléfono invalido, ingrese de nuevo: ");
			gets_s(AA[i].tel);

		}
	//	gets_s(basura);


		printf("PRODUCTO AGREGADO EXITOSAMENTE!!\n");
		system("pause");


	
}

void BAJA(struct inventario AA[50]) {
	int i=0, j=0, clave;
	do {
		i++;
	} while (AA[i].clave != 9999);
	printf("Clave del producto a dar de baja: ");
	scanf_s("%i", &clave);
	for (j = 0; j < 50; j++) {
		if (AA[j].clave == clave) {
			AA[j].clave = 0;
			AA[j].cantidad = 0;
			AA[j].precio = 0;
			
			strcpy_s(AA[j].nombre, "0");
			strcpy_s(AA[j].proveedor, "0");
			strcpy_s(AA[j].tel, "0");
			strcpy_s(AA[j].correo, "0");
			strcpy_s(AA[j].ingreso, "0");
			strcpy_s(AA[j].caducidad, "0");

		}
	}
	printf("\nPRODUCTO DADO DE BAJA EXITOSAMENTE!!\n");
	system("pause");
}
void CAMBIO(struct inventario AA[50]) {
	int i=0, j=0, clave, n=0, h=0;
	char basura[50];
	char correo[25];
	char ing[10];
	char cad[10];
	char* b1;
		char* b2;
		char* b3;
		char* b4;
	printf("Clave del producto a cambiar: ");
	scanf_s("%i", &clave);
	while (clave != AA[i].clave)
		i++;
	printf("Clave del nuevo producto: ");
	scanf_s(" %i", &AA[i].clave);
	fflush(stdin);
	for (j = 0; j < i;j++)
		if (AA[j].clave == AA[i].clave) {
			n = 1;
		}
	while (n == 1) {
		printf("Clave ya existente, ingrese una nueva: ");
		scanf_s("%i", &AA[i].clave);
		fflush(stdin);
		n = 0;
		for (j = 0; j < i;j++)
			if (AA[j].clave == AA[i].clave) {
				n = 1;
			}
	}
	n = 0;
	fflush(stdin);
	gets_s(basura);
	printf(" Nombre del nuevo producto: ");
	fflush(stdin);
	gets_s(AA[i].nombre);
	for (j = 0; j < i; j++)
		if (strcmp(AA[j].nombre, AA[i].nombre) == 0) {
			n = 1;
		}
	while (n == 1) {
		printf("Producto ya existente, ingrese nuevo nombre: ");
		gets_s(AA[i].nombre);
		n = 0;
		for (j = 0; j < i;j++)
			if (strcmp(AA[j].nombre, AA[i].nombre) == 0)
				n = 1;
	}
	printf("\nPrecio: ");
	scanf_s(" %f", &AA[i].precio);
	while (AA[i].precio <= 0) {
		printf("Precio invalido, ingrese de nuevo: ");
		scanf_s("%f", &AA[i].precio);
	}
	printf("Cantidad: ");
	scanf_s("%i", &AA[i].cantidad);
	while (AA[i].cantidad <= 0) {
		printf("Cantidad invalida, ingrese de nuevo: ");
		scanf_s("%i", &AA[i].cantidad);
	}
	gets_s(basura);
	printf("Fecha de ingreso(dd/mm/yy): ");
	gets_s(ing);
	while (ing[2] != '/' || ing[5] != '/' || strlen(ing) != 8) {
		printf("Fecha invalida, ingrese de nuevo: ");
		gets_s(ing);
	}
	strcpy_s(AA[i].ingreso, ing);

	//gets_s(basura);

	printf("\nFecha de caducidad(mm/yy): ");
	gets_s(cad);

	while (cad[2] != '/' || strlen(cad) != 5) {
		printf("Fecha invalida, ingrese de nuevo: ");
		gets_s(cad);

	}
	strcpy_s(AA[i].caducidad, cad);


	//gets_s(basura);
	printf("Proveedor: ");
	gets_s(AA[i].proveedor);
	//gets_s(basura);
	printf("Correo: ");
	gets_s(correo);

	char r1[] = "@gmail.com";
	char r2[] = "@yahoo.com";
	char r3[] = "@outlook.com";
	char r4[] = "@hotmail.com";

	b1 = strstr(correo,r1);
	b2 = strstr(correo,r2);
	b3 = strstr(correo,r3);
	b4 = strstr(correo,r4);
	for (j = 0;j < 25;j++) {
		if (correo[j] == '@') {
			h++;
		}
	}

	while (b1 == NULL && b2 == NULL && b3 == NULL && b4 == NULL || h>1) {
		printf("\nCorreo invalido, ingrese de nuevo: \n");
		gets_s(correo);
		b1 = strstr(correo, r1);
		b2 = strstr(correo, r2);
		b3 = strstr(correo, r3);
		b4 = strstr(correo, r4);
		h = 0;
		for (j = 0;j < 25;j++) {
			if (correo[j] == '@') {
				h++;
			}
		}
	}

	strcpy_s(AA[i].correo, correo);

	//	gets_s(basura);
	printf("Telefono: ");
	gets_s(AA[i].tel);
	while ((strlen(AA[i].tel)) != 10) {
		printf("Teléfono invalido, ingrese de nuevo: ");
		gets_s(AA[i].tel);

	}
	//	gets_s(basura);

	printf("PRODUCTO CAMBIADO EXITOSAMENTE!!\n");
	system("pause");


}
void REPORTE_COMPLETO(struct inventario AA[50]) {
	int i, j=0;
	while (AA[j].clave!=9999) {
		j++;

	}
	printf("\nREPORTE COMPLETO\n\n");
	for (i = 0; i < j; i++) {
		printf("PRODUCTO %i\n", i + 1);
		printf("Clave: %i\n", AA[i].clave);
		printf("Nombre: %s\n", AA[i].nombre);
		printf("Precio: %.2f\n", AA[i].precio);
		printf("Cantidad: %i\n", AA[i].cantidad);
		printf("Ingreso: %s\n", AA[i].ingreso);
		printf("Caducidad: %s\n", AA[i].caducidad);
		printf("Proveedor: %s\n", AA[i].proveedor);
		printf("Correo: %s\n", AA[i].correo);
		printf("Telefono: %s\n", AA[i].tel);
		printf("\n\n");



	}

}
void REPORTE_CADUCIDAD(struct inventario AA[50]) {
	char fecha[20] ,basura[10];
	int i, j=0, n=0;
	printf("\nMes y año(mm/yy): \n");
	gets_s(fecha);
	while (AA[j].clave != 9999) {
		j++;
	}
	printf("\nREPORTE PRODUCTOS CADUCADOS:\n");
	for (i = 0; i < j; i++) {
		if (strcmp(AA[i].caducidad,fecha) <= 0) {
			n = 1;
			printf("PRODUCTO CADUCADO %i\n", i + 1);
			printf("Clave: %i\n", AA[i].clave);
			printf("Nombre: %s\n", AA[i].nombre);
			printf("Precio: %.2f\n", AA[i].precio);
			printf("Cantidad: %i\n", AA[i].cantidad);
			printf("Ingreso: %s\n", AA[i].ingreso);
			printf("Caducidad: %s\n", AA[i].caducidad);
			printf("Proveedor: %s\n", AA[i].proveedor);
			printf("Correo: %s\n", AA[i].correo);
			printf("Telefono: %s\n", AA[i].tel);
			printf("\n\n");

		}

	}
	if (n == 0) {
		printf("\nNO HAY PRODUCTOS CADUCADOS!!\n");

	}
	system("pause");

}


void REPORTE_ORDENES(struct inventario AA[50]) {
	int i, n=0, cant=0, j=0, c=0;

	printf("\nPRODUCTOS AGOTADOS O POR AGOTARSE: \n");

	while (AA[j].clave!=9999) {
		j++;
	}
	for (i = 0;i < j;i++) {
		if (AA[i].cantidad < 2) {
			printf("Orden de compra %i\n", i + 1);
			printf("Clave: %i\n", AA[i].clave);
			printf("Producto: %s\n", AA[i].nombre);
			printf("Proveedor: %s\n", AA[i].proveedor);
			printf("Telefono: %s\n", AA[i].tel);
			printf("Correo: %s\n", AA[i].correo);
			printf("Cantidad: %i\n", AA[i].cantidad);
			c++;
		}
	}
	if (c == 0) {
		printf("NO HAY PRODUCTOS POR AGOTARSE\n");
	}
	system("pause");
			
}

void REPORTE_VENTAS(struct inventario AA[50], struct ticket TT[100]) {
	int i, j=0;

	while (TT[j].clave != 0) {
		j++;

	}

	printf("\nREPORTE VENTAS\n");
	for (i = 0; i < j; i++) {
		printf("Ticket %i\n", i + 1);
		printf("Clave: %i\n", TT[i].clave);
		printf("Nombre: %s\n", TT[i].nombre);
		printf("Precio unitario: %.2f\n", TT[i].precioU);
		printf("Cantidad: %i\n", TT[i].cantidad);
		printf("Total: %.2f\n", TT[i].total);
		printf("\n");


	}

}
void REPORTE_PRECIO(struct inventario AA[50]) {
	struct inventario AAA[50];

	int i, j,n=0;
	float temp;
	char aux[25];

	for (i = 0;i < 50;i++) {
		AAA[i].clave = AA[i].clave;
		AAA[i].precio = AA[i].precio;
		AAA[i].cantidad = AA[i].cantidad;
		strcpy_s(AAA[i].nombre, AA[i].nombre);
		strcpy_s(AAA[i].proveedor, AA[i].proveedor);
		strcpy_s(AAA[i].correo, AA[i].correo);
		strcpy_s(AAA[i].tel, AA[i].tel);
		strcpy_s(AAA[i].ingreso, AA[i].ingreso);
		strcpy_s(AAA[i].caducidad, AA[i].caducidad);
	}
	j = 0;
	while (AA[n].clave != 9999) {
		n++;

	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (AAA[j].precio > AAA[j + 1].precio) {
				temp = AAA[j].precio;
				AAA[j].precio = AAA[j + 1].precio;
				AAA[j + 1].precio = temp;

				temp = AAA[j].clave;
				AAA[j].clave = AAA[j + 1].clave;
				AAA[j + 1].clave = temp;

				temp = AAA[j].cantidad;
				AAA[j].cantidad = AAA[j + 1].cantidad;
				AAA[j + 1].cantidad = temp;


				strcpy_s(aux, AAA[j].nombre);
				strcpy_s(AAA[j].nombre, AAA[j+1].nombre);
				strcpy_s(AAA[j + 1].nombre,aux);

				strcpy_s(aux, AAA[j].proveedor);
				strcpy_s(AAA[j].proveedor, AAA[j + 1].proveedor);
				strcpy_s(AAA[j + 1].proveedor, aux);

				strcpy_s(aux, AAA[j].tel);
				strcpy_s(AAA[j].tel, AAA[j + 1].tel);
				strcpy_s(AAA[j + 1].tel, aux);

				strcpy_s(aux, AAA[j].correo);
				strcpy_s(AAA[j].correo, AAA[j + 1].correo);
				strcpy_s(AAA[j + 1].correo, aux);

				strcpy_s(aux, AAA[j].ingreso);
				strcpy_s(AAA[j].ingreso, AAA[j + 1].ingreso);
				strcpy_s(AAA[j + 1].ingreso, aux);

				strcpy_s(aux, AAA[j].caducidad);
				strcpy_s(AAA[j].caducidad, AAA[j + 1].caducidad);
				strcpy_s(AAA[j + 1].caducidad, aux);



				
			}
		}
	}
	j = 0;
	while (AA[j].clave != 9999) {
		j++;

	}
	printf("REPORTE POR PRECIO(MENOR A MAYOR)\n\n");
	for (i = 0;i < j;i++) {
		printf("PRODUCTO %i\n", i + 1);
		printf("Clave: %i\n", AAA[i].clave);
		printf("Nombre: %s\n", AAA[i].nombre);
		printf("Precio: %.2f\n", AAA[i].precio);
		printf("Cantidad: %i\n", AAA[i].cantidad);
		printf("Ingreso: %s\n", AAA[i].ingreso);
		printf("Caducidad: %s\n", AAA[i].caducidad);
		printf("Proveedor: %s\n", AAA[i].proveedor);
		printf("Correo: %s\n", AAA[i].correo);
		printf("Telefono: %s\n", AAA[i].tel);
		printf("\n\n");
	} 
}
void REPORTE_CANTIDAD(struct inventario AA[50]) {
	struct inventario AAA[50];

	int i, j, n = 0;
	float temp;
	char aux[25];

	for (i = 0;i < 50;i++) {
		AAA[i].clave = AA[i].clave;
		AAA[i].precio = AA[i].precio;
		AAA[i].cantidad = AA[i].cantidad;
		strcpy_s(AAA[i].nombre, AA[i].nombre);
		strcpy_s(AAA[i].proveedor, AA[i].proveedor);
		strcpy_s(AAA[i].correo, AA[i].correo);
		strcpy_s(AAA[i].tel, AA[i].tel);
		strcpy_s(AAA[i].ingreso, AA[i].ingreso);
		strcpy_s(AAA[i].caducidad, AA[i].caducidad);
	}
	j = 0;
	while (AA[n].clave != 9999) {
		n++;

	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (AAA[j].cantidad > AAA[j + 1].cantidad) {
				temp = AAA[j].precio;
				AAA[j].precio = AAA[j + 1].precio;
				AAA[j + 1].precio = temp;

				temp = AAA[j].clave;
				AAA[j].clave = AAA[j + 1].clave;
				AAA[j + 1].clave = temp;

				temp = AAA[j].cantidad;
				AAA[j].cantidad = AAA[j + 1].cantidad;
				AAA[j + 1].cantidad = temp;


				strcpy_s(aux, AAA[j].nombre);
				strcpy_s(AAA[j].nombre, AAA[j + 1].nombre);
				strcpy_s(AAA[j + 1].nombre, aux);

				strcpy_s(aux, AAA[j].proveedor);
				strcpy_s(AAA[j].proveedor, AAA[j + 1].proveedor);
				strcpy_s(AAA[j + 1].proveedor, aux);

				strcpy_s(aux, AAA[j].tel);
				strcpy_s(AAA[j].tel, AAA[j + 1].tel);
				strcpy_s(AAA[j + 1].tel, aux);

				strcpy_s(aux, AAA[j].correo);
				strcpy_s(AAA[j].correo, AAA[j + 1].correo);
				strcpy_s(AAA[j + 1].correo, aux);

				strcpy_s(aux, AAA[j].ingreso);
				strcpy_s(AAA[j].ingreso, AAA[j + 1].ingreso);
				strcpy_s(AAA[j + 1].ingreso, aux);

				strcpy_s(aux, AAA[j].caducidad);
				strcpy_s(AAA[j].caducidad, AAA[j + 1].caducidad);
				strcpy_s(AAA[j + 1].caducidad, aux);




			}
		}
	}
	j = 0;
	while (AA[j].clave != 9999) {
		j++;

	}
	printf("REPORTE POR CANTIDAD(MENOR A MAYOR)\n\n");
	for (i = 0;i < j;i++) {
		printf("PRODUCTO %i\n", i + 1);
		printf("Clave: %i\n", AAA[i].clave);
		printf("Nombre: %s\n", AAA[i].nombre);
		printf("Precio: %.2f\n", AAA[i].precio);
		printf("Cantidad: %i\n", AAA[i].cantidad);
		printf("Ingreso: %s\n", AAA[i].ingreso);
		printf("Caducidad: %s\n", AAA[i].caducidad);
		printf("Proveedor: %s\n", AAA[i].proveedor);
		printf("Correo: %s\n", AAA[i].correo);
		printf("Telefono: %s\n", AAA[i].tel);
		printf("\n\n");
	}

}

void VENTAS(struct inventario AA[50], struct ticket TT[10]) {
	int i, j=0, clave, c, k=0, cant=0, n=0, o=0;
		float precio_T;

	printf("Clave del producto a vender: ");
	scanf_s("%i", &clave);
	for (i = 0; i < 50; i++)
		if (clave == AA[i].clave) {
			n = 1;
		}
	while (n == 0) {
		printf("Clave no existente, ingrese de nuevo: ");
		scanf_s("%i", &clave);
		for (i = 0; i < 50; i++)
			if (clave == AA[i].clave) {
				n = 1;
			}
	}


	printf("Cantidad a vender: ");
	scanf_s("%i", &c);
	for (i = 0; i < 50; i++) {
		if (clave == AA[i].clave) {
			while(c > AA[i].cantidad) {
				printf("Cantidad insuficiente, ingrese de nuevo: ");
					scanf_s("%i", &c);
			}
			precio_T = c * AA[i].precio;
			AA[i].cantidad = AA[i].cantidad - c;
			i = i + 100;
		}
		j++;
		
	}
	j--;



	printf("TICKET DE VENTA\n");
	printf("Clave: %i\nNombre: %s\nPrecio unitario: %.2f\nCantidad: %i\nTotal a pagar: %.2f ", AA[j].clave, AA[j].nombre, AA[j].precio,c, precio_T);
	printf("\nTICKET GENERADO EXITOSAMENTE!!\n");

	char nArchivo[100];
	FILE* T;

	T = fopen("data.txt", "r");
	fscanf_s(T, "%i", &t);
	fclose(T);

	



	sprintf(nArchivo, "Tickets/Ticket%i.txt", t);

	
	
	tickets[t] = fopen(nArchivo, "w");


	fprintf(tickets[t], "====DULCERIA C====\n");
	fprintf(tickets[t], "---Apodaca, Nuevo Leon---\n");
	fprintf(tickets[t], "Ticket %i", t);
	fprintf(tickets[t], "\nClave: %i ", AA[j].clave);
	fprintf(tickets[t], "\nNombre: %s", AA[j].nombre);
	fprintf(tickets[t], "\nPrecio: %.2f", AA[j].precio);
	fprintf(tickets[t], "\nCantidad: %i", c);
	fprintf(tickets[t], "\nPrecio total:  %.2f", precio_T);
	fprintf(tickets[t],"\n\nContactanos!\nCorreo: DulceriaC@gmail.com\nTelefono: 8111197258\n");


	fclose(tickets[t]);

	


	system("pause");
	while (TT[k].clave != 0)
		k++;
	TT[k].clave = AA[j].clave;
	strcpy_s(TT[k].nombre, AA[j].nombre);
	TT[k].precioU = AA[j].precio;
	TT[k].total = precio_T;
	TT[k].cantidad = c;

	t++;
	

	T = fopen("data.txt", "w");
	fprintf(T, "%i", t);

	fclose(T);




	







}


void ARCHIVO_COMPLETO(struct inventario AA[50]) {
	int i, j = 0;
	while (AA[j].clave != 9999) {
		j++;

	}
	FILE* INVENTARIO;
	FILE* REGISTRO;
	

	

	INVENTARIO = fopen("Registro.txt" ,"w");
	for (i = 0;i < j;i++) {

		fprintf(INVENTARIO,"PRODUCTO %i\n", i + 1);
		fprintf(INVENTARIO,"Clave: %i\n", AA[i].clave);
		fprintf(INVENTARIO,"Nombre: %s\n", AA[i].nombre);
		fprintf(INVENTARIO,"Precio: %.2f\n", AA[i].precio);
		fprintf(INVENTARIO,"Cantidad: %i\n", AA[i].cantidad);
		fprintf(INVENTARIO,"Ingreso: %s\n", AA[i].ingreso);
		fprintf(INVENTARIO,"Caducidad: %s\n", AA[i].caducidad);
		fprintf(INVENTARIO,"Proveedor: %s\n", AA[i].proveedor);
		fprintf(INVENTARIO,"Correo: %s\n", AA[i].correo);
		fprintf(INVENTARIO,"Telefono: %s\n", AA[i].tel);
		fprintf(INVENTARIO,"\n\n");

	}

	fclose(INVENTARIO);

	REGISTRO = fopen("datos.txt", "w");
	for (i = 0;i < j;i++) {
		fprintf(REGISTRO, "%i\n", AA[i].clave);
		fprintf(REGISTRO, "%s\n", AA[i].nombre);
		fprintf(REGISTRO, "%.2f\n", AA[i].precio);
		fprintf(REGISTRO, "%i\n", AA[i].cantidad);
		fprintf(REGISTRO, "%s\n", AA[i].ingreso);
		fprintf(REGISTRO, "%s\n", AA[i].caducidad);
		fprintf(REGISTRO, "%s\n", AA[i].proveedor);
		fprintf(REGISTRO, "%s\n", AA[i].correo);
		fprintf(REGISTRO, "%s\n", AA[i].tel);

	}

	


	printf("\nArchivo Generado!!\n");




}
void LEER_REGISTRO(struct inventario AA[50]) {
	int i=0;
	char basura;
	FILE* REGISTROO;

	REGISTROO = fopen("datos.txt", "r");

	if (REGISTROO == NULL) {
		printf("No existe el archivo!\n");
	}
	else {
		while (feof(REGISTROO) == 0) {

			fscanf(REGISTROO, "%i", &AA[i].clave);
			basura = fgetc(REGISTROO);
			fgets(AA[i].nombre, 25, REGISTROO);
			fscanf(REGISTROO, "%f", &AA[i].precio);
			fscanf(REGISTROO, "%i", &AA[i].cantidad);
			basura = fgetc(REGISTROO);
			fgets(AA[i].ingreso, 25, REGISTROO);
			fgets(AA[i].caducidad, 25, REGISTROO);
			fgets(AA[i].proveedor, 25, REGISTROO);
			fgets(AA[i].correo, 25, REGISTROO);
			fgets(AA[i].tel, 25, REGISTROO);

			i++;
				
		}
	}
	fclose(REGISTROO);

	printf("\nArchivo leido!!\n");

}

void BINARIO(struct inventario AA[50]) {

	FILE* BI;
	BI = fopen("Binario.bin", "wb");
	
		fwrite(AA, sizeof(struct inventario), 50, BI);
		fprintf(BI, "\n");


	fclose(BI);

	printf("\nArchivo creado!!\n");




}
















void INICIALIZAR(struct inventario AA[50]) {
	int i;

	  AA[0] =
	{
		2001, "Tutsi Pop", 5.00, 100, "25/03/23", "05/23", "May Day", "May_Day@gmail.com", "4961270681"
	};
	 AA[1] =
	{
		2002, "Pulparindo", 8.00, 55, "25/03/23", "05/23", "Rosa", "Ros_dul@hotmail.com", "2377723050"
	};
	  AA[2] =
	{
		2003, "Pica-fresas", 2.00, 40, "25/03/23", "05/23", "Comercio", "Dul_Co@yahoo.com", "2208650272"
	};
	  AA[3] =
	{
		2004, "Tamborcitos", 2.00, 40, "25/03/23", "06/23", "Enviro", "Enviro_D@gmail.com", "8755224980"
	};
	 AA[4] =
	{
		2005, "Bombones", 15.00, 50, "20/03/23", "07/23", "Primavera", "Primav@gmail.com", "2418522044"
	};
	  AA[5] =
	{
		2006, "Tarugos", 5.00, 75, "20/03/23", "07/23", "Nuevo Mundo", "NuevoM@gmail.com", "7586825364"
	};
	  AA[6] =
	{
		2007, "Bubbaloo", 1.00, 80, "20/03/23", "07/23", "Brite dulces", "Brite@outlook.com", "9960649695"
	};
	  AA[7] =
	{
		2008, "Snickers", 17.00, 55, "20/03/23", "07/23", "Petra", "Petra@yahoo.com", "7843474680"
	};
	  AA[8] =
	{
		2009, "M&M´s", 20.00, 25, "20/03/23", "05/23", "Luxus", "Luxus@gmail.com", "5373417563"
	};
	  AA[9] =
	{
		2010, "Duvalin", 7.00, 30, "27/03/23", "10/23", "El descuento", "DulcesD@gmail.com", "3267745997"
	};
	  AA[10] =
	{
		2011, "Bubu-lubu", 8.00, 40, "27/03/23", "10/23", "CandyMania", "Mania@gmail.com", "3530809685"
	};
	  AA[11] =
	{
		2012, "Mazapan", 5.00, 50, "27/03/23", "10/23",  "De la Rosa", "DeRosa@gmail.com", "4774564881"
	};
	  AA[12] =
	{
		2013, "Panditas", 16.00, 60, "27/03/23", "10/23", "Surtidulces", "Surtidul@gmail.com", "6160767531"
	};
	  AA[13] =
	{
		2014, "Rebanaditas", 5.00, 75, "27/03/23", "05/23", "JM", "JM@gmail.com","2696985334"
	};
	  AA[14] =
	{
		2015, "Glorias", 12.00, 20, "27/03/23", "06/23", "Tobi", "Tobi@yahoo.com", "7951987707"
	};
	  AA[15] =
	{
		2016, "Winis", 9.00, 15, "30/03/23", "06/23", "Sonrick´s", "Sonrick@hotmail.com", "9252263120"
	};
	 AA[16] =
	{
		2017, "Nerds", 10.00, 25, "30/03/23", "05/23", "Ricolino", "Rico@hotmail.com", "6424542509"
	};
	  AA[17] =
	{
		2018, "Reese´s", 6.00, 30, "30/03/23", "11/23", "Gutierrez", "GruGut@hotmail.com", "3480011033"
	};
	  AA[18] =
	{
		2019, "Bokadin", 5.00, 10, "30/03/23", "08/23", "Candyrico", "CanRi@hotmail.com", "0342260178"
	};
	  AA[19] =
	{
		2020, "Halls", 12.00, 30, "30/03/23", "08/23", "Cospor", "Cospor@gmail.com", "9418623424"
	};

	  for (i = 20;i < 50; i++) {
		  AA[i].clave = 9999;
	  }








	  */
//}
