#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    static bool judge_str(string word, int mode) {
        printf("%d\n", mode);
        for (int i=1;i<word.length();i++) {
            printf("%c\n", word[i]);
            if ((mode==1 || mode==2) && word[i] >= 'A' && word[i] <= 'Z') return false;
            if (mode==3 && word[i] >= 'a' && word[i] <= 'z') return false;
        }
        return true;
    }

    bool detectCapitalUse(string word) {
        if (word.length() <= 1) {return true;}
        int mode = 0;
        if (word[0] >= 'a' && word[0] <= 'z') mode = 1;  // 全小写
        else if (word[0] >= 'A' && word[0] <= 'Z') {
            mode = 2;  // 首字母大写
            if (word[1] >= 'A' && word[1] <= 'Z') mode = 3;  // 全大写 
        }
        return judge_str(word, mode);
    }
};