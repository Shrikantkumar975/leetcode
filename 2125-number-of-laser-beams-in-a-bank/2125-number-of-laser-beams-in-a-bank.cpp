class Solution {
public:
    int findOne(string s) {
        int a = 0;
        for (char c : s) {
            if (c == '1')
                a++;
        }
        return a;
    }

    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int res = 0;
        int n = bank.size();

        for (int i = 0; i < n; i++) {
            int curr = findOne(bank[i]);
            res += curr * prev;
            if (curr != 0)
                prev = curr;
        }

        return res;
    }
};