#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update>// set

typedef tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
#define ll long long
void myerase(ordered_set &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_multiset sorted;
        int ans = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            ans+=( sorted.size() - sorted.order_of_key((long long)(nums[i])*2 + 1) );
            sorted.insert(nums[i]);
        }
        return ans;
    }
};