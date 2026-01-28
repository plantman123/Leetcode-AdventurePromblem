#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> htmp_idx;  // 栈顶温度低
        vector<int> higher_day(temperatures.size(), 0);
        for (int i=0;i<temperatures.size();i++) {
            while (!htmp_idx.empty()) {
                if (temperatures[htmp_idx.back()] < temperatures[i]) {
                    higher_day[htmp_idx.back()] = i-htmp_idx.back();
                    htmp_idx.pop_back();
                }
                else {break;}
            }
            htmp_idx.push_back(i);
        }
        return higher_day;
    }
};