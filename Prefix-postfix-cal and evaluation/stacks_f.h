#include<bits/stdc++.h>
using namespace std;
template<class T>
class stacks;
template<class T>
class node{
    private:
    T data;
    node <T>*next;
    public:
    node(T val);
    friend class stacks<T>;
};template<class T>
class stacks{
    private:
    node <T>*top;
    public:
    stacks();
    int empty();
    void push(T);
    void pop();
    void display();
    T peek();
    T popa(); // pop last element and moves to second last elements wrt to popped element
};
string Infix_to_postfix(string ,stacks<char>);
bool precedance(char ,char );
string Infix_to_prefix(string,stacks<char>);
int post_fix_to_int();
int prefix_evaluation(string s,stacks<int>A);