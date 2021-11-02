#ifndef PARCIAL2_PIII_FERNANDEZ_RUIBAL_P_MUERTES_H
#define PARCIAL2_PIII_FERNANDEZ_RUIBAL_P_MUERTES_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include "../Estructuras/quickSort.h"

using namespace std;

/**
 * Muestra las n primeras provincias con más muertes ordenadas
de más a menos. Si n no es pasado, se mostrarán todas las provincias.
 * @param n variable int que me permitirá la muestra de las primeras provincias con mayor muertes
 * @param f variable string opción argumento ingresado por el usuario
 * @return lista de provincias ordenadas de más a menos
 */

void p_muertes(int n, string fileName) {
    fstream fin;
    fin.open("./" + fileName, ios::in);
    if (fin.fail()) {
        cout << "EL ARCHIVO NO EXISTE O NO SE PUEDE ABRIR!" << endl;
        //return 1;
    }
    cout << "Calculando..." << endl;
    vector<string> muertes[25];
    string word, nombreprovincia;
    int sumaprovincias[25];
    string Provincias[] = {"CABA", "Buenos Aires", "Catamarca", "Chaco", "Chubut", "Córdoba", "Corrientes", "Entre Ríos", "Formosa", "La Pampa", "La Rioja", "Mendoza", "Neuquén", "Río Negro", "Salta", "San Juan", "San Luis", "Santa Cruz", "Santa Fe", "Santiago del Estero", "Tierra del Fuego", "Tucumán", "Jujuy", "Misiones", "SIN ESPECIFICAR"};
    for (int i = 0; i < 25; i++)
    {
        muertes[i].push_back(Provincias[i]);
    }

    for (int i = 0; i < 25; i++)
    {
        sumaprovincias[i] = 0;
    }

    while (getline(fin, word, ',')) { //mientras haya algo que leer
    for(int i=0; i<4; i++){
            getline(fin, word, ',');
        }
        //ciclo for recorre la tabla hasta llegar a la columna de provincia
        getline(fin, nombreprovincia, ','); //obtengo el nombre de la provincia
        for(int i=0; i<9; i++){
            getline(fin, word, ',');
        }
        //ciclo for recorre la tabla hasta llegar a la columna de muertes

       if (word.substr(1, word.size() - 2) == "SI") {
            for (int i = 0; i < 25; i++)
        {
            if (nombreprovincia.substr(1, nombreprovincia.size() - 2) == Provincias[i])
            {
                sumaprovincias[i]++;
            }
        }
        }
        for(int i=0; i<9; i++){
            getline(fin, word, ',');
        }
        getline(fin, word);
        //termina de recorrer la tabla para repetir todo otra vez
    }
    for (int i = 0; i < 25; i++)
    {
        muertes[i].push_back(to_string(sumaprovincias[i]));
    }

    quickSort(muertes, 0, 24);

    if (n == 0) {
        cout<<"Todas las provincias con más muertes ordenadas de más a menos son:"<<endl;
        for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<" --> "<<muertes[i][j];
        }
        cout<<endl;
    } //sin n muestra todas
    } else {
    cout<<"Las primeras provincias con más muertes ordenadas de más a menos son:"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<" --> "<<muertes[i][j];
        }
        cout<<endl;
    }
    } //con n muestra la cantidad n
}

#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_P_MUERTES_H