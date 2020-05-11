/*
					********************** TEXTO SIN ACENTOS NI VIRGULILLAS***************************
	Name: Acatlan-Eats
	Authors: Albarran Lopez Denisse, Gonzalez Ortega Fernando Elias, Ordoniez Perez Arizbeth, Ramos Miguel Roxana, Rivas Torres Monserrat

	Date Start: 20/02/20 17:49
	Description:	Base de datos y app para pedir comida dentro de la FES
	
					************* PROGRAMA CORRIDO EN DEV C++ EN WINDOWS ****************** 
*/

/*	Numero confidencial del gerente: 0001
	Contraseña del Gerente: admin
	Modificar numero y clave en la linea 1840 y 1841*/

#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#define CLEAN "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAN "clear"
#else
#error "No se admite limpieza de pantalla"
#endif

#define CADENA 30
#define TECLA_RETROCESO 8
#define PRIMER_CARACTER_ASCII 32
#define ADMINS 100
#define TOTAL_CLIENTES 100
#define PEDIDOS 100
#define TAMANO_SINOPSIS 100
#define TOTAL_ATRIBUTOS_ADMINISTRADORES 6
#define TOTAL_ATRIBUTOS_CLIENTES 5
#define ENTER 13
#define NOMBRE_LEIDO 1
#define USUARIO_LEIDO 2
#define CLAVE_LEIDA 3
#define NUM_TARJETA_LEIDA 4
#define ENVIO_LEIDO 5
#define NUM_TRABAJADOR_LEIDO 2
#define DOMICILIO_LEIDO 4
#define TELEFONO_LEIDO 5
#define SUELDO_LEIDO 6
#define PUESTO_LEIDO 7
#define EDIFICIO_LEIDO 2 
#define SALON_LEIDO 3
#define LUGAR_LEIDO 4
#define SUBTOTAL_LEIDO 5
#define TOTAL_PEDIDOS 100
#define TIPO_LEIDO 6
#define TOTAL_LEIDO 7
#define TOTAL_ATRIBUTOS_PEDIDOS 7

typedef enum {falso,verdadero} booleano;
typedef enum {programado,express} tipoPedido;

typedef struct
{
    char numTrabajador[CADENA+1];
    char clave [CADENA+1];
    char nombre[CADENA+1];
    char domicilio[CADENA+1];
    char telefono[CADENA+1];
    long int sueldo;
} admin;

typedef struct
{
    char nombre[CADENA+1];
    char clave [CADENA+1];
    char usuario[CADENA+1];
    char numTarjetaCredito[CADENA+1];
    tipoPedido tipo;
} cliente;

typedef struct
{
    char platillo[CADENA+1];
    char edificio [CADENA+1];
    char salon [CADENA+1];
    char lugar [TAMANO_SINOPSIS+1];
    float subtotal;
    float total;
} orden;

//Variables para la manipulacion de registros
admin administradores[ADMINS];
cliente clientes[TOTAL_CLIENTES];
orden pedidos[PEDIDOS];
int cuentaClientes=0;
int cuentaAdministradores=0;
int cuentaPedidos=0;

//Funciones generales del programa
int opcionesMenuPrincipal();
void imprimirError();
void imprimirTitulo();
int opcionesMenuSesion();
void ocultarClave(char *clave);
void pausa();
void inicializarRegistros();
void bienvenida();

//Funciones para la manipulacion de registros de pedidos
void menuOrden();
void pedirDatosPedido(int i);
void altaPedido();
void cargarDatosPedidos();
void imprimirTicket();
void modificarPedido();
void bajaPedido();
void listarPedidos();
void buscarPedido();
booleano coincideNombrePedido(char *nombrePedido);
int damePosicionPedido(char* nombrePedido);
void guardarArchivoPedido();
int opcionesMenuPedido();
void mostrarDatosPedido(int i);

//Funciones para la manipulacion de registros de clientes
void pedirDatosCliente(int i);
booleano datosCorrectosClientes(char *usuario, char *clave);
void altaCliente();
void modificarCliente();
void bajaCliente();
void inicioSesionCliente();
void cargarDatosClientes();
void menuCliente(char* usuario);
int queClienteIngreso(char *correoIniciado);
void mostrarDatosCliente(int i);
void listarClientes();
void buscarCliente();
booleano coincideCorreoCliente(char *usuarioCliente);
int damePosicionCliente(char* usuarioCliente);
int opcionesMenuCliente();
void menuAdminClientes();
void guardarArchivoCliente();

//Funciones para la manipulacion de registros de trabajadores
void pedirDatosEmpleado(int i);
void menuAdministrador();
void inicioSesionEmpleado();
void menuGerente();
void menuTrabajador();
void cargarDatosadministradores();
void altaTrabajador();
int queTrabajadorIngreso(char *numTrabajador);
void modificarTrabajador();
void bajaTrabajador();
void listarTrabajadores();
void buscarTrabajador();
void mostrarDatosTrabajador(int i);
booleano coincideNumeroTrabajador(char *numTrabajador);
int damePosicionTrabajador(char* numTrabajador);
int opcionesMenuGerente();
booleano datosCorrectosGerente(char *num, char *clave);
void guardarArchivoTrabajador();
void inicioSesionGerente();
booleano datosCorrectosadministradores(char *numTrabajador, char *clave);
int opcionesMenuTrabajador();

//***************************************************************************************

