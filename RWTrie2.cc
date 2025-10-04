#include "RWTrie.hh"

template <typename T> typename RWTrie<T>:: node* RWTrie<T>::deleteNode(node* n, const string &key, int i) {
    if(i == key.length()) n->valor = NULL;
    else if(n->pHijos[key[i]] != nullptr){
        n->pHijos[key[i]] = delete_key(n->pHijos[key[i]], key, i + 1);
        if(n->pHijos[key[i]] == nullptr) n->nHijos--;
    }
    if(n->valor == NULL and n->nHijos == 0){
        delete n; 
        return nullptr;
    } 
    return n;
}

template <typename T> void RWTrie<T>::remove(const string &key){
    raiz = deleteNode(raiz, key, 0);
}