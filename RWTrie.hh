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

    //static node* copia_node(node* m) { 
        /* Pre: cert */
        /* Post: el resultat �s NULL si m �s NULL;
        en cas contrari, el resultat apunta al node arrel 
        d'una jerarquia de nodes que �s una c�pia de la
        jerarquia de nodes que t� el node apuntat per m com a arrel */
        /*node* n;
        if (m==NULL) n=NULL;
        else {
            n = new node;
            n->info = m->info;

            n->segE = copia_node(m->segE);
            n->segD = copia_node(m->segD);
        }
        return n;
    }*/

    //static void esborra_node(node* m) {  
        /* Pre: cert */
        /* Post no fa res si m �s NULL; en cas contrari,
        allibera espai de tots els nodes de la 
        jerarquia que t� el node apuntat per m com a arrel */
        /*if (m != NULL) {
        esborra_node(m->segE);
        esborra_node(m->segD);
        delete m;
        }
    }*/

public:

    RWTrie() {
        raiz = NULL;
    }

    RWTrie(string key) {
        insert()
    }

    T get(const string &x) {
        
        return findInRwtrie(x); 
    }

    bool contain(const string &x) {

        return (findInRwtrie(x) != T());
    }

    bool contains(string key) {
        return getValue(key) != NULL;
    }

    //T getValue(string key);

    /*Arbre() {
        primer_node= NULL;
    }

    Arbre(const Arbre& original) {
        if (this != &original)     
        primer_node = copia_node(original.primer_node);
    }

    ~Arbre() {
        esborra_node(primer_node);
    }

    Arbre& operator=(const Arbre& original) {
        if (this != &original) {
        esborra_node(primer_node);
        primer_node = copia_node(original.primer_node);
        }
        return *this;
    }

    void a_buit() {
        esborra_node(primer_node);
        primer_node= NULL;
    }        

    void plantar(const T &x, Arbre &a1, Arbre &a2) {
        if (this != &a1 and this != &a2) {
        if (primer_node==NULL) {
            node* aux;
            aux= new node;
            aux->info= x;
            aux->segE= a1.primer_node;
            if (a1.primer_node == a2.primer_node) aux->segD= copia_node(a1.primer_node);
            else  aux->segD= a2.primer_node;
            primer_node= aux;
            a1.primer_node= NULL;
            a2.primer_node= NULL;
        }
        else
            throw PRO2Excepcio ("El p.i. de plantar ha de ser buit a la crida");
        }
        else
        throw PRO2Excepcio ("El p.i. de plantar no pot coincidir amb els parametres");
    }


    void fills (Arbre &fe, Arbre &fd) {
        if (primer_node!=NULL and fe.primer_node==NULL
            and fd.primer_node==NULL) {
        if (&fe != &fd) {       
            node* aux;
            aux= primer_node;
            fe.primer_node= aux->segE;
            fd.primer_node= aux->segD;
            primer_node= NULL;
            delete aux;
        }
        else 
            throw PRO2Excepcio 
                ("Els dos parametres de fills no poden coincidir");
        }
        else if (primer_node==NULL)
        throw PRO2Excepcio ("Un arbre buit no te fills");
        else   
        throw PRO2Excepcio 
            ("Els dos parametres de fills han de ser buits a la crida");
    }

    T arrel() const {
        if (primer_node!=NULL)
        return primer_node->info;    
        else
        throw PRO2Excepcio ("Un arbre buit no te arrel");
    }

    bool es_buit() const {
        return (primer_node==NULL);
    }*/

};

#endif
