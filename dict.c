#include <assert.h>
#include "dict.h"
#include "key_value.h"

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

dict_t dict_empty() {
    dict_t dict = NULL;
    dict = (dict_t)malloc(sizeof(struct _node_t));
    dict->key = NULL;
    dict->value = NULL;
    assert(dict != NULL && dict_length(dict) == 0);
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    assert(dict != NULL && word != NULL && def != NULL);
    /* needs implementation */
    assert(value_eq(def, dict_search(dict, word)));
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {

    key_t def=NULL;
    assert(dict != NULL && word != NULL);
    
    if (strless(dict->key,word)) {
        def = dict_search(dict->left,word);
    }
    
    else {
        def = dict_search(dict->right,word);
    }
    
    assert((def==NULL && !dict_exists(dict, word)) || def != NULL);

    return def;
}

bool dict_exists(dict_t dict, key_t word) {

    assert(dict != NULL && word != NULL);
    bool res = false;
    
    if (string_eq(dict->key,word)) {
        res = true;
    }

    else{

        if(string_less(dict->key,word)){
            res = dict_exists(dict->left,word);
        }

        else {
            res = dict_exists(dict->left,word);
        }
    }

    return res;
}

unsigned int dict_length(dict_t dict) {

    assert(dict != NULL);

    unsigned int count = 1;

    if(dict->key != NULL){

        if (dict->left != NULL){
            count += dict_length(dict->left);
        }
        
        if (dict->right != NULL){
            count += dict_length(dict->right);
        }
    }

    return count;
}

dict_t dict_remove(dict_t dict, key_t word) {
    assert(dict != NULL && word != NULL);
    /* needs implementation */
    assert(dict != NULL && !dict_exists(dict, word));
    return dict;
}

dict_t dict_remove_all(dict_t dict) {
    assert(dict != NULL);
    /* needs implementation */
    assert(dict != NULL && dict_length(dict) == 0);
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
    assert(dict != NULL && file != NULL);
    /* needs implementation */
    assert(dict != NULL);
}

dict_t dict_destroy(dict_t dict) {
    assert(dict != NULL);
    /* needs implementation */
    assert(dict == NULL);
    return dict;
}
