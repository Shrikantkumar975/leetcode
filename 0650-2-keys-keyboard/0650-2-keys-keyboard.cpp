class Solution {
public:
    int minSteps(int n) {
        vector<int> v(n+1,0);
        v[1]=0;

        for(int i=2;i<=n;i++){
            v[i]=i;
        }

        for(int i=2;i<=n;i++){
            for(int j=i*2;j<=n;j+=i){
                v[j]=min(v[j],v[i]+((j-i)/i)+1);
            }
        }

        return v[n];
    }
};