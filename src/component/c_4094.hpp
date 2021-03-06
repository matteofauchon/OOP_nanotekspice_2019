/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4094.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_C_4094_HPP
#define OOP_NANOTEKSPICE_2019_C_4094_HPP

#include "Component.hpp"

namespace nts {
    class c_4094: public Component {
    public:
        c_4094(const std::string &name);
        nts::Tristate compute(size_t pin) override;
    };
}


#endif // OOP_NANOTEKSPICE_2019_C_4094_HPP
