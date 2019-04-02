#include <stdio.h>
#include <stdlib.h>
#include "CalculadoraF.h"

//pedir numero
/** \brief Limpia la memoria y realiza un scanf
 * \param ()
 * \return El numero ingresado
 */
float pedirNum(){
float n;
fflush(stdin);
scanf("%f", & n);

return n;
};

//continuar
/** \brief Pregunta al usuario si quiere continuar (S o N) ; no permite otros caracteres
 * \param ()
 * \return Si se ingresa S devuelve int 1 , si se ingresa N devuelve int 0
 */
int continuar(void){

    char r;
    printf( "\n --S-- o --N-- \n");
    r = toupper(getche());

while ( !((r=='S')||(r=='N')) ){

        printf ("\nError, ingrese (S/N)... ");
        r = toupper(getche());
        }

return (r=='S');
};

//suma
/** \brief Ingresan 2 numeros y devuelve la suma
 * \param "a" es el primer numero a sumar
 * \param "b" es el segundo numero a sumar
 * \return La suma de ambos numeros
 */

float suma (float a , float b){
float total;
total = (a+b);

return total;
};

//resta
/** \brief Ingresan 2 numeros y devuelve la resta
 * \param "a" es el numero al que se le resta
 * \param "b" se le resta a "a"
 * \return La resta entre ambos numeros
 */
float resta (float a , float b){
float total;
total = (a-b);

return total;
};

//multiplicacion
/** \brief Ingresan 2 numeros y devuelve la multiplicacion
 * \param "a" es el numero a multiplicar
 * \param "b" es el multiplicador
 * \return El producto de ambos numeros
 */
float multiplicacion (float a , float b){
float total;
total = (a*b);

return total;
};
//division
/** \brief Ingresan 2 numeros y devuelve la division
 * \param "a" es el dividendo
 * \param "b" es el divisor (NO se valida si es 0)
 * \return El producto de la division.
 */
float division(float a ,float b){

float total;

total = a/b;

return total ;
};

//factorizacion
/** \brief Ingresa un numero float y se castea a int , se devuelve su factorial
 * \param "x" es el numero ingresado (NO se valida si es negativo)
 * \return El factorial de "x" como int.
 */
int factorial(float x)
{
int total=1,i;

(int)x;

for (i=x;i>0;i--){
    total = total*i;
    }

    return total;
};
