class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> hash(10,0);
        vector<int> ans;
        for(int a: digits){
            hash[a]++;
        }

        for(int i=100;i<1000;i++){
            vector<int> copy = hash;
            int num=i;
            int f =0;
            while(num){
                if(copy[num%10] == 0){
                    f=1;
                    break;
                }
                copy[num%10]--;
                num/=10;
            }

            if(f==0 && i%2==0) ans.push_back(i); 

        }
        return ans;
    }
};