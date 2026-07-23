public class Solution {
    public IList<int> FindWordsContaining(string[] words, char x) {
        List<int> res = new List<int>();
        for (int i = 0 ; i < words.Length ; i++){
            foreach(var ch in words[i]){
                if (ch == x){
                    res.Add(i);
                    break;
                }
            }
        }
        return res;
    }
}