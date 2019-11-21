class FenwickTree {
    vector<int> ft;
    public:
    FenwickTree(int n) { ft.assign(n+1, 0); }
    int getSum(int b) {
        int ret = 0;
        while(b) {
            ret += ft[b]; 
            b -= (b & -b);
        }
        return ret;
    }
    
    void add(int pos,int val) {
        while(pos <= ft.size()) {
            ft[pos] += val;
            pos += (pos & -pos);
        }
    }

    void add (int a,int b, int val){
        add(a,val);
        add(b+1,-val);
    }

    int getSum(int a,int b) {
        return getSum(b) - getSum(a - 1);
    }
    
    int getValue(int pos) {
        getSum(pos);
    }
    
    void setValue(int pos,int val) {
        add(pos, val - getValue(pos));
    }
};