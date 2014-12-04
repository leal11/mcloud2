/**
Cambios en el pograma
- Ya no haremos un archivo por cada álbum, lo haremos en uno sólo, las portadas si se pondrán en archivos jpg aparte
- La cosa no cambia mucho, encontre que ordenarlos no está difícil, así que es mejor en un sólo archivo, para no hacernos bolas con 
los archivos, manejaríamos muchos.

-Les voy a mostrar algunas variables globales que pueden usar en sus funciones, si necesitan más las declaran en la funcion
-El archivo de texto que guarda la biblioteca musical se llama biblioteca.txt, 
**/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
struct catalogo
{
  int numero;
  int nocanciones;
  char artista[20];
  char album[20];
  char genero[20];
  char ano[8];
  char portada[20];
  char cancion[5][20]; // arreglo de 5 canciones de 20 caracteres de largo
} disco, lista[100];

int sort_function(const void* a, const void* b);
void ordenar(void);
void registroa(int accion, int numerocatalogo, char fechare[]);
void baja(int numerobaja);
void altausuario(void);
void bitacora(char useraction[], char escuchada[]);
int accesoadmin(char usuario[], char contrasena[]);
int accesouser(char nickname[], char pass[]);
void alta(void);
void imprimiracervo(void);
void seleccionar(char usuarioescucha[]);

struct usuario
{
  char nombre[40];
  char nickname[20];
  char password[20];
  char correo[30];
} nuevousuario;

