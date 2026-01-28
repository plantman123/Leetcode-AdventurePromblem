#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    static int string2int(string num){
        int zf = (num[0] == '-')? -1: 1;
        if (zf == -1) num = num.substr(1, num.length()-1);
        int resnumber = 0;
        for (int i=num.length()-1, base=1;i>=0;i--, base*=10) {
            resnumber += ((int)(num[i]) - (int)'0') * base;
        }
        return resnumber * zf;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> compute;
        for (int i=0;i<tokens.size();i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int number1 = compute.top();
                compute.pop();
                int number2 = compute.top();
                compute.pop();
                int new_number = 0;
                if (tokens[i] == "+") {
                    new_number = number1 + number2;
                }
                else if (tokens[i] == "-") {
                    new_number = number2 - number1;
                }
                else if (tokens[i] == "*") {
                    new_number = number1 * number2;
                }
                else if (tokens[i] == "/") {
                    new_number = (int)(number2 / number1);
                }
                compute.push(new_number);
            }
            else {
                compute.push(string2int(tokens[i]));
            }
        }
        return compute.top();
    }
};