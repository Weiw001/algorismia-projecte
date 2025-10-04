#include "RWTrie.hh"

template <typename T> 
typename RWTrie<T>::node* RWTrie<T>::put(node* current, const string &key, const T &val, int i) {
    if(current == nullptr) current = new node();
    if(i == key.length()) current->valor = val;
    else current->phijos[key[i]] = put(current->phijos[key[i]], key, val, i+1);
    return current;

}

template <typename T>
void RWTrie<T>::insert(const string &key, const T &val){
    raiz = put(raiz, key, val, 0);
}