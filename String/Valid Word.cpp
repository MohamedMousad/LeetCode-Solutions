class Solution {
public:
    bool isValid(string word)
    {
        bool vowels = 0, consonants = 0;
        if (word.length() < 3)
            return false;
        for (int i = 0; i < word.length(); i++)
        {
            if ((word[i] - '0' >= 0 && word[i] - '0' <= 9) || isalpha(word[i]))
            {
                if (isalpha(word[i]))
                {
                    char c = tolower(word[i]);
                    if (c == 'a' || c == 'e' ||c == 'i' ||c == 'o' ||c == 'u')
                        vowels = true;
                    else 
                        consonants = true;
                }
            }
            else return false;
        }
        return vowels && consonants;
    }
};