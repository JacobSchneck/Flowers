// Jacob Schneck
// CS 120
// Final Project

#ifndef BASICFLOWER_H
#define BASICFLOWER_H

#include "flower.h"
using namespace std;

class BasicFlower : public Flower {
    private: 
        // field variables defining pistal
        color color_pistal; 
        int radius_pistal;
        point2D center_pistal;

        // field variables defining petals;
        color color_petal;

        // helper method to construct petals vector
        void constructPetals() override;

    public: 
        // Constructors
        BasicFlower();
        BasicFlower(color color_pistal, color color_petal, point2D center_pistal, int radius_pistal);

        // Deconstructor
        ~BasicFlower() = default;

        // Getters
        color getColorPistal() const;
        int getRadiusPistal() const;
        point2D getCenterPistal() const;
        color getColorPetal() const;

        // Setters
        void setColorPistal(color color_pistal); 
        void setRadiusPistal(int radius_pistal);
        void setCenterPistal(point2D center_pistal);
        void setColorPetal(color color_petal);

        // non-trivial 
        void draw() const override;
        void rotate(int rotation_factor) override;
};

#endif 