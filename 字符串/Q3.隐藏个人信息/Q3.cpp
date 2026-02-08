#include<string>
#include<iostream>
using namespace std;


class Solution {
static string email(string s, int at_idx) {
    string res_str = "";
    res_str += s[0];
    res_str += "*****";
    res_str += s[at_idx-1];
    return res_str + s.substr(at_idx, s.length()-at_idx);
}

static string phonenumvber(string s) {
    string reverse_number = "";
    int cnt = 0;
    int f_or_th = 0;  // 0:4, 1:3
    for (int i=s.length()-1;i>=0;i--) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (f_or_th == 0) reverse_number += s[i];
            else reverse_number += '*';
            cnt += 1;
            if (cnt == 4 && f_or_th == 0) {
                cnt = 0;
                f_or_th += 1;
                reverse_number += '-';
            }
            else if (cnt == 3 && f_or_th == 1) {
                cnt = 0;
                reverse_number += '-';
            }
        }
    }
    if (reverse_number[reverse_number.length()-1] == '-') {
        reverse_number = reverse_number.substr(0, reverse_number.length()-1);
        if (reverse_number.length() == 16) reverse_number += '+';
    }
    else reverse_number += '+';
    string formal_number = "";
    for (int i=reverse_number.length()-1;i>=0;i--) formal_number += reverse_number[i];
    return formal_number; 
}

public:
    string maskPII(string s) {
        int at_idx = 0;  // 1：@  0：number
        for (int i=0;i<s.length();i++) {
            if (s[i] == '@') at_idx = i;
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        }
        if (at_idx) return email(s, at_idx);
        return phonenumvber(s);
    }
};