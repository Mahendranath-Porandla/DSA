#include <string>
#include <unordered_map>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> mp1, mp2;
        int ws = s1.size(), n = s2.size();

        for (char ch : s1) {
            mp1[ch]++;
        }
        int i = 0, j = 0;
        while (j < n) {
            mp2[s2[j]]++;

            if (j - i + 1 > ws) {
                mp2[s2[i]]--;
                if (mp2[s2[i]] == 0)
                    mp2.erase(s2[i]);
                i++;
            }

            if (mp1 == mp2)
                return true;

            j++;
        }

        return false;
    }
};
