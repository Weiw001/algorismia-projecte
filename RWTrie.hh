#ifndef RWTRIE_HH
#define RWTRIE_HH

#include <vector>
#include <string>

using namespace std;

template <typename T> class RWTrie { 

private:     

    const int R = 256; // extended ascii

    struct node {
        T valor;
        vector<node*> phijos; // vector de R punteros de los hijos
    };

    node* raiz;

    static int recursiveFind(node* raiz, int index, const string &x);

    static node* put(node* current, const string &key, const T &val, int i);

public:

    RWTrie() {
        raiz = new node();
        raiz->phijos.resize(R);
    }

    RWTrie(const string &key, const T &val) {
        insert(key, val);
    }

    void insert(const string &key, const T &val);

    T getValue(const string &x);

    bool contains(string key);

    node* delete_key(node* n, string key);

};

#endif
