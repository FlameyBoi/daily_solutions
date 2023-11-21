using namespace std;

#include <vector>
#include <string>

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int total = 0, n = garbage.size();
        bool G = false, P = false, M = false;
        for (string s : garbage)
            total += s.length();
        for (int i = n - 1; i >= 0; i--)
        {
            if (G)
                total += travel[i];
            else if (garbage[i].find('G') != string::npos)
                G = true;
            if (P)
                total += travel[i];
            else if (garbage[i].find('P') != string::npos)
                P = true;
            if (M)
                total += travel[i];
            else if (garbage[i].find('M') != string::npos)
                M = true;
        }
        return total;
    }
};