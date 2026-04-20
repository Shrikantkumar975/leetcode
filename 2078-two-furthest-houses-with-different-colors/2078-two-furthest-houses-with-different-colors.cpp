class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;

        for(int i=0;i<colors.size()-1;i++){
            for(int j=colors.size()-1;j>i;j--){
                if(colors[j]!=colors[i]){
                    ans = max(ans,j-i);
                }
            }
        }

        return ans;
    }
};