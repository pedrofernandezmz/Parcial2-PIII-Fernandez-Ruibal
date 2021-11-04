#ifndef PARCIAL2_PIII_FERNANDEZ_RUIBAL_CASOS_CUI_H
#define PARCIAL2_PIII_FERNANDEZ_RUIBAL_CASOS_CUI_H

#include <iostream>
#include <fstream> //permite manejo de archivos
#include <sstream>
#include "string.h"
#include <vector>
#include <string.h>
#include "../Estructuras/ArbolBinario.h"
#include "../Estructuras/fecha.h"

/**
 * Mostrará los datos de los casos ordenados por fecha cui
 * @param f variable string que me permitirá la ver la fecha
 * @param fileName variable string csv ingresado por el usuario
 * @return imprime los datos de las personas por fecha
 */

void casos_cui(string f, string fileName){
int fecha = fechaint(f);

    fstream fin;
    fin.open("./" + fileName, ios::in);
    if (fin.fail()) {
        cout << "EL ARCHIVO NO EXISTE O NO SE PUEDE ABRIR!" << endl;
        //return 1;
    }
    cout << "Calculando..." << endl;

if(!fin.fail()){
    vector<string> row;
    string line, word;
   
   int total = -1;
   int fecha2 = 0;

ArbolBinario<vector <string> > arbol;
    while (getline(fin, line))
    {
        total++;
        row.clear();
        stringstream s(line);
        while (getline(s, word, ','))
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);
            }
            else
            {
                word = "NA";
            }
            row.push_back(word);
          
        }
        
        if (row[12].compare("SI") == 0 )
        {
            fecha2 = fechaint(row[13]);

            if(fecha<=fecha2){
              arbol.put(row);
            }
        } 
    }
    arbol.inorder();
}
}

#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_CASOS_CUI_H