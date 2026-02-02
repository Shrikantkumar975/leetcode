class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) adj[f[0]].push_back({f[1], f[2]});

        const long long INF = (long long)1e15;
        vector<long long> dist(n, INF);
        dist[src] = 0;

        queue<pair<int,int>> q;
        q.push({src,0});

        while(!q.empty() && K-->=0){

            int size = q.size();

            while(size--){
                auto [u,d] = q.front();
                q.pop();

                for(auto [v,w]: adj[u]){
                    if(d+w < dist[v]){
                        dist[v]=d+w;
                        q.push({v,dist[v]});
                    }
                }
            }
        }
        
        return dist[dst] == INF ? -1 : (int)dist[dst];
    }
};