//
// Created by Roberto Luque Peña on 23/09/2026.
//

#ifndef INC_50085834A3194F8ABB30A4A6712C768D
#define INC_50085834A3194F8ABB30A4A6712C768D
#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;


template<class T>
class VDinamico {

private:
    T* v;
    unsigned int _tlogico;
    unsigned int _tfisico;

public:

    VDinamico();
    VDinamico(unsigned int tamlog, T&dato);
    VDinamico(const VDinamico<T>& origen);
    VDinamico(const VDinamico<T>& origen, unsigned int posicionInicial, unsigned int numElementos);
    VDinamico& operator=(VDinamico& arr);
    T &operator[] (int pos);
    void insertar(const T& dato, unsigned int pos =UINT_MAX);
    T borrar(unsigned int pos =UINT_MAX);
    void ordenar();
    int busquedaBinaria(const T& dato);
    int get__tlogico();
    ~VDinamico();

};

template<class T>
VDinamico<T>::VDinamico() {
    _tlogico=0;
    _tfisico=1;
    v=new T[_tfisico];
}

template<class T>
VDinamico<T>::VDinamico(unsigned int tamlog, T&dato) {
    _tlogico=tamlog;
    _tfisico=1;

    while (_tfisico<_tlogico) {
        _tfisico*=2;
    }
    v=new T[_tfisico];

    for (unsigned int i=0;i<_tlogico;i++) {
        v[i]=dato;
    }
}

template<class T>
VDinamico<T>::VDinamico(const VDinamico<T>& origen) {
    _tfisico=origen._tfisico;
    _tlogico=origen._tlogico;

    v=new T[_tfisico];

    for (unsigned int i=0;i<_tlogico;i++)
        v[i]=origen.v[i];

}

template<class T>
VDinamico<T>::VDinamico(const VDinamico<T>& origen, unsigned
        int posicionInicial, unsigned int numElementos) {
    if (posicionInicial+numElementos>origen._tlogico) {
        throw out_of_range("Rango fuera de los limites del vector origen");
    }
    _tlogico=numElementos;
    _tfisico = 1;
    while (_tfisico < _tlogico) {
        _tfisico *= 2;
    }
    v=new T[_tfisico];

    // Lo hago para reordenar los datos
    for (unsigned int i = 0; i < _tlogico; i++) {
        v[i] = origen.v[posicionInicial + i];
    }
}

template <class T>
VDinamico<T>& VDinamico<T>::operator=(VDinamico& arr) {
    if (&arr !=this) {
        delete[] v;
        _tfisico=arr._tfisico;
        _tlogico=arr._tlogico;

        v=new T[_tfisico];
        for (unsigned int i=0;i<_tlogico;i++) {
            v[i]=arr.v[i];
        }
    }
    return *this;
}

template <class T>
T& VDinamico<T>::operator[] (int pos) {

    if (pos>=_tlogico) {
        throw out_of_range("Indice fuera de rango");
    }
    return v[pos];
}

template <class T>
void VDinamico<T>::insertar(const T& dato, unsigned int pos =UINT_MAX) {
    if (pos>_tlogico)
        pos=_tlogico;

    if (_tlogico==_tfisico) {
        _tfisico*=2;
        T* v_aux=new T[_tfisico];
        for (unsigned int i=0;i<_tlogico;i++) {
            v_aux[i]=v[i];
        }
        delete[] v;
        v=v_aux;
    }

    for (unsigned int i=_tlogico;i>pos;i--)
        v[i]=v[i-1];

    v[pos]=dato;
    _tlogico++;
}

template <class T>
T VDinamico<T>::borrar(unsigned int pos) {

    if (_tlogico==0)
        throw out_of_range("No se puede eliminar ningun elemento");
    if (pos==UINT_MAX || pos>=_tlogico)
        pos=_tlogico - 1;

    T aux=v[pos]; //Aquí guardo una copia antes de perderlo

    for (unsigned int i=pos; i<_tlogico - 1 ;i++)
        v[i]=v[i+1];
    //Dejamos el ultimo valor del vector duplicado como basura y le restamos 1 al tlog
    // para que en las proximas operaciones lo tome como vacio,
    //ya que no podemos borrar una casilla del vector pq daria error de compilacion en Clion.

    _tlogico--;

    return aux;
}

template<class T>
void VDinamico<T>::ordenar() {
    std::sort(v, v + _tlogico);
}

template<class T>
int VDinamico<T>::busquedaBinaria(const T &dato) {
    v-ordenar();
    int min=0;
    int max=_tlogico;
    int aux;

    while (min<max) {
        aux=(max+min)/2;
        if (v[aux]==dato) {
            return aux;
        }
        if (v[aux]<dato) min=aux+1;

        else max=aux-1;
    }
}

template<class T>
int VDinamico<T>::get__tlogico() {
    return _tlogico;
}

template<class T>
VDinamico<T>::~VDinamico() {
    delete[] v;
}

#endif //INC_50085834A3194F8ABB30A4A6712C768D
