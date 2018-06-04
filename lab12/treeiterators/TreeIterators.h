#ifndef JIMP_EXERCISES_TREEITERATOR_H
#define JIMP_EXERCISES_TREEITERATOR_H
#include "Tree.h"
#include <vector>

using namespace std;

namespace tree {

    //--------InOrder---------

    template<class T>
    class InOrderTreeIterator;

    //left-root-right
    template <class T>
    void InOrderTreeVector(Tree<T> *tree, std::vector<Tree<T> *> &vector){
        if(tree->Left()){
            InOrderTreeVector(tree->Left(),vector);
        }

        vector.push_back(tree);

        if(tree->Right()){
            InOrderTreeVector(tree->Right(),vector);
        }
    }

    template <class T>
    class InOrderTreeView{
        Tree<T> *tree_;
    public:
        InOrderTreeView(Tree<T> *tree) : tree_(tree) {};

        InOrderTreeIterator<T> begin(){
            InOrderTreeIterator<T> iter_start(tree_->Root());
            return iter_start;
        }
        InOrderTreeIterator<T> end(){
            InOrderTreeIterator<T> iter_back(tree_->Root());
            iter_back.toBack();
            return iter_back;
        }
    };

    template<class T>
    InOrderTreeView<T> InOrder(Tree<T> *tree) {
        return InOrderTreeView<T>(tree);
    }

    template <class T>
    class InOrderTreeIterator{
        void toBack(){
            it_ = (int) vector_.size();
        }
        vector<Tree<T> *> vector_;
        int it_;
//operatory != *  ++ InOrdrTreeIterator
    public:
        bool operator!=(const InOrderTreeIterator<T> &sth) const{
            return it_ != sth.it_;
        }
        T operator*(){
            return vector_[it_]->Value();
        }
        InOrderTreeIterator<T> &operator++() {
            ++it_;
            return *this;
        }
        InOrderTreeIterator(Tree<T> *tree) : it_(0) {
            InOrderTreeVector<T>(tree, vector_);
        }
        friend class InOrderTreeView<T>;
    };


    //--------PreOrder--------

    //root-left-right
    template <class T>
    void PreOrderVector(Tree<T> *tree, std::vector<Tree<T> *> &vector){
        vector.push_back(tree);

        if(tree->Left()) {
            PreOrderVector(tree->Left(),vector);
        }
        if(tree->Right()){
            PreOrderVector(tree->Right(),vector);
        }
    }

    template<class T>
    class PreOrderTreeIterator;

    template <class T>
    class PreOrderTreeView{
        Tree<T> *tree_;
    public:
        PreOrderTreeView(Tree<T> *tree) : tree_(tree) {};

        PreOrderTreeIterator<T> begin(){
            PreOrderTreeIterator<T> iter_start(tree_->Root());
            return iter_start;
        }
        PreOrderTreeIterator<T> end(){
            PreOrderTreeIterator<T> iter_back(tree_->Root());
            iter_back.toBack();
            return iter_back;
        }
    };

    template<class T>
    PreOrderTreeView<T> PreOrder(Tree<T> *tree) {
        return PreOrderTreeView<T>(tree);
    }

    template <class T>
    class PreOrderTreeIterator{
        void toBack(){
            it_ = (int) vector_.size();
        }
        vector<Tree<T> *> vector_;
        int it_;
    public:
        bool operator!=(const PreOrderTreeIterator<T> &sth) const{
            return it_ != sth.it_;
        }
        T operator*(){
            return vector_[it_]->Value();
        }
        PreOrderTreeIterator<T> &operator++() {
            ++it_;
            return *this;
        }
        PreOrderTreeIterator(Tree<T> *tree) : it_(0) {
            PreOrderVector<T>(tree, vector_);
        }
        friend class PreOrderTreeView<T>;
    };


    //--------PostOrder--------

    //left-right-root
    template <class T>
    void PostOrderVector(Tree<T> *tree, vector<Tree<T> *> &vector){
        if(tree->Left()){
            PostOrderVector(tree->Left(),vector);
        }
        if(tree->Right()) {
            PostOrderVector(tree->Right(),vector);
        }
        vector.push_back(tree);
    }

    template<class T>
    class PostOrderTreeIterator;

    template <class T>
    class PostOrderTreeView{
        Tree<T> *tree_;
    public:
        PostOrderTreeView(Tree<T> *tree) : tree_(tree) {};

        PostOrderTreeIterator<T> begin(){
            PostOrderTreeIterator<T> iter_start(tree_->Root());
            return iter_start;
        }
        PostOrderTreeIterator<T> end(){
            PostOrderTreeIterator<T> iter_back(tree_->Root());
            iter_back.toBack();
            return iter_back;
        }
    };

    template<class T>
    PostOrderTreeView<T> PostOrder(Tree<T> *tree) {
        return PostOrderTreeView<T>(tree);
    }

    template <class T>
    class PostOrderTreeIterator{
        void toBack(){
            it_ = (int) vector_.size();
        }
        vector<Tree<T> *> vector_;
        int it_;
    public:
        bool operator!=(const PostOrderTreeIterator<T> &sth) const{
            return it_ != sth.it_;
        }
        T operator*(){
            return vector_[it_]->Value();
        }
        PostOrderTreeIterator<T> &operator++() {
            ++it_;
            return *this;
        }
        PostOrderTreeIterator(Tree<T> *tree) : it_(0) {
            PostOrderVector<T>(tree, vector_);
        }
        friend class PostOrderTreeView<T>;
    };
}

#endif //JIMP_EXERCISES_TREE_H

