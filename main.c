#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;
    char nombre[20];
    int edad;
    int notas[3];

    do {
        printf("\nSistema de Gestión de Alumnos\n");
        printf("1. Crear alumno\n");
        printf("2. Leer alumnos\n");
        printf("3. Buscar y actualizar alumno\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre del alumno: ");
                fgets(nombre, 20, stdin);
                int len = strlen(nombre) - 1;
                if (nombre[len] == '\n') nombre[len] = '\0'; // Eliminar salto de línea
                printf("Ingrese la edad: ");
                scanf("%d", &edad);
                printf("Ingrese la Nota 1: ");
                scanf("%d", &notas[0]);
                printf("Ingrese la Nota 2: ");
                scanf("%d", &notas[1]);
                printf("Ingrese la Nota 3: ");
                scanf("%d", &notas[2]);
                createAlumno(nombre, edad, notas);
                break;

            case 2:
                readAlumno();
                break;

            case 3:
                printf("Ingrese el nombre del alumno a buscar: ");
                fgets(nombre, 20, stdin);
                len = strlen(nombre) - 1;
                if (nombre[len] == '\n') nombre[len] = '\0'; // Eliminar salto de línea
                updateAlumno(nombre);
                break;

            case 4:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}
