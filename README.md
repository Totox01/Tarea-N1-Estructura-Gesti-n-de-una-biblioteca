**--GESTOR DE BIBLIOTECA EN C--**

Esta aplicacion permite gestionar una biblioteca en consola, gestion tal que crea una lista y permite la manipulacion de esta

**-COMO COMPILAR Y EJECUTAR EL PROGRAMA--**
1. Clonar el repositorio
  *git clone <https://github.com/Totox01/Tarea-N1-Estructura-Gesti-n-de-una-biblioteca>*
2. Navegar hasta el directorio del protecto
  *cd Tarea-N1-Estructura-Gestión-de-una-biblioteca*
3. Compilar el codigo
  *gcc main.c list.c -o Biblioteca*
4. Ejecutar la aplicacion
  ./Biblioteca

**--FUNCIONALIDADES--**
-Añadir un libro 
-Ver los datos de un libro
-Ver los datos de todos los libros en la biblioteca
-Reservar un libro
-Cancelar la reserva del libro
-Retirar un libro
-Devolver el libro
-Mostrar los libros prestados
-Importar libros desde un archivo *(Para utilizar esta funcion hay que reemplazar ARCHIVO con el nombre de tu archivo)*
-Exportar libros a un csv

**--PROBLEMAS CONOCIDOS--**
-La aplicacion no verifica el tamaño de los strings ingresados por lo que ingresar strings de mayor largo que los indicados en la estructura lleva a errores de ejecucion.
-Las funciones Importar desde un csv y Exportar a un csv no toman correctamente en cuenta los archivos por lo que si no se actualizan como es indicado previamente lleva a errores de ejecucion.

**--FUNCIONES A MEJORAR--**
-Automatizar el proceso de identificacion de los archivos en las funciones Importar y Exportar
-Verificar correctamente el tamaño de los strings ingresados en la funcion Registrar libro para que no superen los 50 caracteres 

**Javier Montoya**
-Creación de las funciones del codigo
-Autoevaluacion: (3)Aporte excelente


**Ricardo Santana:**
-Documentacion y comentarios del codigo
-Corrrección de detalles del codigo
-Diseño y redaccion del README
-Autoevaluacion: (2)Aporte bueno