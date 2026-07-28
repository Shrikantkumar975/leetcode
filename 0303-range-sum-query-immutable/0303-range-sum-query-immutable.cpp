class NumArray {
public:
    int n;
    vector<int> segTree;
    NumArray(vector<int>& nums) {
        n= nums.size();
        segTree.resize(4*n);

        build(nums,0,0,n-1);
    }

    void build(vector<int> &nums,int i,int l,int r){
        if(l==r){
            segTree[i]=nums[l];
            return;
        }

        int mid = (l + r)/2;

        build(nums,2*i+1,l,mid);
        build(nums,2*i+2,mid+1,r);

        segTree[i]= segTree[2*i+1] + segTree[2*i+2];
    }

    int segSum(int i,int l,int r,int left,int right){
        // if(l==r){
        //     return segTree[i];
        // }
        if(l > right || r < left){
            return 0;
        }
        
        if(l>=left && r<=right){
            return segTree[i];
        }

        int mid = (l+r)/2;

        return segSum(2*i+1,l,mid,left,right) + 
        segSum(2*i+2,mid+1,r,left,right);
    }
    
    int sumRange(int left, int right) {
        return segSum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */