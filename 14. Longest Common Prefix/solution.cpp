#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string first_str = strs[0];
        for (int i = 0; i < first_str.length(); i++) {
            char current_char = first_str[i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != current_char) {
                    return first_str.substr(0, i);
                }
            }
        }

        return first_str;
    }
};

int main() {
    Solution solver;

    vector<string> test = {"flower", "flow", "flight"};
    string res = solver.longestCommonPrefix(test);
    cout << res <<  endl;

}
