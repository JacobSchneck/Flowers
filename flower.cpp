// Jacob Schneck
// CS 120
// Final Project

#include "flower.h"

//================= Constructors ===================
Flower::Flower() : pistal(Circle()) {} 
Flower::Flower(Circle pistal) : pistal(pistal) {}

//================= Getters ========================
Circle Flower::getPistal() const {
    return pistal;
}

PetalSet Flower::getPetals() const {
    return petals;
}

//================= Setters ========================
// n/a

//================= Non-Trivial Methods ============ 
// n/a