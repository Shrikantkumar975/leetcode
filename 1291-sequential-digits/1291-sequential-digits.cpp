class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;

        for(int i=1;i<10;i++) q.push(i);
        vector<int> ans;

        while(!q.empty()){
            int num = q.front();
            q.pop();

            if(num>=low) ans.push_back(num);

            int lastDigit = num%10;
            lastDigit++;
            if(lastDigit<=9) {
                int newNum = num*10+lastDigit;
                if(newNum <= high) q.push(newNum);
            }
        }

        return ans;
    }
};