int main()
{
    bienvenida();
    inicializarRegistros();
    cargarDatosClientes();
    cargarDatosadministradores();
    cargarDatosPedidos();
    fflush(stdin);
    int opcion;
    do
    {
        imprimirTitulo();
        opcion=opcionesMenuPrincipal();

        switch(opcion)
        {
        case 1:
            system(CLEAN);
            altaCliente();
            break;

        case 2:
            switch(opcionesMenuSesion())
            {
            case 1:
                inicioSesionGerente();
                break;

            case 2:
                inicioSesionEmpleado();
                break;

            case 3:
                inicioSesionCliente();

            default:
                imprimirError();
                break;
            }

            break;
        default:
            imprimirError();
            break;
        }
        system(CLEAN);
    }
    while(opcion!=3);
    return 0;
}

//*************************************************************************************
//Inicio Funciones
void imprimirError()
{
    printf("\n\nHas ingresado una opcion no valida!\n\n");
}

int opcionesMenuPrincipal()
{
    int opcion;
    error: fflush(stdin);
    printf("1. Registrarse\n\n");
    printf("2. Iniciar Sesion\n\n");
    printf("3. Salir\n\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    while(opcion<0&&opcion>3)
    {
    	fflush(stdin);
        printf("\n\nHas ingresado una opcion no valida!\n\n");
        pausa();
        goto error;
    }

    return opcion;
}

void imprimirTitulo()
{
    printf("\t\t\t***ACATLAN-EATS***\n\n");
}

int opcionesMenuSesion()
{
    int opcion;
    error: fflush(stdin);
    system(CLEAN);
    printf("\t\t\t***Iniciar Sesion***\n\n");
    printf("1. Iniciar sesion como Gerente\n");
    printf("2. Iniciar Sesion como Empleado\n");
    printf("3. Iniciar sesion como Cliente\n\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    while(opcion<0&&opcion>3)
    {
        printf("\n\nHas ingresado una opcion no valida!\n\n");
        goto error;
    }
    return opcion;
}

void pausa()
{
    printf("\n\nPresiona Enter para continuar...");
    getch();
}

void ocultarClave(char *clave)
{
    fflush(stdin);
    int i=0;
    printf("Ingresa tu clave: ");
    while(clave[i]!=ENTER)
    {
        clave[i]=getch();
        if(clave[i]>PRIMER_CARACTER_ASCII && i<CADENA)
        {
            putchar('*');
            i++;
        }
        else if(clave[i]==TECLA_RETROCESO && i>0)
        {
            putchar(TECLA_RETROCESO);
            putchar(' ');
            putchar(TECLA_RETROCESO);
            i--;
        }
    }
    clave[i]='\0';
    printf("\n");
}

void inicioSesionCliente()
{
    system(CLEAN);
    char usuarioIniciado[CADENA];
    char clave [CADENA+1];
    error: fflush(stdin);
    printf("Ingresa tu usuario: ");
    gets(usuarioIniciado);
    fflush(stdin);
    ocultarClave(clave);
    while(strcmp(usuarioIniciado,"\0")==0)
    {
        printf("\n\nOpcion no valida!\n\n");
        goto error;

    }
    while(!datosCorrectosClientes(usuarioIniciado,clave))
    {
        error2: printf("\n\nLos datos ingresados no fueron correctos intentalo nuevamente\n\n");
        fflush(stdin);
        printf("Ingresa tu usuario: ");
        gets(usuarioIniciado);
        fflush(stdin);
        ocultarClave(clave);
        while(strcmp(usuarioIniciado,"\0")==0)
        {
            printf("\n\nOpcion no valida!\n\n");
            goto error2;
        }
    }
    pausa();
    menuCliente(usuarioIniciado);
    pausa();
}

booleano datosCorrectosClientes(char *usuario, char *clave)
{
    booleano datosEncontrados;
    int i;
    for(i=0; i<TOTAL_CLIENTES; i++)
    {

        if(strcmp(usuario,clientes[i].usuario)==0&&strcmp(clave,clientes[i].clave)==0)
        {
            datosEncontrados=verdadero;
            break;
        }
        else
        {
            datosEncontrados=falso;
        }
    }
    if(datosEncontrados)
    {
        return verdadero;

    }
    else
    {
        return falso;
    }
}

booleano datosCorrectosadministradores(char *numTrabajador, char *clave)
{
    int i;

    booleano datosEncontrados;
    for(i=0; i<ADMINS; i++)
    {

        if(strcmp(numTrabajador,administradores[i].numTrabajador)==0&&
                strcmp(clave,administradores[i].clave)==0)
        {
            datosEncontrados=verdadero;
            break;
        }
        else
        {
            datosEncontrados=falso;
        }
    }
    if(datosEncontrados)
    {
        return verdadero;

    }
    else
    {
        return falso;
    }
}

void pedirDatosCliente(int i) 
{
    int opcion;
    int tarjeta;
    fflush(stdin);
    printf("***Ingresa los datos***\n\n");
    printf("Nombre: ");
    gets(clientes[i].nombre);
    fflush(stdin);
    printf("usuario: ");
    gets(clientes[i].usuario);
    ocultarClave(clientes[i].clave);
    fflush(stdin);
    printf("Ingresa el numero de tarjeta de credito: ");
    CC: gets(clientes[i].numTarjetaCredito);
    tarjeta=strlen(clientes[i].numTarjetaCredito);
    if(tarjeta!=16){
    	printf("Cantidad de digitos incorrecta\n\n Ingresa de nuevo: ");
    	goto CC;
	}
    error: fflush(stdin);
    printf("\n\nQue tipo de envio desea para su pedido: \n");
    printf("1. Programado\n");
    printf("2. Express\n\n");
    printf("Opcion (1 / 2): ");
    scanf("%d",&opcion);
    while(opcion<0||opcion>2)
    {
        printf("\n\nHas ingresado una opcion no valida!\n\n");
        goto error;
    }
    if(opcion==1)
    {
        clientes[i].tipo=programado;
    }

    else if(opcion==2)
    {
        clientes[i].tipo=express;
    }
}

void pedirDatosEmpleado(int i)
{
    fflush(stdin);
    printf("***Ingresa los datos***\n\n");
    printf("Nombre: ");
    gets(administradores[i].nombre);
    fflush(stdin);
    printf("Ingresa el numero de trabajador: ");
    gets(administradores[i].numTrabajador);
    fflush(stdin);
    ocultarClave(administradores[i].clave);
    fflush(stdin);
    printf("Ingresa tu domicilio: ");
    gets(administradores[i].domicilio);
    fflush(stdin);
    printf("Ingresa tu telefono: ");
    gets(administradores[i].telefono);
    fflush(stdin);
    printf("Ingresa el sueldo: ");
    scanf("%ld",&administradores[i].sueldo);
}

void inicioSesionEmpleado()
{
    system(CLEAN);
    char clave [CADENA+1];
    char numTrabajadorIniciado[CADENA];
    fflush(stdin);
    printf("Ingresa tu Numero de empleado: ");
    gets(numTrabajadorIniciado);
    fflush(stdin);
    ocultarClave(clave);
    while(strcmp(numTrabajadorIniciado,"\0")==0)
    {
        printf("\n\nOpcion no valida!\n\n");
        fflush(stdin);
        printf("Ingresa tu Numero de empleado: ");
        gets(numTrabajadorIniciado);
        fflush(stdin);
        ocultarClave(clave);

    }
    while(!datosCorrectosadministradores(numTrabajadorIniciado,clave))
    {
        error: printf("\n\nLos datos ingresados no fueron correctos intentalo nuevamente\n\n");
        fflush(stdin);
        printf("Ingresa tu numero de empleado: ");
        gets(numTrabajadorIniciado);
        fflush(stdin);
        ocultarClave(clave);
        while(strcmp(numTrabajadorIniciado,"\0")==0)
        {
            goto error;
        }
    }
    pausa();
    menuTrabajador(numTrabajadorIniciado);
}

void cargarDatosClientes()
{
    FILE *lecturaClientes;

    booleano sinRegistros=verdadero;
    lecturaClientes=fopen("clientes.txt","r");
    

    int i=0;
    int lineasLeidas=0;
    char comprobador[CADENA+1];

    if(lecturaClientes!=NULL)
    {

        while(fgets(comprobador,sizeof(comprobador),lecturaClientes)!=NULL)
        {

            strtok(comprobador,"\n");
            lineasLeidas++;

            if(lineasLeidas==NOMBRE_LEIDO)
            {
                strcpy(clientes[i].nombre,comprobador);
            }

            if(lineasLeidas==CLAVE_LEIDA)
            {
                strcpy(clientes[i].clave,comprobador);
            }

            if(lineasLeidas==USUARIO_LEIDO)
            {
                strcpy(clientes[i].usuario,comprobador);
            }

            if(lineasLeidas==NUM_TARJETA_LEIDA)
            {
                strcpy(clientes[i].numTarjetaCredito,comprobador);
            }
            if(lineasLeidas==ENVIO_LEIDO)
            {
                if(strcmp(comprobador,"programado")==0)
                {

                    clientes[i].tipo=programado;
                }

                else if(strcmp(comprobador,"express")==0)
                {
                    clientes[i].tipo=express;
                }
            }
            if(lineasLeidas==TOTAL_ATRIBUTOS_CLIENTES)
            {
                i++;
                cuentaClientes++;
                sinRegistros=falso;
                lineasLeidas=0;
            }

        }

        if(!sinRegistros)
        {
            printf("Se han cargado %d registos de clientes!\n\n",cuentaClientes);
        }
    }

    else
    {
        printf("No se pudo leer el archivo o aun no se ha registrado a ningun cliente!\n\n");

    }
    fclose(lecturaClientes);
}

void cargarDatosPedidos()
{
    FILE *lecturaPedidos;

    booleano sinRegistros=verdadero;
    lecturaPedidos=fopen("pedidos.txt","r");
    

    int i=0;
    int lineasLeidas=0;
    char comprobador[CADENA+1];

    if(lecturaPedidos!=NULL)
    {

        while(fgets(comprobador,sizeof(comprobador),lecturaPedidos)!=NULL)
        {

            strtok(comprobador,"\n");
            lineasLeidas++;

            if(lineasLeidas==NOMBRE_LEIDO)
            {
                strcpy(pedidos[i].platillo,comprobador);
            }

            if(lineasLeidas==EDIFICIO_LEIDO)
            {
                strcpy(pedidos[i].edificio,comprobador);
            }

            if(lineasLeidas==SALON_LEIDO)
            {
                strcpy(pedidos[i].salon,comprobador);
            }

            if(lineasLeidas==LUGAR_LEIDO)
            {
                strcpy(pedidos[i].lugar,comprobador);
            }

            if(lineasLeidas==SUBTOTAL_LEIDO)
            {
                pedidos[i].subtotal=40.00;
            }
            
            if(lineasLeidas==TOTAL_LEIDO)
            {
                pedidos[i].total=pedidos[i].subtotal;
            }
            
            if(lineasLeidas==TIPO_LEIDO)
            {
                if(strcmp(comprobador,"programado")==0)
                {

                    clientes[i].tipo=programado;
                }

                else if(strcmp(comprobador,"express")==0)
                {
                    clientes[i].tipo=express;
                }
            }
            
            if(lineasLeidas==TOTAL_ATRIBUTOS_PEDIDOS)
            {
                i++;
                cuentaPedidos++;
                sinRegistros=falso;
                lineasLeidas=0;
            }

        }

        if(!sinRegistros)
        {
            printf("Se han cargado %d registros de pedidos!\n\n",cuentaPedidos);
            pausa();
        }
    }

    else
    {
        printf("No se pudo leer el archivo o aun no se ha registrado ningun pedido!\n\n");
        pausa();

    }
    fclose(lecturaPedidos);
    system(CLEAN);
}


void cargarDatosadministradores()
{
    FILE *lecturaadministradores;

    booleano sinRegistros=verdadero;
    lecturaadministradores=fopen("trabajadores.txt","r");
    

    int i=0;
    int lineasLeidas=0;
    char comprobador[CADENA+1];

    if(lecturaadministradores!=NULL)
    {

        while(fgets(comprobador,sizeof(comprobador),lecturaadministradores)!=NULL)
        {

            strtok(comprobador,"\n");
            lineasLeidas++;

            if(lineasLeidas==NOMBRE_LEIDO)
            {
                strcpy(administradores[i].nombre,comprobador);
            }

            if(lineasLeidas==NUM_TRABAJADOR_LEIDO)
            {
                strcpy(administradores[i].numTrabajador,comprobador);
            }

            if(lineasLeidas==CLAVE_LEIDA)
            {
                strcpy(administradores[i].clave,comprobador);
            }

            if(lineasLeidas==DOMICILIO_LEIDO)
            {
                strcpy(administradores[i].domicilio,comprobador);
            }
            if(lineasLeidas==TELEFONO_LEIDO)
            {
                strcpy(administradores[i].telefono,comprobador);
            }
            if(lineasLeidas==SUELDO_LEIDO)
            {
                administradores[i].sueldo=atoi(comprobador);
            }

            if(lineasLeidas==TOTAL_ATRIBUTOS_ADMINISTRADORES)
            {
                i++;
                cuentaAdministradores++;
                sinRegistros=falso;
                lineasLeidas=0;
            }

        }

        if(!sinRegistros)
        {
            printf("Se han cargado %d registos de administradores!\n\n",cuentaAdministradores);
        }
    }

    else
    {
        printf("No se pudo leer el archivo o aun no se ha registrado a ningun trabajador!\n\n");

    }
    fclose(lecturaadministradores);
}

int queTrabajadorIngreso(char *numTrabajador)
{
    int i;

    for(i=0; i<ADMINS; i++)
    {
        if(strcmp(numTrabajador,administradores[i].numTrabajador)==0)
        {
        	printf("Ingresa de nuevo\n\n");
            break;
        }
    }
    return i;
}

int queClienteIngreso(char* usuarioIniciado)
{
    int i;

    for(i=0; i<TOTAL_CLIENTES; i++)
    {
        if(strcmp(usuarioIniciado,clientes[i].usuario)==0)
        {
            break;
        }
    }
    return i;
}

void altaTrabajador()
{
    if(cuentaAdministradores<ADMINS)
    {
        pedirDatosEmpleado(cuentaAdministradores);
        cuentaAdministradores++;
        guardarArchivoTrabajador();
        printf("\n\nRegistro completado!");
    }
    else
    {
        printf("\n\nYa no hay mas espacio de captura!\n\n");
    }
    pausa();
}

void altaCliente()
{
    if(cuentaClientes<TOTAL_CLIENTES)
    {
        pedirDatosCliente(cuentaClientes);
        cuentaClientes++;
        guardarArchivoCliente();
        printf("\n\nRegistro completado!");
    }
    else
    {
        printf("\n\nYa no hay mas espacio de captura!\n\n");
    }
    pausa();
}

void pedirDatosPedido(int i)
{
    int opcion;
    fflush(stdin);
    printf("Ingrese el platillo deseado: ");
    gets(pedidos[i].platillo);
    fflush(stdin);
    printf("Ingrese el edificio: ");
    gets(pedidos[i].edificio);
    fflush(stdin);
    printf("Ingrese el salon: ");
    gets(pedidos[i].salon);
    fflush(stdin);
    printf("Ingrese su lugar favorito para este platillo: ");
    gets(pedidos[i].lugar);
    fflush(stdin);
}

void altaPedido()
{
    if(cuentaPedidos<PEDIDOS)
    {
        pedirDatosPedido(cuentaPedidos);
        cuentaPedidos++;
        guardarArchivoPedido();
        imprimirTicket();
        printf("\n\nRegistro completado!");
        
    }
    else
    {
        printf("\n\nYa no hay mas espacio de captura!\n\n");
    }
    pausa();
}

void limpiarRegistroCliente(int i)
{
    strcpy(clientes[i].usuario,"");
    strcpy(clientes[i].clave,"");
    strcpy(clientes[i].nombre,"");
    strcpy(clientes[i].numTarjetaCredito,"");
    clientes[i].tipo=0;
}

void limpiarRegistroPedido(int i)
{
    strcpy(pedidos[i].platillo,"");
    strcpy(pedidos[i].edificio,"");
    strcpy(pedidos[i].salon,"");
    strcpy(pedidos[i].lugar,"");
    pedidos[i].subtotal=0;
    pedidos[i].total=0;
    
}

void limpiarRegistroTrabajador(int i)
{
    strcpy(administradores[i].numTrabajador,"");
    strcpy(administradores[i].clave,"");
    strcpy(administradores[i].domicilio,"");
    strcpy(administradores[i].nombre,"");
    strcpy(administradores[i].telefono,"");
    administradores[i].sueldo=0;
}

void inicializarRegistros()
{
    int i;
    for(i=0; i<ADMINS; i++)
    {
        limpiarRegistroTrabajador(i);
    }

    for(i=0; i<TOTAL_CLIENTES; i++)
    {
        limpiarRegistroCliente(i);
    }

    for(i=0; i<PEDIDOS; i++)
    {
        limpiarRegistroPedido(i);
    }
}

void guardarArchivoCliente()
{
    int i;
    FILE *escritura;
    escritura=fopen("clientes.txt","w");
    


    for(i=0; i<cuentaClientes; i++)
    {

        fprintf(escritura,"%s\n",clientes[i].nombre);
        fprintf(escritura,"%s\n",clientes[i].usuario);
        fprintf(escritura,"%s\n",clientes[i].clave);
        fprintf(escritura,"%s\n",clientes[i].numTarjetaCredito);
        if(clientes[i].tipo==programado)
        {
            fputs("Programado\n",escritura);
        }
        else
        {
            fputs("Express\n",escritura);
        }

    }
    fclose(escritura);
}

void guardarArchivoTrabajador()
{
    FILE *escritura;
    escritura=fopen("trabajadores.txt","w");
    
    int i;
    for(i=0; i<cuentaAdministradores; i++)
    {
        fprintf(escritura,"%s\n",administradores[i].nombre);
        fprintf(escritura,"%s\n",administradores[i].numTrabajador);
        fprintf(escritura,"%s\n",administradores[i].clave);
        fprintf(escritura,"%s\n",administradores[i].domicilio);
        fprintf(escritura,"%ld\n",administradores[i].sueldo);
        fprintf(escritura,"%s\n",administradores[i].telefono);
    }

    fclose(escritura);
}

void guardarArchivoPedido()
{
    int i;
    FILE *escritura;
    escritura=fopen("pedidos.txt","w");

    for(i=0; i<cuentaPedidos; i++)
    {
        fprintf(escritura,"%s\n",pedidos[i].platillo);
        fprintf(escritura,"%s\n",pedidos[i].edificio);
        fprintf(escritura,"%s\n",pedidos[i].salon);
        fprintf(escritura,"%s\n",pedidos[i].lugar);
        fprintf(escritura,"%f\n",pedidos[i].subtotal);
        fprintf(escritura,"%f\n",pedidos[i].total);

        if(clientes[i].tipo==programado)
        {
            fputs("programado\n",escritura);
        }
        else
        {
            fputs("express\n",escritura);
        }

    }
    fclose(escritura);
}

void bienvenida()
{
    printf("\t\t\t***BIENVENIDO A ACATLAN-EATS***\n\n");
    printf("\t\t     REGISTRATE PARA MAYORES BENEFICIOS!!!\n\n");
    pausa();
    system(CLEAN);
}

void mostrarDatosCliente(int i)
{
    printf("Nombre: %s\n",clientes[i].nombre);
    printf("usuario: %s\n",clientes[i].usuario);
    printf("Clave: %s\n",clientes[i].clave);
    printf("Numero de tarjeta de credito: %s\n",clientes[i].numTarjetaCredito);
    if(clientes[i].tipo==programado)
    {
        printf("Tipo de envio: Programado\n\n");
    }
    else
    {
        printf("Tipo de envio: Express\n\n");
    }

}

void mostrarDatosTrabajador(int i)
{
    printf("\n\nNombre: %s\n",administradores[i].nombre);
    printf("Numero de trabajador: %s\n",administradores[i].numTrabajador);
    printf("Clave: %s\n",administradores[i].clave);
    printf("Domicilio: %s\n",administradores[i].domicilio);
    printf("Telefono: %s\n",administradores[i].telefono);
    printf("Suelgo: %ld\n\n",administradores[i].sueldo);
}

void mostrarDatosPedido(int i)
{

    printf("\tPlatillo: %s\n",pedidos[i].platillo);
    printf("\tLugar: %s\n",pedidos[i].lugar);
    printf("\tEdificio: %s\n",pedidos[i].edificio);
    printf("\tSalon: %s\n",pedidos[i].salon);
    printf("\tSubtotal: %.2f\n",pedidos[i].subtotal);
    printf("\tTotal: %.2f\n",pedidos[i].total);
    if(clientes[i].tipo==programado)
    {
        printf("\tTipo de envio: Programado\n\n");
    }
    else
    {
        printf("\tTipo de envio: Express\n\n");
    }

}

void menuCliente(char *usuario)
{
    int i;
    int opcion;
    i=queClienteIngreso(usuario);
    do
    {
        system(CLEAN);
        printf("Bienvenido %s",clientes[i].nombre);
        printf("   ****Usuario con tipo de envio: ");
        if(clientes[i].tipo==programado)
        {
            printf("Programado");
        }
        else
        {
            printf("Express");
        }
        printf(" ***\n\n");
        printf("1. Ingresar un pedido.\n\n");
        printf("2. Salir\n\n");
        fflush(stdin);
        printf("Opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            system(CLEAN);
        case 1:
            menuOrden();
            break;

        case 2:
            break;

        default:
            imprimirError();
            break;

        }
    }
    while(opcion!=2);
}

void menuTrabajador(char *numTrabajador)
{
    int i;
    int opcion;
    system(CLEAN);
    i=queTrabajadorIngreso(numTrabajador);
    do
    {
        printf("***Bienvenido %s***\n\n",administradores[i].nombre);
        opcion=opcionesMenuTrabajador();

        switch(opcion)
        {
            system(CLEAN);
        case 1:
            menuAdminClientes();
            break;

        case 2:
            
            listarPedidos();
            break;

        case 3:
            break;

        default:
            imprimirError();
            break;

        }
    }
    while(opcion!=3);
    pausa();
}


void imprimirTicket()
{
	system(CLEAN);
	int encontrados=0;
    int i=cuentaPedidos;
    char* patron;
    fflush(stdin);

    printf("\n\t\t*********TICKET************\n\n");

    
        patron=strstr(pedidos[i].platillo,pedidos[i].platillo);
        if (patron!=NULL)
        {
            mostrarDatosPedido(i);
            printf("\n\n");
            encontrados++;
        }

    
        printf("Su pedido se entregara conforme a la demanda de envios express");
    

    	printf("\n\n El TOTAL incluye envio\nEn caso de que el pedido sobre pase el total, se te cobrara un extra significativo");
    	pausa();
    	menuOrden();
    	
}

void modificarPedido()
{
    char nombreBuscar[CADENA];
    fflush(stdin);
    printf("MODIFICAR UN PEDIDO\n\n");
    printf("Ingresa el nombre del platillo que deseas modificar (De manera exacta): ");
    gets(nombreBuscar);
    if(coincideNombrePedido(nombreBuscar))
    {
        int i=damePosicionPedido(nombreBuscar);
        mostrarDatosPedido(i);
        fflush(stdin);
        printf("***********************************************************************\n\n");
        printf("Nuevos Datos: \n\n");
        pedirDatosPedido(i);
        guardarArchivoPedido();
        printf("\nRegistro Modificado!\n");
    }
    else
    {
        printf("\n\nNo se encontro ningun pedido con ese platillo!\n");
    }

    pausa();

}

void bajaPedido()
{
    char nombreBuscar[CADENA];
    fflush(stdin);
    char respuesta;
    printf("DAR DE BAJA UNA PEDIDO\n\n");
    printf("Ingresa el nombre del platillo que deseas eliminar: ");
    gets(nombreBuscar);
    if(coincideNombrePedido(nombreBuscar))
    {
        int i=damePosicionPedido(nombreBuscar);
        mostrarDatosPedido(i);
        fflush(stdin);
        printf("\nDeseas borrar a esta platillo (s/n) : ");
        scanf("%c",&respuesta);
        fflush(stdin);
        if(respuesta=='s'||respuesta=='S')
        {
            for(cuentaPedidos--; i<cuentaPedidos; i++)
            {
                pedidos[i]=pedidos[i+1];
            }
            guardarArchivoPedido();
            printf("\nRegistro Eliminado!\n");
        }
        else
        {
            printf("\nRegistro Conservado!\n");
        }
    }
    else
    {
        printf("\n\nNo se encontro ningun pedido con ese platillo!\n");
    }

    pausa();

}

void listarPedidos()
{
    int i;
    if(cuentaPedidos>0)
    {
        for(i=0; i<cuentaPedidos; i++)
        {
            mostrarDatosPedido(i);
        }
    }
    else
    {
        printf("\n\nNo hay ningun platillo registrado!\n");
    }

    pausa();
}

void buscarPedido()
{
    int encontrados=0;
    int i;
    char* patron;
    char nombreBuscar[CADENA];
    fflush(stdin);

    printf("Ingresa el nombre del platillo (De manera exacta): ");
    gets(nombreBuscar);

    for(i=0; i<cuentaPedidos; i++)
    {
        patron=strstr(pedidos[i].platillo,nombreBuscar);
        if (patron!=NULL)
        {
            mostrarDatosPedido(i);
            printf("\n\n");
            encontrados++;
        }

    }

    if (encontrados)
    {
        printf("Se encontro %d registro(s) con la palabra buscada\n",encontrados);
    }
    else
    {
        printf("No se encontro algun registro con la palabra buscada\n");
    }

    pausa();


}

booleano coincideNombrePedido(char* nombrePedido)
{
    booleano coincide=falso;
    int i;

    for(i=0; i<cuentaPedidos; i++)
    {
        if (strcmp(pedidos[i].platillo,nombrePedido)==0)
        {
            coincide=verdadero;
            break;
        }
    }

    return coincide;

}

int damePosicionPedido(char* nombrePedido)
{
    int posicion;
    int i;

    for(i=0; i<cuentaPedidos; i++)
    {
        if (strcmp(pedidos[i].platillo,nombrePedido)==0)
        {
            posicion=i;
            break;
        }
    }

    return posicion;
}

int opcionesMenuPedido()
{
    fflush(stdin);
    int opcion;
    printf("1. Dar de alta un pedido\n");
    printf("2. Dar de baja un pedido\n");
    printf("3. Modificar un pedido\n");
    printf("4. Buscar un pedido\n");
    printf("5. Salir\n\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    while(opcion<0||opcion>6)
    {
        fflush(stdin);
        printf("Opcion: ");
        scanf("%d",&opcion);
    }
    system(CLEAN);
    return opcion;
}

void menuOrden()//trabajar sobre esta, pasarla a cliente
{
    int opcion;
    do
    {
        system(CLEAN);
        printf("ADMINISTRACION DE ORDENES\n\n");
        opcion=opcionesMenuPedido();
        switch(opcion)
        {
        case 1:
            altaPedido();
            break;

        case 2:
            bajaPedido();
            break;

        case 3:
            modificarPedido();
            break;

        case 4:
            buscarPedido();
            break;

        case 5:
            exit(1);
            break;

        /*case 6:
            break;*/

        default:
            imprimirError();
            break;
        }

        system(CLEAN);
    }
    while(opcion!=6);

}

int opcionesMenuTrabajador()
{
    fflush(stdin);
    int opcion;
    printf("1. Administracion de clientes\n");
    printf("2. Listar pedidos\n");
    printf("3. Salir\n\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    while(opcion<0||opcion>3)
    {
        fflush(stdin);
        printf("Opcion: ");
        scanf("%d",&opcion);
    }
    system(CLEAN);
    return opcion;
}

void modificarCliente()
{
    char correoBuscar[CADENA];
    fflush(stdin);
    printf("MODIFICAR UN CLIENTE\n\n");
    printf("Ingresa el usuario del cliente que deseas modificar: ");
    gets(correoBuscar);
    if(coincideCorreoCliente(correoBuscar))
    {
        int i=damePosicionCliente(correoBuscar);
        mostrarDatosCliente(i);
        fflush(stdin);
        printf("***********************************************************************\n\n");
        printf("Nuevos Datos: \n\n");
        pedirDatosCliente(i);
        guardarArchivoCliente();
        printf("\nRegistro Modificado!\n");
    }
    else
    {
        printf("\n\nNo se encontro ningun cliente con ese usuario!\n");
    }

    pausa();
}
void bajaCliente()
{
    char correoBuscar[CADENA];
    fflush(stdin);
    char respuesta;
    printf("DAR DE BAJA UN CLIENTE\n\n");
    printf("Ingresa el usuario del que deseas eliminar: ");
    gets(correoBuscar);
    if(coincideCorreoCliente(correoBuscar))
    {
        int i=damePosicionCliente(correoBuscar);
        mostrarDatosCliente(i);
        fflush(stdin);
        printf("\nDeseas borrar a este cliente (s/n) : ");
        scanf("%c",&respuesta);
        fflush(stdin);
        if(respuesta=='s'||respuesta=='S')
        {
            for(cuentaClientes--; i<cuentaClientes; i++)
            {
                clientes[i]=clientes[i+1];
            }
            guardarArchivoCliente();
            printf("\nRegistro Eliminado!\n");
        }
        else
        {
            printf("\nRegistro Conservado!\n");
        }
    }
    else
    {
        printf("\n\nNo se encontro ningun cliente con ese usuario!\n");
    }

    pausa();

}
void listarClientes()
{
    int i;
    if(cuentaClientes>0)
    {
        for(i=0; i<cuentaClientes; i++)
        {
            mostrarDatosCliente(i);
        }
    }
    else
    {
        printf("\n\nNo hay ningun cliente registrado!\n");
    }

    pausa();

}
void buscarCliente()
{
    int encontrados=0;
    int i;
    char* patron;
    char nombreBuscar[CADENA];
    fflush(stdin);

    printf("Ingresa el nombre del cliente que deseas buscar: ");
    gets(nombreBuscar);

    for(i=0; i<cuentaClientes; i++)
    {
        patron=strstr(clientes[i].nombre,nombreBuscar);
        if (patron!=NULL)
        {
            mostrarDatosCliente(i);
            printf("\n\n");
            encontrados++;
        }

    }

    if (encontrados)
    {
        printf("Se encontro %d registro(s) con la palabra buscada\n",encontrados);
    }
    else
    {
        printf("No se encontro algun registro con la palabra buscada\n");
    }

    pausa();

}

booleano coincideCorreoCliente(char *usuarioCliente)
{
    int i;
    booleano coincide=falso;

    for(i=0; i<cuentaClientes; i++)
    {
        if(strcmp(usuarioCliente,clientes[i].usuario)==0)
        {
            coincide=verdadero;
            break;
        }
    }

    return coincide;
}

int damePosicionCliente(char* usuarioCliente)
{
    int i;
    int posicion;

    for(i=0; i<cuentaClientes; i++)
    {
        if(strcmp(usuarioCliente,clientes[i].usuario)==0)
        {
            posicion=i;
            break;
        }
    }

    return posicion;

}

int opcionesMenuCliente()
{
    fflush(stdin);
    int opcion;
    printf("1. Dar de alta un cliente\n");
    printf("2. Dar de baja un cliente\n");
    printf("3. Modificar un cliente\n");
    printf("4. Buscar un cliente\n");
    printf("5. Listar clientes\n");
    printf("6. Salir\n\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    while(opcion<0||opcion>6)
    {
        fflush(stdin);
        printf("Opcion: ");
        scanf("%d",&opcion);
    }
    system(CLEAN);
    return opcion;

}
void menuAdminClientes()
{
    int opcion;
    do
    {
        system(CLEAN);
        printf("ADMINISTRACION DE CLIENTES\n\n");
        opcion=opcionesMenuCliente();
        switch(opcion)
        {
        case 1:
            altaCliente();
            break;

        case 2:
            bajaCliente();
            break;

        case 3:
            modificarCliente();
            break;

        case 4:
            buscarCliente();
            break;

        case 5:
            listarClientes();
            break;

        case 6:
            break;

        default:
            imprimirError();
            break;
        }

        system(CLEAN);
    }
    while(opcion!=6);

}

void menuGerente()
{
    int opcion;
    do
    {
        system(CLEAN);
        printf("ADMINISTRACION DE TRABAJADORES\n\n");
        opcion=opcionesMenuGerente();
        switch(opcion)
        {
        case 1:
            altaTrabajador();
            break;

        case 2:
            bajaTrabajador();
            break;

        case 3:
            modificarTrabajador();
            break;

        case 4:
            buscarTrabajador();
            break;

        case 5:
            listarTrabajadores();
            break;

        case 6:
            break;

        default:
            imprimirError();
            break;
        }
        system(CLEAN);
    }
    while(opcion!=6);

}


void modificarTrabajador()
{
    char buscarNumero[CADENA];
    fflush(stdin);
    printf("MODIFICAR UN TRABAJADOR\n\n");
    printf("Ingresa el numero del trabajador que deseas modificar: ");
    gets(buscarNumero);
    if(coincideNumeroTrabajador(buscarNumero))
    {
        int i=damePosicionTrabajador(buscarNumero);
        mostrarDatosTrabajador(i);
        fflush(stdin);
        printf("***********************************************************************\n\n");
        printf("Nuevos Datos: \n\n");
        pedirDatosEmpleado(i);
        guardarArchivoTrabajador();
        printf("\nRegistro Modificado!\n");
    }
    else
    {
        printf("\n\nNo se encontro ningun empleado con ese numero!\n");
    }

    pausa();

}


void bajaTrabajador()
{
    char buscarNumero[CADENA];
    fflush(stdin);
    char respuesta;
    printf("DAR DE BAJA UN TRABAJADOR\n\n");
    printf("Ingresa el numero del trabajador que deseas eliminar: ");
    gets(buscarNumero);
    if(coincideNumeroTrabajador(buscarNumero))
    {
        int i=damePosicionTrabajador(buscarNumero);
        mostrarDatosTrabajador(i);
        fflush(stdin);
        printf("\nDeseas borrar a este empleado (s/n) : ");
        scanf("%c",&respuesta);
        fflush(stdin);
        if(respuesta=='s'||respuesta=='S')
        {
            for(cuentaAdministradores--; i<cuentaAdministradores; i++)
            {
                administradores[i]=administradores[i+1];
            }
            guardarArchivoTrabajador();
            printf("\nRegistro Eliminado!\n");
        }
        else
        {
            printf("\nRegistro Conservado!\n");
        }
    }
    else
    {
        printf("\n\nNo se encontro ningun empleado con ese numero!\n");
    }

    pausa();

}


void listarTrabajadores()
{
    int i;
    if(cuentaAdministradores>0)
    {
        for(i=0; i<cuentaAdministradores; i++)
        {
            mostrarDatosTrabajador(i);
        }
    }
    else
    {
        printf("\n\nNo hay ningun empleado registrado!\n");
    }

    pausa();

}


void buscarTrabajador()
{
    int encontrados=0;
    int i;
    char* patron;
    char nombreBuscar[CADENA];
    fflush(stdin);

    printf("Ingresa el nombre del empleado que deseas buscar: ");
    gets(nombreBuscar);

    for(i=0; i<cuentaAdministradores; i++)
    {
        patron=strstr(administradores[i].nombre,nombreBuscar);
        if (patron!=NULL)
        {
            mostrarDatosTrabajador(i);
            printf("\n\n");
            encontrados++;
        }

    }

    if (encontrados)
    {
        printf("Se encontro %d registro(s) con la palabra buscada\n",encontrados);
    }
    else
    {
        printf("No se encontro algun registro con la palabra buscada\n");
    }

    pausa();

}


booleano coincideNumeroTrabajador(char *numTrabajador)
{
    int i;
    booleano coincide=falso;

    for(i=0; i<cuentaAdministradores; i++)
    {
        if(strcmp(numTrabajador,administradores[i].numTrabajador)==0)
        {
            coincide=verdadero;
            break;
        }
    }

    return coincide;

}


int damePosicionTrabajador(char* numTrabajador)
{
    int i;
    int posicion;

    for(i=0; i<cuentaAdministradores; i++)
    {
        if(strcmp(numTrabajador,administradores[i].numTrabajador)==0)
        {
            posicion=i;
            break;
        }
    }

    return posicion;

}


int opcionesMenuGerente()
{
    fflush(stdin);
    int opcion;
    printf("1. Dar de alta a un empleado\n");
    printf("2. Dar de baja a un empleado\n");
    printf("3. Modificar a un empleado\n");
    printf("4. Buscar a un empleado\n");
    printf("5. Listar empleados\n");
    printf("6. Salir\n\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    while(opcion<0||opcion>6)
    {
        fflush(stdin);
        printf("Opcion: ");
        scanf("%d",&opcion);
    }
    system(CLEAN);
    return opcion;
}

void inicioSesionGerente()
{
    system(CLEAN);
    fflush(stdin);
    char numero[CADENA];
    char clave [CADENA];

    error: printf("Ingresa el numero confidencial del gerente ");
    printf("(se encuentra en la primera linea del codigo): ");
    gets(numero);
    fflush(stdin);
    ocultarClave(clave);
    fflush(stdin);

    while(!datosCorrectosGerente(numero,clave))
    {
        printf("\n\nLos datos no coinciden, intentalo de nuevo...\n\n");
        goto error;
    }

    pausa();
    menuGerente();
    pausa();

}

booleano datosCorrectosGerente(char* num, char* clave)
{
    booleano coincide=falso;

    char numeroGerente[]="0001";
    char claveGerente[]="admin";

    if(strcmp(num,numeroGerente)==0&&strcmp(clave,claveGerente)==0)
    {
        coincide=verdadero;
    }

    return coincide;
}