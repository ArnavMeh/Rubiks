#define swapPos(a, b, c, d) {    \
    int temp = positions[a];     \
    positions[a] = positions[d]; \
    positions[d] = positions[c]; \
    positions[c] = positions[b]; \
    positions[b] = temp;         \
}


inline void Cube::TopC() { // top clockwise
    swapPos(0,1,2,3);
    swapOrientT(positions[0]);
    swapOrientT(positions[1]);
    swapOrientT(positions[2]);
    swapOrientT(positions[3]);
}
int orientMapT[6] = {0,5,2,4,1,3};
inline void Cube::swapOrientT (int a) {
    orientations[a] = orientMapT[orientations[a]];
}


void Cube::LeftC() {
    swapPos(0,3,7,4);
    swapOrientL(positions[0]);
    swapOrientL(positions[3]);
    swapOrientL(positions[7]);
    swapOrientL(positions[4]);
}
int orientMapL[6] = {1,2,3,0,4,5};
inline void Cube::swapOrientL (int a) {
    orientations[a] = orientMapL[orientations[a]];
}


void Cube::FrontC() {
    swapPos(3,2,6,7);
    swapOrientF(positions[3]);
    swapOrientF(positions[2]);
    swapOrientF(positions[6]);
    swapOrientF(positions[7]);
}
int orientMapF[6] = {4,1,5,3,2,0};
inline void Cube::swapOrientF (int a) {
    orientations[a] = orientMapF[orientations[a]];
}