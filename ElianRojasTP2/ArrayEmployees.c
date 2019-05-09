#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "InputElian.h"
#define TRUE 1
#define FALSE 0

/** \brief This function initializes the IDs of each element of the structure employee , from 1 to x
* the max quantity of elements.
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return void
*/
void initIds (Employee * list , int len){
    int i;
    for(i=0;i < len ; i++)
    {
        list[i].id = i+1;
    }
};

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len){
    int i;

    for(i=0;i < len ; i++)
    {
        list[i].isEmpty = TRUE ;
    };
    return 0;
};

/** \brief indicates that all position in the array are empty
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (1) if array is all empty , else returns 0.
*
*/
int isAllEmpty(Employee*list , int len){
int i;
    for(i=0;i < len ; i++)
    {
        if (list[i].isEmpty != 1){
            return 0;
        };
    };
    return 1;
};

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
*
* \param list employee*
* \param len int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
**/
int addEmployee(Employee* list,int len, char name[],char lastName[] , float salary , int sector){

    //Find free space//

    int i=0 , idFreeSpace = -1;

    for (i=0;i<len;i++){

    if (list[i].isEmpty == TRUE){
            idFreeSpace = i;
            break;
    }
    }

    if (idFreeSpace != -1){

    list[idFreeSpace].isEmpty = FALSE;
    strcpy(list[idFreeSpace].name , name );
    strcpy(list[idFreeSpace].lastName , lastName );
    list[idFreeSpace].salary =  salary;
    list[idFreeSpace].sector =  sector;

    return 0;

    };

    return -1;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \param sector *str_sector
* \return int
*/
int printEmployees(Employee * list, int length , str_sector * sector){

    int i;
    printf("Id:  Sector:        Salario:  Apellido y nombre:\n\n");
        for(i=0;i<length;i++){
        if (list[i].isEmpty == 0){
            printf("%4d %5.14s %3.3f     %s %s\n",list[i].id, sector[list[i].sector-1].sectorName ,list[i].salary, list[i].lastName , list[i].name );
        };
        };
    return 0;
}

/** \brief print the content of one employee
*
* \param OneEmployee Employee
* \param length int
* \param sector *str_sector
* \return int
*/
int printOneEmployee(Employee * oneEmployee , int id , int length , str_sector * sector){

    printf("Id:  Sector:        Salario:  Apellido y nombre:\n\n");
    printf("%4d %5.14s %3.3f     %s %s\n",oneEmployee[id].id , sector[oneEmployee[id].sector-1].sectorName,oneEmployee[id].salary, oneEmployee[id].lastName , oneEmployee[id].name );
    return 0;
}

/** \brief find an Employee by Id en returns the index position in array.
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*/
int findEmployeeById(Employee* list, int len,int id){
    int i;
    for ( i=0; i<len ; i++ ){

        if ( list[i].id == id && list[i].isEmpty == 0){
            return i;
        }

        };

        return -1;
};

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
* \param list Employee*
* \param len int
* \param id int
* \param sector str_sector *
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*/

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id , str_sector * sector){

    int aux;
    int opcion;
    aux = findEmployeeById(list, len, id);

    if( aux != -1 ){

       printOneEmployee(list , aux , len , sector);

        opcion = f_i_SioNo("Desea eliminar este empleado?\n");

        if (opcion == 1) {
            list [aux].isEmpty = 1;
            limpiar();
            printf("\nEmpleado eliminado de la lista correctamente\n");
            return 0;
        } else {
            limpiar();
            printf("\nNo se elimino el empleado\n");
            return 0;
        };
    }
    limpiar();
    printf("\nNo se encontro el empleado\n");
    return -1;
}

