public class Solution {
    public int[] ConcatWithReverse(int[] nums) {
        int [] res = new int[nums.Length*2];
        for (int i = 0 ; i < nums.Length ; i++){
            res[i] = (nums[i]);
        }
        for (int i = nums.Length - 1 , j = 0 ; i >= 0 ; i--, j++){
            res[nums.Length + j] = (nums[i]);
        }
        return res;
    }
}