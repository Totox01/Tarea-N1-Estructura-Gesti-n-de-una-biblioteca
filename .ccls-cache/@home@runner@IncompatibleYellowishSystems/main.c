/*INTEGRANTES: RICARDO SANTANA / JAVIER MONTOYA
  RUTS: 21213874-6 / 21519157-5 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
typedef struct Libro {
  char titulo[51];
  char autor[21];
  char genero[21];
  char isbn[14];
  char ubicacion[21];
  char estado[11]; 
  List* reservas;
} Libro;

// ————  ꒰ Funciones del libro ꒱  ————

void registrarLibro(List* lista){
  Libro* nuevo = (Libro*) malloc(sizeof(Libro));
  if (nuevo == NULL) {
    printf("No se pudo reservar memoria para el libro\n");
    return;
  }

  nuevo->reservas = createList();
  if (nuevo->reservas == NULL) {
    printf("No se pudo crear la lista de reservas\n");
    free(nuevo);
    return;
  }
 
  printf("Ingrese el titulo del libro: ");
  scanf(" %[^\n]", nuevo->titulo);
  printf("Ingrese el autor del libro: ");
  scanf(" %[^\n]", nuevo->autor);
  printf("Ingrese el genero del libro: ");
  scanf(" %[^\n]", nuevo->genero);
  printf("Ingrese el ISBN del libro: ");
  scanf(" %[^\n]", nuevo->isbn);
  printf("Ingrese la ubicacion del libro: ");
  scanf(" %[^\n]", nuevo->ubicacion);

  strcpy(nuevo->estado, "Disponible");

  pushBack(lista, nuevo);
}

void mostrarLibro(List* lista) {
  char isbn[14];
  printf("Ingrese el ISBN del libro: ");
  scanf(" %[^\n]", isbn);

  Libro* aux = firstList(lista);
  while (aux != NULL) {
   
    if (strcmp(isbn, aux->isbn) == 0) {
      
      printf("=========LIBRO==========\n");
      printf("Titulo: %s\n", aux->titulo);
      printf("Autor: %s\n", aux->autor);
      printf("Genero: %s\n", aux->genero);
      printf("ISBN: %s\n", aux->isbn);
      printf("Ubicacion: %s\n", aux->ubicacion);
      printf("Estado: %s\n", aux->estado);
     
      if (firstList(aux->reservas) != NULL) {
        printf("Reservas:\n");
        char* estudiante = firstList(aux->reservas);
        while (estudiante != NULL) {
          printf("- %s\n", estudiante);
          estudiante = nextList(aux->reservas);
        }
      }
      return; 
    }
   
    aux = nextList(lista);
  }

  printf("No se encontró ningún libro con ese ISBN\n");
}

void mostrarBiblioteca(List* lista) {
  int cont = 1;
  Libro* aux = firstList(lista);
  
  while (aux!=NULL){
    printf("=========LIBRO %i =========\n",cont);
    printf("Titulo: %s \n",aux->titulo);
    printf("Autor: %s \n",aux->autor);
    printf("Género: %s \n",aux->genero);
    printf("ISBN: %s \n",aux->isbn);
    printf("Ubicación: %s \n",aux->ubicacion);
    printf("Estado: %s \n",aux->estado);
    cont++;
    aux = nextList(lista);
  }
    
}

void reservarLibro(List* lista) {
  char tituloAux[51];
  char autorAux[21];
  printf("Ingrese el titulo del libro: ");
  scanf(" %[^\n]", &tituloAux);
  printf("Ingrese el autor del libro: ");
  scanf(" %[^\n]",&autorAux);
  Libro* aux = firstList(lista);
  while(aux!=NULL){
    if(strcmp(tituloAux,aux->titulo)==0 &&strcmp(autorAux,aux->autor)==0){
      char estudiante[51];
      printf("Ingrese el nombre del estudiante: ");
      scanf(" %[^\n]",&estudiante);

      pushBack(aux->reservas,estudiante);
      strcpy(aux->estado,"Reservado");
      return;
    }
    aux = nextList(lista);
  }
  
}

void cancelarReserva(List* lista) {
  char tituloAux[51];
  char autorAux[21];
  printf("Ingrese el titulo del libro");
  scanf(" %[^\n]", &tituloAux);
  printf("Ingrese el autor del libro: ");
  scanf(" %[^\n]",&autorAux);
  Libro* aux = firstList(lista);
  while(aux!=NULL){
    if(strcmp(tituloAux,aux->titulo)==0 &&strcmp(autorAux,aux->autor)==0){
      char estudiante[51];
      printf("Ingrese el nombre del estudiante: ");
      scanf(" %[^\n]",&estudiante);
      char* aux2 = firstList(aux->reservas);
      
      while(aux2!=NULL){
        if(strcmp(estudiante,aux2)==0){
          popCurrent(aux->reservas);
          
          if(firstList(aux->reservas)==NULL) strcpy(aux->estado, "Disponible");
          printf("La reserva del libro %s de %s ha sido cancelada.\n");
          return;
        }
        aux2=nextList(aux->reservas);
      }
    }
  }
    
}

void retirarLibro(List* lista) {
  char isbn[14];
  char estudiante[51];
  printf("Ingrese el ISBN del libro: ");
  scanf(" %[^\n]", isbn);
  printf("Ingrese el nombre del estudiante: ");
  scanf(" %[^\n]", estudiante);

   Libro* aux = firstList(lista);
   while (aux != NULL) {
     if (strcmp(isbn, aux->isbn) == 0) {
       if (strcmp(aux->estado, "Disponible") == 0) {
         strcpy(aux->estado, "Prestado");
         pushFront(aux->reservas, estudiante);
         printf("El libro %s ha sido prestado a %s\n", aux->titulo, estudiante);
         return;
       }
       else {
         printf("El libro %s no está disponible\n", aux->titulo);
         return;
       }
     }
     aux = nextList(lista);
   }
   printf("No se encontró ningún libro con ese ISBN\n");
}

void devolverLibro(List* lista) {
  char isbn[14];
  char estudiante[51];
  printf("Ingrese el ISBN del libro: ");
  scanf(" %[^\n]", isbn);
  printf("Ingrese el nombre del estudiante: ");
  scanf(" %[^\n]", estudiante);

   Libro* aux = firstList(lista);
   while (aux != NULL) {
     if (strcmp(isbn, aux->isbn) == 0) {
       if (strcmp(aux->estado, "Prestado") == 0) {
         char* prestamista = firstList(aux->reservas);
         if (strcmp(estudiante, prestamista) == 0) {
           popFront(aux->reservas);
           if (firstList(aux->reservas) == NULL) {
             strcpy(aux->estado, "Disponible");
           }
           else {
             strcpy(aux->estado, "Reservado");
           }
           printf("El libro %s ha sido devuelto por %s\n", aux->titulo, estudiante);
           return;
         }
         else {
           printf("El estudiante %s no tiene prestado el libro %s\n", estudiante, aux->titulo);
           return;
         }
       }
       else {
         printf("El libro %s no está prestado\n", aux->titulo);
         return;
       }
     }
     aux = nextList(lista);
   }
   printf("No se encontró ningún libro con ese ISBN\n");
}

void mostrarLibrosPrestados(List* lista) {
  int cont = 0;
  Libro* aux = firstList(lista);
  while (aux != NULL) {
    if (strcmp(aux->estado, "Prestado") == 0) {
      cont++;
      printf("=========LIBRO %i==========\n", cont);
      printf("Titulo: %s\n", aux->titulo);
      printf("Autor: %s\n", aux->autor);
      printf("Genero: %s\n", aux->genero);
      printf("ISBN: %s\n", aux->isbn);
      printf("Ubicacion: %s\n", aux->ubicacion);
      printf("Estado: %s\n", aux->estado);
      printf("Prestado a: %p\n", firstList(aux->reservas));
    }
    aux = nextList(lista);
  }
  if (cont == 0) {
    printf("No hay ningún libro prestado\n");
  }
}

#define ARCHIVO "biblioteca.csv"
#define MAX_LINEA 256

void importarCSV(List* lista) {
  FILE* archivo = fopen(ARCHIVO, "r");
  if (archivo == NULL) {
    printf("No se pudo abrir el archivo %s\n", ARCHIVO);
    return;
  }
  
  char linea[MAX_LINEA];
  while (fgets(linea, MAX_LINEA, archivo) != NULL) {
    Libro* nuevo = (Libro*) malloc(sizeof(Libro));
    if (nuevo == NULL) {
      printf("No se pudo reservar memoria para el libro\n");
      break;
    }
    
    nuevo->reservas = createList();
    if (nuevo->reservas == NULL) {
      printf("No se pudo crear la lista de reservas\n");
      free(nuevo);
      break;
    }
    
    char* token = strtok(linea, ",");
    strcpy(nuevo->titulo, token);
    token = strtok(NULL, ",");
    strcpy(nuevo->autor, token);
    token = strtok(NULL, ",");
    strcpy(nuevo->genero, token);
    token = strtok(NULL, ",");
    strcpy(nuevo->isbn, token);
    token = strtok(NULL, ",");
    strcpy(nuevo->ubicacion, token);
    token = strtok(NULL, ",");
    strcpy(nuevo->estado, token);

    while ((token = strtok(NULL, ",")) != NULL) {
      char* salto = strchr(token, '\n');
      if (salto != NULL) {
        *salto = '\0';
      }
      pushBack(nuevo->reservas, token);
    }
    
    pushBack(lista, nuevo);
  }
  
  fclose(archivo);
  printf("Se han importado los libros desde el archivo %s\n", ARCHIVO);
}

void exportarCSV(List* lista) {
  FILE* archivo = fopen(ARCHIVO, "w");
  if (archivo == NULL) {
    printf("No se pudo abrir el archivo %s\n", ARCHIVO);
    return;
  }
  
  Libro* aux = firstList(lista);
  while (aux != NULL) {
    fprintf(archivo, "%s,%s,%s,%s,%s,%s", aux->titulo, aux->autor, aux->genero,
            aux->isbn, aux->ubicacion, aux->estado);
            
    char* estudiante = firstList(aux->reservas);
    while (estudiante != NULL) {
      fprintf(archivo, ",%s", estudiante);
      estudiante = nextList(aux->reservas);
    }
    
    fprintf(archivo, "\n");
    aux = nextList(lista);
  }
  
  fclose(archivo);
  printf("Se han exportado los libros al archivo %s\n", ARCHIVO);
}


int main(void) {
  List* lista = createList();
  int opcion;

  do {
    printf("Bienvenido al programa de gestión de biblioteca.\n");
    printf("Por favor, elija una opción:\n");
    printf("1. Registrar libro\n");
    printf("2. Mostrar datos de libro\n");
    printf("3. Mostrar todos los libros\n");
    printf("4. Reservar libro\n");
    printf("5. Cancelar reserva de libro\n");
    printf("6. Retirar libro\n");
    printf("7. Devolver libro\n");
    printf("8. Mostrar libros prestados\n");
    printf("9. Importar libros desde un archivo CSV\n");
    printf("10. Exportar libros a un archivo CSV\n");
    printf("11. Salir\n");
    scanf("%i", &opcion);

    switch (opcion) {
      case 1:
        registrarLibro(lista);
        break;
      case 2:
        mostrarLibro(lista);
        break;
      case 3:
        mostrarBiblioteca(lista);
        break;
      case 4:
        reservarLibro(lista);
        break;
      case 5:
        cancelarReserva(lista);
        break;
      case 6:
        retirarLibro(lista);
        break;
      case 7:
        devolverLibro(lista);
        break;
      case 8:
        mostrarLibrosPrestados(lista);
        break;
      case 9:
        importarCSV(lista);
        break;
      case 10:
        exportarCSV(lista);
        break;
      default:
        printf("Opción inválida. Por favor, ingrese una opción válida.\n");
    }
  } while (opcion != 11);
  
  cleanList(lista);

  return 0;
}

