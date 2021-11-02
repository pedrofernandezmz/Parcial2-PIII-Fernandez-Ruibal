#ifndef PARCIAL2_PIII_FERNANDEZ_RUIBAL_P_CASOS_H
#define PARCIAL2_PIII_FERNANDEZ_RUIBAL_P_CASOS_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include "../Estructuras/quickSort.h"

using namespace std;

/**
 * Muestra las n primeras provincia con más contagios ordenadas
de más a menos. Si n no es pasado, se mostrarán todas las provincia.
 * @param n variable int que me permitirá la muestra de las primeras provincia con mayor contagio
 * @param f variable string opción argumento ingresado por el usuario
 * @return lista de provincia ordenadas de más a menos
 */

void p_casos(int n, string fileName) {
    fstream fin;
    fin.open("./" + fileName, ios::in);
    if (fin.fail()) {
        cout << "EL ARCHIVO NO EXISTE O NO SE PUEDE ABRIR!" << endl;
        //return 1;
    }
    cout << "Calculando..." << endl;
    vector<string> casos[25];
    string word, nombreprovincia;
    int sumaprovincia[25];
    string provincia[] = {"CABA", "Buenos Aires", "Catamarca", "Chaco", "Chubut", "Córdoba", "Corrientes", "Entre Ríos", "Formosa", "La Pampa", "La Rioja", "Mendoza", "Neuquén", "Río Negro", "Salta", "San Juan", "San Luis", "Santa Cruz", "Santa Fe", "Santiago del Estero", "Tierra del Fuego", "Tucumán", "Jujuy", "Misiones", "SIN ESPECIFICAR"};
    for (int i = 0; i < 25; i++)
    {
        casos[i].push_back(provincia[i]);
    }

    for (int i = 0; i < 25; i++)
    {
        sumaprovincia[i] = 0;
    }
    //Lista<estado> provincia;

    /**
   * Lectura del archivo .CSV a través de getline
   */

    while (getline(fin, word, ',')) { //mientras haya algo que leer
    for(int i=0; i<4; i++){
            getline(fin, word, ',');
        }
        //ciclo for recorre la tabla hasta llegar a la columna de provincia
        /*getline(fin, word, ','); //el Dato no importa
        getline(fin, word, ','); //edad
        getline(fin, word, ','); //si la edad son años o meses
        getline(fin, word, ','); //pais donde vive
        */
        getline(fin, nombreprovincia, ','); //obtengo el nombre de la provincia
        for(int i=0; i<15; i++){
            getline(fin, word, ',');
        }
        //ciclo for recorre la tabla hasta llegar a la columna de clasificacio-->Confirmado o Descartado
        /*getline(fin, word, ','); //departamento donde vive
        getline(fin, word, ','); //provincia donde se examina
        getline(fin, word, ','); //fecha de inicio de sintomas (en formato fecha)
        getline(fin, word, ','); //fecha donde se consulto con medico? (en formato fecha)
        getline(fin, word, ','); //semana de consulta con doctor (en numero del 2020)
        getline(fin, word, ','); // fecha si es que se interno
        getline(fin, word, ','); //estuvo en cui?
        getline(fin, word, ','); //cuando estuvo en cui?
        getline(fin, word, ','); //murio?
        getline(fin, word, ','); //si murio, cuando?
        getline(fin, word, ','); //estuvo en asistencia respiratoria?
        getline(fin, word, ','); //codigo de la provincia de ingreso
        getline(fin, word, ','); //financiamiento publico o privado
        getline(fin, word, ','); //Estado del paciente
        getline(fin, word, ','); //resumen del estado*/

        /**
        * Generación de lista para comparar provincia
        * En caso de que la provincia ya se encuentre, se incrementa el número. En caso contrario,
        * se forma un nuevo contador
        * @param temp(nombreprovincia,cantidad) = lista donde se almacena el Nombre de las provincia
        * @param nombreprovincia = nombres de las provincia
        */

       if (word.substr(1, word.size() - 2) == "Confirmado") {
            for (int i = 0; i < 25; i++)
        {
            if (nombreprovincia.substr(1, nombreprovincia.size() - 2) == provincia[i])
            {
                sumaprovincia[i]++;
            }
        }
        }
        for(int i=0; i<3; i++){
            getline(fin, word, ',');
        }
        getline(fin, word);
        //termina de recorrer la tabla para repetir todo otra vez
        /*getline(fin, word, ','); //id de provincia donde vive
        getline(fin, word, ','); //fecha de diagnostico
        getline(fin, word, ','); //id de departamento donde vive
        getline(fin, word); //ultima actualizacion*/
    }
    for (int i = 0; i < 25; i++)
    {
        casos[i].push_back(to_string(sumaprovincia[i]));
    }

    quickSort(casos, 0, 24);

    if (n == 0) {
        cout<<"Todas las provincia con más contagios ordenadas de más a menos son:"<<endl;
        for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<" --> "<<casos[i][j];
        }
        cout<<endl;
    } //sin n muestra todas
    } else {
    cout<<"Las primeras provincia con más contagios ordenadas de más a menos son:"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<" --> "<<casos[i][j];
        }
        cout<<endl;
    }
    } //con n muestra la cantidad n

    /**
    * Lista con algoritmo de ordenamiento
    * Si no se presenta variable n, imprime todas las provincia. En caso contrario, se muestra provincia
    * ordenadas de más a menos
    * @param final = lista con las provincia y el algoritmo de ordenamiento para ordenar las mismas
    */

    /*Lista<estado> final = mergesortnum(provincia);
    if (n == 0) {
        final.print(); //sin n
        return 0;
    }
    final.printn(n); //con n
    return 0;*/
}
#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_P_CASOS_H