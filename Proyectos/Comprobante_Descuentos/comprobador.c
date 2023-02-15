#include <stdio.h>

int main() {
   float totalMatricula, descuentoDiscapacidad, totalMatriculaDescuento, pagoMensual;
   int numCursos, i;
   float precioCurso, totalCursos = 0;

   // Solicitar los datos necesarios
   printf("Introduce el total de cursos a cursar: ");
   scanf("%d", &numCursos);

   for (i = 0; i < numCursos; i++) {
      printf("Introduce el precio del curso %d: ", i+1);
      scanf("%f", &precioCurso);
      totalCursos += precioCurso;
   }

   // Calcular el descuento de discapacidad y el total de la matrícula con descuento
   descuentoDiscapacidad = totalCursos * 0.15;
   totalMatricula = totalCursos - descuentoDiscapacidad;
   totalMatriculaDescuento = totalMatricula * 0.75;

   // Calcular el pago mensual
   printf("Introduce el número de meses para pagar la matrícula: ");
   int numMeses;
   scanf("%d", &numMeses);
   pagoMensual = totalMatriculaDescuento / numMeses;

   // Mostrar los resultados
   printf("El total de la matrícula con descuento es: %.2f\n", totalMatriculaDescuento);
   printf("El pago mensual es: %.2f\n", pagoMensual);

   return 0;
}
