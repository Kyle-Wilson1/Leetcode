#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Solution {
public:

    Solution() = default;

    int maxOfTwo(int, int);

    int maxSubArray(vector<int> &nums) {
        int pre = 0, now = 0, maxAnswer = -2147483647;
        for (int i = 0; i < nums.size(); i++) {

            if (pre > 0)
                now = pre + nums[i];
            else
                now = nums[i];
            maxAnswer = maxOfTwo(maxAnswer, now);
            pre = now;
        }
        return maxAnswer;
    }
};

int Solution::maxOfTwo(int a, int b) {
    return a > b ? a : b;
}

int main() {

    ifstream fin("a.in");
    ofstream fout("a.out");

    int i = 0, n;
    vector<int> nums(10000, 0);

    while (fin >> n) {
        nums[i++] = n;
    }

    auto *solution = new Solution();
    fout << solution->maxSubArray(nums);

    fin.close();
    fout.close();
    return 0;
}