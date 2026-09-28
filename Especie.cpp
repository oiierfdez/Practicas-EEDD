//
// Created by Roberto Luque Peña on 24/09/2026.
//

#include "Especie.h"

 bool Especie::operator==(const Especie &e)const {
  return codigoEspecie == e.codigoEspecie;
}

 bool Especie::operator<(const Especie &e)const {
     return codigoEspecie < e.codigoEspecie;
 }

std::string Especie::getCodigo() const {
  return codigoEspecie;
}
