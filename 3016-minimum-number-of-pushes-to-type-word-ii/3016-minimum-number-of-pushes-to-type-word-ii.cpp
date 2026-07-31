class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26);

        for(char c: word){
            v[c-'a']++;
        }

        priority_queue<pair<int,char>> pq;

        for(int i=0;i<26;i++){
            if(v[i]>0)
            pq.push({v[i],i+'a'});
        }

        int i=1;
        int count=0;
        int ans=0;

        while(pq.size()>0){
            if(count==8){
                i++;
                count=0;
            }

            ans+=pq.top().first*i;
            pq.pop();
            count++;
        }

        return ans;
    }
};