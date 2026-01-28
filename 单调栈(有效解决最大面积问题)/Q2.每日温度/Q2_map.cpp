#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        map<int,int> higher_backup;  // first: temp, second: date
        vector<int> higher_day(n, 0);
        for (int i=0;i<n-1;i++) {
            if (higher_backup[temperatures[i]] == 0 || higher_backup[temperatures[i]] < i) {
                for (int j=i+1;j<n;j++) {
                    if (temperatures[j] > temperatures[i]) {
                        higher_day[i] = j-i;
                        higher_backup[temperatures[i]] = j;
                        break;
                    }
                }
            }
            else {
                higher_day[i] = higher_backup[temperatures[i]] - i;
            }
        }
        return higher_day;
    }
};