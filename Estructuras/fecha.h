#ifndef PARCIAL2_PIII_FERNANDEZ_RUIBAL_FECHA_H
#define PARCIAL2_PIII_FERNANDEZ_RUIBAL_FECHA_H

#include <iostream>
#include <fstream> //permite manejo de archivos
#include <sstream>
#include "string.h"
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
/**
 * Convierte fecha a int ---> 08-08-2020 a 08082020 (sacada de internet)
 * @param fecha fecha en formato string
 * @return devuelve la fecha en formato int
 */

int fechaint(string fecha){
   fecha.erase(remove(fecha.begin(), fecha.end(), '-'), fecha.end()); //saca caracter "-" de la fecha 
   return stoi(fecha);
   }

#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_FECHA_H