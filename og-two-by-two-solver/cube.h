class Cube {

    public:

        int positions[8];
        int orientations[8];
        int targetPos[8];
        int targetOrient[8];
        int maxDepth = MAX_DEPTH;
        char history[MAX_DEPTH];

        Cube (vector<int> pos, vector<int> ori) {
            for (int i=0; i<8; i++) {
                positions[i] = pos[i];
                orientations[i] = ori[i];
            }
        }


        void TopC();
        void LeftC();
        void FrontC();
        void swapOrientF (int a);
        void swapOrientL (int a);
        void swapOrientT (int a);
        
        void CalcInit(vector<int> pos, vector<int> ori);
        void CalcT (int depth);
        void CalcL (int depth);
        void CalcF (int depth);


        bool equalsTarget() {
            for (int i=0; i<8; i++) {
                if (positions[i] != targetPos[i] || orientations[i] != targetOrient[i]) {
                    return false;
                }
            }
            return true;
        }
        void printSolution (int depth) {
            cout << depth << ": ";
            for (int i=0; i<depth; i++) {
                cout << history[i];
            }
            cout << '\n';
        }

        void printCube() {
            for (int i=0; i<8; i++) {
                cout << positions[i];
            }
            cout << '\n';
            for (int i=0; i<8; i++) {
                cout << orientations[i];
            }
            cout << '\n';
        }

        void performTansforms (string tranfs) {
            for (int i=0; i<tranfs.length(); i++) {
                switch (tranfs[i]) {
                    case 'T': TopC(); break;
                    case '+': TopC();TopC(); break;
                    case 't': TopC();TopC();TopC(); break;
                    case 'L': LeftC(); break;
                    case '1': LeftC();LeftC(); break;
                    case 'l': LeftC();LeftC();LeftC(); break;
                    case 'F': FrontC(); break;
                    case 'e': FrontC();FrontC(); break;
                    case 'f': FrontC();FrontC();FrontC(); break;
                }
            }
        }
};