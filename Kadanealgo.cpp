//for finding maximum subarray sum
int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = 0;
        for(int i : nums)
        {
            sum += i;
            maxi = max(sum, maxi);
            if(sum < 0)
            sum = 0;
        }
        return maxi;
    }
