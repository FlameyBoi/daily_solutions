using namespace std;

#include <vector>

class Solution {
public:
    int maxFrequency_counting(vector<int>& nums, int k) {
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
        unsigned int cur_cost = 0;
        int max_freq = 0;
        unsigned int left = 0;
        prev = nums[0];
        for (int i = 0; i < n; i++)
        {
            cur_cost = cur_cost + (nums[i] - prev) * (i - left);
            if (cur_cost > k)
            {
                cur_cost -= (nums[i] - nums[left]);
                left++;
            }
            prev = nums[i];
            if (i - left + 1 > max_freq) max_freq = i - left + 1;
        }
        return max_freq;
    }

    int maxFrequency_radix(vector<int>& nums, int k) {
        int n = nums.size();
        radix(nums);
        unsigned int cur_cost = 0;
        int max_freq = 0;
        unsigned int left = 0;
        int prev = nums[0];
        for (int i = 0; i < n; i++)
        {
            cur_cost = cur_cost + (nums[i] - prev) * (i - left);
            if (cur_cost > k)
            {
                cur_cost -= (nums[i] - nums[left]);
                left++;
            }
            prev = nums[i];
            if (i - left + 1 > max_freq) max_freq = i - left + 1;
        }
        return max_freq;
    }

#define BITS 0xFFFF

    void radix(vector<int>& nums)
    {
        int count[0x10000] = { 0 };
        int n = nums.size();
        int* out = new int[n];
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
        delete[] out;
    }
};