char fecha[20];
char auxorden[100][20];

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		if (strcmp(argv[1], "-c") == 0)
		{
			system("clear");			
			printf("\n\n\t\t\tDesarrollado por:\n\t\t\t ☁︎  Ivan Parada\n\t\t\t ☁︎  Santiago Olavarri\n\t\t\t ☁︎  Leonardo Lael Villar\n");
		}

		else if (strcmp(argv[1], "-lst") == 0)
		{
			imprimiracervo();
		}	
	}

	else
	{	
		char usuarioacces[20];
		char passwordacces[20];
		int opcionuser,menu,resultado = 0, opadmin = 0, bajalbum, menubaja, menuadmin;

		system("clear");

		printf("\n\t\t\t\t\t ♫  M-CLOUD ®\n\t\t\t\tTu servicio de musica gratuito");
		printf("\n\n\t\t\tDesarrollado por:\n\t\t\t ☁︎  Ivan Parada\n\t\t\t ☁︎  Santiago Olavarri\n\t\t\t ☁︎  Leonardo Lael Villar\n");
		printf("\n\n\t\t\t\t\tPresione  ENTER  para continuar");
		getchar();

		system("clear");

		printf("\n\t\t\t  SELECCIONE UNA OPCION:\n\n\t\t\t\t1)Usuario\t\t♖ \n\n\t\t\t\t2)Administrador\t\t✍ \n");
        scanf("%d",&opcionuser);
		getchar();
	
		switch (opcionuser)
		{
			case 1:
				do
				{
					system("clear");
		  			printf("\n\n\t\t\t ♖ \tUSUARIO\n\n\t\tINGRESE SU USUARIO Y CONTRASEÑA:\n\n\n\n");
					printf("\t\t\tUSUARIO: ");				
					gets(usuarioacces);
					printf("\t\t\tCONTRASEÑA: ");
					gets(passwordacces);
					resultado = accesouser(usuarioacces, passwordacces);
				
					if (resultado != 1)
					{
						system("clear");
						printf("\t\t\tUSUARIO INCORRECTO\n");
					}

				}while(resultado != 1);

				system("clear");
	    
				printf("\t\t\t\t\t\t\t\t♫  M-CLOUD\n\t\t\t\t\t\t♖ \n\t\t\tBIENVENIDO:%s ",usuarioacces);
				printf("\n\n\t\t\tSELECCIONA UNA OPCION:\n\n\t\t\t  1) Acceder a la biblioteca\t\t♫ ");
				printf("\n\n\t\t\t  2) Salir\t\t\t\tⓍ \n\n\t\t\tOPCION: ");
				scanf("%d",&menu);
				getchar();
				switch (menu)
		  		{
		    		case 1:
		       			system("clear");
		        		printf("\t\t\t\t\t\t\t\t♫  M-CLOUD\n\n\t\t\t♖   %s ",usuarioacces);
						printf("\n\n\t\t\t🀫 🀫  ÁLBUMS:\n\n");
						seleccionar(usuarioacces);
						break;

					case 2:

						printf("HASTA LUEGO\n");
						break;

					default:
        				system("clear");
        				printf("\n\n\n\n\n\n\n\t\t\tESA OPCION NO ESTA DENTRO DE LAS OPCIONES DEL MENU\n");
        				usleep(3000000);
        				system("clear");
						break;
				}
		
						break;
			case 2:

				do
				{
					system("clear");
		   			printf("\n\n\t\t\t ✎ \tADMINISTADOR\n\n\t\t\tINGRESE SU USUARIO Y CONTASEÑA:\n\n\n\n");				
					printf("ADMIN: ");
					gets(usuarioacces);
					printf("CONTRASEÑA: ");
					gets(passwordacces);
					resultado = accesoadmin(usuarioacces, passwordacces);
					
					if (resultado == 1)
					{
						printf("Bienvenido\n");
					}

					else
					{
						printf("Acceso denegado\n");
					}
				}while(resultado != 1);
	
				do
				{

					system("clear");
		
					printf("\t\t\t..........Bienvenido..........\n\n");
					printf("\t\t\tSELECCIONE UNA OPCIÓN:\n\n\n");
					printf("\t\t\t1)Nuevo    Usuario\t✚\n\n");
			        printf("\t\t\t2)Nuevo      Álbum\t♫\n\n");
					printf("\t\t\t3)Eliminar   Álbum\t♺\n\n");
					printf("\t\t\t4)Actualizar Álbum\tZ\n\n");
					printf("\t\t\t4)Ayda            \t?\n\n");
					printf("\t\t\t5)Salir           \tⓍ\n\n");
					printf("\n\t\t\tOPCIÓN: ");
					scanf("%d", &opadmin);
					getchar();

					switch(opadmin)
					{
		 				case 1:
							system("clear");
							printf("\t\t\t\t\t✚ ♖\n\n");
							printf("\t\t\tINGRESE LOS DATOS DEL NUEVO USUARIO:\n");
							altausuario();

							system("clear");
							printf("\n\n\n\n\n\t\t\t\t\t  ✚ ♖\n\n");
							printf("\t\t\t\tSE HAN AGREGADO LOS DATOS\n\t\t\t\t     CORRECTAMENTE\n\n\t\t\t\t\t   ✔\n ");
							usleep(3000000);
							break;

//_________________________________________________________________________________________________________
						 case 2:
							system("clear");
							printf("\t\t\t\t\t✚ \n\n");
							printf("\t\t\tINGRESE LOS DATOS DEL NUEVO ÁLBUM:\n\n");
							alta();

							system("clear");
							printf("\n\n\n\n\n\t\t\t\t\t  ✚ \n\n");
							printf("\t\t\t\tSE HAN AGREGADO LOS DATOS\n\t\t\t\t     CORRECTAMENTE\n\n\t\t\t\t\t   ✔\n ");
							usleep(3000000);

							break;

//__________________________________________________________________________________________________________
						 case 3:

		 					system("clear");
           				    printf("\n\n\t\t\t\t\t     ♺  \n\n");
            			    printf("\t\t\t\t¿QUE NUMERO DE ÁLBUM DESEA\n\t\t\t\t\t ELIMINAR?\n\n");
							printf("\t\t\tNUMERO:");
							scanf("%d",&bajalbum);
							getchar();
							system("clear");
							printf("\n\n\n\n\n\t\t\t\t\t\t♺  \n\n");
               				printf("\t\t\t\t   ¿ESTAS SEGURO QUE DESEAS\n\t\t\t\t\tELIMINAR EL ÁLBUM\n\n");
					//		printf("\t\t\t%s",nombre del album);
              				printf("\t\t\t\t1) SI\t\t\t2)NO\n");
							scanf("%d",&menubaja);
		
							switch(menubaja)
							{
							 	case 1:
									baja(bajalbum);
									system("clear");
									printf("\n\n\t\t\t\t\t   ♺  \n\n");
									printf("\t\t\t\t   EL ÁLBUM HA SIDO\n\t\t\t\t      ELIMINADO\n");
						   			break;

			 					case 2:
								// Se regresa a el menu principal
			 					break;
							}

							break;

//_________________________________________________________________________________________________________
							case 4:
		
								system("clear");
								printf("\n\n\t\t\t\t    ? \n\n");
								printf("\t\t\t\t  AYUDA  \n\n");
								printf("\t\t\tSELECCIONE UNA OPCION\n\n");
								printf("\t\t\t1)Nuevo Usuario \t✚\n\n");
        						printf("\t\t\t2)Nuevo Álbum   \t♫\n\n");
								printf("\t\t\t3)Eliminar Álbum\t♺\n\n");
        						printf("\t\t\t4)Salir         \tⓍ\n\n");
								printf("\n\n\t\t\tOPCIÓN: ");

								scanf("%d",&menuadmin);
								getchar();
								switch (menuadmin)
								{
//______________________________
									case 1:
	                					system("clear");
                						printf("\n\n\t\t\t\t    ?  \n\n");
                						printf("\t\t\t\t  AYUDA\n\n");
										printf("\t\t\tPARA AGREGAR UN NUEVO USUARIO:\n\n");
										printf("\t\t\tEscoja la opción 1.\n");
										printf("\t\t\tEscriba el nombre de usuario y contraseña.\n");
										printf("\t\t\tEsto le permitirá a un nuevo usuario acceder a M-CLOUD\n");
										printf("\t\t\tPara regresar al menu presione enter\n");
										getchar();
										break;
//_____________________________
			 						 case 2:

										system("clear");
                                		printf("\n\n\t\t\t\t    ?  \n\n");
                                		printf("\t\t\t\t  AYUDA\n\n");
										printf("\t\t\tPARA AGREGAR UN NUEVO ÁLBUM: \n\n");
										printf("\t\t\tEscoja la opción 2.\n\n");
										printf("\t\t\tEscriba los datos que le pida el programa.\n\n");
										printf("\t\t\tPara agregar una portada a el álbum,\n");
										printf("\t\t\tdeberá haber creado y guardado en un \n");
										printf("\t\t\tnuevo archivo, la imagen de la portada de\n");
										printf("\t\t\tdicho álbum. \n\n");
										printf("\t\t\tUna vez guardada la imagen en el \n");
										printf("\t\t\tarchivo, escriba el nombre del archivo creado en donde dice: \n");
										printf("\t\t\t“ Archivo de la portada: ” \n\n");
										printf("\t\t\tDespués de haber rellenado los datos, el \n");
										printf("\t\t\tprograma lo regresara a el menú \n");
										printf("\t\t\tprincipal. \n");
										printf("\t\t\tPara regresar al menu presione enter\n");
										getchar();
										break;

//____________________________________
									case 3:

										system("clear");
                               			printf("\n\n\t\t\t\t    ?  \n\n");
                                		printf("\t\t\t\t  AYUDA\n\n");

										printf("\t\t\tPARA ELIMINAR UN ALBUM:\n\n");
				                        printf("\t\t\tEscoja la opción 3. \n");
				                        printf("\t\t\tEscriba el numero de Álbum que desee \n");
				                        printf("\t\t\teliminar\n \n");
				                        printf("\t\t\t( Una vez eliminado el álbum, se perderá \n");
				                        printf("\t\t\ttoda la información acerca de ese álbum)\n\n");
				                        printf("\t\t\tSi esta de acuerdo con esto, presione 1 \n");
				                        printf("\t\t\tpara continuar, o 2 para cancelar la \n");
				                        printf("\t\t\toeración \n");
										printf("\t\t\tEl programa lo regresara a el menú\n");
										printf("\t\t\tprincipal.");
										printf("\t\t\tPara regresar al menu presione enter\n");
										getchar();
										break;
								}
//____________________________________

							case 5:
						//VOLVER AL MENU PRINCIPAL
							break;
						}
				}while(opadmin != 5);
			
				break;
		}
	}
 
	return 0;
}

