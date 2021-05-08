vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        n=nums.size();
        vector<long long int>output;
        if(n<=1){
            output.push_back(1);
            return output;
        }
        long long int product=1;
        for(int i=0;i<n;i++){
            product*=nums[i];
            output.push_back(product);
        }
        output[n-1]=output[n-2];
        product=nums[n-1];
        for(int i=n-2;i>=1;i--){
            output[i]=output[i-1]*product;
            product*=nums[i];
        }
        output[0]=product;
        return output;
    }
