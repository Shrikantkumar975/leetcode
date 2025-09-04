class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diffX = abs(x-z);
        int diffY = abs(y-z);

        return diffX<diffY?1:diffY<diffX?2:0;
    }
};