#include<iostream>
#include"stacks_f.h"
using namespace std;
template<class T>
node<T>::node(T val){
    data=val;
    next=NULL;
}
template<class T>
stacks<T>::stacks(){
    top=NULL;
}
template<class T>
void stacks<T>::display(){
    if(top==NULL){
        cout<<"STACK UNDERFLOW"<<endl;
    }
    else{
        node <T>*temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
template<class T>
void stacks<T>::pop(){
    if(top==NULL){
        cout<<"STACK UNDERFLOW"<<endl;
    }
    else{
        node <T>*temp=top;
        cout<<"DELETED ELEMENT IS : "<<temp->data<<endl;
        top=top->next;
        delete(temp);
    }
}
template<class T>
void stacks<T>::push(T val){
    node <T>*new1=new node<T>(val);
    if(top==NULL){
        top=new1;
    }
    else{
        new1->next=top;
        top=new1;
    }
}
template<class T>
int stacks<T>::empty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}
template<class T>
T stacks<T>::peek(){
    return top->data;
}
template<class T>
T stacks<T>::popa(){
    node <T>*temp = top;
    top=top->next;
    //cout<< temp->data;
    return temp->data;
}


//-----------------------------------------------------------------------------------------------------------------------


bool precedance(char c,char b){
    int c1,b1;
    if(c=='*' || c=='/'){
        c1=2;
    }
    else {
        c1=1;
    }
    if(b=='*' || b=='/'){
        b1=2;
    }
    else {
        b1=1;
    }
    return ( c1<=b1);
}
string Infix_to_postfix(string a,stacks<char>A){
    int n=a.length();
    string ans="";
    for(int i=0;i<n;i++){
        if( ( a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z')){
            ans.push_back(a[i]);
        }
        else if( a[i]=='('){
            A.push(a[i]);
        }
        else if( a[i]== ')'){
            if( A.empty()){
                return "INVALID EXPRESSION";
            }
            while(   A.empty()==0 && A.peek()!='('  ){
                ans.push_back(A.peek());
                A.pop();
            }
            if(A.peek()=='('){
                A.pop();
            }
        }
        else{
            if(A.empty() ){
              return "INVALID EXPRESSION";
            }
           // 
            else{
               if(precedance( A.peek(),a[i])){
                   A.push(a[i]);
               }
               else{
                   ans.push_back(a[i]);
               } 
            }   
            
        }
    }
    while(A.empty()!=1){
        ans.push_back(A.peek());
        A.pop();
    }
    return ans;
}



// INFIX TO POSTFIX  -----------------------------------------------------------------------      




string Infix_to_prefix(string a,stacks <char>A){
  //  
  // cout<<a<<endl;
    for(int i=0;i<a.length();++i){
        if( a[i]=='('){ a[i]=')';}
        else if( a[i]==')'){a[i]='(';}
    }
   // cout<<"\n"<<a;
    reverse(a.begin(),a.end());
    string sna =Infix_to_postfix(a,A);
     reverse(sna.begin(),sna.end());
     return sna;
}


// CAlCULATION OF POSTFIX EXPRESSION --------------------------------------------------------


int post_fix_to_int(){
    stacks<int>A;
   // int ans=0;
    int k3,k4; // elements from stack
    int k1,k2; 
    char k0 ; // switch for input;
    bool i =true;
    while(i){
        cout<<"1. int 2. operation  3. exit  :: ";
        int k;
        cin>>k;
        cin.ignore();
        switch (k){
            case 1:
                cout<<"ENter the integer : ";
                cin>>k1;
                A.push(k1);
                cin.ignore();
                break;
            case 2:
                cout<<"enter operatotr : ";
                cin>>k0;
                k3 = A.popa();
                k4 = A.popa();
                switch(k0){
                    case '+':
                    A.push(k4+k3);
                    break;
                    case '-':
                    A.push(k4-k3);
                    break;
                    case '*':
                    A.push(k4 *k3);
                    break;
                    case '/':
                    A.push(k4/k3);
                    break;
                    case '^':
                    A.push(pow(k4,k3));
                    break;
                } 
                    break;
            case 3:
                cout<<"Are you sure you want to exit :"<<endl;
                int exitc;
                cout<<"1 to exit : ";
                cin>>exitc;
                if(exitc==1){
                    i=false;
                }
                break;
        }
    }
    return A.peek();
}



// CAlCULATION OF PREFIX ---------------------------------------------------------------



int prefix_evaluation(string s,stacks<int>A){
    //stacks<int>A;
    for(int i=(s.length()-1);i>=0;i--){
        if( s[i]>='0' && s[i]<='9'){
                A.push( ( s[i]-'0')  );
        }
        else{
            int k3=A.popa();
            int k4=A.popa();
            switch(s[i]){
                    case '+':
                    A.push(k4+k3);
                   // cout<<A.peek()<<endl;
                    break;
                    case '-':
                    A.push(k3-k4);
                   // cout<<A.peek()<<endl;
                    break;
                    case '*':
                    A.push(k4 *k3);
                   // cout<<A.peek()<<endl;
                    break;
                    case '/':
                    A.push(k3/k4);
                  //  cout<<A.peek()<<endl;
                    break;
                    case '^':
                    A.push(pow(k3,k4));
                    break;
                } 
        }
    }
    return A.peek();
}