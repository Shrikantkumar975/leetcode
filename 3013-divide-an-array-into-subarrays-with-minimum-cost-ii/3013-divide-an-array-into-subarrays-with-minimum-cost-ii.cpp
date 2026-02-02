class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> P;

    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        set<P> kMinimum;   // holds k-1 smallest
        set<P> remaining;  // holds rest
        ll sum = 0;

        // build initial window [1 .. dist]
        int i = 1;
        while (i - dist < 1) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];

            if (kMinimum.size() > k - 1) {
                P temp = *kMinimum.rbegin(); // largest among kMinimum
                kMinimum.erase(temp);
                sum -= temp.first;
                remaining.insert(temp);
            }
            i++;
        }

        ll ans = LLONG_MAX;

        // sliding window
        while (i < n) {
            // add new element
            kMinimum.insert({nums[i], i});
            sum += nums[i];

            if (kMinimum.size() > k - 1) {
                P temp = *kMinimum.rbegin();
                kMinimum.erase(temp);
                sum -= temp.first;
                remaining.insert(temp);
            }

            ans = min(ans, sum);

            // remove outgoing element (i - dist)
            P rem = {nums[i - dist], i - dist};

            if (kMinimum.count(rem)) {
                kMinimum.erase(rem);
                sum -= rem.first;

                if (!remaining.empty()) {
                    P temp = *remaining.begin();
                    remaining.erase(temp);
                    kMinimum.insert(temp);
                    sum += temp.first;
                }
            } else {
                remaining.erase(rem);
            }

            i++;
        }

        return nums[0] + ans;
    }
};
