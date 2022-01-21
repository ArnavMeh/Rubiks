typedef unsigned char U8;

class Cube {
    public:
        U32 edges[4] {};
        U32 corners[2] {};

        U8* getCorners() {
            U8* bitCorners = new U8[8];

            int i = 0;
            for (int c1 = corners[0]; c1 != 0; c1 /= 24) {
                bitCorners[i++] = c1 % 24;
            }
            for (int c2 = corners[1]; c2 != 0; c2 /= 24) {
                bitCorners[i++] = c2 % 24;
            }
            return bitCorners;
        }

        Cube() {
            int mult = 1;
            for (int i = 0; i < 4; i++) {
                edges[2] += (i + 8) * mult;
                edges[1] += (i + 4) * mult;
                edges[0] += i * mult;
                mult *= 24;
            }
            corners[0] = edges[0];
            corners[1] = edges[1];
        }
};