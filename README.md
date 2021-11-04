# Proyecto 2° Parcial - Programación III - Francisco Ruibal, Pedro Fernández Márquez
### Introducción:
Debido al caso de pandemia del año 2020, deseamos hacer un visualizador de datos de los casos
de Argentina. Para esto se quiere poder mostrar datos ordenados y agrupados en distintas categorías.
Como así también hacer un procesado simple de los datos y mostrar alguna información extra.
### Enunciado:
Realizar una aplicación informática que lea el archivo “CSV” emitido por el Ministerio de Salud con
los casos registrados hasta la fecha. El programa será comandado por línea de comandos para realizar
determinadas tareas.
El archivo debe ser leído y procesado para brindar la siguiente información según los argumentos
que se le pasen.
### Información estadística:
*Cantidad total de muestras
Cantidad total de infectados
Cantidad de fallecidos
% de infectado por muestras
% de fallecidos por infectados
Cantidad de infectados por rango etario ( rango de 10 años)
Cantidad de muertes por rango etario ( rango de 10 años)*
### Manual de uso:
**covid19.exe [ Argumentos ] Covid19Casos.csv**
Como por Ejemplo:
--> ./main [ -casos_cui 08-08-2020 ] Covid19Casos100000.csv
--> ./main [ -p_muertes 5 ] Covid19Casos100000.csvs
### Argumentos posibles:
- **-estad** *Mostrará la información estadística.*
- **-p_casos [n]** *Mostrará las n primeras provincias con más contagios ordenadas de más a menos. Si n no es pasado, se mostrarán todas las provincias.*
- **-p_muertes [n]** *Mostrará las n provincias con más muertes ordenadas de más a menos. Si n no es pasado, se mostrarán todas las provincias.*
- **-casos_edad años** *Mostrará los datos de los casos donde la edad sea ‘años’ (ordenados por nombre de provincia).*
- **-casos_cui [fecha]** *Mostrará los datos de los casos que estuvieron en cuidados intensivos ordenados por fecha de cuidados intensivos, si fecha está indicada, se mostrarán solo las fechas mayores a esta.*
