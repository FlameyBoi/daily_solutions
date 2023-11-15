using namespace std;

#include <vector>

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        int* count = new int[n];
        memset(count, 0, sizeof(int) * n);
        for (auto num : arr)
        {
            int norm = (n < num) ? n : num;
            count[norm - 1]++;
        }
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            int norm = (count[i] > i + 1) ? i + 1 : count[i];
            max = (max + norm > i + 1) ? i + 1 : max + norm;
        }
        return max;
    }
};