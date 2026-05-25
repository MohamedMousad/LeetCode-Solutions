class Solution {
public:
    static int triangleNumber(vector<int>& nums) {
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
        sort(nums.begin(), nums.end());
        short n=nums.size(); int ans=0;
        for(int i=2; i<n; i++){
            short l=0, r=i-1;
            while(l<r){
                if(nums[l]+nums[r]>nums[i]){
                    ans+=r-l;
                    r--;
                }
                else l++;
            }
        }
        return ans;
    }
};