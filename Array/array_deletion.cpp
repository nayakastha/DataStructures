

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



void deletion(int ar[], int n, int &present_size){
    int ele;
    cout<<"Enter element to delete: ";
    cin>>ele;
    if(!search_element(ar,present_size,ele)){
        for(int i =0; i<present_size; i++){
            if(ar[i]==ele){
                for(int j=i; j<present_size-1; j++){
                    ar[j] = ar[j+1];
                }
            }
        }
        present_size--;
    }
    else{
        cout<<ele<<" doesn't exist!"<<endl;
    }
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
    deletion(ar,max_size,present_size);
    output(ar,present_size);
    return 0;
}
