#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long long sumSkill = accumulate(skill.begin(), skill.end(), 0LL);
        long long prevWizardDone = sumSkill * mana[0];
        int n = skill.size(), m = mana.size();
        for (int j = 1; j < m; j++) {
            long long prevPotionDone = prevWizardDone;
            for (int i = n - 2; i >= 0; i--) {
                prevPotionDone -= 1LL * skill[i + 1] * mana[j - 1];
                prevWizardDone = max(prevPotionDone, prevWizardDone - 1LL * skill[i] * mana[j]);
            }
            prevWizardDone += sumSkill * mana[j];
        }
        return prevWizardDone;
    }
};


int main() {
    vector<int> skill = {1,5,2,4};
    vector<int> mana = {5,1,4,2};
    Solution solve;
    cout << solve.minTime(skill, mana);
}