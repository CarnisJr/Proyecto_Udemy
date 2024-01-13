#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct empleado{
    char nombre[255];
    char id[12];
    char sueldo[200];
    char horas[10];
};

void desplegarMenu(){

    printf("\nQue opcion desea ejecutar?\n");
    printf("1. Alta Empleado\n2. Baja empleado\n3. Listar empleados\n4. Consultar datos empleado\n5. Modficar sueldo\n6. Modificar horas\n7. Salir\n");
}


int cargarEmpleados(struct empleado empleados[100]){
    int nEmp = 0;
    FILE *f;
    f = fopen("empleados.txt", "r");
    char cadena[255];
    char delimitador[] = ";";
    
    while(feof(f) == 0){

        struct empleado e;
        fgets(cadena, 255, f);
        char *token = strtok(cadena, delimitador);

        if (token != NULL){
            int campo = 1;
            while (token != NULL){
                if (campo == 1){
                    strcpy(e.nombre, token);
                }else if (campo == 2){
                    strcpy(e.id, token);
                }else if (campo == 3){
                    strcpy(e.sueldo, token);
                }else if (campo == 4){
                    strcpy(e.horas, token);
                }
                campo++;
                token = strtok(NULL, delimitador);
            }
        }
        empleados[nEmp] = e;
        nEmp++;
    }
    fclose(f);
    return --nEmp;
}


void listarEmpleados(struct empleado empleados[100], int nEmp){
    printf("\n+----------------------------+------+-------------+-------+\n");
    printf("|           Nombre           |  id  |    sueldo   | horas |");
    for (size_t i = 0; i < nEmp; i++){
        printf("\n+----------------------------+------+-------------+-------+\n");
        printf("| %-26s | %-4s | %-11s | %-5s |", empleados[i].nombre, empleados[i].id, empleados[i].sueldo, empleados[i].horas);
    }
    printf("\n+----------------------------+------+-------------+-------+\n");
}


void agregarEmpledos(struct empleado empleados[100], int nEmp){

    char controlador;
    struct empleado e;
    FILE *f;
    f = fopen("empleados.txt", "a");

    do{

       fflush(stdin); 
       printf("Nombre: ");
       gets(e.nombre);
       fwrite(e.nombre, 1, strlen(e.nombre), f);
       fprintf(f, ";");

       printf("ID: ");
       gets(e.id);
       fwrite(e.id, 1, strlen(e.id), f);
       fprintf(f, ";");
       
       printf("Sueldo: ");
       gets(e.sueldo);
       fwrite(e.sueldo, 1, strlen(e.sueldo), f);
       fprintf(f, ";");

       printf("Horas: ");
       gets(e.horas);
       fwrite(e.horas, 1, strlen(e.horas), f);
       fprintf(f, ";");
       fprintf(f, "\n");

       printf("Desea continuar?\n");
       scanf("%c", &controlador);
    }while(controlador == 's');
    fclose(f);
}

int eliminarEmpleado(struct empleado empleados[100], int nEmp){

    FILE *f;
    f = fopen("empleadosBaja.txt", "a");

    nEmp = cargarEmpleados(empleados);
    int indice; 
    struct empleado aux;
    char id[5];
    int idVerificada;

    printf("Ingrese la id del empleado: ");
    scanf("%s", id);

    for(size_t i = 0; i < nEmp; i++){
        if(strncmp(empleados[i].id, id, 2) == 0){
            idVerificada = 1;
            break;
        }else{
            idVerificada = 0;
        }
    }
    if(idVerificada == 1){
        for(size_t i = 0; i < nEmp; i++){
            if(strncmp(empleados[i].id, id, 2) == 0){
                fflush(stdin); 
                fwrite(empleados[i].nombre, 1, strlen(empleados[i].nombre), f);
                fprintf(f, ",");
        
                fwrite(empleados[i].id, 1, strlen(empleados[i].id), f);
                fprintf(f, ",");
                
                fwrite(empleados[i].sueldo, 1, strlen(empleados[i].sueldo), f);
                fprintf(f, ",");
        
                fwrite(empleados[i].horas, 1, strlen(empleados[i].horas), f);
                fprintf(f, "\n");
                indice = i;
                for(size_t j = indice; j < nEmp - 1; j++){
                    empleados[j] = empleados[j + 1];
                    empleados[j + 1] = aux;
                }
            }
        }    
    }else{
        printf("No existe Empleado\n");
    }
    fclose(f);
    return idVerificada; 
}

