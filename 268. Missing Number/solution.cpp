#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;

        for (int num : nums) {
            sum -= num;
        }

        return sum;
    }

};

int main() {
    Solution solver;

    vector<int> test = {3, 0, 1};
    int result = solver.missingNumber(test);
    cout << result << endl;

}
