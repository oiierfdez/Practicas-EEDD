#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "VDinamico.h"
#include "Especie.h"


void ordenarBurbuja(VDinamico<Especie>& v) {

    unsigned int n=v.get__tlogico();
    for (unsigned int i=0;i<n-1;i++) {
        for (unsigned int j=0;j<n-i-1;j++) {
            if (v[j+1]<v[j]) {
                Especie aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

VDinamico<Especie*>BuscarPorNombre(VDinamico<Especie*>&v,string& palabra) {
    VDinamico<Especie*> resultado;
    for (unsigned int i=0;i<v.get__tlogico();i++) {
        std::string nombre=v[i].get
    }
}

int main(int argc, const char * argv[]) {

    std::ifstream is;
    std::stringstream  columnas;
    std::string fila;
    int contador=0;
    char delimitador = ',';

    std::string _codigoEspecie = "";
    std::string _nombreComun = "";
    std::string _nombreCientifico = "";
    std::string _tipoPlanta = "";


    is.open("../arbolado-especies.csv"); //carpeta de proyecto
    if ( is.good() ) {

        clock_t t_ini = clock();
        getline(is, fila ); //salto la cabecera

        while ( getline(is, fila ) ) {

            //¿Se ha leído una nueva fila?
            if (fila!="") {

                columnas.str(fila);

                //Código - Nombre común - Nombre científico - Tipo de planta

                getline(columnas, _codigoEspecie, delimitador);
                getline(columnas, _nombreComun, delimitador);
                getline(columnas, _nombreCientifico, delimitador);
                getline(columnas, _tipoPlanta, delimitador);

                fila="";
                columnas.clear();

                std::cout << ++contador
                          << " Codigo Especie= " << _codigoEspecie
                          << " Nombre comun= " << _nombreComun << " Nombre Cientifico= " << _nombreCientifico
                          << " Tipo planta= " << _tipoPlanta << std::endl;
            }
        }

        is.close();

        std::cout << "Tiempo de lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }

    //PARTE DE ROBERTO --> CUIDADO CON LAS VARIABLES
    VDinamico<Especie>vEspecies;
    ordenarBurbuja(vEspecies);

    unsigned int total=vEspecies.get__tlogico();
    for (unsigned int i=total;i>total-50;i--) {
        std::cout<<vEspecies[i].getCodigo();
    }


    return 0;
}
