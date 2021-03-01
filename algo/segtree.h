//
// Created by Дима Шестаков on 24.02.2021.
//

#ifndef ALGO_SEGTREE_H
#define ALGO_SEGTREE_H


#include<vector>


class seg_tree{    //This data structure helps us to work with intervals in arrays
private:
    std::vector<int> tree_s;    //In tnis implementation we keep our segment tree in array
    std::vector<int> tree_max;
    std::vector<int> tree_min;
public:
    seg_tree(size_t size){
        tree_s.resize(size*4);
        tree_max.resize(size*4);
        tree_min.resize(size*4);
    }
    void build(std::vector<int>& a, int tl, int tr, int v) {
        if(tl == tr){
            tree_s[v] = a[tl];
            tree_max[v] = a[tl];
            tree_min[v] = a[tl];
        }

        else{
            int k = (tl+tr)/2;
            build(a, tl, k, v*2);
            build(a, k+1, tr, v*2+1);
            tree_s[v] = tree_s[2*v]+tree_s[2*v+1];
            tree_max[v] = std::max(tree_max[2*v],tree_max[2*v+1]);
            tree_min[v] = std::min(tree_min[2*v],tree_min[2*v+1]);
        }
    }
    int sum(int v, int tl , int tr, int l, int r){
        if(l > r)
            return 0;
        if(l == tl && r == tr)
            return tree_s[v];
        int k = (tl+tr)/2;
        return sum(v*2, tl, k, l, std::min(k, r)) + sum(v*2+1, k+1, tr, std::max(l, k+1), r);
    }
    int max(int v, int tl , int tr, int l, int r){
        if(l > r)
            return 0;
        if(l == tl && r == tr)
            return tree_max[v];
        int k = (tl+tr)/2;
        return std::max(max(v*2, tl, k, l, std::min(k, r)),max(v*2+1, k+1, tr, std::max(l, k+1), r));
    }
    int min(int v, int tl , int tr, int l, int r){
        if(l > r)
            return 0;
        if(l == tl && r == tr)
            return tree_min[v];
        int k = (tl+tr)/2;
        return std::min(min(v*2, tl, k, l, std::min(k, r)) , min(v*2+1, k+1, tr, std::max(l, k+1), r));
    }

    void update(int v, int tl, int tr, int pos, int val){
        if(tl == tr){
            tree_s[v] = val;
            tree_max[v] = val;
            tree_min[v] = val;
        }

        else{
            int k = (tl+tr)/2;
            if(pos < k)
                update(v*2, tl, k, pos, val);
            else
                update(v*2+1, k+1, tr, pos, val);
            tree_s[v] = tree_s[v*2]+tree_s[v*2+1];
            tree_max[v] = std::max(tree_max[v*2],tree_max[v*2+1]);
            tree_min[v] = std::min(tree_min[v*2],tree_min[v*2+1]);
        }
    }
    void print_min(){
        for(int& i : tree_min)
            cout << i << " ";
    }
};



//subinterval with max sum

struct Data{
    int sum, pref, suff, ans;
};

Data combine(Data l, Data r){
   Data res;
   res.sum = l.sum+r.sum;
   res.pref = std::max(l.pref, l.sum+r.pref);
   res.suff = std::max(r.suff, r.sum+l.suff);
   res.ans = std::max(std::max(l.ans, r.ans), l.suff+r.pref);
   return res;
}

Data make_data(int val){
    Data res;
    res.sum = val;
    res.pref = res.suff = res.ans = std::max(val, 0);
    return res;
}

class mod_tree{
private:
    std::vector<Data> tree;
public:
    mod_tree(std::vector<int>& v){
        tree.resize(v.size()*4);
    }
    void build(std::vector<int>& a, int tl, int tr, int v){
        if(tl == tr)
            tree[v] = make_data(a[tl]);
        else{
            int m = (tl+tr)/2;
            build(a, tl, m, v*2);
            build(a, m+1, tr, v*2+1);
            tree[v] = combine(tree[2*v], tree[2*v+1]);
        }
    }
    void update(int v, int tl, int tr, int val, int pos){
        if(tl == tr)
            tree[v] = make_data(val);
        else{
            int m = (tl+tr)/2;
            if(pos < m)
                update(v*2, tl, m, val, pos);
            else
                update(v*2+1, m+1, tr, val, pos);
            tree[v] = combine(tree[2*v+1], tree[2*v]);
        }
    }

    Data query(int v, int tl, int tr, int l, int r){
        if(tl == l && r == tr)
            return tree[v];
        int m = (tl+tr)/2;
        if(r < m)
            return query(2*v, tl, m, l, r);
        if(l > m)
            return query(2*v+1, m+1, tr, l, r);
        return combine(query(2*v, tl, m, l, m), query(2*v+1, m+1, tr, m+1, r));
    }
};
#endif //ALGO_SEGTREE_H
