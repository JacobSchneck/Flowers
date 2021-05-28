// Jacob Schneck
// CS 120
// Final Project

#include "SunFlower.h"

// #include <math.h>
#include <stdlib.h>
using namespace std;

//==================== Private Methods ===================
void SunFlower::constructPetals() {
    petals.clear();
    int rand_val = rand() % 2;

    if (rand_val) {
        petals.push_back(make_unique<Circle>(Circle(color_petal, {center_pistal.x, center_pistal.y + radius_pistal}, radius_pistal)));
        petals.push_back(make_unique<Circle>(Circle(color_second_petal, {center_pistal.x, center_pistal.y - radius_pistal}, radius_pistal)));
        
        petals.push_back(make_unique<Circle>(Circle(color_petal, {center_pistal.x + radius_pistal, center_pistal.y}, radius_pistal)));
        petals.push_back(make_unique<Circle>(Circle(color_second_petal, {center_pistal.x - radius_pistal, center_pistal.y}, radius_pistal)));

        petals.push_back(make_unique<Circle>(Circle(color_petal, {center_pistal.x + radius_pistal*cos(M_PI/4), center_pistal.y + radius_pistal*sin(M_PI/4)}, radius_pistal)));
        petals.push_back(make_unique<Circle>(Circle(color_second_petal, {center_pistal.x - radius_pistal*cos(M_PI/4), center_pistal.y + radius_pistal*sin(M_PI/4)}, radius_pistal)));

        petals.push_back(make_unique<Circle>(Circle(color_petal, {center_pistal.x + radius_pistal*cos(M_PI/4), center_pistal.y - radius_pistal*sin(M_PI/4)}, radius_pistal)));
        petals.push_back(make_unique<Circle>(Circle(color_second_petal, {center_pistal.x - radius_pistal*cos(M_PI/4), center_pistal.y - radius_pistal*sin(M_PI/4)}, radius_pistal)));

    } else {
        petals.push_back(make_unique<Circle>(Circle(color_petal, {center_pistal.x, center_pistal.y + radius_pistal}, radius_pistal)));
        petals.push_back(make_unique<Circle>(Circle(color_second_petal, {center_pistal.x + radius_pistal*cos(M_PI/4), center_pistal.y + radius_pistal*sin(M_PI/4)}, radius_pistal)));

        petals.push_back(make_unique<Circle>(Circle(color_petal, {center_pistal.x, center_pistal.y - radius_pistal}, radius_pistal)));
        petals.push_back(make_unique<Circle>(Circle(color_second_petal, {center_pistal.x + radius_pistal*cos(M_PI/4), center_pistal.y - radius_pistal*sin(M_PI/4)}, radius_pistal)));
        
        petals.push_back(make_unique<Circle>(Circle(color_petal, {center_pistal.x + radius_pistal, center_pistal.y}, radius_pistal)));
        petals.push_back(make_unique<Circle>(Circle(color_second_petal, {center_pistal.x - radius_pistal*cos(M_PI/4), center_pistal.y - radius_pistal*sin(M_PI/4)}, radius_pistal)));

        petals.push_back(make_unique<Circle>(Circle(color_petal, {center_pistal.x - radius_pistal, center_pistal.y}, radius_pistal)));
        petals.push_back(make_unique<Circle>(Circle(color_second_petal, {center_pistal.x - radius_pistal*cos(M_PI/4), center_pistal.y + radius_pistal*sin(M_PI/4)}, radius_pistal)));
    }
}

//===================== Constructors =====================
SunFlower::SunFlower() : Flower() {} 
SunFlower::SunFlower(color color_pistal, color color_petal, color color_second_petal, point2D center_pistal, int radius_pistal) : Flower(Circle(color_pistal, center_pistal, radius_pistal)) {
    this->color_pistal = color_pistal;    
    this->color_petal = color_petal;
    this->color_second_petal = color_second_petal;
    this->center_pistal = center_pistal;
    this->radius_pistal = radius_pistal;
    constructPetals();
}

//===================== Getters ==========================
color SunFlower::getColorPistal() const {
    return color_pistal;
}

int SunFlower::getRadiusPistal() const {
    return radius_pistal;
}

point2D SunFlower::getCenterPistal() const {
    return center_pistal;
}

color SunFlower::getColorPetal() const {
    return color_petal;
}

color SunFlower::getColorSecondPetal() const {
    return color_second_petal;
}
//===================== Setters ==========================
void SunFlower::setColorPistal(color color_pistal) {
    this->color_pistal = color_pistal;
}

void SunFlower::setRadiusPistal(int radius_pistal) {
    this->radius_pistal = radius_pistal;
}

void SunFlower::setCenterPistal(point2D center_pistal) {
    this->center_pistal = center_pistal;
}

void SunFlower::setColorPetal(color color_petal) {
    this->color_petal = color_petal;
}

void SunFlower::setColorSecondPetal(color color_second_petal) {
    this->color_second_petal = color_second_petal;
}
//===================== Non-Trivial Methods ==============
void SunFlower::draw() const {
    for (auto &p : petals) {
        p->draw();
    }
    pistal.draw();
}

void SunFlower::rotate(int rotation_factor) {
    double radius_from_center, petal_center_x, petal_center_y, angle, x_diff, y_diff, x_change, y_change;
    for (auto &p : petals) {
        petal_center_x = p->getCenterX();
        petal_center_y = p->getCenterY();

        // cout << "petal center " << petal_center_x << ", " << petal_center_y << endl;
        x_diff = petal_center_x - center_pistal.x;
        y_diff = petal_center_y - center_pistal.y;
        // cout << "petal diff " << x_diff << ", " << y_diff << endl;
        radius_from_center = sqrtf(x_diff*x_diff + y_diff*y_diff);
        // cout << "radius from center " << radius_from_center << endl;
        angle = atan2(y_diff, x_diff);
        // cout << "angle " << angle*360/(2*M_PI) << endl;

        x_change = radius_from_center*cos(angle - M_PI/rotation_factor);
        y_change = radius_from_center*sin(angle - M_PI/rotation_factor);
        // cout << "change " << x_change << ", " << y_change << endl;
        p->setCenter({x_change + center_pistal.x, y_change + center_pistal.y});
        // cout << "new center" << p->getCenterX() << ", " << p->getCenterY() << endl;
        p->draw();
        // cout << p->getCenter().x << endl;
        // cout << endl;
    }
    pistal.draw();
}