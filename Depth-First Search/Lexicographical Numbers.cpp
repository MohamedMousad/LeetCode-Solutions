class Solution {
public:
vector<int> vec;
void rec(int n, int limit , bool flag = 0)
{
    if (n > limit)
        return;
    if (flag != 0)
        vec.push_back(n);
    if (flag == 0){
        for (int i = 0; i < 9; i++)
        {
            rec((int)(n + i), limit , 1);
        }
    }
    else {
        for (int i = 0; i <= 9; i++)
        {
            rec((int)(n * 10 + i), limit , 1);
        }
    }
    return;
}
    vector<int> lexicalOrder(int n) {
        rec(1 , n);
        return vec;
    }
};