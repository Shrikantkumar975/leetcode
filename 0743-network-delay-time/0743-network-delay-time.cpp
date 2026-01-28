class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &t: times){
            adj[t[0]].push_back({t[1],t[2]});
        }

        vector<int> distance(n+1,INT_MAX);

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;

        pq.push({0,k});
        distance[k] = 0;
        int maxi=0;
        while(!pq.empty()){
            auto [d,node] = pq.top();
            pq.pop();

            for(auto [v,w]: adj[node]){
                if(d+w < distance[v]){
                    distance[v]=d+w;
                    maxi=max(maxi,d+w);
                    pq.push({d+w,v});
                }
            }
        }

    for(int i=1;i<=n;i++){
        if(distance[i]==INT_MAX) return -1;
    }
    return maxi;
    }
};