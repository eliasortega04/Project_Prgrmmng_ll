/* ********************* TEXTO SIN ACENTOS *********************/
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
	unsigned int blldng;
	unsigned int clssrm;
	float dscnt;
	float sbttl;
	float ttl;
}; // Estructura de pedido

int main() {
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
  }
	

	// tambien arreglos Usar system("cls"); en Dev C++ para limpiar pantalla. 
	// Mon y Denisse: Switch para pedido, con funciones, con arreglos, variables de esructura.
  

  //Elias 28/04/20: Creación y asignación de estructuras y trabajo para ambos

	return 0;
}