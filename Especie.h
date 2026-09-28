//
// Created by Roberto Luque Peña on 24/09/2026.
//

#ifndef INC_B9580CB4EF714E6CA853FC0D5FAEC9CB
#define INC_B9580CB4EF714E6CA853FC0D5FAEC9CB
#include <string>

class Especie {
private:
    std::string codigoEspecie;
    std::string nombreComun;
    std::string nombreCientifico;
    std::string tipoPlanta;

public:
    bool operator==(const Especie& e)const;
    bool operator<(const Especie& e)const;

    std::string getCodigo() const;
};



#endif //INC_B9580CB4EF714E6CA853FC0D5FAEC9CB
