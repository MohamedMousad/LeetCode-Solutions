class Solution {
    int good(vector<int>& arr , int mid){
        if (mid == 0)
            return 1 ;
        if (mid == arr.size() - 1)
            return -1;
        if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            return 0;
        if (arr[mid] < arr[mid-1])
            return -1;
        else
            return 1;
    }
    int BS(vector<int>& arr){
        int l = 0 , r = arr.size() - 1;
        while(l <= r){
            int mid = l + ((r-l)>>1);
            int check = good(arr,mid); 
            if (check < 0 )
                r = mid - 1 ;
            else if (check > 0 )
                l = mid + 1 ;
            else 
                return mid;
        }
        return l;
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return BS(arr);
    }
};