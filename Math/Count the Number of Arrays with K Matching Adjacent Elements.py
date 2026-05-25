class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        return math.comb(n-1, k)*m*pow(m-1 , n-1-k , (MOD:= pow(10 , 9) + 7))%MOD
        