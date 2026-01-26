class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        int i=0;
        int j=1;
        int mini=INT_MAX;
        while(j<arr.size()){
            mini = min(mini,arr[j]-arr[i]);
            i++;
            j++;
        }

        vector<vector<int>> v;
        i=0,j=1;

        while(j<arr.size()){
            if(arr[j]-arr[i] == mini) v.push_back({arr[i],arr[j]});

            i++;
            j++;
        }

        return v;
    }
};