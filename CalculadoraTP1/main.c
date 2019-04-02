#include <stdio.h>
#include <stdlib.h>
#include "CalculadoraF.h"

int main()
{
float a=0, b=0 , laSuma , laResta , laMultiplicacion , laDivision;

int inicio=1 , opcion , factorialA , factorialB, flag=0;


while (inicio==1)
    {
    printf("--------------------MENU--------------------\n"
           "A=%.2f--------------------------------B=%.2f\n", a,b);

    printf("\nIngrese 1 para modificar el primer operando (A)\n"
           "\nIngrese 2 para modificar el primer operando (B)\n"
           "\nIngrese 3 para calcular todas las operaciones\n"
            "\na) Calcular la suma (%.2f + %.2f)"
            "\nb) Calcular la resta (%.2f - %.2f)"
            "\nc) Calcular la division (%.2f / %.2f)"
            "\nd) Calcular la multiplicacion (%.2f x %.2f)"
            "\ne) Calcular el factorial (%.0f! y %.0f!)\n"
           "\nIngrese 4 para mostrar los resultados\n"
           "\n-Ingrese 0 para salir.\n\n"
           "\n\nOpcion : ",a,b ,a,b ,a,b ,a,b ,a,b);

    opcion= pedirNum();

    switch(opcion){
        case 1:printf("\n-Ingrese el valor de A :") ; a = pedirNum() ; system("CLS") ;flag=0; break;
        case 2:printf("\n-Ingrese el valor de B :") ; b= pedirNum() ; system("CLS") ;flag=0; break;

        case 3:
        system("CLS");flag=1;
        if (a==0&&b==0){
                printf("**No ingresaste ningun valor***\n\n") ; break ;};

        printf("**Todos los valores fueron calculados, presione 4 para mostrar los resultados**\n\n");
        laSuma = suma(a,b) ; laResta = resta(a,b) ; laDivision = division(a,b) ; laMultiplicacion = multiplicacion(a,b) ;
        factorialA = factorial(a) ; factorialB = factorial(b) ;break;

        case 4:system("CLS");
        //veo si se calcularon los valores
        if (flag==0) {
            system("CLS");
            printf("**Primero se deben calcular/actualizar todos los resultados**\n\n");break;};

        printf("------------------Resultados------------------\n\n"
           "A=%.2f------------------------------------B=%.2f\n\n", a,b);
        // suma resta

        printf("A)El resultado de %.2f + %.2f es: %.2f\n\n",a,b,laSuma);
        printf("B)El resultado de %.2f - %.2f es %.2f\n\n",a,b,laResta);
        //division

        if (b==0){
            printf("C)No se puede dividir por 0\n\n");}
        else {
            printf("C)El resultado de %.2f / %.2f es %.2f\n\n",a,b,laDivision) ;};
        //multiplicacion

        printf("D)El resultado de %.2f x %.2f es %.2f\n\n",a,b,laMultiplicacion) ;
        //factorial

        if (a<0){
            printf("E)No se puede calcular el factorial de (%.0f) porque es un numero negativo\n\n",a);}
        else{
            printf("E)El factorial de %.0f es: %d \n\n",a,factorialA);};
        if (b<0){
            printf("No se puede calcular el factorial de (%.0f) porque es un numero negativo\n\n",b);}
        else{
            printf("El factorial de %.0f es : %d \n\n",b,factorial(b));};
        //pregunta volver

        printf("\n\nVolver al menu?\n\n") ; inicio=continuar() ;system("CLS"); break ;
        //salida

        case 5:return 0;
        //error

        default:system("CLS");printf("*** La ultima opcion ingresada no fue valida ***\n\n");
    };//switch
    };//while "inicio"

return 0;

}//main{

