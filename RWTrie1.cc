#include "RWTrie.hh"

template<class T> int RWTrie<T>::recursiveFind(RWTrie<T>::node* raiz, int index, const string &x) {

    if(index != x.length() - 1) {
        // before verifying the  last character 
        node* next = raiz[x[index]-'0'];
        if(next != NULL)return recursiveFind(next,index+1,x);
        else return T();
    }
    else {
        // case we are verifying the last character
        if(raiz != NULL) return raiz->value;
        else return T();
    }
}

template<class T> T RWTrie<T>::getValue(const string &x) {
    if (raiz->phijos[x[0] - '0'] == NULL) return T();
    int result;
    int index = 0;
    for (node* nextNode : raiz->phijos) {
        if (nextNode->info == x[index]) {
            result = recursiveFind(nextNode,index+1,x);
            
        } 
    }
    return result;
}

template<class T> bool RWTrie<T>::contains(string key) {
    return getValue(key) != NULL;
}