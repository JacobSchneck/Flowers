// Jacob Schneck
// CS 120
// Final Project

#ifndef ELONGATEDFLOWER_H
#define ELONGATEDFLOWER_H

#include "flower.h"
using namespace std;

class ElongatedFlower : public Flower {
    private:
        // field variables defining pistal
        color color_pistal; 
        int radius_pistal;
        point2D center_pistal;

        // field variables defining petals;
        color color_petal;
        color color_second_petal;

        // helper method to construct petals vector
        void constructPetals() override;

    public:
        ElongatedFlower();
        ElongatedFlower(color color_pistal, color color_petal, color color_second_petal, point2D center_pistal, int radius_pistal);

        // Deconstructor
        ~ElongatedFlower() = default;

        // Getters
        color getColorPistal() const;
        int getRadiusPistal() const;
        point2D getCenterPistal() const;
        color getColorPetal() const;
        color getColorSecondPetal() const;

        // Setters
        void setColorPistal(color color_pistal); 
        void setRadiusPistal(int radius_pistal);
        void setCenterPistal(point2D center_pistal);
        void setColorPetal(color color_petal);
        void setColorSecondPetal(color color_second_petal);

        // non-trivial 
        void draw() const override;
        void rotate(int rotation_factor) override;

};

#endif