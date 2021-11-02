#ifndef PARCIAL2_PIII_FERNANDEZ_RUIBAL_RANGO_H
#define PARCIAL2_PIII_FERNANDEZ_RUIBAL_RANGO_H

#include <ostream>

class rango {
private:
    int minrango;
    int maxrango;
    int cantidad;
public:
    rango(int minrango, int maxrango, int cantidad) : minrango(minrango), maxrango(maxrango), cantidad(cantidad) {}

    int getMinrango() const { return minrango; }

    void setMinrango(int minrango) { rango::minrango = minrango; }

    int getMaxrango() const { return maxrango; }

    void setMaxrango(int maxrango) { rango::maxrango = maxrango; }

    int getCantidad() const { return cantidad; }

    void setCantidad(int cantidad) { rango::cantidad = cantidad; }

    friend std::ostream &operator<<(std::ostream &os, const rango &rango) {
        os << rango.minrango << "-" << rango.maxrango << " Cantidad: " << rango.cantidad;
        return os;
    }

    bool operator==(const rango &rhs) const {
        return minrango == rhs.minrango &&
               maxrango == rhs.maxrango;
    }

    bool operator!=(const rango &rhs) const { return !(rhs == *this); }

    bool operator<(const rango &rhs) const {
        if (minrango < rhs.minrango)
            return true;
        if (rhs.minrango < minrango)
            return false;
        return maxrango < rhs.maxrango;
    }

    bool operator>(const rango &rhs) const { return rhs < *this; }

    bool operator<=(const rango &rhs) const { return !(rhs < *this); }

    bool operator>=(const rango &rhs) const { return !(*this < rhs); }
    
    void addCantidad() {
        int x = rango::cantidad;
        x++;
        rango::cantidad = x;
    }
};

#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_RANGO_H
