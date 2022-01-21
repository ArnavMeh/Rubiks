U8 U_cornerPosMap[8] = {3, 0, 1, 2, VD, VD, VD, VD};
U8 D_cornerPosMap[8] = {VD, VD, VD, VD, 5, 6, 7, 4};
U8 L_cornerPosMap[8] = {4, VD, VD, 0, 7, VD, VD, 3};
U8 R_cornerPosMap[8] = {VD, 2, 6, VD, VD, 1, 5, VD};
U8 F_cornerPosMap[8] = {1, 5, VD, VD, 0, 4, VD, VD};
U8 B_cornerPosMap[8] = {VD, VD, 3, 7, VD, VD, 2, 6};

U8 U_cornerUnitMap[3][24];
U8 D_cornerUnitMap[3][24];
U8 L_cornerUnitMap[3][24];
U8 R_cornerUnitMap[3][24];
U8 F_cornerUnitMap[3][24];
U8 B_cornerUnitMap[3][24];

U32 *U_cornerHalfMap[3];
U32 *D_cornerHalfMap[3];
U32 *L_cornerHalfMap[3];
U32 *R_cornerHalfMap[3];
U32 *F_cornerHalfMap[3];
U32 *B_cornerHalfMap[3];

void init_cornerUnitMap(U8 (&cornerUnitMap)[3][24], U8 *cornerPosMap, U8 *orientMap) {
    for (int orient = 0; orient < 3; orient++) { // orient: 0-2
        for (int pos = 0; pos < 8; pos++) { // pos: 0-7
            U8 key = (orient << 3) | pos;
            if (cornerPosMap[pos] != VD) {
                U8 newPos = pos, newOrient = orient;
                for (int i = 0; i < 3; i++) {
                    newPos = cornerPosMap[newPos];
                    newOrient = orientMap[newOrient];
                    cornerUnitMap[i][key] = (newOrient << 3) | newPos;
                }
            } else {
                cornerUnitMap[0][key] = key;
                cornerUnitMap[1][key] = key;
                cornerUnitMap[2][key] = key;
            }
        }
    }
}

void init_cornerHalfMap(U8 (&cornerUnitMap)[3][24], U32 *(&cornerHalfMap)[3]) {
    for (int i = 0; i < 3; i++) {
        cornerHalfMap[i] = new U32[331776];
        for (int k1 = 0; k1 < 24; k1++) {
            for (int k2 = 0; k2 < 24; k2++) {
                for (int k3 = 0; k3 < 24; k3++) {
                    for (int k4 = 0; k4 < 24; k4++) {
            U8 v1 = cornerUnitMap[i][k1];
            U8 v2 = cornerUnitMap[i][k2];
            U8 v3 = cornerUnitMap[i][k3];
            U8 v4 = cornerUnitMap[i][k4];
            U32 key = k1 + (k2 * 24) + (k3 * 576) + (k4 * 13824);
            U32 value = v1 + (v2 * 24) + (v3 * 576) + (v4 * 13824);
            cornerHalfMap[i][key] = value;
        }}}}    
    }
}

void init_cornerMaps() {
    init_cornerUnitMap(U_cornerUnitMap, U_cornerPosMap, UD_orientMap);
    init_cornerUnitMap(D_cornerUnitMap, D_cornerPosMap, UD_orientMap);
    init_cornerUnitMap(L_cornerUnitMap, L_cornerPosMap, LR_orientMap);
    init_cornerUnitMap(R_cornerUnitMap, R_cornerPosMap, LR_orientMap);
    init_cornerUnitMap(F_cornerUnitMap, F_cornerPosMap, FB_orientMap);
    init_cornerUnitMap(B_cornerUnitMap, B_cornerPosMap, FB_orientMap);

    init_cornerHalfMap(U_cornerUnitMap, U_cornerHalfMap);
    init_cornerHalfMap(D_cornerUnitMap, D_cornerHalfMap);
    init_cornerHalfMap(L_cornerUnitMap, L_cornerHalfMap);
    init_cornerHalfMap(R_cornerUnitMap, R_cornerHalfMap);
    init_cornerHalfMap(F_cornerUnitMap, F_cornerHalfMap);
    init_cornerHalfMap(B_cornerUnitMap, B_cornerHalfMap);
}