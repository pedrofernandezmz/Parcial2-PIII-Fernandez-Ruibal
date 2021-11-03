#ifndef U05_ARBOL_ARBOL_NODOARBOLAVL_H_
#define U05_ARBOL_ARBOL_NODOARBOLAVL_H_

#include <string.h>
using namespace std;

template <class T>
class NodoArbolAVL
{
private:
  vector<string> data;
  NodoArbolAVL<T> *left, *right;
  int height;

public:
  NodoArbolAVL()
  {
    left = nullptr;
    right = nullptr;
    height=1;
  }

  explicit NodoArbolAVL(T data) : data(data)
  {
    //data = d;
    left = nullptr;
    right = nullptr;
    height=1;
  }

  T &getData() { return data; }

  void setData(T data)
  {
    this->data = data;
  }
  int getClave()
  {
    return stoi(data[17]);
  }

  NodoArbolAVL<T> *getRight() const
  {
    return right;
  }

  void setRight(NodoArbolAVL<T> *r)
  {
    this->right = r;
  }
  NodoArbolAVL *getLeft() const
  {
    return left;
  }

  void setLeft(NodoArbolAVL *l)
  {
    this->left = l;
  }

  int getHeight() const 
  {
    return height;
  }

  void setHeight(int h){
    height = h;
  }

  void print(bool esDerecho, string identacion) {
    if (right != NULL) {
        right->print(true, identacion + (esDerecho ? "     " : "|    "));
    }
    cout << identacion;
    if (esDerecho) {
        cout << " /";
    } else {
        cout << " \\";
    }
    cout << "-- ";
    cout << data << endl;
    if (left != NULL) {
        left->print(false, identacion + (esDerecho ? "|    " : "     "));
    }
}

void print2(){
         
    int colsOfInterest[] = {2, 3, 7, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);
            cout<<"Edad: "<<data[colsOfInterest[0]]<<" ";
            cout<<data[colsOfInterest[1]]<<"   ";
            cout<<"Provincia: "<<data[colsOfInterest[2]]<<"   ";
            cout<<"CUI: "<<data[colsOfInterest[3]]<<"   ";
            cout<<"Fecha CUI: "<<data[colsOfInterest[4]]<<"   ";
            cout<<"Murio: "<<data[colsOfInterest[5]]<<"   ";
            cout<<"Estado: "<<data[colsOfInterest[7]];
            cout << endl;
    }

};

#endif // U05_ARBOL_ARBOL_NODOARBOLAVL_H_
