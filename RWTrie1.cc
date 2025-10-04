#include "RWTrie.hh"

T get(const string &x) {
    
    return findInRwtrie(x); 
}

bool contains(string key) {
    return getValue(key) != NULL;
}