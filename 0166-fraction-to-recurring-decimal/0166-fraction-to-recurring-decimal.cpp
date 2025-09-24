class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res = "";

        // sign handling
        if ((long long)numerator * denominator < 0) res += "-";

        // convert safely to long long before abs
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // integer part
        long long a = num / den;
        res += to_string(a);

        long long b = num % den;
        if (b == 0) return res;

        res += '.';
        unordered_map<long long, int> m;

        // fractional part
        while (b != 0) {
            if (m.count(b)) {
                res.insert(m[b], "(");
                res += ")";
                return res;
            }

            m[b] = res.size();
            b *= 10;
            long long digit = b / den;
            res += to_string(digit);
            b %= den;
        }
        return res;
    }
};
