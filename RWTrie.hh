#ifndef RWTRIE_HH
#define RWTRIE_HH

#include <vector>

using namespace std;

template <typename T> class RWTrie { 

private:     

    const int R = 256; // extended ascii

    struct node {
        T valor;
        vector<node*> phijos(R); // vector de R punteros de los hijos
    };

    node* raiz;

    int recursiveFind(node* raiz, int index, const string &x);


    static int findInRwtrie(const string &x);

public:

    RWTrie() {
        raiz = NULL;
    }

    RWTrie(string key) {
        //insert()
    }

    T get(const string &x);

    bool contains(string key);

    node* delete_key(node* n, string key);

    //T getValue(string key);

    node* delete_key(node* n, string key);

};

#endif
