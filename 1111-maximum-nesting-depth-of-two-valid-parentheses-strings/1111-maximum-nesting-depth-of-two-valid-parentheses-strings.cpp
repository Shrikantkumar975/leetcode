class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<int> open;
        stack<int> close;

        vector<int> ans(seq.size(), 0);
        int depth=0;

        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                depth++;
                ans[i] = depth % 2;
            } else {
                ans[i] = depth % 2;
                depth--;
            }
        }

        // int g1 = ceil(close.size() / 2);

        // int i = 0;

        // while (i < g1) {
        //     ans[close.top()] = 1;
        //     ans[open.top()] = 1;

        //     close.pop();
        //     open.pop();

        //     i++;
        // }

        return ans;
    }
};