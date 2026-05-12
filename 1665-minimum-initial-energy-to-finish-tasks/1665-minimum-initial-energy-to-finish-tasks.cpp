class Solution {
public:

    bool check(int energy, vector<vector<int>>& tasks){

        for(auto &t : tasks){

            int actual = t[0];
            int minimum = t[1];

            if(energy < minimum)
                return false;

            energy -= actual;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        auto cmp = [](vector<int>& a, vector<int>& b){

            return (a[1] - a[0]) > (b[1] - b[0]);
        };

        sort(tasks.begin(), tasks.end(), cmp);

        int low = 0;
        int high = 1e9;

        int ans = high;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(check(mid, tasks)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};