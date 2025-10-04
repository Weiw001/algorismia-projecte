#include "RWTrie.hh"

template <typename T> typename RWTrie<T>:: node* RWTrie<T>::delete_key(node* n, string key) {
    if(n == nullptr) return nullptr;
    else if(key.empty()) n->info = NULL;
    //recursively delete from children
    else n->phijos[key[0]] = delete_node(n->phijos[key[0]], key.substr(1));
    
    //if current node still has value, keep it
    if(n->info != NULL) return n;
    
    //if current node is prefix for another key, keep it
    for (auto child : n->phijos) {
        if (child != nullptr) return n;
    }

    //if current node doesn't have value and is not prefix, delete it
    delete n;
    return nullptr;
}