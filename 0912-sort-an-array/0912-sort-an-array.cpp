class Solution {
public:
    vector<int> sortArray(vector<int>& arr) {
        // for(int i=1;i<arr.size();i++){
        //     int key = arr[i];
        //     int j = i-1;
        //     while(j>=0 && arr[j]>key){
        //         arr[j+1]=arr[j];
        //         j--;
        //     }
        //     arr[j+1]=key;
        // }
        sort(arr.begin(),arr.end());

        return arr;
    }
};