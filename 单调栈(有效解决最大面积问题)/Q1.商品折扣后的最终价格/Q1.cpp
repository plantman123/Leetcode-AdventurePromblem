#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> discount(n, -1);
        for (int i=0;i<n;i++) {
            discount[i] = prices[i];
            if (i == n-1) {break;}
            else {
                for (int j=i+1;j<n;j++) {
                    if (prices[j] <= prices[i]) {
                        discount[i] -= prices[j];
                        break;
                    }
                }
            }
        }
        return discount;
    }
};