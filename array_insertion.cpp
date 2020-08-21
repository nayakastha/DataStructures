
#include <iostream>
using namespace std;

void output(int ar[], int n){
    cout<<"\nupdated array: ";
    for(int i=0; i<n; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

bool search_element(int ar[], int n, int ele){
    for(int i=0; i<n; i++){
        if(ar[i]==ele) return 0;
    }
    return true;
}

void insertion(int ar[], int n, int &present_size){
    int ele,pos;
    cout<<"Enter element and position(separated by a space & 0 is base position): ";
    cin>>ele>>pos;
    int check = search_element(ar,present_size,ele);
    if(present_size>=n){
        cout<<"size fill\n";
        return;
    }
    if(check){
        for(int i=n-1; i>pos; i--){
            ar[i] = ar[i-1];
        }
        ar[pos] = ele;
        present_size = max(pos+1,present_size);
    }
    else cout<<ele<<" already exist!"<<endl;
}




void initializer(int ar[], int max_size, int &present_size){
    int fill_size;
    cout<<"Enter the no. of elemens to fill: ";
    cin>>fill_size;
    cout<<"fill elements\n";
    fill_size = min(fill_size, max_size);
    for(int i=0; i<fill_size; i++)
        cin>>ar[i];
    for(int i=fill_size; i<max_size; i++) ar[i] = 0;
    present_size = fill_size;
}
int main(){
    int max_size, present_size=0;
    cout<<"Enter the max size: ";
    cin>>max_size;
    int ar[max_size];
    initializer(ar,max_size,present_size);
    insertion(ar,max_size,present_size);
    output(ar,present_size);
    return 0;
}
