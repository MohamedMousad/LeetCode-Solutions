class Solution {
public:
    int minLights(vector<int>& lights) {
        vector<int> is_light(lights.size() + 5 , 0);
        for (int i = 0 ; i < lights.size() ; i++){
            if (lights[i] != 0){
                is_light[max(i - lights[i] , (int)(0))]++;
                is_light[min(i + lights[i] + 1 , (int)(is_light.size() - 1))]--;
            }
        }
        for (int i = 1 ; i < lights.size() ; i++){
            is_light[i]+=is_light[i-1];
        }
        int ans = 0 ;
        for (int i = 0 ; i < lights.size() ;){
            int cnt = 0;
            if (is_light[i] != 0){
                i++;
                continue;
            }
            while (i < lights.size() && is_light[i] == 0){
                cnt++;
                i++;
            }
            if (cnt)
                ans +=((cnt/3 )+ ((cnt % 3 )!= 0 ));
        }
        return ans;
    }
};