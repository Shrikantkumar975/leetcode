class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,vector<string>& businessLine,vector<bool>& isActive) {

        map<string,string> mpp;
        for (int i = 0; i < isActive.size(); i++) {
            if (isActive[i] == true) {
                if (businessLine[i] == "restaurant" ||businessLine[i] == "grocery" ||
                    businessLine[i] == "pharmacy" ||businessLine[i] == "electronics") {
                    
                    if(!code[i].size()) continue;
                    
                    int count = 0;
                    for (char ch : code[i]) {
                        if ((ch>='A' && ch <= 'Z') ||
                            (ch >= 'a' && ch <= 'z') ||
                            (ch >= '0' && ch <= '9') || ch == '_')
                            count++;
                    }

                    if (count == code[i].size()) {
                        mpp[businessLine[i]] = code[i];
                    }
                }
            }
        }
        vector<string> v;
        for (auto m : mpp) {
            v.push_back(m.second);
        }

        return v;
    }
};