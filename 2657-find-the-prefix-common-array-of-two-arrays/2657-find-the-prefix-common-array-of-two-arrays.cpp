class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> arr(n+1,0);
        vector<int> brr(n+1,0);

        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            arr[A[i]]=1;
            brr[B[i]]=1;

            int count=0;
            for(int j=0;j<=i;j++){
                if(arr[B[j]]!=0) count++;
            }

            int countB=0;
            for(int j=0;j<=i;j++){
                if(brr[A[j]]!=0) countB++;
            }

            ans[i]=min(count,countB);
        }

        return ans;
    }
};