class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> pq;

        for(int a: stones) pq.push(a);

        while(pq.size()>1){
            int curr = pq.top();
            pq.pop();
            int next = pq.top();
            pq.pop();

            if(curr != next) pq.push(curr-next);
        }

        return pq.top();
    }
};