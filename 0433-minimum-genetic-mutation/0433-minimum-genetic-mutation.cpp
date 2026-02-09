class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        string str = "ACGT";

        set<string> s;

        for (auto st : bank) {
            s.insert(st);
        }

        if(s.find(endGene)==s.end()) return -1;

        queue<string> q;

        q.push(startGene);

        if (s.find(startGene) != s.end())
            s.erase(startGene);
        int step = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string u = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < u.size(); j++) {
                        if(u[j]==str[i]) continue;
                        char temp = u[j];
                        u[j] = str[i];
                        if(u==endGene){
                            return step+1;
                        }
                        if (s.find(u) != s.end()) {
                            q.push(u);
                            s.erase(u);
                        }
                        u[j] = temp;
                    }
                }
            }
            step++;
        }

        return -1;
    }
};