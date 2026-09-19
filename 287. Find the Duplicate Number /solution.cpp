#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        int n = nums.size();

        while (slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;

        while (slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    Solution solver;

    vector<int> test = {1, 3, 4, 2, 2};
    int result = solver.findDuplicate(test);
    cout << result << endl;
}
