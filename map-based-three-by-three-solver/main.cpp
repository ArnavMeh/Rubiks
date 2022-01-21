typedef unsigned char U8;
typedef unsigned int U32;

#include <iostream>

#include "edge-maps.hpp"
#include "corner-maps.hpp"
#include "conversion.hpp"
#include "cube.hpp"

int main() {
    init_cornerMaps();
    init_edgeMaps();

    
    // Cube c = Cube();
    // U8* cnrs = c.getCorners();
    // for (int i = 0; i < 8; i++) {
    //     std::cout << (int)(cnrs[i]) << '\n';
    // }

}