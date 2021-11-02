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
    int EdadF[11], EdadI[11];
    for (int i=0; i<11; i++){
        EdadF[i]=0;
        EdadI[i]=0;
    }

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

        for(int i=0; i<11; i++){
            getline(fin, word, ',');
        }
        if (word.substr(1, word.size() - 2) == "SI") {
            fallecidos++;
                if(edad>=0 && edad<=9){
                    EdadF[0]++;
                }
                if(edad>=10 && edad<=19){
                    EdadF[1]++;
                }
                if(edad>=20 && edad<=29){
                    EdadF[2]++;
                }
                if(edad>=30 && edad<=39){
                    EdadF[3]++;
                }
                if(edad>=40 && edad<=49){
                    EdadF[4]++;
                }
                if(edad>=50 && edad<=59){
                    EdadF[5]++;
                }
                if(edad>=60 && edad<=69){
                    EdadF[6]++;
                }
                if(edad>=70 && edad<=79){
                    EdadF[7]++;
                }
                if(edad>=80 && edad<=89){
                    EdadF[8]++;
                }
                if(edad>=90 && edad<=99){
                    EdadF[9]++;
                }
                if(edad>=100 && edad<=109){
                    EdadF[10]++;
                }
        }
        for(int i=0; i<6; i++){
            getline(fin, word, ',');
        }

        if (word.substr(1, word.size() - 2) == "Confirmado") {
            infectados++;
            if(edad>=0 && edad<=9){
                    EdadI[0]++;
                }
                if(edad>=10 && edad<=19){
                    EdadI[1]++;
                }
                if(edad>=20 && edad<=29){
                    EdadI[2]++;
                }
                if(edad>=30 && edad<=39){
                    EdadI[3]++;
                }
                if(edad>=40 && edad<=49){
                    EdadI[4]++;
                }
                if(edad>=50 && edad<=59){
                    EdadI[5]++;
                }
                if(edad>=60 && edad<=69){
                    EdadI[6]++;
                }
                if(edad>=70 && edad<=79){
                    EdadI[7]++;
                }
                if(edad>=80 && edad<=89){
                    EdadI[8]++;
                }
                if(edad>=90 && edad<=99){
                    EdadI[9]++;
                }
                if(edad>=100 && edad<=109){
                    EdadI[10]++;
                }
        }
        for(int i=0; i<3; i++){
            getline(fin, word, ',');
        }
        getline(fin, word);
    }

    cout << "Cantidad total de muestras: " << total << endl;
    cout << "Cantidad total de infectados: " << infectados << endl;
    cout << "Cantidad total de fallecidos: " << fallecidos << endl;
    cout << "Porcentaje de infectados por muestras: " << (infectados * 100) / total << "%" << endl;
    cout << "Porcentaje de fallecidos por infectados: " << (fallecidos * 100) / infectados << "%" << endl;
    cout << "Cantidad de infectados por rango etario (rango de 10 años):" << endl;
    cout << "\n De 00 a 09: " << EdadI[0] << "\n De 10 a 19: " << EdadI[1] << "\n De 20 a 29: " << EdadI[2] << "\n De 30 a 39: " << EdadI[3] << "\n De 40 a 49: " << EdadI[4] << "\n De 50 a 59: " << EdadI[5] << "\n De 60 a 69: " << EdadI[6] << "\n De 70 a 79: " << EdadI[7] << "\n De 80 a 89: " << EdadI[8] << "\n De 90 a 99: " << EdadI[9] << "\n De 100 a 109: " << EdadI[10] << endl;
    cout << "Cantidad de fallecidos por rango etario (rango de 10 años):" << endl;
    cout << "\n De 00 a 09: " << EdadF[0] << "\n De 10 a 19: " << EdadF[1] << "\n De 20 a 29: " << EdadF[2] << "\n De 30 a 39: " << EdadF[3] << "\n De 40 a 49: " << EdadF[4] << "\n De 50 a 59: " << EdadF[5] << "\n De 60 a 69: " << EdadF[6] << "\n De 70 a 79: " << EdadF[7] << "\n De 80 a 89: " << EdadF[8] << "\n De 90 a 99: " << EdadF[9] << "\n De 100 a 109: " << EdadF[10] << endl;
    return 0;
}
#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_ESTAD_H