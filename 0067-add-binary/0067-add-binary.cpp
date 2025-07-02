// class Solution {
// public:
//     string addBinary(string a, string b) {
//         int i=a.length()-1;
//         int j=b.length()-1;

//         int mx= i<j?i:j;
//         int carry = 0;
//         string s ="";
//         while(mx--){
//             int sum=carry+a[i--]-'0'+ b[j--]-'0');
//             carry=0;
//             if(sum <= 1) s+=to_string(sum);
//             else{
//                 s+="0";
//                 carry=1;
//             }
//         }

//         while(i>=0){
//             int sum = carry + stoi(a[i--]);
//             carry=0;
//             if(sum <= 1) s+=to_string(sum);
//             else{
//                 s+="0";
//                 carry=1;
//             }
            
//         }




//     }
// };

class Solution {
public:
    string addBinary(string a, string b) {   // a"101" b ="1011"
        string res; 
        int carry = 0;
        int i = a.length() - 1;   // 3,2 , 1 , 0 , -1
        int j = b.length() - 1;    // 3,2 , 1 , 0 , -1

        while (i >= 0 || j >= 0 || carry) {   // 3 >  0 , 3 > 0 , 0 ; 2>=0 , 2>=0 , 0 ; 1 > 0 ; 0== 0  , c = 1>0;
            if (i >= 0) carry += a[i--] - '0';   // carry = 0, carry = 1; , c = 1  , c = 1 ,na 
            if (j >= 0) carry += b[j--] - '0';     // c = 1 , c = 2 , c = 1  c = 2  na

            res += carry % 2 + '0';     // res ="1"  "10" , "10101" 
            carry /= 2; // carry =0,     1  , 0 , 1 , 0
        }

        reverse(res.begin(), res.end());
        return res;        
    }
};