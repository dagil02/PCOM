class SegmentTree {
    vector<int> st;
    int tam; // Número de hojas que manejamos
    public:
    SegmentTree(intmaxN) {
        st.reserve(4 * maxN + 10);
    }

    int query(inta,intb) {
        return query(1, 0, tam-1, a, b);
    }
    
    int query(intvertex,intL,intR,inti,intj) {
        if(i > R || j < L) {
            return0;
        }
        
        if(L >= i && R <= j)// Segmento completamente dentro de la consulta
            return st[vertex];
            
        intmitad = (L + R) / 2;
        return query(2*vertex, L, mitad, i, j) + query(2*vertex+1, mitad+1, R, i, j);
    }


    void update(int pos,int newVal) {
        update(1, 0, tam-1, pos, newVal);
    }
    
    void update(int vertex,int l,int r,int pos,int newVal) {
        if((pos < l) || (r < pos)) return;
        if(l == r) {
            st[vertex] = newVal;
            return;
        }
        int m = (l+r) / 2;
        
        if((l <= pos) && (pos <= m)) update(2*vertex, l, m, pos, newVal);
        else update(2*vertex + 1, m+1, r, pos, newVal);
        
        st[vertex] = st[2*vertex] + st[2*vertex + 1];
    }


    void build(int *values,int n) {
        tam = n;
        build(values, 1, 0, n-1);
    }
    void build(int *values,int p,int l,int r) {
        if(l == r) {
            st[p] = values[l];
            return;
        }
        int m = (l+r)/2;
        build(values, 2*l, l, m);
        build(values, 2*l+1, m+1, r);
        st[p] = st[2*l]+st[2*l+1];
    }

}