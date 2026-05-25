class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
    vector <long long> scores(score.size());
    vector <string> ranks(score.size());
    for (long long i = 0 ; i < score.size() ; i++)
    {
        scores[i] = score[i];
    }
    sort (score.begin() , score.end());
    for (long long i = 0 ; i < score.size() ; i++)
    {
        long long k =(lower_bound(score.begin() , score.end() , scores[i]) - score.begin());
        if (k == score.size()-1)
        {
            ranks[i] = "Gold Medal";
        }
        else if (k == score.size()-2)
        {
            ranks[i] = "Silver Medal";
        }
        else if (k == score.size()-3)
        {
            ranks[i] = "Bronze Medal";
        }
        else
        {
            long long x = score.size() - k;
            ranks[i] = to_string(x);
        }
    }
        return ranks;
    }
};