using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        while (a != 0 || b != 0 || c != 0) {
            int x = a & 0x1;
            int y = b & 0x1;
            int z = c & 0x1;

            if (x == 1 && y == 1 && z == 0) {
                flips += 2;
            } else if ((x | y) != z) {
                flips += 1;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
    }
};