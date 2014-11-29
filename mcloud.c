/**
Cambios en el pograma
- Ya no haremos un archivo por cada álbum, lo haremos en uno sólo, las portadas si se pondrán en archivos jpg aparte
- La cosa no cambia mucho, encontre que ordenarlos no está difícil, así que es mejor en un sólo archivo, para no hacernos bolas con 
los archivos, manejaríamos muchos.

-Les voy a mostrar algunas variables globales que pueden usar en sus funciones, si necesitan más las declaran en la funcion
-El archivo de texto que guarda la biblioteca musical se llama biblioteca.txt, 
**/
void registroa(int accion, int numerocatalogo, char fechare[]);
void baja(void);
void bitacora(char useraction[], char escuchada[]);
int accesoadmin(char usuario[], char contrasena[]);
int accesouser(char nickname[], char pass[]);
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

int main()
{
  
  return 0;
}

void registroa(int accion, int numerocatalogo, char fechare[]);
{
 FILE* archivor;
 archivor = fopen("registroa.txt", "a+");
 
 switch (accion)
 {
   case 1:
    fprintf(archivor, "Dio de baja el catálogo número %d el %s\n", numerocatalogo, fechare);
    break;
  case 2:
    fprintf(archivor, "Actualizo el catálogo número %d el %s\n", numerocatalogo, fechare);
    break;
  case 3:
    fprintf(archivor, "Dio de alta el catálogo número %d el %s\n", numerocatalogo, fechare);
    break;
 }
fclose(archivor);  
  
}
void baja(void)
{
  FILE* archivobib;
  int cont = 0, cont2 = 0, senal = 0;
  int numcat, size;
  char fecha[30];
  archivobib = fopen("biblioteca.txt", "a+");
  
  fseek(archivobib, 0, SEEK_END);
  size = ftell(archivobib) / sizeof(disco);
  if (size == 0)
  {
    printf("Aún no hay catálogos registrado\n");
    fclose(archivobib);
  }
  else
  {
    fseek(archivobib, 0, SEEK_SET);
    for (cont = 0; cont < size; cont++)
    {
      fread(&lista[cont], sizeof(disco), 1, archivobib);
    }
    fclose(archivobib);
    
    printf("Qué número de catálogo quieres borrar?: ")
    scanf(" %d", &numcat);
    getchar();ç
    archivobib = fopen("biblioteca.txt", "w");
    for (cont2 = 0; cont < size; cont++)
    {
      if (lista.numero[cont] == numcat)
      {
        printf("El catálogo se ha dado de baja\n");
        senal = 1;
      }
      else
      {
        fwrite(&lisa[cont], sizeof(disco), 1, archivobib);
      }
    }
    fclose(archivobib);
    if (senal == 1)
    {
      time_t ltime;
      ltime=time(NULL);
      strcpy(fecha, asctime(localtime(&ltime)))
      registroa(1, numcat, fecha);
    }
    else
    {
      printf("El número de catálogo que seleccionó no existe\n");
    }
  }
}

bitacora(char user[], char escuchada[])
{
  FILE* archivobitacora;
  archivobitacora = fopen("bitacora.txt", "a+");
  
  fprintf(archivobitacora,"El usuario %s ha escuchado la canción %s\n", user, escuchada);
  fclose(archivobitacora);
  
}
accesoadmin(char usuario[], char contrasena[])
{
  FILE* accesoa;
  char admincorrect[20];
  char passwordcorrect[20];
  accesoa = fopen("accesoadmin.dat", "rb");
  fscanf(accesoa, "%s", admincorrect);
  fscanf(acceso, "%s", passwordcorrect);
  
  
}