/** \brief ask values for a employee structure
*
* \param name char []
* \param lastName[] char
* \param salary * float
* \param sector * int
* \return void
**/
void chargeEmployeeData(char name[] , char lastName[] , float * salary,int * sector){

    char aux [51];

    f_i_PedirIntEntre(sector , 1 , 5, "Ingrese el Sector del empleado:\n1-Administracion\n2-Finanzas\n3-Mantenimiento\n4-RR.HH\n5-Ventas\n");

    f_i_PedirNombre(name , 51 , "\nIngrese el Nombre del empleado:");

    f_i_PedirNombre(lastName , 51 , "\nIngrese el Apellido del empleado:");

    f_i_PedirStringSoloFloat(aux,25,"\nIngrese el Salario del empleado");

    * salary = atof(aux);

};

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployeesBySector(Employee * list, int len){

    Employee aux;

    int i,j;
    for(i=0; i<len-1; i++)
    {
    for(j=i+1; j<len; j++)
    {
    if(list[i].sector>list[j].sector){
        aux = list[j];
        list[j] = list[i];
        list[i] = aux;
    }

    if (list[i].sector == list[j].sector){

    if( strcmp( list[i].lastName , list[j].lastName)>0 ){
        aux = list[j];
        list[j] = list[i];
        list[i] = aux;
    };
    };
};
};
    return 0;
};

/** \brief ask values for an existing employee structure to modify
* \param list Employee*
* \param len int
* \param id int
* \return void
**/
void modifyEmployee (Employee list [],int len,int id){

    int auxSector,option;
    char auxName[25];
    float auxSalary;

    f_i_PedirIntEntre(&option,1,5,"\n1-Modificar Nombre\n2-Modificar Apellido\n3-Modificar Salario\n4-Modificar Sector\n5-Salir\nOpcion : ");

    switch (option){
    case 1 :f_i_PedirNombre(auxName,51,"\nIngrese el Nombre del empleado:\n");
            strcpy(list[id].name,auxName);
        break;
    case 2 :f_i_PedirNombre(auxName,51,"\nIngrese el Apellido del empleado:\n");
            strcpy(list[id].lastName,auxName);
        break;
    case 3 : f_i_PedirStringSoloFloat(auxName,25,"\nIngrese el Salario del empleado");
            auxSalary = atof(auxName);
            list[id].salary = auxSalary;
        break;
    case 4 :f_i_PedirIntEntre(&auxSector, 1 , 5, "Ingrese el sector del empleado:\n1-Administracion\n2-Finanzas\n3-Mantenimiento\n4-RR.HH\n5-Ventas\n");
            list[id].sector = auxSector;
        break;
    case 5 :
        break;
}



}

/** \brief prints average salary , total salaries , quantity of employees with over average salary
* \param list Employee*
* \param len int
* \return void
*/
void printSalary(Employee list[] , int len){
    float TotalSalaries , averageSalary = 0;
    int overAverage = 0 , activeEmployees = 0 , i;

    for (i=0;i<len;i++){
        if (list[i].isEmpty == 0){
            activeEmployees ++;
            TotalSalaries = TotalSalaries + list[i].salary;
        };
    };

    averageSalary = (TotalSalaries / activeEmployees)  ;

    for(i=0;i<len;i++){

        if (list[i].salary > averageSalary && list[i].isEmpty == 0){
            overAverage++;
        };
    };
    printf("\nSuma de todos los salarios: %.3f \nSalario promedio: %.3f \nCantidad de empleados por encima del promedio:%d\n",TotalSalaries,averageSalary,overAverage);
}

/** \brief charges predefined examples of employees
* \param list Employee*
* \return void
**/
void hardCode(Employee list[]){

    Employee example[]=
    {
        {1, "Uno", "Aaa" , 23.000,1,0},
        {22, "Dos", "Zzz", 18.000, 1, 0},
        {35, "Tres", "Jjj", 21.000, 5,0},
        {42, "Cuatro", "Ppppp" , 24.000, 2, 0},
        {56, "Cinco", "Bbb" , 34.000, 3, 0},
        {1000, "Seis", "Ccc" , 32.000,5, 0},
        {73, "Siete", "Iiiii" , 26.000, 4,0},
        {99, "Ocho", "Wwww" , 32.000,5, 0},
        {980, "Nueve", "Llll" , 32.000,5, 0},
        {21, "Diez", "Kkkkkkkkk" , 32.000,5, 0}
    };
    int i;
    for( i=0; i < 10; i++)
    {
        list[i] = example[i];
    };




};


