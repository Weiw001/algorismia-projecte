#include "RWTrie.hh"

int recursiveFind(node* raiz, int index, const string &x) {

    if(index != x.length()) {
        node* next = raiz[x[index]-'0'];
        if(next != NULL)return recursiveFind(next,index+1,x);
        else return T();
    }
    else {
        if(raiz != NULL) return raiz->value;
        else return T();
    }
}

static int findInRwtrie(const string &x) {
    if(phijos[x[0] - '0'] == NULL)return T();
    int result;
    int index = 0;
    for(node* nextNode:raiz->phijos) {
        if(nextNode->info == x[index]) {
            result = recursiveFind(nextNode,index+1,x);
            
        } 
    }
    return result;
}

T get(const string &x) {
    
    return findInRwtrie(x); 
}

bool contains(string key) {
    return getValue(key) != NULL;
}