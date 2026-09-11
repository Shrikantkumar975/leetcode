class Solution {
public:
    set<int> ans;
    
    void dfs(vector<int> &digits,vector<int> used,int curr,int takenCount){
        if(takenCount==3){
            if(curr != 0 && (curr%10)%2==0 && curr/100!=0) ans.insert(curr);
            return;
        }

        for(int i=0;i<digits.size();i++){
            if(used[i]) continue;
            
            used[i]=1;
            int newCurr=curr*10+digits[i];
            dfs(digits,used,newCurr,takenCount+1);

            used[i]=0;
            // dfs(digits,used,curr,takenCount);
        }
    }

    int totalNumbers(vector<int>& digits) {
        ans.clear();
        vector<int> used(digits.size(),0);
        
        dfs(digits,used,0,0);

        return ans.size();
    }
};