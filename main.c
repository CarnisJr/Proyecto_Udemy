#include "funciones.h"
int main(void){
 
    int selector = 0, empleadoEliminado, empleadoBuscado, empleadoNuevoSueldo, empleadosHoras;
    int numEmpleados;
    struct empleado empleados[100];

    numEmpleados = cargarEmpleados(empleados);
    printf("GESTOR DE EMPLEADOS\n");
    do{
        desplegarMenu();
        scanf("%d", &selector);
        switch(selector){
        case 1:
            printf("Alta a empleado\n");
            agregarEmpledos(empleados, numEmpleados);
            numEmpleados = cargarEmpleados(empleados);
            break;
        case 2:
            printf("Baja a empleado\n");
            empleadoEliminado = eliminarEmpleado(empleados, numEmpleados);
            if(empleadoEliminado == 1)
                numEmpleados--;            
            break;
        case 3:
            printf("Listar empleado");
            listarEmpleados(empleados, numEmpleados);
            system("pause");
            break;
        case 4:
            printf("Consultar informacion de empleado");
            empleadoBuscado = buscarEmpleado(empleados, numEmpleados);
            if(empleadoBuscado == 1)
                printf("Se encontro al empleado\n");            
            else
                printf("No se encontro al empleado\n");            
            system("pause");
            break;
        case 5:
            printf("Modificar sueldo");
            empleadoNuevoSueldo = modificarSueldo(empleados, numEmpleados);
            if(empleadoNuevoSueldo == 1)
                printf("Se encontro al empleado\n");            
            else
                printf("No se encontro al empleado\n");            
            system("pause");
            break;
        case 6:
            printf("Modificar horas");
            empleadosHoras = modificarHoras(empleados, numEmpleados);
            if(empleadosHoras == 1)
                printf("Se encontro al empleado\n");            
            else
                printf("No se encontro al empleado\n");            
            system("pause");
            break;
        default:
            printf("Opcion no valida");
            break;
        }
        system("clear");
    }while(selector != 7);

    printf("Saliendo");
    system("pause");
    return 0;
}