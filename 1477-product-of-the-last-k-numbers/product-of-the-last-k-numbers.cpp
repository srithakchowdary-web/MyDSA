class ProductOfNumbers {
public:
    vector<int>  product;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num==0) product.clear();
        else if(product.size()==0){
            product.push_back(num);
        }
        else{
            int val = product.back()*num;
            product.push_back(val); 
        }
    }
    
    int getProduct(int k) {
        if(k > product.size()) return 0;
        else if(k == product.size()) return product.back();
        return  product.back() / (product[product.size()-k-1]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */