class Solution {
public:
    int rec(int i  , deque<int>& freq , int k){
        if (freq.back() - freq[i] <= k)
            return 0;
        int ch1 = rec(i+1 , freq, k ) + freq[i];
        int sum = 0;
        for (int j = 25 ; j >= i ; j--){
            if (freq[j] - freq[i] <= k)
                break;
            else
                sum+=(freq[j] - freq[i] - k);
        }
        int ch2 = sum;
        return min(ch1 , ch2);
    }
    int minimumDeletions(string word, int k) {
        deque<int> freq(26 , 0); 
        for (int i = 0 ; i < word.length() ; i++)
            freq[word[i] - 'a']++;
        sort(freq.begin() , freq.end());
        int sum = rec( 0 , freq ,k);
        return sum;
    }
};