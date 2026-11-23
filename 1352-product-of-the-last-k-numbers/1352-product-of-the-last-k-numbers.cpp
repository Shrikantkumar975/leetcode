class ProductOfNumbers {
public:
    int lastZero;
    vector<long long> prefPrd;

    ProductOfNumbers() {
        prefPrd.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            prefPrd.clear();
            prefPrd.push_back(1);
        }else{
            prefPrd.push_back(prefPrd.back()*num);
        }
    }
    
    int getProduct(int k) {
        int n=prefPrd.size();

        if(k>=n) return 0;

        return prefPrd[n-1]/prefPrd[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */