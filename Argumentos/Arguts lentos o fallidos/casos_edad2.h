#ifndef PARCIAL2_PIII_FERNANDEZ_RUIBAL_CASOS_EDAD_2_H
#define PARCIAL2_PIII_FERNANDEZ_RUIBAL_CASOS_EDAD_2_H
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <fstream> //permite manejo de archivos
#include <sstream>
//#include "Paciente.h"
#include "../Estructuras/Lista.h"
#include "../Estructuras/quickSort.h"
//#include "../Data_sortings/mergesort.h"

using namespace std;

struct persona
{   
    string genero, nomprov, cui, fechacui, muerte, resumenestado, edad;
};

/**
 * Mostrará los datos de los casos donde la edad sea ‘años’ (ordenados por Nombre de provincia)
 * @param x variable unsigned int con la que comparo edades
 * @param f variable const string opción argumento ingresado por el usuario
 * @return lista ordenada por provincias con casos donde la edad sea en años
 */

int casos_edad(string n, string fileName) {
    fstream fin;
    fin.open("./" + fileName, ios::in);
    if (fin.fail()) {
        cout << "EL ARCHIVO NO EXISTE O NO SE PUEDE ABRIR!" << endl;
        return 1;
    }
    cout << "Calculando..." << endl;
    //string word, id, genero, nomprov, cui, fechacui, muerte, resumenestado;
    //unsigned int total = 0, edad = 0;
    //Lista<persona> delaedad;
    persona e[10000];
    int total=0, edadd;
    string word, edadaux;

    /**
     * Lectura del archivo .CSV a través de getline
     */

    while (getline(fin, word, ',')) {
        getline(fin, word, ','); //Genero
        e[total].genero = word;
        getline(fin, edadaux, ',');
        e[total].edad = edadaux;
        getline(fin, word, ','); //si la edad son años o meses
        getline(fin, word, ','); //pais donde vive
        getline(fin, word, ','); //provincia donde vive
        e[total].nomprov = word;
        getline(fin, word, ','); //departamento donde vive
        getline(fin, word, ','); //provincia donde se examina
        getline(fin, word, ','); //fecha de inicio de sintomas (en formato fecha)
        getline(fin, word, ','); //fecha donde se consulto con medico? (en formato fecha)
        getline(fin, word, ','); //semana de consulta con doctor (en numero del 2020)
        getline(fin, word, ','); // fecha si es que se interno
        getline(fin, word, ','); //estuvo en cui?
        e[total].cui = word;
        getline(fin, word, ','); //cuando estuvo en cui?
        e[total].fechacui = word;
        getline(fin, word, ','); //murio?
        e[total].muerte = word;
        getline(fin, word, ','); //si murio, cuando?
        getline(fin, word, ','); //estuvo en asistencia respiratoria?
        getline(fin, word, ','); //codigo de la provincia de ingreso
        getline(fin, word, ','); //financiamiento publico o privado
        getline(fin, word, ','); //Estado del paciente
        getline(fin, word, ','); //resumen del estado
        e[total].resumenestado = word;
        getline(fin, word, ','); //id de provincia donde vive
        getline(fin, word, ','); //fecha de diagnostico
        getline(fin, word, ','); //id de departamento donde vive
        getline(fin, word); //ultima actualizacion
        total++;
    }
    persona aux;
    for (int i = 1;i < total; i++){
        for (int j = 1; j< total-1; j++){
            if (e[j].nomprov > e[j+1].nomprov){
                aux = e[j]; 
                e[j] = e[j+1]; 
                e[j+1] = aux;
            }
        }
    }
    for (int j = 0; j < total; j++) {
        //if(e[j].edad.substr(1, e[j].edad.size() - 2) == "38"){
        cout <<"Genero: "<< e[j].genero << " Provincia: "<< e[j].nomprov << " Edad: "<< e[j].edad << " CUI: "<< e[j].cui << " Fecha CUI: "<< e[j].fechacui << " Muerte: "<< e[j].muerte << " Resumen: "<< e[j].resumenestado << "\n";
        //}
    }

    return 0;

}

#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_CASOS_EDAD_2_H