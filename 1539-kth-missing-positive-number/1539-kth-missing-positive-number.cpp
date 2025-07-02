class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int i=0;
        int mx = arr[0];


        for(int i=0;i<arr.size();i++){
            mx = max(mx,arr[i]);
        }
        
        vector<int> hash(mx+1,-1);//{0,1,2,3,4,5,6}

        for(int i=0;i<arr.size();i++){
            hash[arr[i]]++;
        }
        int count=0;
        int ans =-1;
        for(int i=1;i<hash.size();i++){
            if(hash[i]==-1) k--;
            if(k==0){
                ans=i;
                break;
            }
        }

        while(k>0){
            mx++;
            ans=mx;
            k--;
        }
         
         return ans;
    }
};