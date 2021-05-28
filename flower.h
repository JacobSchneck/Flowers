// Jacob Schneck
// CS 120
// Final Project

#ifndef FLOWER_H
#define FLOWER_H

#include "shapes/shape.h"
#include "shapes/rect.h"
#include "shapes/circle.h"
#include <math.h>
#include <memory>
#include <vector> 
using namespace std;

// Helper type def so I can type less
typedef vector<shared_ptr<Shape>> PetalSet;

class Flower {
    protected:
        Circle pistal; // middle of flower
        PetalSet petals; // petals of flower

        // Helper Abstract Method
        virtual void constructPetals() = 0;

    public: 
        // Constructor
        Flower();
        Flower(Circle pistal);
        // Deconstructor
        virtual ~Flower() = default;

        // Getters 
        Circle getPistal() const;
        PetalSet getPetals() const;

        // Non-Trivial Method

        /*  draw(), defines how the flower is drawn to the screen
            input: N/A
            output: N/A
        */
        virtual void draw() const = 0;

        /*  rotate(..) rotates the flower 
            input: int rotational factor to modify a petal
            output: N/A
        */
        virtual void rotate(int rotational_factor) {};
};

#endif