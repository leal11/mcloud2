/**
Cambios en el pograma
- Ya no haremos un archivo por cada álbum, lo haremos en uno sólo, las portadas si se pondrán en archivos jpg aparte
- La cosa no cambia mucho, encontre que ordenarlos no está difícil, así que es mejor en un sólo archivo, para no hacernos bolas con 
los archivos, manejaríamos muchos.

Les voy a mostrar algunas variables globales que pueden usar en sus funciones, si necesitan más las declaran en la funcion

**/

struct catalogo
{
  int numero;
  char artista[20];
  char album[20];
  char genero[20];
  char portada[20];
  char cancion[5][20]; // arreglo de 5 canciones de 20 caracteres de largo
} disco, lista[100];

char fecha[20];
