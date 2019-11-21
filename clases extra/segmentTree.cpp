class SegmentTree {
    vector<int> st;
    vector<int> lazy;
    int tam; // Número de hojas que manejamos
    public:
    SegmentTree(int maxN) {
        st.reserve(4 * maxN + 10);
    }

    int query(int a,int b) {
        return query(1, 0, tam-1, a, b);
    }
    
    int query(int vertex,int L,int R,int i,int j) {
        pushLazyUpdate(vertex, L, R);
        if(L >= i && R <= j)// Segmento completamente dentro de la consulta
            return st[vertex];
        
        int mitad = (L + R) / 2;
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

    void updateRange(int vertex,int l,int r,int a,int b,int op) {
        // Resolvemos posibles operaciones pendientes
        pushLazyUpdate(vertex, l, r);
        if((pos < l) || (r < pos)) return;
        // ¿Intervalo afectado por completo?
        if((a <= L) && (R <= b)) {
            // Nos aplicamos la operaci ́on y propagamos la
            // pereza a los hijos. Para evitar copiar/pegar,
            // lo hacemos aplic ́andonos la pereza, y luego
            // resolvi ́endola
            setLazyUpdate(vertex, op);
            pushLazyUpdate(vertex, L, R);
            return;
        }

        // Intervalo no afectado por completo. No podemos
        // ser perezosos. Aplicamos la operaci ́on en
        // los hijos
        int m = (L + R) / 2;
        updateRange(2*vertex, L, m, a, b, op);
        updateRange(2*vertex + 1, m+1, R, a, b, op);
        // Combinamos
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

    void setLazyUpdate(int vertex, int value) {
        // Mezclamos
        // Importante +=: el nodo podr ́ıa tener
        // otras operaciones pendientes anteriores
        lazy[vertex] += op;
    }

    void pushLazyUpdate(int vertex, int L, int R) {
        st[vertex] += (R - L + 1)*lazy[vertex];
            if (L != R) {// Tenemos hijos
            int m = (L + R) / 2;
            setLazyUpdate(2*vertex, L, m);
            setLazyUpdate(2*vertex+1, m+1, R);
            }
        lazy[vertex] = 0;
    }

}