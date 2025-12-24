class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());

        int sum = accumulate(apple.begin(),apple.end(),0);
        int count=0;
        
        for(int a: capacity){
            if(sum<=0) break;

            sum-=a;
            count++;
        }

        return count;
    }
};