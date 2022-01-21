#define VD 69

U8 UD_orientMap[3] = {0, 2, 1};
U8 LR_orientMap[3] = {2, 1, 0};
U8 FB_orientMap[3] = {1, 0, 2};

U8 U_edgePosMap[12] = {3,  0,  1,  2,  VD, VD, VD, VD, VD, VD, VD, VD};
U8 D_edgePosMap[12] = {VD, VD, VD, VD, VD, VD, VD, VD, 9,  10, 11, 8};
U8 L_edgePosMap[12] = {5,  VD, VD, VD, 0,  8,  VD, VD, 4,  VD, VD, VD};
U8 R_edgePosMap[12] = {VD, VD, 7,  VD, VD, VD, 2,  10, VD, VD, 6,  VD};
U8 F_edgePosMap[12] = {VD, 6,  VD, VD, VD, 1,  9,  VD, VD, 5,  VD, VD};
U8 B_edgePosMap[12] = {VD, VD, VD, 4,  11, VD, VD, 3,  VD, VD, VD, 7};

U8 U_edgeUnitMap[3][36];
U8 D_edgeUnitMap[3][36];
U8 L_edgeUnitMap[3][36];
U8 R_edgeUnitMap[3][36];
U8 F_edgeUnitMap[3][36];
U8 B_edgeUnitMap[3][36];

U32 *U_edgeThirdMap[3];
U32 *D_edgeThirdMap[3];
U32 *L_edgeThirdMap[3];
U32 *R_edgeThirdMap[3];
U32 *F_edgeThirdMap[3];
U32 *B_edgeThirdMap[3];

void init_edgeUnitMap(U8 (&edgeUnitMap)[3][36], U8 *edgePosMap, U8 *orientMap) {
    for (int orient = 0; orient < 3; orient++) { // orient: 0-2
        for (int pos = 0; pos < 12; pos++) { // pos: 0-11
            U8 key = orient * 12 + pos;
            if (edgePosMap[pos] != VD) {
                U8 newPos = pos, newOrient = orient;
                for (int i = 0; i < 3; i++) {
                    newPos = edgePosMap[newPos];
                    newOrient = orientMap[newOrient];
                    edgeUnitMap[i][key] = newOrient * 12 + newPos;
                }
            } else {
                edgeUnitMap[0][key] = key;
                edgeUnitMap[1][key] = key;
                edgeUnitMap[2][key] = key;
            }
        }
    }
}

void init_edgeThirdMap(U8 (&edgeUnitMap)[3][36], U32 *(&edgeThirdMap)[3]) {
    for (int i = 0; i < 3; i++) {
        edgeThirdMap[i] = new U32[1679616];
        for (int k1 = 0; k1 < 36; k1++) {
            for (int k2 = 0; k2 < 36; k2++) {
                for (int k3 = 0; k3 < 36; k3++) {
                    for (int k4 = 0; k4 < 36; k4++) {
            U8 v1 = edgeUnitMap[i][k1];
            U8 v2 = edgeUnitMap[i][k2];
            U8 v3 = edgeUnitMap[i][k3];
            U8 v4 = edgeUnitMap[i][k4];
            U32 key = k1 + (k2 * 36) + (k3 * 1296) + (k4 * 46656);
            U32 value = v1 + (v2 * 36) + (v3 * 1296) + (v4 * 46656);
            edgeThirdMap[i][key] = value;
        }}}}
    }
}

void init_edgeMaps() {
    init_edgeUnitMap(U_edgeUnitMap, U_edgePosMap, UD_orientMap);
    init_edgeUnitMap(D_edgeUnitMap, D_edgePosMap, UD_orientMap);
    init_edgeUnitMap(L_edgeUnitMap, L_edgePosMap, LR_orientMap);
    init_edgeUnitMap(R_edgeUnitMap, R_edgePosMap, LR_orientMap);
    init_edgeUnitMap(F_edgeUnitMap, F_edgePosMap, FB_orientMap);
    init_edgeUnitMap(B_edgeUnitMap, B_edgePosMap, FB_orientMap);

    init_edgeThirdMap(U_edgeUnitMap, U_edgeThirdMap);
    init_edgeThirdMap(D_edgeUnitMap, D_edgeThirdMap);
    init_edgeThirdMap(L_edgeUnitMap, L_edgeThirdMap);
    init_edgeThirdMap(R_edgeUnitMap, R_edgeThirdMap);
    init_edgeThirdMap(F_edgeUnitMap, F_edgeThirdMap);
    init_edgeThirdMap(B_edgeUnitMap, B_edgeThirdMap);
}