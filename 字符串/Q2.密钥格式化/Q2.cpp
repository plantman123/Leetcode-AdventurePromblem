#include<string>
using namespace std;


class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res_str = "";
        int cnt = 0;
        for (int i=s.length()-1;i>=0;i--) {
            if (s[i] != '-') {
                cnt += 1;
                if (s[i] >= 'a' && s[i] <= 'z') res_str += (s[i]-32);
                else res_str += s[i];
                if (cnt == k) {
                    res_str += '-';
                    cnt = 0;
                }
            }
        }
        if (cnt == 0) res_str = res_str.substr(0, res_str.length()-1);
        string tmp_str = "";
        for (int i=res_str.length()-1;i>=0;i--) tmp_str += res_str[i];
        return tmp_str;
    }
};