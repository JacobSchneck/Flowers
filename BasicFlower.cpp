// Jacob Schneck
// CS 120
// Final Project

#include "BasicFlower.h"
#include <iostream>

using namespace std;

//==================== Private Methods ===================
void BasicFlower::constructPetals() {
    petals.clear();
    petals.push_back(make_unique<Circle>(Circle(color_petal, { center_pistal.x + radius_pistal, center_pistal.y - radius_pistal }, radius_pistal)));
    petals.push_back(make_unique<Circle>(Circle(color_petal, { center_pistal.x + radius_pistal, center_pistal.y + radius_pistal }, radius_pistal)));
    petals.push_back(make_unique<Circle>(Circle(color_petal, { center_pistal.x - radius_pistal, center_pistal.y - radius_pistal }, radius_pistal)));
    petals.push_back(make_unique<Circle>(Circle(color_petal, { center_pistal.x - radius_pistal, center_pistal.y + radius_pistal }, radius_pistal)));
}

//===================== Constructors =====================
BasicFlower::BasicFlower() : Flower() {} 
BasicFlower::BasicFlower(color color_pistal, color color_petal, point2D center_pistal, int radius_pistal) : Flower(Circle(color_pistal, center_pistal, radius_pistal)) {
    this->color_pistal = color_pistal;    
    this->color_petal = color_petal;
    this->center_pistal = center_pistal;
    this->radius_pistal = radius_pistal;
    constructPetals();
}

//===================== Getters ==========================
color BasicFlower::getColorPistal() const {
    return color_pistal;
}

int BasicFlower::getRadiusPistal() const {
    return radius_pistal;
}

point2D BasicFlower::getCenterPistal() const {
    return center_pistal;
}

color BasicFlower::getColorPetal() const {
    return color_petal;
}

//===================== Setters ==========================
void BasicFlower::setColorPistal(color color_pistal) {
    this->color_pistal = color_pistal;
}

void BasicFlower::setRadiusPistal(int radius_pistal) {
    this->radius_pistal = radius_pistal;
}

void BasicFlower::setCenterPistal(point2D center_pistal) {
    this->center_pistal = center_pistal;
}

void BasicFlower::setColorPetal(color color_petal) {
    this->color_petal = color_petal;
}

//===================== Non-Trivial Methods ==============
void BasicFlower::draw() const {
    for (auto &p : petals) {
        p->draw();
    }
    pistal.draw();
}

void BasicFlower::rotate(int rotation_factor) {
    double radius_from_center, petal_center_x, petal_center_y, angle, x_diff, y_diff, x_change, y_change;
    for (auto &p : petals) {
        petal_center_x = p->getCenterX();
        petal_center_y = p->getCenterY();
        x_diff = petal_center_x - center_pistal.x;
        y_diff = petal_center_y - center_pistal.y;
        radius_from_center = sqrtf(x_diff*x_diff + y_diff*y_diff);
        angle = atan2(y_diff, x_diff);
        x_change = radius_from_center*cos(angle - M_PI/rotation_factor);
        y_change = radius_from_center*sin(angle - M_PI/rotation_factor);
        
        p->setCenter({x_change + center_pistal.x, y_change + center_pistal.y});
        p->draw();
    }
    pistal.draw();
}