class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<int> v1;
        vector<int> v2;
        for(int num: nums){
            if(num%3==1 && v1.size()<2){
                 v1.push_back(num);
            }else if(num%3==2 && v2.size()<2){
                v2.push_back(num);
            }
        }

        int require = sum%3;

        if(require==1){
            int a=0;
            int b=0;
            if(v1.size()>0) a=v1[0];
            if(v2.size()==2) b=v2[0]+v2[1];

            if(a && b) sum-=min(a,b);
            else if(a) sum-=a;
            else if(b) sum-=b;
            else sum=0;
        }
        else if(require == 2){
            int a=0;
            int b=0;
            if(v1.size()==2) a=v1[0]+v1[1];
            if(v2.size()>0) b=v2[0];

            if(a && b) sum-=min(a,b);
            else if(a) sum-=a;
            else if(b) sum-=b;
            else sum=0;
        }

        // int sum1=0;
        // int count1=0;

        // for(int i=0;i<nums.size();i++){
        //     if(count1==2){
        //         break;
        //     }
        //     if(mod[i]==1){
        //         count1++;
        //         sum1+=nums[i];
        //     }
        //     else if(mod[i]==2){
        //         if(count1!=2){
        //             return sum-nums[i];
        //         }
        //     }
        // }
        return sum;
        
    }
};