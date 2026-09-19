#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result=0;

        for (int i=0; i<n; i++) {
            result ^= nums[i] ^ (i+1);
        }

        return result;
    }

};

int main() {
    Solution solver;

    vector<int> test = {3, 0, 1};
    int result = solver.missingNumber(test);
    cout << result << endl;

}
