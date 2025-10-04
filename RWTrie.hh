#ifndef RWTRIE_HH
#define RWTRIE_HH

#include <vector>
#include <string>

using namespace std;

template <typename T> class RWTrie { 

private:     

    static const int R = 256; // extended ascii

    struct node {
        T valor;
        vector<node*> pHijos; // vector de R punteros de los hijos
        int nHijos;
    };

    node* raiz;

    static T recursiveFind(node* actNode, const string &key, int i);

    static node* insertNode(node* current, const string &key, const T &val, int i);

    static node* deleteNode(node* n, const string &key, int i);

public:

    RWTrie() {
        raiz = new node();
        raiz->pHijos.resize(R);
        raiz->nHijos = 0;
    }

    void insert(const string &key, const T &val);

    T getValue(const string &key);

    bool contain(const string &key);

    void remove(const string &key);

};

#endif
