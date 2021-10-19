#ifndef U04_COLAS_COLA_COLA_H_
#define U04_COLAS_COLA_COLA_H_

#include "nodo.h"

/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Cola {
private:
Nodo<T> *tope, *fondo;
public:
  Cola();

  ~Cola();

  void encolar(T dato);

  T desencolar();

  T peek();

  bool esVacia();

};

/**
 * Constructor de la clase Cola
 * @tparam T
 */
template <class T> Cola<T>::Cola() {
tope = nullptr;
fondo = nullptr;
}

/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Cola
 * @tparam T
 */
template <class T> Cola<T>::~Cola() {
  while(!esVacia()){
    desencolar();
  }
  delete tope;
  delete fondo;
}

/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T> void Cola<T>::encolar(T dato) {

Nodo<T> *nuevonodo = new Nodo<T>;
nuevonodo->setDato(dato);
nuevonodo->setSiguiente(nullptr);

if(fondo == nullptr){
  tope = nuevonodo;
}else{
  fondo->setSiguiente(nuevonodo);
}
fondo = nuevonodo;

}

/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T> T Cola<T>::desencolar() {

if (esVacia()) {
  throw 404;
}
T dato = tope->getDato();
Nodo<T> *aBorrar = tope;

tope = tope->getSiguiente();
if(tope==nullptr){
  fondo = nullptr;
}
delete aBorrar;
return dato;

}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T> bool Cola<T>::esVacia() {

if(fondo == nullptr){
  return true;
}else{
  return false;
}

//return fondo == nullptr

}

/**
 * Permite previsualizar el tope de la cola
 * sin eliminar dicho nodo
 * @tparam T
 * @return el dato que edsta en el tope de la cola
 */
template <class T>
T Cola<T>::peek() {
if (esVacia()){
throw 404;
}
return tope->getDato();
}

#endif // U04_COLAS_COLA_COLA_H_
