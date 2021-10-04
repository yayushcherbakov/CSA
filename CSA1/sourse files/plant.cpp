//------------------------------------------------------------------------------
// plant.cpp - содержит процедуры связанные с обработкой обобщенного растения
// и создания произвольной растения
//------------------------------------------------------------------------------

#include "plant.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного растения из файла
plant* In(ifstream &ifst) {
    plant* sp = new plant;
    int k;
    ifst >> k;
    switch(k) {
        case plant::TREE:
            sp->k = plant::TREE;
            In(sp->t, ifst);
            return sp;
        case plant::SHRUB:
            sp->k = plant::SHRUB;
            In(sp->s, ifst);
            return sp;
        case plant::FLOWER:
            sp->k = plant::FLOWER;
            In(sp->f, ifst);
            return sp;
        default:
            throw std::invalid_argument("Invalid plant type");
    }
}

// Случайный ввод обобщенного растения
plant *InRnd() {
    plant *sp = new plant;
    auto k = RandomNumber() % 3 + 1;
    switch(k) {
        case plant::TREE:
            sp->k = plant::TREE;
            InRnd(sp->t);
            return sp;
        case plant::SHRUB:
            sp->k = plant::SHRUB;
            InRnd(sp->s);
            return sp;
        case plant::FLOWER:
            sp->k = plant::FLOWER;
            InRnd(sp->f);
            return sp;
        default:
            throw std::invalid_argument("Invalid plant");
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей растения в поток
void Out(plant &s, ofstream &ofst) {
    switch(s.k) {
        case plant::TREE:
            Out(s.t, ofst);
            break;
        case plant::SHRUB:
            Out(s.s, ofst);
            break;
        case plant::FLOWER:
            Out(s.f, ofst);
            break;
        default:
            throw std::invalid_argument("Invalid plant");
    }
}

//------------------------------------------------------------------------------
// Получение частного от деления числа гласных букв в названии на общую длину названия
double GetPartOfVowels(plant& p) {
    switch (p.k) {
    case plant::TREE:
        return GetPartOfVowels(p.t);
        break;
    case plant::SHRUB:
        return GetPartOfVowels(p.s);
        break;
    case plant::FLOWER:
        return GetPartOfVowels(p.f);
        break;
    default:
        throw std::invalid_argument("Invalid plant");
    }
}
