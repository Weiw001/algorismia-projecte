#include "RWTrie.hh"

template<typename T> T RWTrie<T>::recursiveFind(node* actNode, const string &key, int i) {
    if(actNode == nullptr) return NULL;
    if(i == key.length()) return actNode->valor;
    return recursiveFind(actNode->pHijos[key[i]], key, i+1);
}

template<typename T> T RWTrie<T>::getValue(const string &key) {
    return recursiveFind(raiz, 0, key);
}

template<typename T> bool RWTrie<T>::contain(const string &key) {
    return (getValue(key) != NULL);
}