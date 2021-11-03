#ifndef PARCIAL2_PIII_FERNANDEZ_RUIBAL_ESTAD_H
#define PARCIAL2_PIII_FERNANDEZ_RUIBAL_ESTAD_H

#include <iostream>
#include <fstream> //permite manejo de archivos
#include <string.h>
#include <sstream>
#include "../Estructuras/ArbolBinarioAVL.h"
#include "../Estructuras/rango.h"

using namespace std;

/**
 * Permite la muestra de información estadística
 * @param f = variable string opción argumento ingresado por el usuario
 * @return árbol binario y muestra de información estadística
 */
int estad(string fileName) {
    fstream fin;
    fin.open("./" + fileName, ios::in);
    if (fin.fail()) {
        cout << "EL ARCHIVO NO EXISTE O NO SE PUEDE ABRIR!" << endl;
        return 1;
    }
    cout << "Calculando..." << endl;
    string word;
    int total = 0, edad = 0, infectados = 0, fallecidos = 0;
    ArbolBinarioAVL<rango> arboldeinfectados, arboldefallecidos; //los árboles para ordenar rangos etarios

    while (getline(fin, word, ',')) { //mientras haya algo que leer
        total++;
        getline(fin, word, ','); //Genero
        getline(fin, word, ','); //Edad
        try {
            edad = std::stoi(word.substr(1, word.size() - 2)); //std::stoi pasa string a int
        } catch (...) {
            edad = 0; //Si no hay edad pongo 0 de lo contrario obtengo un error
        }
        getline(fin, word, ','); //Años o Meses
        if (word.substr(1, word.size() - 2) == "Meses") {
            edad = 0;
        }

        int mrango = edad / 10;
        int minrango = mrango * 10;
        int maxrango = mrango * 10 + 9;
        rango dato(minrango, maxrango, 1);

        for(int i=0; i<11; i++){
            getline(fin, word, ',');
        }
        if (word.substr(1, word.size() - 2) == "SI") {
            fallecidos++;
            try {
                arboldefallecidos.put(dato);
            } catch (int error) {
                arboldefallecidos.search(dato).addCantidad();
            }
        }
        for(int i=0; i<6; i++){
            getline(fin, word, ',');
        }

        if (word.substr(1, word.size() - 2) == "Confirmado") {
            infectados++;
            try {
                arboldeinfectados.put(dato);
            } catch (int error) {
                arboldeinfectados.search(dato).addCantidad();
            }
        }
        for(int i=0; i<3; i++){
            getline(fin, word, ',');
        }
        getline(fin, word);
        //termina de recorrer la tabla para repetir todo otra vez
    }

    cout << "Cantidad total de muestras: " << total << endl;
    cout << "Cantidad total de infectados: " << infectados << endl;
    cout << "Cantidad total de fallecidos: " << fallecidos << endl;
    cout << "Porcentaje de infectados por muestras: " << (infectados * 100) / total << "%" << endl;
    cout << "Porcentaje de fallecidos por infectados: " << (fallecidos * 100) / infectados << "%" << endl;
    cout << "Cantidad de infectados por rango etario (rango de 10 años):" << endl;
    arboldeinfectados.print();
    cout << endl;
    cout << "Cantidad de fallecidos por rango etario (rango de 10 años):" << endl;
    arboldefallecidos.print();
    cout << endl;
    return 0;
}
#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_ESTAD_H