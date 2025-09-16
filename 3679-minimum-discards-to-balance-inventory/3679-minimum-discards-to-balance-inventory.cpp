class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int i = 0, j = 0, n = arrivals.size();
        unordered_map<int, int> mp;

        int cnt = 0;

        while (j < n) {

            mp[arrivals[j]]++;

            while (j - i + 1 > w) {
                if (arrivals[i] != -1)
                    mp[arrivals[i]]--;

                i++;
            }

            if (mp[arrivals[j]] > m) {
                cnt++;
                mp[arrivals[j]]--;
                arrivals[j] = -1;
            }

            j++;
        }

        return cnt;
    }
};