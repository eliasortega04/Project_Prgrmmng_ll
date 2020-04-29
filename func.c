#include <stdio.h>
#include "func.h"

int Register(){
	printf("Hola\n");
  return(0);
}

int login(){
	printf("Usuario\n");
  return(0);
}
int  Torta(){
	int cant_1, sab_1, past_1=0, pll_1=0, bist_1=0;
  float prc_1;
  const float tort=20.00f;
  printf("Precio: $%.2f\n", tort);
  otra_vez: printf("\n\n******\t\tSABORES\t\t*****\n");
  printf("1. Pastor.\n");
  printf("2. Pollo.\n");
  printf("3. Bistec.\n");
  printf("Elige una opcion: ");
  scanf("%d", &sab_1);
  switch(sab_1){
    case 1:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &past_1);
    break;

    case 2:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &pll_1);
    break;

    case 3:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &bist_1);
    break;

    default: 
      printf("Opcion no encontrada :( \n");
      printf("Ingresa una opcion valida.\n");
      goto otra_vez;

  }
  cant_1= past_1 + pll_1 + bist_1;
  prc_1= cant_1*tort;
  printf("\nTotal de Tortas: $%.2f", prc_1);
  return 0;
}

int Tacos(){
	int cant_2, sab_2, past_2=0, pll_2=0, bist_2=0;
  float prc_2;
  const float tac=20.00f;
  printf("Precio: $%.2f\n", tac);
  otra_vez: printf("\n\n******\t\tSABORES\t\t*****\n");
  printf("1. Pastor.\n");
  printf("2. Pollo.\n");
  printf("3. Bistec.\n");
  printf("Elige una opcion: ");
  scanf("%d", &sab_2);
  switch(sab_2){
    case 1:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &past_2);
    break;

    case 2:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &pll_2);
    break;

    case 3:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &bist_2);
    break;

    default: 
      printf("Opcion no encontrada :( \n");
      printf("Ingresa una opcion valida.\n");
      goto otra_vez;

  }
  cant_2= past_2 + pll_2 + bist_2;
  prc_2= cant_2*tac;
  printf("\nTotal de Tacos: $%.2f", prc_2);
  return 0;
}

int Hambuguesa(){
	int cant_3, sab_3, past_3=0, pll_3=0, bist_3=0;
  float prc_3;
  const float ham=25.00f;
  printf("Precio: $%.2f\n", ham);
  otra_vez: printf("\n\n******\t\tSABORES\t\t*****\n");
  printf("1. Pastor.\n");
  printf("2. Pollo.\n");
  printf("3. Bistec.\n");
  printf("Elige una opcion: ");
  scanf("%d", &sab_3);
  switch(sab_3){
    case 1:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &past_3);
    break;

    case 2:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &pll_3);
    break;

    case 3:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &bist_3);
    break;

    default: 
      printf("Opcion no encontrada :( \n");
      printf("Ingresa una opcion valida.\n");
      goto otra_vez;

  }
  cant_3= past_3 + pll_3 + bist_3;
  prc_3= cant_3*ham;
  printf("\nTotal de Hambuguesas: $%.2f", prc_3);
  return 0;
}

int Chilaquiles(){
	int cant_4, sab_4, past_4=0, pll_4=0, bist_4=0;
  float prc_4;
  const float chiq=20.00f;
  printf("Precio: $%.2f\n", chiq);
  otra_vez: printf("\n\n******\t\tSABORES\t\t*****\n");
  printf("1. Pastor.\n");
  printf("2. Pollo.\n");
  printf("3. Bistec.\n");
  printf("Elige una opcion: ");
  scanf("%d", &sab_4);
  switch(sab_4){
    case 1:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &past_4);
    break;

    case 2:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &pll_4);
    break;

    case 3:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &bist_4);
    break;

    default: 
      printf("Opcion no encontrada :( \n");
      printf("Ingresa una opcion valida.\n");
      goto otra_vez;

  }
  cant_4= past_4 + pll_4 + bist_4;
  prc_4= cant_4*chiq;
  printf("\nTotal de Chilaquiles: $%.2f", prc_4);
  return 0;
}

int Burrito(){
int cant_5, sab_5, past_5=0, pll_5=0, bist_5=0;
  float prc_5;
  const float bur=35.00f;
  printf("Precio: $%.2f\n", bur);
  otra_vez: printf("\n\n******\t\tSABORES\t\t*****\n");
  printf("1. Pastor.\n");
  printf("2. Pollo.\n");
  printf("3. Bistec.\n");
  printf("Elige una opcion: ");
  scanf("%d", &sab_5);
  switch(sab_5){
    case 1:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &past_5);
    break;

    case 2:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &pll_5);
    break;

    case 3:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &bist_5);
    break;

    default: 
      printf("Opcion no encontrada :( \n");
      printf("Ingresa una opcion valida.\n");
      goto otra_vez;

  }
  cant_5= past_5 + pll_5 + bist_5;
  prc_5= cant_5*bur;
  printf("\nTotal de Burritos: $%.2f", prc_5);
  return 0;
}

int Gringa(){
  int cant_6, sab_6, past_6=0, pll_6=0, bist_6=0;
  float prc_6;
  const float grin=35.00f;
  printf("Precio: $%.2f\n", grin);
  otra_vez: printf("\n\n******\t\tSABORES\t\t*****\n");
  printf("1. Pastor.\n");
  printf("2. Pollo.\n");
  printf("3. Bistec.\n");
  printf("Elige una opcion: ");
  scanf("%d", &sab_6);
  switch(sab_6){
    case 1:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &past_6);
    break;

    case 2:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &pll_6);
    break;

    case 3:
    printf("\nSelecciona la cantidad: ");
    scanf("%d", &bist_6);
    break;

    default: 
      printf("Opcion no encontrada :( \n");
      printf("Ingresa una opcion valida.\n");
      goto otra_vez;

  }
  cant_6= past_6 + pll_6 + bist_6;
  prc_6= cant_6*grin;
  printf("\nTotal de Gringas: $%.2f", prc_6);
 return 0;
}