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

    node raiz;

    int recursiveFind(node* raiz, int index, const string &x);

public:

    RWTrie() {
        raiz.phijos.resize(R);
    }

    RWTrie(string key) {
        //insert()
    }

    T getValue(const string &x);

    bool contains(string key);

    node* delete_key(node* n, string key);

};

#endif
