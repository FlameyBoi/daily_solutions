
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        vector<int> out;
        int first;
        for (auto pair : adjacentPairs)
        {
            mp[pair[0]].push_back(pair[1]);
            mp[pair[1]].push_back(pair[0]);
        }
        for (auto ent : mp)
        {
            if (ent.second.size() == 1)
            {
                first = ent.first;
                break;
            }
        }
        out.push_back(first);
        int prev = first;
        int next = mp[first][0];
        while (1)
        {
            if (mp[next].size() == 1)
                break;
            out.push_back(next);
            int temp = next;
            if (prev == mp[next][0])
                next = mp[next][1];
            else
                next = mp[next][0];
            prev = temp;
        }
        out.push_back(next);
        return out;
    }
};