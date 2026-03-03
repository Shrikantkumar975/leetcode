class Solution {
public:
    int ans = INT_MAX;

    void backtrack(int idx,
                   vector<int>& cookies,
                   vector<int>& children,
                   int k) {

        if(idx == cookies.size()) {
            ans = min(ans, *max_element(children.begin(), children.end()));
            return;
        }

        int cookie = cookies[idx];

        for(int i = 0; i < k; i++) {

            // Prune
            if(children[i] + cookie >= ans) continue;

            children[i] += cookie;

            backtrack(idx + 1, cookies, children, k);

            children[i] -= cookie;

            // Symmetry break
            if(children[i] == 0) break;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {

        sort(cookies.rbegin(), cookies.rend());

        vector<int> children(k, 0);

        backtrack(0, cookies, children, k);

        return ans;
    }
};