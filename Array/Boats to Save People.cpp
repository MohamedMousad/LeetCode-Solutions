class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        long long sum = 0 , count = 0 ; 
        sort (people.begin() , people.end());
        int i = 0 , j = people.size()-1;
        while (true)
        {
            if (j < i )
            {
                return count;
            }
            if ( j == i)
            {
                count++;
                return count;
            }
            if (people[i]+people[j] <= limit)
            {
                i++;
            }
            j--;
            count++;
        }
        return count ;
    }
};