#include "RWTrie.hh"

template <typename T> 
typename RWTrie<T>::node* RWTrie<T>::insertNode(node* current, const string &key, const T &val, int i) {
    if(current == nullptr){
        current = new node();
        current->phijos.resize(R);
        current->nHijos = 0;
    } 
    if(i == key.length()) current->valor = val;
    else{
        if(current->phijos[key[i]] == nullptr) current->nHijos++;
        current->phijos[key[i]] = putNode(current->phijos[key[i]], key, val, i+1);
    } 
    return current;
}

template <typename T>
void RWTrie<T>::insert(const string &key, const T &val){
    raiz = putNode(raiz, key, val, 0);
}