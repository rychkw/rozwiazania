#include "SmartTree.h"

namespace datastructures{
    unique_ptr <SmartTree> CreateLeaf(int value){
        unique_ptr <SmartTree> ptr = make_unique<SmartTree>();
        ptr -> value = value;
        ptr -> left = NULL;
        ptr -> right = NULL;
        return ptr;
    }

    unique_ptr <SmartTree> InsertLeftChild(unique_ptr <SmartTree> tree, unique_ptr <SmartTree> left_subtree){
        if (tree -> left == NULL){
            tree -> left = move(left_subtree);
        }
        return tree;
    }

    unique_ptr <SmartTree> InsertRightChild(unique_ptr <SmartTree> tree, unique_ptr <SmartTree> right_subtree){
        if (tree -> right == NULL){
            tree -> right = move(right_subtree);
        }
        return tree;
    }

    void PrintTreeInOrder(const unique_ptr<SmartTree> &unique_ptr, ostream *out){
        if (unique_ptr == NULL){
            return;
        }
        else {
            PrintTreeInOrder(unique_ptr -> left, out);
            *out << unique_ptr -> value << ", ";
            PrintTreeInOrder(unique_ptr -> right, out);
        }
    }

    string DumpTree(const unique_ptr<SmartTree> &tree)
    {
        string text_result = "";
        text_result += "[" + to_string(tree->value) + " ";
        if(tree -> left != NULL) {
            text_result += DumpTree(tree->left);
        }
        else{
            text_result += "[none]";
        }
        text_result += " ";

        if(tree -> right != NULL){
            text_result += DumpTree(tree->right);
        }
        else {
            text_result += "[none]";
        }
        text_result += "]";

        return text_result;
    }

    void PartTree(int nawiasy, const string &tree, int &i);

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){

        std::unique_ptr <SmartTree> tree_new = CreateLeaf(0);
        std::string tmp="";
        int i=1;
        int nawiasy;
        int j;

        while(tree[i] != ' ' && tree[i] != ']'){
            tmp += tree[i];
            i++;
        }

        if(tmp == "none"){
            return 0;
        }
        else{
            tree_new -> value = stoi(tmp);
        }

        i += 1;
        j = i;
        nawiasy = 1;

        PartTree(nawiasy, tree, i);

        tree_new -> left = RestoreTree(tree.substr(j,i-1));

        j = i + 2;
        i += 2;
        nawiasy = 1;

        PartTree(nawiasy, tree, i);

        tree_new -> right = RestoreTree(tree.substr(j,i-1));

        return tree_new;
    }

    void PartTree(int nawiasy, const string &tree, int &i) {
        while(nawiasy > 0){
            i++;
            if(tree[i]=='[') nawiasy++;
            if(tree[i]==']') nawiasy--;
        }
    }
}
