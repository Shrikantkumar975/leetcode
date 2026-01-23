class Solution {
public:
    bool check(string s) {
        if (s.size() > 1 && s[0] == '0') return false;
        int val = stoi(s);
        return val >= 0 && val <= 255;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.size();

        for (int i = 1; i <= 3 && i < n; i++) {
            for (int j = i + 1; j <= i + 3 && j < n; j++) {
                for (int k = j + 1; k <= j + 3 && k < n; k++) {

                    if (n - k > 3) continue;

                    string a = s.substr(0, i);
                    string b = s.substr(i, j - i);
                    string c = s.substr(j, k - j);
                    string d = s.substr(k);

                    if (valid(a) && valid(b) && valid(c) && valid(d)) {
                        res.push_back(a + "." + b + "." + c + "." + d);
                    }
                }
            }
        }
        return res;
    }
};
