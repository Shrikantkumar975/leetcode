class Solution {
public:
    void balance(multiset<int>& left, multiset<int>& right) {

        // fix ordering
        while (!left.empty() && !right.empty() &&
               *prev(left.end()) > *right.begin()) {

            int a = *prev(left.end());
            int b = *right.begin();

            left.erase(prev(left.end()));
            right.erase(right.begin());

            left.insert(b);
            right.insert(a);
        }

        // fix size
        while (left.size() > right.size() + 1) {
            right.insert(*prev(left.end()));
            left.erase(prev(left.end()));
        }

        while (left.size() < right.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> left, right;
        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {

            // insert
            if (left.empty() || nums[i] <= *prev(left.end()))
                left.insert(nums[i]);
            else
                right.insert(nums[i]);

            balance(left, right);

            // window ready
            if (i >= k - 1) {

                // median
                if (k % 2 == 0)
                    ans.push_back(
                        ((double)*prev(left.end()) + *right.begin()) / 2.0
                    );
                else
                    ans.push_back(*prev(left.end()));

                // remove outgoing
                int out = nums[i - k + 1];
                if (left.find(out) != left.end())
                    left.erase(left.find(out));
                else
                    right.erase(right.find(out));

                balance(left, right);
            }
        }
        return ans;
    }
};
