#include <stdio.h>
#include <stdlib.h>


float pedirNum();
/** \brief Limpia la memoria y realiza un scanf
 * \param ()
 * \return El numero ingresado
 */

int continuar();
/** \brief Pregunta al usuario si quiere continuar (S o N) ; no permite otros caracteres
 * \param ()
 * \return Si se ingresa S devuelve int 1 , si se ingresa N devuelve int 0
 */

float suma(float,float);
/** \brief Ingresan 2 numeros y devuelve la suma
 * \param "a" es el primer numero a sumar
 * \param "b" es el segundo numero a sumar
 * \return La suma de ambos numeros
 */

float resta(float,float);
/** \brief Ingresan 2 numeros y devuelve la resta
 * \param "a" es el numero al que se le resta
 * \param "b" se le resta a "a"
 * \return La resta entre ambos numeros
 */

float multiplicacion(float,float);
/** \brief Ingresan 2 numeros y devuelve la multiplicacion
 * \param "a" es el numero a multiplicar
 * \param "b" es el multiplicador
 * \return El producto de ambos numeros
 */

float division(float,float);
/** \brief Ingresan 2 numeros y devuelve la division
 * \param "a" es el dividendo
 * \param "b" es el divisor (NO se valida si es 0)
 * \return El producto de la division.
 */

int factorial(float);
/** \brief Ingresa un numero float y se castea a int y se devuelve su factorial
 * \param "x" es el numero ingresado (NO se valida si es negativo)
 * \return El factorial de "x" como int.
 */

