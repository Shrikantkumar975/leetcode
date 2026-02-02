class Solution {
public:
//Krushkal Algorithms
    vector<int> parent;
    vector<int> rank;

    int find(int u){
        if(parent[u]==u) return u;

        return parent[u]=find(parent[u]);
    }

    void Union(int u,int v){
        int pu = find(u);
        int pv = find(v);

        if(pu==pv) return;

        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        vector<vector<int>> adj;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj.push_back({i,j,dist});
            }
        }

        auto comp = [&](vector<int> &v1,vector<int> &v2){
            return v1[2]<v2[2];
        };

        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        sort(adj.begin(),adj.end(),comp);

        int ans=0;
        for(auto a: adj){
            int u=a[0];
            int v=a[1];
            int w=a[2];

            int p1=find(u);
            int p2=find(v);

            if(p1!=p2){
                Union(u,v);
                ans+=w;
            }
        }

        return ans;


    }
};