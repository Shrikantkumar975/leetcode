class Solution {
public:
    int mini = INT_MAX;
    pair<int, int> coord(char ch) {
        int c = ch - 'A';
        return {c / 6, c % 6};
    }
    void solve(string word, int i, int sum, char f1, char f2) {
        if (i == word.size()) {
            mini = min(mini, sum);
            return;
        }
        auto [a, b] = coord(word[i]);
        auto [x1, y1] = coord(f1);
        auto [x2, y2] = coord(f2);
    
        int newSum = abs(x1-a)+abs(y1-b);
        solve(word,i+1,sum+newSum,word[i],f2);

        if (f2 != '0')
            sum += abs(x2 - a) + abs(y2 - b);
        solve(word, i + 1, sum, f1, word[i]);
    }

    int minimumDistance(string word) {

        solve(word, 1, 0, word[0], '0');

        return mini;
    }
};