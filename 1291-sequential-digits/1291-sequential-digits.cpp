class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        for(int i=1;i<=9;i++){
            int last = i;
            int num = 0;
            while(num<=high && last<10){
                num = num*10+last;

                if(num>=low && num<=high){
                    ans.push_back(num);
                }

                last++;
            }
        }
        sort(ans.begin(),ans.end());

        return ans;
    }
};