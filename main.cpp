#include <iostream>
#include <fstream> //permite manejo de archivos
#include <sstream>
#include "string.h"
#include "ctime"
#include <vector> //clase lista (es lo mismo)
#include "Argumentos/estad.h"
#include "Argumentos/p_casos.h"
#include "Argumentos/p_muertes.h"
#include "Argumentos/casos_edad.h"

using namespace std;

int main(int argc, char **argv)
{
    time_t start = time(NULL);
    int n;
    if (argc >= 3) {
        if (std::string(argv[1]) == "-estad") {
            estad(argv[2]);
        }
        if (std::string(argv[1]) == "-p_casos") {
            try {
                n = std::stoi(argv[2]);
                p_casos(n, argv[3]);
            } catch (...) {
                p_casos(0, argv[2]);
            }
        }
        if (std::string(argv[1]) == "-p_muertes") {
            try {
                n = std::stoi(argv[2]);
                p_muertes(n, argv[3]);
            } catch (...) {
                p_muertes(0, argv[2]);
            }
        }
        if (std::string(argv[1]) == "-casos_edad") {
            try {
                n = std::stoi(argv[2]);
                casos_edad(n, argv[3]);
            } catch (...) {
                cout<<"NO INGRESO CANTIDAD DE ANOS!";
            }
        }
        if (std::string(argv[1]) == "-casos_cui") {
            cout<<"casoscui";
        }
    }else {
            cout<<"ARGUMENTOS INCORECCTOS";
        }
    time_t end = time(NULL);
    cout<<"\nSegundos para correr el argumento: "<<end-start<<" \n\n";
    return 0;
}