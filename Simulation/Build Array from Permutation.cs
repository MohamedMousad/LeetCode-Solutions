public class Solution {
    public int[] BuildArray(int[] nums) {
        int [] arr = new int[nums.Length];
        for (int i = 0 ; i < nums.Length ; i++){
            arr[i] = nums[nums[i]];
        }
        return arr;
    }
}