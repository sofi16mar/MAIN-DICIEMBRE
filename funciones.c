#include <stdio.h>
#include <string.h>
#include "funciones.h"


void createAlumno(char nombre[], int edad, int notas[]){
    FILE *fnombre=fopen("nombres.txt","a+");
    FILE *fdatos=fopen("datos.txt","a+");
    if (fnombre==NULL || fdatos==NULL)
    {
        printf("Error al abrir el archivo");
        return;
    }
    fputs(nombre,fnombre);
    fprintf(fdatos,"%d %d %d %d\n",edad,notas[0],notas[1],notas[2]);
    fclose(fnombre);
    fclose(fdatos);
}

void readAlumno(){
    char nombre[20];
    int edad, n1, n2, n3, len;
    int i=1;
    FILE *fnombre=fopen("nombres.txt","r");
    FILE *fdatos=fopen("datos.txt","r");
    if (fnombre==NULL || fdatos==NULL)
    {
        printf("Error al abrir el archivo");
        return;
    }
    printf("#\t\tNombre\t\tEdad\t\tNota1\t\tNota2\t\tNota3\n");
    while (!feof(fnombre))
    {
        fgets(nombre,20,fnombre);
        len = strlen(nombre) - 1;
        nombre[len]='\0';
        fscanf(fdatos,"%d %d %d %d\n",&edad,&n1,&n2,&n3);
        printf("%d %s %d %d %d %d\n",i,nombre,edad,n1,n2,n3);
        i++;
    }
    fclose(fnombre);
    fclose(fdatos);
}

void searchAlumnoByNombre(char nombre[], int *posNombre, int *posDatos){
    char txnombre[30];
    char txdatos[30];
    int f=0;
    FILE *fnombre=fopen("nombres.txt","r");
    FILE *fdatos=fopen("datos.txt","r");
    if (fnombre==NULL || fdatos==NULL)
    {
        printf("Error al abrir el archivo");
        return;
    }
    while (!feof(fnombre))  
    {
        fgets(txnombre,20,fnombre);
        fgets(txdatos,20,fdatos);
        if (strcmp(txnombre,nombre)==0)
        {
            f=1;
            break;
        }
        *posNombre = ftell(fnombre);
        *posDatos = ftell(fdatos);
    }
    if (f==0)
    {
        *posNombre=-1;
        *posDatos=-1;
    }
    fclose(fnombre);
    fclose(fdatos);
}

void updateAlumno(char nombreBuscar[]){
    int posNombre=0, posDatos=0;
    char nombre[20];
    int edad, len;
    int notas[3]={0};
    searchAlumnoByNombre(nombreBuscar,&posNombre,&posDatos);
    if (posNombre != -1)
    {
        printf("Ingrese el nuevo nombre: ");
        fgets(nombre, 20, stdin);
        len = strlen(nombre) - 1;
        nombre[len] = '\0';
        printf("Ingrese la nueva edad: ");
        scanf("%d", &edad);
        printf("Ingrese la nueva Nota 1: ");
        scanf("%d", &notas[0]);
        printf("Ingrese la nueva Nota 2: ");
        scanf("%d", &notas[1]);
        printf("Ingrese la nueva Nota 1: ");
        scanf("%d", &notas[2]);
        FILE *fnombre = fopen("nombres.txt", "r+");
        FILE *fdatos = fopen("datos.txt", "r+");
        if (fnombre == NULL || fdatos == NULL)
        {
            printf("Error al abrir el archivo");
            return;
        }
        fseek(fnombre, posNombre, 0);
        fputs(nombre, fnombre);
        fseek(fdatos, posDatos, 0);
        fprintf(fdatos, "%d %d %d %d\n", edad, notas[0], notas[1], notas[2]);
        fclose(fnombre);
        fclose(fdatos);
    }else
    {
        printf("No existe el alumno\n");
    }
    
}
