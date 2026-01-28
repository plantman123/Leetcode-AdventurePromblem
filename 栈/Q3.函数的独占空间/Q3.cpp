#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

typedef struct func{
    int func_id;
    int start;
    int unuse_time;
} func;
class Solution {
public:
    static int string2int(string num){
        return stoi(num);
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<func> func_stack;
        vector<int> funcs_time(n, 0);
        for (int i=0;i<logs.size();i++) {
            string logi = logs[i];
            int func_id, func_opt, timestamp;
            int sid1 = 0, sid2 = 0;
            for (int j=0;j<logi.length();j++) {
                if (logi[j] == ':') {
                    if (sid1 == 0){
                        sid1 = j;
                    }
                    else {
                        sid2 = j;
                        break;
                    }
                }
            }
            func_id = string2int(logi.substr(0, sid1));
            timestamp = string2int(logi.substr(sid2+1, logi.length()-sid2));
            func_opt = (logi.substr(sid1+1, sid2-sid1-1) == "start")? 1: 0;

            if (func_opt) {  // push
                func new_func;
                new_func.func_id = func_id;
                new_func.start = timestamp;
                new_func.unuse_time = 0;
                func_stack.push_back(new_func);
            }
            else {  // pop
                func last_func = func_stack.back();
                int func_time = timestamp + 1 - last_func.start - last_func.unuse_time;
                funcs_time[func_id] += func_time;
                func_stack.pop_back();
                for (int i=0;i<func_stack.size();i++) {
                    func_stack[i].unuse_time += func_time;
                }
            }
        }
        return funcs_time;
    }
};
