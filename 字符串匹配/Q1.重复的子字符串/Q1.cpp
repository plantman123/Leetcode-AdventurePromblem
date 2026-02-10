#include<string>
using namespace std;


class Solution {
static bool ifsubstr(string s, string sub_s, int times) {
    string new_s = "";
    for (int i=0;i<times;i++) new_s += sub_s;
    if (new_s == s) return true;
    return false;
}

public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i=1;i<n;i++) {
            if (s[i] == s[0]) {
                string sub_str = s.substr(0, i);
                if (n % i == 0) {
                    if (ifsubstr(s, sub_str, n/i)) return true;
                }
            }
        }
        return false;
    }
};