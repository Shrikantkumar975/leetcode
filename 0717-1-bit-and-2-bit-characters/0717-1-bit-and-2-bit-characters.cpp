class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int count = 0;
        int length = bits.size();
        int i = length - 2;
        if (bits[i] == 0)
            return true;
        else {
            while (i >= 0 && bits[i] == 1) {
                count = count + 1;
                i = i - 1;
            }
            if (count % 2 == 0)
                return true;
            else
                return false;
        }
    }
};