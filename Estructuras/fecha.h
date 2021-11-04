#ifndef PARCIAL2_PIII_FERNANDEZ_RUIBAL_FECHA_H
#define PARCIAL2_PIII_FERNANDEZ_RUIBAL_FECHA_H

#include <iostream>
#include <fstream> //permite manejo de archivos
#include <sstream>
#include "string.h"
#include <vector>
#include <string.h>

using namespace std;
/**
 * Convierte fecha a int ---> 08-08-2020 a 08082020
 * @param fecha fecha en formato string
 * @return devuelve la fecha en formato int
 */

int fechaint(string fecha){
int n=fecha.size();
int i=0;
string fecha_;
for(int j = 0; j<n; j++){
int x = fecha[j];
if(x>=48 && x<=57){
fecha_[i] = fecha[j];
i++;
}
}
return stoi(fecha_);
}

#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_FECHA_H