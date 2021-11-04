#ifndef PARCIAL2_PIII_FERNANDEZ_RUIBAL_CASOS_EDAD_H
#define PARCIAL2_PIII_FERNANDEZ_RUIBAL_CASOS_EDAD_H
#include <iostream>
#include <fstream> //permite manejo de archivos
#include <sstream>
#include "string.h"
#include <vector>
#include <string.h>
#include "../Estructuras/ArbolBinarioAVL.h"

using namespace std;

/**
 * Mostrará los datos de los casos donde la edad sea ‘años’
(ordenados por nombre de provincia).
 * @param n variable int que me permitirá la ver la edad de la muestra
 * @param fileName variable string csv ingresado por el usuario
 * @return imprime los datos de las personas con esa edad
 */

void casos_edad(int n, string fileName) {

    int colsOfInterest[] = {0, 2, 3, 5, 12, 13, 14, 17, 20, 22}; //columnas almacenadas en array... columnas importantes
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + fileName, ios::in);
    if (fin.fail()) {
        cout << "EL ARCHIVO NO EXISTE O NO SE PUEDE ABRIR!" << endl;
        //return 1;
    }
    cout << "Calculando..." << endl;

    vector<string> row;
    string line, word, edadaux;
    int total = 0;
    int edadn = n;
ArbolBinarioAVL<vector <string> > arbol;//inicio arbol

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
        edadaux = row[2];
        if (row[3].compare("Años") == 0){
        if(edadaux.compare("NA") != 0){
            if(stoi(edadaux) == edadn){
            arbol.put(row); //paso losdatos al arbol si la edad es igual a la ingresada
         }
       } 
      }
    }
    arbol.inorder();//ordeno arbol de casos segun el id de provincia(CABA antes que BSAS)
}

#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_CASOS_EDAD_H