int sort_function(const void* a, const void* b)
{
  return (strcmp((char*)a, (char*)b));
}
void ordenar(void)
{
	FILE* ordenaralbum;
	int medir, contadorord, contador2;
	ordenaralbum = fopen("biblioteca.txt", "r");
	fseek(ordenaralbum, 0, SEEK_END);
	medir = ftell(ordenaralbum) / sizeof(disco);
	fseek(ordenaralbum, 0, SEEK_SET);
	for (contadorord = 0; contadorord < medir; contadorord++)
	{
		fread(&lista[contadorord], sizeof(disco), 1, ordenaralbum);
		strcpy(auxorden[contadorord], lista[contadorord].album);
	}

	qsort((void*)auxorden, medir, sizeof(auxorden[0]), sort_function);

	for (contadorord = 0; contadorord < medir; contadorord++)
	{
		for (contador2 = 0; contador2 < medir; contador2++)
		{
			if (strcmp(auxorden[contadorord], lista[contador2].album) == 0)
			{
				disco = lista[contadorord];
				lista[contadorord] = lista[contador2];
				lista[contador2] = disco;
			}
		}
	}

}
void registroa(int accion, int numerocatalogo, char fechare[])
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
void baja(int numerobaja)
{
  FILE* archivobib;
  int cont = 0, cont2 = 0, senal = 0;
  int  size;
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

    
    archivobib = fopen("biblioteca.txt", "w");
    for (cont2 = 0; cont2 < size; cont2++)
    {
      if (lista[cont2].numero == numerobaja)
      {
        printf("El catálogo se ha dado de baja\n");
        senal = 1;
      }
      else
      {
        fwrite(&lista[cont2], sizeof(disco), 1, archivobib);
      }
    }
    fclose(archivobib);
    if (senal == 1)
    {
      time_t ltime;
      ltime=time(NULL);
      strcpy(fecha, asctime(localtime(&ltime)));
      registroa(1, numerobaja, fecha);
    }
    else
    {
      printf("El número de catálogo que seleccionó no existe\n");
    }
  }
}

