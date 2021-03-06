/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4030.cpp
*/

#include "c_4030.hpp"
#include "../gate/Xor.hpp"

nts::c_4030::c_4030(const std::string& name) : Component(name, "4030"){
    initGate();
}

nts::Tristate nts::c_4030::compute(size_t pin) {
    auto gate = getGate();
    auto link = getLink();
    std::map<size_t, Tristate> comp_int;

    for (auto & i : gate) {
        auto input = i.first->getInput();
        auto output = i.first->getOutput();
        if (input.find(pin) != input.end()) {
            auto find_pin = link.find(pin);
            return find_pin->second.first->compute(find_pin->second.second);
        }
        if (output.find(pin) != output.end()) {
            for (auto ind : dynamic_cast<Xor *>(i.first)->getInput())
                comp_int.insert(std::make_pair(ind.first, compute(ind.first)));
            return dynamic_cast<Xor *>(i.first)->gate_operator(comp_int);
        }
    }
    return UNDEFINED;
}

void nts::c_4030::initGate() {
    std::vector<std::pair<Gate *, std::vector<size_t>>> gate;
    gate.push_back(std::pair<Xor *, std::vector<size_t>>(new Xor({1, 2}, {3}), {1, 2, 3}));
    gate.push_back(std::pair<Xor *, std::vector<size_t>>(new Xor({5, 6}, {4}), {4, 5, 6}));
    gate.push_back(std::pair<Xor *, std::vector<size_t>>(new Xor({8, 9}, {10}), {8, 9, 10}));
    gate.push_back(std::pair<Xor *, std::vector<size_t>>(new Xor({12, 13}, {11}), {11, 12, 13}));
    setGate(gate);
}