class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long long> wizards(skill.size());
        for (int i = 0; i < mana.size() ; i++){
            long long min_start = 0 , sum = 0;
            for (int j = 0 ; j < wizards.size() ; j++ )
                min_start = max ( (long long)(wizards[j] - sum) , min_start) , sum+=(skill[j]*mana[i]);
            for (int j = 0 ; j < wizards.size() ; j++)
                wizards[j] = ( j > 0 ? wizards[j-1] : min_start ) + (long long)skill[j]*mana[i];
        }
        return wizards.back();
    }
};