int buscarEmpleado(struct empleado empleados[100], int nEmp){

    char id[5];
    int idVerificada;

    printf("Ingrese la id del empleado: ");
    scanf("%s", id);

    for(size_t i = 0; i < nEmp; i++){
        if(strncmp(empleados[i].id, id, 2) == 0){
            idVerificada = 1;
            break;
        }else{
            idVerificada = 0;
        }
    }

    if(idVerificada == 1){
        printf("\n+----------------------------+------+-------------+-------+\n");
        printf("|           Nombre           |  id  |    sueldo   | horas |");
        for(size_t i = 0; i < nEmp; i++){
            if(strncmp(empleados[i].id, id, 2) == 0){
                printf("\n+----------------------------+------+-------------+-------+\n");
                printf("| %-26s | %-4s | %-11s | %-5s |", empleados[i].nombre, empleados[i].id, empleados[i].sueldo, empleados[i].horas);
                printf("\n+----------------------------+------+-------------+-------+\n");
            }
        }    
    }
    return idVerificada;
}

int modificarSueldo(struct empleado empleados[100], int nEmp){

    FILE *f;
    f = fopen("empleados.txt", "w");
    char id[5];
    int idVerificada;

    printf("\nIngrese la id del empleado: ");
    scanf("%s", id);

    for(size_t i = 0; i < nEmp; i++){
        if(strncmp(empleados[i].id, id, 2) == 0){
            idVerificada = 1;
            break;
        }else{
            idVerificada = 0;
        }
    }

    if(idVerificada == 1){
        for(size_t i = 0; i < nEmp; i++){
            if(strncmp(empleados[i].id, id, 2) == 0){

                fflush(stdin); 
                fwrite(empleados[i].nombre, 1, strlen(empleados[i].nombre), f);
                fprintf(f, ";");

                fwrite(empleados[i].id, 1, strlen(empleados[i].id), f);
                fprintf(f, ";");
                
                printf("Ingrese el nuevo sueldo: ");
                gets(empleados[i].sueldo);
                fwrite(empleados[i].sueldo, 1, strlen(empleados[i].sueldo), f);
                fprintf(f, ";");

                fwrite(empleados[i].horas, 1, strlen(empleados[i].horas), f);
                fprintf(f, ";");
                fprintf(f, "\n");

            }else{

                fflush(stdin); 
                fwrite(empleados[i].nombre, 1, strlen(empleados[i].nombre), f);
                fprintf(f, ";");

                fwrite(empleados[i].id, 1, strlen(empleados[i].id), f);
                fprintf(f, ";");
                
                fwrite(empleados[i].sueldo, 1, strlen(empleados[i].sueldo), f);
                fprintf(f, ";");

                fwrite(empleados[i].horas, 1, strlen(empleados[i].horas), f);
                fprintf(f, ";");
                fprintf(f, "\n");
            }
        }    
    }
    fclose(f);
    return idVerificada;
}

int modificarHoras(struct empleado empleados[100], int nEmp){

    FILE *f;
    f = fopen("empleados.txt", "w");
    char id[5];
    int idVerificada;

    printf("\nIngrese la id del empleado: ");
    scanf("%s", id);

    for(size_t i = 0; i < nEmp; i++){
        if(strncmp(empleados[i].id, id, 2) == 0){
            idVerificada = 1;
            break;
        }else{
            idVerificada = 0;
        }
    }

    if(idVerificada == 1){
        for(size_t i = 0; i < nEmp; i++){
            if(strncmp(empleados[i].id, id, 2) == 0){

                fflush(stdin); 
                fwrite(empleados[i].nombre, 1, strlen(empleados[i].nombre), f);
                fprintf(f, ";");

                fwrite(empleados[i].id, 1, strlen(empleados[i].id), f);
                fprintf(f, ";");
                
                fwrite(empleados[i].sueldo, 1, strlen(empleados[i].sueldo), f);
                fprintf(f, ";");

                printf("Ingrese cantidad de horas: ");
                gets(empleados[i].horas);
                fwrite(empleados[i].horas, 1, strlen(empleados[i].horas), f);
                fprintf(f, ";");
                fprintf(f, "\n");

            }else{

                fflush(stdin); 
                fwrite(empleados[i].nombre, 1, strlen(empleados[i].nombre), f);
                fprintf(f, ";");

                fwrite(empleados[i].id, 1, strlen(empleados[i].id), f);
                fprintf(f, ";");
                
                fwrite(empleados[i].sueldo, 1, strlen(empleados[i].sueldo), f);
                fprintf(f, ";");

                fwrite(empleados[i].horas, 1, strlen(empleados[i].horas), f);
                fprintf(f, ";");
                fprintf(f, "\n");
            }
        }    
    }
    fclose(f);
    return idVerificada;
}
#endif