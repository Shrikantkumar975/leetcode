class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long curr = mass;

        for(int i=0;i<a.size();i++){
            if(a[i]>curr) return false;

            curr=curr+a[i];
        }

        return true;
    }
};