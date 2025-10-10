class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int maxi = -1001;

        for(int i=energy.size()-1;i>=0;i--){
            if(i+k<energy.size()){
                energy[i]+=energy[i+k];
            }
        }
        return *max_element(energy.begin(),energy.end());
    }
};