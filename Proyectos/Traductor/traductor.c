#include <stdio.h>
#include <string.h>
#define N 50

typedef struct
{
  char eng[N];
  char esp[N];
  int lleno;
} traductor;

traductor trad[N];

void vacio();
void anadir();
void traducir();
void tradu(int op);

int main()
{
  int op;
  char key;

  vacio();

  do
  {
    do
    {
      printf("\n\nElige que deseas hacer:\n");
      printf("(1) Anadir palabras al traductor.\n");
      printf("(2) Buscar traduccion de una palabra.\n");
      scanf("%i", &op);
    } while (op < 1 || op > 2);

    switch (op)
    {
    case 1:
      anadir();
      break;
    case 2:
      traducir();
      break;
    }
    printf("Introducir si deseas realizar otra operacion: (S/N) ");
    scanf("%c", &key);
  } while (key == 'S' || key == 's');

  system("pause");
  return 0;
}

void vacio()
{
  int i;

  for (i = 0; i < N; i++)
  {
    trad[i].lleno = 0;
  }
}

void anadir()
{
  int i, aux;
  aux = 0;

  for (i = 0; i < N && aux == 0; i++)
  {
    if (trad[i].lleno == 0)
    {
      printf("Introduce la palabra en Ingles: ");
      fflush(stdin);
      fgets(trad[i].eng, N, stdin);
      cambio(trad[i].eng);
      printf("Introduce la palabra en Espanol: ");
      fflush(stdin);
      fgets(trad[i].esp, N, stdin);
      cambio(trad[i].esp);

      trad[i].lleno = 1;
      aux = 1;
    }
  }
}

void traducir()
{
  int op;
  do
  {
    printf("Elige que deseas hacer:\n");
    printf("(1) Traducir de Ingles a Espanol.\n");
    printf("(2) Traducir de Espanol a Ingles.\n");
    scanf("%i", &op);
  } while (op < 1 || op > 2);

  switch (op)
  {
  case 1:
    tradu(op);
    break;
  case 2:
    tradu(op);
    break;
  }
}

void tradu(int op)
{
  int i, j, temp;
  char aux[N];
  temp = 0;

  printf("Introduce la palabra que deseas buscar: ");
  fflush(stdin);
  fgets(aux, N, stdin);
  cambio(aux);
  if (op == 1)
  {
    for (i = 0; i < N && temp == 0; i++)
    {
      j = strcmp(aux, trad[i].eng);
      if (j == 0)
      {
        printf("La traduccion de %s es %s.\n", trad[i].eng, trad[i].esp);
        temp = 1;
      }
    }
  }
  else
  {
    for (i = 0; i < N && temp == 0; i++)
    {
      j = strcmp(aux, trad[i].esp);
      if (j == 0)
      {
        printf("La traduccion de %s es %s.\n", trad[i].esp, trad[i].eng);
        temp = 1;
      }
    }
  }
}

void cambio(char palabra[N])
{
  int i;
  for (i = 0; i < N; i++)
  {
    if (palabra[i] == '\n')
    {
      palabra[i] = '\0';
    }
  }
}