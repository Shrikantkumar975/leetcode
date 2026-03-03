class Solution {
public:
    int ans = INT_MAX;

    void backtrack(int idx,
                   vector<int>& jobs,
                   vector<int>& workers,
                   int k) {

        if(idx == jobs.size()) {
            ans = min(ans, *max_element(workers.begin(), workers.end()));
            return;
        }

        int job = jobs[idx];

        for(int i = 0; i < k; i++) {

            // Prune: if already worse than best
            if(workers[i] + job >= ans) continue;

            workers[i] += job;

            backtrack(idx + 1, jobs, workers, k);

            workers[i] -= job;

            // Symmetry break: avoid duplicate empty worker states
            if(workers[i] == 0) break;
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {

        sort(jobs.rbegin(), jobs.rend()); // biggest first

        vector<int> workers(k, 0);

        backtrack(0, jobs, workers, k);

        return ans;
    }
};