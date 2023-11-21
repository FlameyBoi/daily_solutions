using namespace std;

#include <vector>

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int max = 0;
        int n = nums.size();
        for (int num : nums)
            if (num > max) max = num;
        int* count = new int[max + 1] {0};
        for (int num : nums)
        {
            count[num]++;
        }
        for (int i = 1; i <= max; i++)
        {
            count[i] += count[i - 1];
        }
        int prev = 0;
        for (int i = 0; i <= max; i++)
        {
            int next = count[i];
            while (count[i] > prev)
            {
                nums[--count[i]] = i;
            }
            prev = next;
        }
        delete[] count;
        unsigned int steps = 0;
        unsigned int total = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                steps++;
            }
            total += steps;
        }
        return total;
    }
};