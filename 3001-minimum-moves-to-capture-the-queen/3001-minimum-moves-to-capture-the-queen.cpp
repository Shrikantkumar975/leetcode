class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // Check rook capturing queen in same row (a == e) or same column (b == f),
        // making sure bishop (c,d) is not strictly between them.
        if (a == e) { // same row
            if (!(c == a && d > min(b, f) && d < max(b, f))) return 1;
        }
        if (b == f) { // same column
            if (!(d == b && c > min(a, e) && c < max(a, e))) return 1;
        }

        // Check bishop capturing queen in one move (same diagonal)
        if (abs(c - e) == abs(d - f)) {
            // Is the rook (a,b) strictly between (c,d) and (e,f) on that diagonal?
            bool rookOnDiag = (abs(a - c) == abs(b - d));
            bool rookBetweenX = (a > min(c, e) && a < max(c, e));
            bool rookBetweenY = (b > min(d, f) && b < max(d, f));
            if (!(rookOnDiag && rookBetweenX && rookBetweenY)) {
                // bishop not blocked by rook
                return 1;
            }
            // else bishop is blocked, fallthrough to return 2
        }

        return 2;
    }
};
