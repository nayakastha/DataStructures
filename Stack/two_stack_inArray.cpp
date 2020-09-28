#include <bits/stdc++.h>
using namespace std;

class two_stacks{
    int *arr;
    int size;
    int top1,top2;

    public:
    two_stacks(int n){
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    void push_1(int num){
        if(top1 < top2-1){
          top1++;
          arr[top1] = num;
        }
        else{
            cout<<"OVERFLOW";
            exit(1);
        }
    }

    void push_2(int num){
        if(top1 < top2-1){
            top2--;
            arr[top2] = num;
        }
        else{
            cout<<"OVERFLOW";
            exit(1);
        }
    }

    int pop1() 
    { 
        if (top1 >= 0) { 
            int x = arr[top1]; 
            top1--; 
            return x; 
        } 
        else { 
            cout << "UNDERFLOW"; 
            exit(1); 
        } 
    } 

    int pop2() 
    { 
        if (top2 < size) { 
            int x = arr[top2]; 
            top2++; 
            return x; 
        } 
        else { 
            cout << "UNDERFLOW"; 
            exit(1); 
        } 
    } 

    void display(){
        for(int i=0; i<size ;i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
   two_stacks ts(8);
   ts.push_1(2);
   ts.push_1(5);
   ts.push_2(6);
   ts.push_2(16);
   ts.display();
    return 0;
}