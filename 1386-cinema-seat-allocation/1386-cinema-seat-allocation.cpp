class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>> mp;        

        for(auto m: reservedSeats){
            mp[m[0]].insert(m[1]);;
        }

        int ans=(n-mp.size())*2;

        for(auto &row: mp){
            auto &s = row.second;

            bool l  = !(s.count(2) || s.count(3) || s.count(4) || s.count(5));
            bool mid   = !(s.count(4) || s.count(5) || s.count(6) || s.count(7));
            bool r = !(s.count(6) || s.count(7) || s.count(8) || s.count(9));


            if(l && r) ans+=2;
            else if(l || mid || r) ans+=1;
        }

        return ans;
    }
};