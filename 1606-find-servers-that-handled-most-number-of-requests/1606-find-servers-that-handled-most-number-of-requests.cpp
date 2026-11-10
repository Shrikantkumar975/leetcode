class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> st(k,0);

        vector<int> count(k,0);

        //end-time,server
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<arrival.size();i++){
            while(!pq.empty() && pq.top().first<=arrival[i]){
                int s = pq.top().second;
                st[s]=0;
                pq.pop();
            }

            if(st[i%k]==0){
                pq.push({arrival[i]+load[i],i%k});
                st[i%k]=1;
                count[i%k]++;
            }else{
                int j=i%k+1;
                int ins = 0;
                while(j<k){
                    if(st[j]==0){
                       pq.push({arrival[i]+load[i],j});
                        st[j]=1;
                        count[j]++; 
                        ins=1;
                        break;
                    }
                    j++;
                }

                if(ins==0){
                    j=0;
                    while(j<i%k){
                        if(st[j]==0){
                            pq.push({arrival[i]+load[i],j});
                            st[j]=1;
                            count[j]++; 
                            ins=1;
                            break;
                        }
                        j++;
                    }
                }
            }
        }

        priority_queue<pair<int,int>> pq2;

        for(int i=0;i<k;i++){
            pq2.push({count[i],i});
        }

        vector<int> ans;

        int curr=pq2.top().first;

        while(!pq2.empty() && pq2.top().first==curr){
            ans.push_back(pq2.top().second);
            pq2.pop();
        }

        return ans;
    }
};