void bitacora(char useraction[], char escuchada[])
{
  FILE* archivobitacora;
  archivobitacora = fopen("bitacora.txt", "a+");

  fprintf(archivobitacora,"El usuario %s ha escuchado la canción %s\n", useraction, escuchada);
  fclose(archivobitacora);
}
int accesoadmin(char usuario[], char contrasena[])
{
  FILE* accesoa;
  char admincorrect[20];
  char passwordcorrect[20];
  accesoa = fopen("accesoadmin.dat", "rb");
  fscanf(accesoa, "%s", admincorrect);
  fscanf(accesoa, "%s", passwordcorrect);
  if(strcmp(admincorrect, usuario) == 0 && strcmp(passwordcorrect, contrasena) == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
  fclose(accesoa);
}

int accesouser(char nick[], char pass[])
{
  FILE* accesou;
  int flag = 0;
  int cont,  size;
  accesou = fopen("accesousuarios.dat", "rb");
 fseek(accesou, 0, SEEK_END);
 size = ftell(accesou) / sizeof(nuevousuario);
 fseek(accesou, 0, SEEK_SET);
 for (cont = 0; cont < size; cont++)
 {
    fread(&nuevousuario, sizeof(nuevousuario), 1, accesou);
    if (strcmp(nuevousuario.nickname, nick) == 0 && strcmp(nuevousuario.password, pass) == 0)
    {
      flag = 1;
    }
 }
  return flag;

}
void altausuario(void)
{
  FILE* adduser;

  printf("Cual es su nombre completo? :");
  gets(nuevousuario.nombre);
  printf("Cual es su nickname?(no mas de 20 caracteres):");
  gets(nuevousuario.nickname);
  printf("Cual es su contraseña?(no mas de 20 caracteres): ");
  gets(nuevousuario.password);
  printf("Cuál es su correo?: ");
  gets(nuevousuario.correo);

  adduser = fopen("accesousuarios.dat", "ab");
  fwrite(&nuevousuario, sizeof(nuevousuario), 1, adduser);
  fclose(adduser);
}


void alta(void)
{
  int numcatalogo, contador, numdecanciones;
  char fechaal[30];
  FILE* archivo;
  archivo=fopen("secuenciacatalogo.txt","r");
 // fseek(archivo, sizeof(int), SEEK_END);
  fscanf(archivo,"%d",&numcatalogo);
	printf("%d", numcatalogo);  
	disco.numero = numcatalogo + 1;
	fclose(archivo);
  printf("\nIntroduce el nombre del  artista: ");
  gets(disco.artista);
  printf("\nIntroduce el nombre del  album: ");
  gets(disco.album);
  printf("\nIntroduce el genero: ");
  gets(disco.genero);
  printf("Año: ");
  gets(disco.ano);	
  printf("\nIntroduce el nombre del archivo de la portada: ");
  gets(disco.portada);
do
  {
  	printf("\nCuantas canciones quieres dar de alta: ");
  	scanf("%d",&numdecanciones);
  	getchar();
	disco.nocanciones = numdecanciones;

	if(numdecanciones>5)
    		printf("\nNo puedes dar de alta mas de 5 canciones");
  }while (numdecanciones >5);
 for (contador = 0; contador < numdecanciones; contador++)
    {
      printf("\nIntroduce el nombre del la cancion %d: ",contador+1);
      gets(disco.cancion[contador]);
    }

	archivo = fopen("biblioteca.txt", "a+");
	fwrite(&disco, sizeof(disco), 1, archivo);
  	fclose(archivo);
  	time_t ltime;
  	ltime = time(NULL);
  	strcpy(fechaal, asctime(localtime(&ltime)));

  	registroa(3, disco.numero, fechaal);
	archivo=fopen("secuenciacatalogo.txt","w");
	fseek(archivo, 0, SEEK_END);
	fprintf(archivo,"%d ", disco.numero);
	fclose(archivo);
}
void seleccionar(char usuarioescucha[])
{

	FILE* archivoselec;
	int tamano,numcatalogo,flag=0, avanzar = 0, cancionrep = 0, album, x, i, opcion, found;
	char mostrarportada[]="shotwell ";
	
	imprimiracervo();

	archivoselec = fopen("biblioteca.txt", "r");
	
	if (archivoselec == NULL)
	{
		printf("hay problemas\n");
		exit(0);
	}
	
	fseek(archivoselec, 0, SEEK_END);
	tamano = ftell(archivoselec) / sizeof(disco);
	fseek(archivoselec, 0, SEEK_SET);
 	
	do
	{
 		printf("\nSELECCIONA UN ALBÚM: ");
 		scanf("%d",&album);
 		getchar();
		system("clear");
	for(x = 0;x < tamano; x++)
    {
		fread(&lista[x], sizeof(disco), 1, archivoselec);
    }

	fclose(archivoselec);

	for(i = 0; i < tamano; i++)
    {
		if(lista[i].numero == album)
		{
			flag = 1;
			found = i;		
		}
    }
  if (flag == 1)
 {
	system("clear");
	do
	{
		//system("clear");
		printf("\t\t\t☁︎ \t\t\t\t\t♫  M-CLOUD\n\n");	
		printf("\t\t\t♫  ÁLBUM: %s\n\n\t\t\tArtista: %s",lista[found + avanzar].album, lista[found + avanzar].artista);

	 	printf("\n\n\t\t\tGénero: %s\n\n\t\t\tAño: %s\n\n\n",lista[found + avanzar].genero, lista[found + avanzar].ano);
	 	strcat(lista[found + avanzar].portada,mostrarportada);
	 //	system(lista[album].portada);

		for (x = 0; x < lista[found + avanzar].nocanciones; x++)
		{
			printf("\t\t\t♪%-20s☁︎ \n", lista[found + avanzar].cancion[x]);
		}

		printf("\t\t\t________________________________________\n");
		printf("\t\t\t⇠ \t\t►  / 𝗹𝗹\t\t⇢    >>\n");
		printf("\t\t\t________________________________________\n");
		printf("\t\t\t⓵ \t\t⓶  / ⓷  \t⓸     ⓹ \n\t\t\t\t\t\t\n\t\t\t\t\t⓺ SALIR Ⓧ\n\t\t\tOPCION: ");
 	
		scanf("%d",&opcion);
		getchar();
	switch(opcion)
		{

			case 1:
   			break;

			case 2: 
				system("clear");			
				printf(" REPRODUCIENDO: %s...\n", lista[found + avanzar].cancion[cancionrep]);
				bitacora(usuarioescucha, lista[found + avanzar].cancion[cancionrep]);	
   			 break;

			case 3:
				system("clear");				
				printf("Pause....\n");
			break;

			case 4:
				if (avanzar < tamano - 1)
					{
						avanzar++;
						cancionrep = 0;
						system("clear");
					}

					else
					{
						printf("Es el último albúm\n");
						usleep(50000000);
						system("clear");
					}

				break;
// salir
   			case 5:
				if (cancionrep < lista[found + avanzar].nocanciones -1)
				{
					system("clear");					
					cancionrep++;
					printf(" Reproduciendo %s...\n", lista[found + avanzar].cancion[cancionrep]);
					bitacora(usuarioescucha, lista[found + avanzar].cancion[cancionrep]);
				}	
				break;

			case 6:
					
			break;

			/*case 7:
				printf(" Reproduciendo %s...\n", lista[found + avanzar].cancion[cancionrep]);
				bitacora(usuarioescucha, lista[found + avanzar].cancion[cancionrep]);
			break;*/

			 default: printf("Error");
				break;
  		}
	}while(opcion != 6);
}

	else
	{
		printf("El numero de catalogo que usted busco no existe\n");
	}

 }while(flag == 0);

}

void imprimiracervo(void)
{

	FILE* archivoimpacer;
	int album,tamano,x;
 
	archivoimpacer = fopen("biblioteca.txt","r");

	fseek(archivoimpacer, 0, SEEK_END);

	tamano = ftell(archivoimpacer) / sizeof(disco);

	fseek(archivoimpacer, 0, SEEK_SET);

	for(x = 0; x < tamano; x++)
	{
		fread(&lista[x], sizeof(disco), 1, archivoimpacer);
	}
    
	fclose(archivoimpacer);

    ordenar();

    for(x = 0; x < tamano; x++)
	{
		printf("%d. %s\n",lista[x].numero, lista[x].album);
	}
}

