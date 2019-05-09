#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "InputElian.h"
#define ELEMENTS 2

int main()
{
    ////// Variables ////////
    Employee employees[ELEMENTS];

    str_sector sector [5] = {{1,"Administracion"},{2,"Finanzas      "},{3,"Mantenimiento "},{4,"RR.HH         "},{5,"Ventas        "}};

    int auxId = -1 , auxSector;

    float auxSalary;

    char auxName[51] , auxLastName[51];

    int option , flagSpace , seleccion;

    //Inicio Ids desde 1 , y asigno isEmpty = 1//

    initEmployees(employees , ELEMENTS);

    initIds(employees , ELEMENTS);

    /////////////////////////

    //MENU//

    do{
        f_i_PedirIntEntre(&option , 1 , 5 , "**Menu**\n"
                          "Ingrese 1 para dar de Alta un empleado -\n"
                          "Ingrese 2 para Modificar los datos de un empleado -\n"
                          "Ingrese 3 para dar de baja un empleado -\n"
                          "Ingrese 4 para Informar -\n"
                          "Ingrese 5 para Salir -\n");

        switch (option){
            case 1:limpiar();

                chargeEmployeeData(auxName,auxLastName,&auxSalary,&auxSector);

                flagSpace = addEmployee(employees,ELEMENTS,auxName,auxLastName,auxSalary,auxSector);

                if (flagSpace == 0 ){
                limpiar();
                printf("\nEmpleado cargado correctamente\n");
                } else {
                limpiar();
                printf("\nNo queda espacio\n");
                };
                break;


            case 2:limpiar();

                if ( !(isAllEmpty(employees,ELEMENTS)) ){

                f_i_PedirIntEntre(&auxId , 1  , ELEMENTS , "\nIngrese el ID del empleado a modificar:\n");

                auxId = findEmployeeById(employees,ELEMENTS,auxId);

                if (auxId != -1){

                    limpiar();
                    printOneEmployee(employees , auxId , ELEMENTS , sector);
                    seleccion = f_i_SioNo("\nEs este el empleado a modificar?\n");

                    if (seleccion == 1 ) {

                        limpiar();
                        modifyEmployee(employees,ELEMENTS,auxId);
                        limpiar();
                        printf("\nEmpleado modificado correctamente\n");

                    } else {
                    limpiar();
                    printf("\nNo se modifico el empleado\n");
                    };

                }else{
                limpiar();
                printf("\nNo hay ningun empleado bajo ese ID\n");
                };

                }else{

                limpiar();
                printf("\nNo hay ningun empleado cargado\n");
                };

                break;


            case 3:limpiar();

                if ( !(isAllEmpty(employees,ELEMENTS)) ){

                f_i_PedirIntEntre(&auxId , 1  , ELEMENTS , "\nIngrese el ID del empleado a dar de baja:\n");
                limpiar();
                removeEmployee(employees,ELEMENTS,auxId,sector);

                }else {

                limpiar();
                printf("\nNo hay ningun empleado cargado\n");

                };

                break;

            case 4:limpiar();
                if ( !(isAllEmpty(employees,ELEMENTS)) ){

                sortEmployeesBySector(employees,ELEMENTS);
                limpiar();
                printEmployees(employees , ELEMENTS , sector);

                printSalary(employees , ELEMENTS);
                break;
                };
                limpiar();
                printf("\nNo hay ningun empleado cargado\n");
                break;

            case 5:
                limpiar();
                printf("\nAdios\n");
                break;

            default:
                limpiar();
                printf("\nError\n");
                break;

        };

    } while (  (option != 5)  );

    return 0;
}
