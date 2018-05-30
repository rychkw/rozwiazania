#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <iostream>
#include <memory>
using namespace std;

namespace tree{
    template <class T>
    class Tree{
    public:
        T value;
        unique_ptr<Tree<T>> left;
        unique_ptr<Tree<T>> right;
        int size;
        int depth;

        Tree();
        Tree(T value_);

        int Depth();
        void Insert(T val);
        int Size(){ return size; }
        auto Value(){ return value; }
    };


    template <class T>
    Tree<T>::Tree() {
        depth= 0;
        size = 0;
        left = nullptr;
        right = nullptr;
    }


    template <class T>
    Tree<T>::Tree(T value_){
        size=1;
        depth=1;
        this->value = value_;
        left = nullptr;
        right = nullptr;
    }


    template <class T>
    void Tree<T>::Insert(T val) {
        if(val<value){
            if(left!=nullptr){
                left->Insert(val);
            }
            else{
                unique_ptr<Tree<T>> newNode = make_unique<Tree<T>>();
                newNode->value=val;
                newNode->left=nullptr;
                newNode->right=nullptr;
                left=std::move(newNode);
            }
        }

        else{
            if(right!=nullptr){
                right->Insert(val);
            }
            else{
                unique_ptr<Tree<T>> newNode = make_unique<Tree<T>>();
                newNode->value=val;
                newNode->left=nullptr;
                newNode->right=nullptr;
                right=std::move(newNode);
            }
        }
        size++;
    }


    template<class T>
    int Tree<T>::Depth(){
        if(this) {
            int LDepth = left->Depth ();
            int RDepth = right->Depth();
            if (LDepth > RDepth) {
                return (LDepth + 1);
            }
            else {
                return (RDepth + 1);
            }
        }
        else {
            return 0;
        }
    }

}


#endif //JIMP_EXERCISES_TREE_H
