#include <iostream>
#include <fstream> //permite manejo de archivos
#include <sstream>
#include "string.h"
#include <vector> //clase lista (es lo mismo)

using namespace std;

void chopCSV(string fileName, int lines)
{

    string newName = fileName.substr(0, fileName.find(".csv"));
    newName += to_string(lines) + ".csv";

    fstream fin, fout;
    fin.open("./" + fileName, ios::in);
    fout.open("./" + newName, ios::out);

    string line, word;
    for (int i = 0; i < lines; i++)
    {
        getline(fin, line);
        fout << line << "\n";
    }
}

void exploreCSV(string fileName)
{
    int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20}; //columnas almacenadas en array... columnas importantes
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row; //declaro lista de caracter string nombre row
    string line, word; //variables temporales
    int confirmed = 0; //casos confirmados
    int total = -1; //total de casos

    while (getline(fin, line))
    {
        total++;
        row.clear(); //metodo vaciar
        stringstream s(line);
        while (getline(s, word, ','))
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2); //la palabra si el espacio y la comilla
            }
            else
            {
                word = "NA"; //cuando no hay datos en esa fila/columna
            }
            row.push_back(word); //push de la fila
        }


        if (row[20].compare("Confirmado") == 0 || total==0) //compara es lo mismo que strcmp, no hay confirmados en csv10
        {
            for (int i = 0; i < nColumns; i++)
            {
                cout << row[colsOfInterest[i]] << " ";
            }
            confirmed++;
            cout << endl;
        }
    }

    cout << "Casos confirmados: " << confirmed << " de " << total << " casos registrados." << endl;
}

void exploreHeaders(string fileName) //me muevo en la primera fila y obtengo nombres de columnas... separo en (, comas)
{
    
    fstream fin;
    
    fin.open("./" + fileName, ios::in);
    
    string headers, header;
    getline(fin, headers);

    stringstream s(headers);
    while (getline(s, header, ','))
    {
        cout << header << endl;
    }
}

int main(int argc, char **argv)
{

    cout << "Cantidad de argumentos: " << argc << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << "Argumento " << i << ": " << argv[i] << endl;
        //aca puedo poner un switch para manejar los argumentos...

        if(strcmp(argv[i], "-file") == 0){ //comparo strings si es igual a 0 estoy en el archivo y imprime nombre archivo...
            cout << "Nombre del Archivo: " << argv[i+1] << endl;
            //exploreHeaders(argv[i+1]);
            exploreCSV(argv[i+1]);
            break;
        }
        
    }

    return 0;
}
