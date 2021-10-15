#include<iostream>
#include"stck.cpp"
using namespace std;
int main(){
     bool loop=true;
    while(loop){
        cout<<"1->Infix to postFix 2->Infix to prefix 3->Postfix Evaluation 4->Prefix Evaluation 5->Exit ::  ";
        int choice;
        cin>>choice;
         string s1;
         string s2;
         string s4;
         int k12;
         int k41;
        stacks<int> C;
        stacks<char> B;
        stacks<char> A;
        switch(choice){
            case 1:
           // stacks<char> A;
             
            cout<<"Format for Infix conversion is : ((a+b)*c) "<<endl;
            cin.ignore() ;
           
            cout<<"Enter the expression : ";
            cin>>s1;
            cout<<"Answer is : "<<Infix_to_postfix( s1,A)<<endl;
            break;
            case 2:
            
            cout<<"Format for Infix conversion is : ((a+b)*c) "<<endl;
            cin.ignore() ;
            
            cout<<"Enter the expression : ";
            cin>>s2;
            cout<<"Answer is : "<<Infix_to_prefix(s2,B)<<endl;
            break;
            case 3:
            k12=post_fix_to_int();
            cout<<"Answer is : "<<k12<<endl;
            break;
            case 4:
            cout<<"Format for Infix conversion is : -+7*45+20 "<<endl;
            cin.ignore();
            
            cout<<"Enter the expression : ";
            cin>>s4;
            
            k41=prefix_evaluation(s4,C);
            cout<<"Answer is : "<<k41<<endl;
            break;
            case 5:
            loop=false;
            break;
        }
    }
//     stacks <int> obj;
//     obj.push(19);
//     obj.display();
//     obj.push(131);
//     obj.push(100);
//     cout<<endl;
//     cout<<obj.popa();
     
//     cout<<endl;
//     cout<< obj.peek();
//     cout<<"   hthththth ";
//     cout<<obj.popa();
//     cout<<endl;
//     obj.pop();
//     obj.display();
//     cout<<obj.empty();

   // stacks<char>A;


   // string s="((a+b)*c)";
  // cout<<Infix_to_postfix( s,A)<<endl;
  // stacks<char>B;
// int n=s.length();
// cout<<n;
// for(int i=0;i<n;i++){
//     if(s[i]=='('){
//         s[i]=')';
//     }
//     else if( s[i]==')'){
//         s[i]='(';
//     }
//     else{

//     }
// }
// reverse(s.begin(),s.end());
// //cout<<a;
//cout<<endl;
 //cout<<Infix_to_prefix(s,B);
// cout<<endl;
// int k=post_fix_to_int();
// cout<<k;

//     string s="-+7*45+20";
//     stacks<int>C;
// int k=prefix_evaluation(s,C);
// cout<<k;
system("pause > 0");
}