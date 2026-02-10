#include<string>
#include<iostream>
using namespace std;


class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        for (int i=0;i<n;i++) {
            if (s[i] == goal[0]) {
                string sub_s1 = s.substr(i, n-i);
                string sub_s2 = s.substr(0, i);
                if (sub_s1+sub_s2 == goal) return true;
            }
        }
        return false;
    }
};