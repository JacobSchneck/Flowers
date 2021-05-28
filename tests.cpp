// Jacob Schneck
// CS 120
// Final Project

#include "shapes/circle.h"
#include "shapes/rect.h"
#include "shapes/shape.h"
#include "flower.h"
#include "BasicFlower.h"
#include "ElongatedFlower.h"
#include "SunFlower.h"

#include <iostream>
#include <vector>
using namespace std;

// Colors
const color skyBlue(77/255.0, 213/255.0, 240/255.0);
const color blue(0, 0 , 1);
const color grassGreen(26/255.0, 176/255.0, 56/255.0);
const color white(1, 1, 1);
const color brickRed(201/255.0, 20/255.0, 20/255.0);
const color darkBlue(1/255.0, 110/255.0, 214/255.0);
const color purple(119/255.0, 11/255.0, 224/255.0);
const color black(0, 0, 0);
const color magenta(1, 0, 1);
const color orange(1, 163/255.0, 22/255.0);
const color cyan (0, 1, 1);
const color yellow(1, 1, 0);
const color green(0, .5, 0);

//================= Function Delcarations =====================
bool test_rotation_method();

//================= Driver ====================================
int main() {
    cout << "Hello, World!" << endl;
    if (test_rotation_method()) {
        cout << "All rotation tests passed" << endl;
    } else {
        cout << "Something failed frowny face" << endl;
    }
    return 0;
}

//================= Function Definitions ======================
bool test_rotation_method() {
    bool passed = true;

    // flower objects
    BasicFlower f1 = BasicFlower(orange, white, {200, 200}, 10);
    ElongatedFlower f2 = ElongatedFlower(orange, darkBlue, magenta, {250, 250}, 10);
    SunFlower f3 = SunFlower(black, yellow, orange, {300, 300}, 10);

    // Tests for Basic Flower
    vector<point2D> petal_locations; 
    petal_locations.push_back({190, 190});
    petal_locations.push_back({210, 190});
    petal_locations.push_back({190, 210});
    petal_locations.push_back({210, 210});
    
    f1.rotate(2); // rotate by 90 degrees
    int i = 0;
    for (auto &p : f1.getPetals()) {
        if ( !(p->getCenter() == petal_locations[i]) ) {
            cout << "Test 1-a: Basic Flower rotation failed: " << p->getCenter() << " != " << petal_locations[i] << endl;
            passed = false;    
        }
        i++;
    }

    f1.rotate(4); // rotate by 45 degrees
    petal_locations.clear();
    petal_locations.push_back({185.858, 200});
    petal_locations.push_back({200, 185.858});
    petal_locations.push_back({200, 214.142});
    petal_locations.push_back({214.142, 200});
    i = 0;
    for (auto &p : f1.getPetals()) {
        if ( !(p->getCenter() == petal_locations[i]) ) {
            cout << "Test 2-a: Basic Flower rotation failed: " << p->getCenter() << " != " << petal_locations[i] << endl;
            passed = false;    
        }
        i++;
    }
    petal_locations.clear();

    // Tests for Elongated Flower
    f2.rotate(2);
    petal_locations.push_back({250, 230});
    petal_locations.push_back({250, 270});
    petal_locations.push_back({270, 250});
    petal_locations.push_back({230, 250});
    petal_locations.push_back({240, 240});
    petal_locations.push_back({260, 240});
    petal_locations.push_back({240, 260});
    petal_locations.push_back({260, 260});
    
    i = 0;
    for (auto &p : f2.getPetals()) {
        if ( !(p->getCenter() == petal_locations[i]) ) {
            cout << "Test 1-b: Basic Flower rotation failed: " << p->getCenter() << " != " << petal_locations[i] << endl;
            passed = false;    
        }
        i++;
    }
    petal_locations.clear();

    // Tests for Sun Flower
    i = 0; 
    f2.rotate(2);
    petal_locations.push_back({300, 310});
    petal_locations.push_back({300, 290});
    petal_locations.push_back({310, 300});
    petal_locations.push_back({290, 300});
    petal_locations.push_back({307.071, 307.071});
    petal_locations.push_back({292.929, 307.071});
    petal_locations.push_back({307.071, 292.929});
    petal_locations.push_back({292.929, 292.929});
    for (auto &p : f3.getPetals()) {
        if ( !(p->getCenter() == petal_locations[i]) ) {
            cout << "Test 1-c: Basic Flower rotation failed: " << p->getCenter() << " != " << petal_locations[i] << endl;
            passed = false;    
        }
        i++;
    }


    return passed;
}