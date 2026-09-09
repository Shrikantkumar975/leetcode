class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        set<vector<int>> seen;

        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         for (int k = j + 1; k < nums.size(); k++) {
        //             if (nums[i] + nums[j] + nums[k] == 0 &&
        //                 seen.find({nums[i], nums[j], nums[k]}) == seen.end())
        //                 { ans.push_back({nums[i], nums[j], nums[k]});
        //                 seen.insert({nums[i], nums[j], nums[k]});
        //             }
        //         }
        //     }
        // }

        // for (int i = 0; i < nums.size(); i++) {
        //     set<int> st;

        //     for (int j = i + 1; j < nums.size(); j++) {

        //         int need = -(nums[i] + nums[j]);

        //         // Check whether the required value appeared
        //         // before j
        //         if (st.find(need) != st.end()) {

        //             vector<int> temp = {
        //                 nums[i],
        //                 nums[j],
        //                 need
        //             };

        //             // Sort so that the same triplet always
        //             // has the same representation
        //             sort(temp.begin(), temp.end());

        //             if (seen.find(temp) == seen.end()) {
        //                 ans.push_back(temp);
        //                 seen.insert(temp);
        //             }
        //         }

        //         // Insert current element AFTER checking
        //         st.insert(nums[j]);
        //     }
        // }

        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                if (nums[left] + nums[right] == -nums[i]) {
                    vector<int> temp = {nums[i], nums[left], nums[right]};

                    if (seen.find(temp) == seen.end()) {
                        ans.push_back(temp);
                        seen.insert(temp);
                    }

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                } else if (nums[left] + nums[right] > -nums[i]) {
                    right--;
                } else
                    left++;
            }
        }

        return ans;
    }
};