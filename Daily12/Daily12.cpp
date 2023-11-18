using namespace std;

#include <vector>

class Solution {
public:
    int* out;
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        out = new int[n];
        int max = 0;
        radix(nums);
        for (int i = 0; i < n; i++)
        {
            max = std::max(max, nums[i] + nums[n - 1 - i]);
        }
        delete[] out;
        return max;
    }

#define BITS 0xFFFF

    inline void radix(vector<int>& nums)
    {
        int count[0x10000] = { 0 };
        int n = nums.size();
        int shift = 0;
        for (int num : nums)
        {
            count[(num >> shift) & BITS]++;
        }
        for (int i = 1; i < 0x10000; i++)
        {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            out[count[(nums[i] >> shift) & BITS] - 1] = nums[i];
            count[(nums[i] >> shift) & BITS]--;
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = out[i];
        }
        shift = 16;
        memset(count, 0, sizeof(int) * 0x10000);
        for (int num : nums)
        {
            count[(num >> shift) & BITS]++;
        }
        for (int i = 1; i < 0x10000; i++)
        {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            out[count[(nums[i] >> shift) & BITS] - 1] = nums[i];
            count[(nums[i] >> shift) & BITS]--;
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = out[i];
        }
    }
};