class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int ex) {
        vector<double> m(classes.size());

        for(int i=0;i<classes.size();i++){
            int a = classes[i][0];
            int b = classes[i][1];

            double ans = a/(double)b;

            m[i] = ans;
        }

        while(ex){
            double change =-1.0;
            int an = -1;
            for(int i=0;i<m.size();i++){
                double b = ((classes[i][0] + 1) / (double)(classes[i][1] + 1)) - m[i];
                if(b > change){
                    change = b;
                    an = i;
                }
            }

            classes[an][0]++; 
            classes[an][1]++; 
            m[an] = (double)classes[an][0] / classes[an][1];
            ex--;
        }

        double sum = accumulate(m.begin(),m.end(),0.0);
        return sum/m.size();
    }
};