#include<string>
#include<iostream>
using namespace std;


class Solution {
// static bool if_substr(string a, string b) {
//     int start_idx = 0, bn = b.length();
//     while(start_idx + bn <= a.length()+1) {
//         if (a[start_idx] == b[0]) {
//             int ret = 1;
//             for (int i=0;i<bn;i++) {
//                 if (a[start_idx+i] != b[i]) {
//                     for (int j=start_idx+i;j<a.length();j++) {
//                         if (a[j] == b[i]) {
//                             start_idx = j-i;
//                             break;
//                         }
//                     }
//                     ret = 0;
//                     break;
//                 }
//             }
//             if (ret) return true;
//         }
//         else start_idx += 1;
//     }
//     return false;
// }
static bool if_substr(string a, string b) {
    int an = a.length(), bn = b.length();
    for (int i=0;i<=an-bn;i++) {
        if (a[i] == b[0]) {
            int ret = 1;
            for (int j=0;j<bn;j++) {
                if (a[i+j] != b[j]) {
                    ret = 0;
                    break;
                }
            }
            if (ret) return true;
        }
    }
    return false;
}
public:
    int repeatedStringMatch(string a, string b) {
        string multi_a = "";
        int times = 0;
        while (multi_a.length() <= 2*a.length()+b.length()) {
            multi_a += a;
            times += 1;
            if (multi_a.length() >= b.length()) {
                if (if_substr(multi_a, b)) return times;
            }
        }
        return -1;
    }
};