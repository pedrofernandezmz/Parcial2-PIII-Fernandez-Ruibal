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
de más a menos. Sin n se muestran todas las provincia.
 * @param n variable int que me permitirá la muestra de las primeras provincia con mayor contagio
 * @param fileName variable string csv ingresado por el usuario
 * @return lista de provincia ordenadas de máyor a menor
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
    }//a casos le doy el nombre de cada provincia

    for (int i = 0; i < 25; i++)
    {
        sumaprovincia[i] = 0;
    }//a cada provincia la inicio en 0

    while (getline(fin, word, ',')) { //mientras haya algo para leer
    for(int i=0; i<4; i++){
            getline(fin, word, ',');
        }
        //ciclo for recorre la tabla hasta llegar a la columna de provincia
        getline(fin, nombreprovincia, ','); //obtengo el nombre de la provincia
        for(int i=0; i<15; i++){
            getline(fin, word, ',');
        }
        //ciclo for recorre la tabla hasta llegar a la columna de clasificacio-->Confirmado o Descartado

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
    }
    for (int i = 0; i < 25; i++)
    {
        casos[i].push_back(to_string(sumaprovincia[i]));
    }//agrego a casos la cantidad de la suma de casos de cada provincia

    quickSort(casos, 0, 24);//quicksort para ordenar de mayor a menor le paso casos y el inicio y fin (25 provs)

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
}
#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_P_CASOS_H