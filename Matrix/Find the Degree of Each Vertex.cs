public class Solution {
    public int[] FindDegrees(int[][] matrix) {
        int [] res = new int[matrix.Length];
        for (int i = 0 ; i < matrix.Length ; i++){
            int sum = 0;
            for (int j = 0 ; j < matrix.Length ; j++){
                sum+=matrix[i][j];   
            }
            res[i]+=sum;
        }
        return res;
    }
}