#include <iostream>
#include <vector>
#define MAX_DEPTH 11
using namespace std;

#include "cube.h"
#include "transform.h"
#include "calc.h"


int main() {

    Cube b ({0,1,3,2,4,5,6,7}, {0,0,0,0,2,2,2,2});
    b.performTansforms("");
    // b.printCube();
    b.CalcInit({0,1,2,3,4,5,6,7}, {0,0,0,0,2,2,2,2});
    
}



// Notation:

// Turns:
// T = top clockwise
// + = top twice
// t = top counter
// L = left clockwise
// 1 = left twice
// l = left counter
// F = front clockwise
// e = front twice
// f = front counter

// Positions
// Top:   
// 0 1
// 3 2
// Bottom:
// 4 5
// 7 6

// Orientations: direction white or yellow face:
// Up: 0
// Front: 1
// Down: 2
// Back: 3
// Right: 4
// Left: 5