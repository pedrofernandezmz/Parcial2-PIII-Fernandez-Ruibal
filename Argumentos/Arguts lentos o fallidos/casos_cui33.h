#ifndef PARCIAL2_PIII_FERNANDEZ_RUIBAL_CASOS_CUI_H
#define PARCIAL2_PIII_FERNANDEZ_RUIBAL_CASOS_CUI_H
#include <iostream>
#include <fstream> //permite manejo de archivos
#include <sstream>
#include "string.h"
#include <vector>
#include <string.h>
#include "../Estructuras/ArbolBinario.h"

using namespace std;

/**
 * Mostrará los datos de los casos donde la edad sea ‘años’
(ordenados por nombre de provincia).
 * @param n variable int que me permitirá la ver la edad de la muestra
 * @param fileName variable string csv ingresado por el usuario
 * @return imprime los datos de las personas con esa edad
 */

void casos_cui(string n, string fileName) {

    int colsOfInterest[] = {0, 2, 3, 5, 12, 13, 14, 17, 20, 22}; //columnas almacenadas en array... columnas importantes
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;
    string line, word, edadaux;
    int total = 0;
    int fechaaux;
    int fecha = stoi(n);
ArbolBinario<vector <string> > arbol;//inicio arbol

    while (getline(fin, line))
    {
        total++;
        row.clear();
        stringstream s(line);
        
        while (getline(s, word, ','))
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);//palabra sin comilla y espacios
            }
            else
            {
                word = "NA"; //no hay nada escrito
            }
            row.push_back(word);
        }
        //comparo si la edad ingresada es igual a la del caso
        if (row[12].compare("SI") == 0 )
        {
            fechaaux = stoi(row[13]);
            if(fecha<fechaaux){
                  arbol.put(row);
            }
         //paso losdatos al arbol si la edad es igual a la ingresada
    }
    arbol.inorder();//ordeno arbol de casos segun el id de provincia(CABA antes que BSAS)
}
}

#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_CASOS_CUI_H