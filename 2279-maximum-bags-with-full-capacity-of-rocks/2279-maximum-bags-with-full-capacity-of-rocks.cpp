class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i=0;i<capacity.size();i++){
            pq.push(capacity[i]-rocks[i]);
        }

        int count=0;
        while(!pq.empty()){
            if(additionalRocks<pq.top()) break;
            additionalRocks-=pq.top();
            pq.pop();
            count++;
        }


        return count;
    }
};