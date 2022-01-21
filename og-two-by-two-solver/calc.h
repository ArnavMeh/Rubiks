#define Calc(depth, exclude) {                      \
    if (depth > maxDepth) {                         \
    } else if (equalsTarget()) {                    \
        printSolution(depth);                       \
        maxDepth = depth-1;                         \
    } else {                                        \
        if (exclude == 'F') {                       \
            CalcT(depth);CalcL(depth);              \
        } else if (exclude == 'L') {                \
            CalcF(depth);CalcT(depth);              \
        } else if (exclude == 'T') {                \
            CalcL(depth);CalcF(depth);              \
        } else {                                    \
            CalcF(depth);CalcL(depth);CalcT(depth); \
        }                                           \
    }                                               \
}


void Cube::CalcInit(vector<int> tpos, vector<int> tori) {
    for (int i=0; i<8; i++) {
        targetPos[i] = tpos[i];
        targetOrient[i] = tori[i];
    }
    Calc(0, 'A');
}
void Cube::CalcT (int depth) {
    TopC(); history[depth] = 'T'; Calc(depth+1, 'T'); 
    TopC(); history[depth] = '+'; Calc(depth+1, 'T');
    TopC(); history[depth] = 't'; Calc(depth+1, 'T'); TopC();
}
void Cube::CalcL (int depth) {
    LeftC(); history[depth] = 'L'; Calc(depth+1, 'L');
    LeftC(); history[depth] = '1'; Calc(depth+1, 'L');
    LeftC(); history[depth] = 'l'; Calc(depth+1, 'L'); LeftC();
}
void Cube::CalcF (int depth) {
    FrontC(); history[depth] = 'F'; Calc(depth+1, 'F');
    FrontC(); history[depth] = 'e'; Calc(depth+1, 'F');
    FrontC(); history[depth] = 'f'; Calc(depth+1, 'F'); FrontC();
}