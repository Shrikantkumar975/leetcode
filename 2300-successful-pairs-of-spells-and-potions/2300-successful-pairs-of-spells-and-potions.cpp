class Solution {
public:
    int found(int sp, vector<int> &potions,long long success){
        int n= potions.size();

        int high = n-1;
        int low =0;
        int ans = -1;

        while(low<=high){
            long long mid = (high + low)/2;
            if(potions[mid]*sp >= success){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        if(ans == -1) return 0;
        return n-ans;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> v;
        sort(potions.begin(),potions.end());

        for(int i=0;i<spells.size();i++){
            int a = found(spells[i],potions,success);
            v.push_back(a);
        }

        return v;
    }
};