/********************** TEXTO SIN ACENTOS *********************/
// Codigo programado con exito en Dev C++ 

#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define T 20

struct rgstr {
	char user[T - 5];
	char psswrd[T - 10];
	char name[T];
}; // Estructura de inicio de sesion 

struct order {
	unsigned int nmbr_order;
	unsigned int blldng; //edificio
	unsigned int clssrm; //salon
	float dscnt;
	float sbttl;
	float ttl;
  char plc[T+10];//lugar 
}; // Estructura de pedido

int main (){
  int op;
  struct rgstr users[T-18], *ptr;
  ptr = users;
  
  // Elias y Ariz: Switch inicio y registro de sesión, con funciones y apuntadores, variables de estructura, funciones.
  error: printf("******\t\tNOMBRE DE LA APP\t\t******\n");
  printf("1. Registro.\n");
  printf("2. Iniciar Sesion.\n");
  printf("3. Salir.\n");
  printf("Elige una opcion: ");
  scanf("%d", &op);
  switch(op){
    case 1: 
		system("cls");
		Register();
    break;
    
    case 2: 
		system("cls");
    break;
	
	case 3: 
		system("cls");
		exit(1);
    break;
	
    default: 
      printf("Opcion no encontrada :( \n");
      printf("Ingresa una opcion valida.\n");
      system("pause");
      system("cls");
      goto error;
  } //Switch principal
	

	// tambien arreglos Usar system("cls"); en Dev C++ para limpiar pantalla. 
	// Mon y Denisse: Switch para pedido, con funciones, con arreglos, variables de esructura.
  error_ord: printf("******\t\tCOMIDA\t\t******\n");
  printf("1. Torta.\n");
  printf("2. Tacos.\n");
  printf("3. Hamburguesa.\n");
  printf("4. Chilaquiles.\n");
  printf("5. Burrito.\n");
  printf("6. Gringa\n");
  printf("Elige una opcion: ");
  scanf("%d", &op_order);
  switch(op_order){
    case 1: 
    system("cls");
    Torta();
		break;
    case 2:
		system("cls");
    Tacos();
    break;
	  case 3: 
		system("cls");
    Hambuguesa();
    break;
    case 4:
    system("cls");
    Chilaquiles();
    break;
    case 5:
    system("cls");
    Burrito();
    break;
    case 6:
    system("cls");
    Gringa();
    break;
    default: 
      printf("Opcion no encontrada :( \n");
      printf("Ingresa una opcion valida.\n");
      system("pause");
      system("cls");
      goto error_ord;
  }
  //Denisse y Monse 28-29/04/20: Creación de switch de comida y las funciones para cada alimento con opcion de sabor
  

  //Elias 28/04/20: Creación y asignación de estructuras y trabajo para ambos

	return 0;
}