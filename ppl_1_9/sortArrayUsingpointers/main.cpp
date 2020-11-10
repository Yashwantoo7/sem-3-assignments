#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //Question 1 sort an array using pointers
//    int arr[10]={9,8,7,5,4,3,2,1,9,8};
//    int *l=NULL ;
//    int *h=NULL;
//    int n=sizeof(arr)/sizeof(arr[0]);
//    for (int i=0;i<n-1;i++){
//            l=&arr[i];
//        for (int j=i+1;j<n;j++){
//            h=&arr[j];
//            if(*h<*l){
//                *h=*h+*l;
//                *l=*h-*l;
//                *h=*h-*l;
//            }
//        }
//    }
//    for (auto i:arr){
//        cout<<i<<" ";
//    }
//
//    string s="this is a test";
//    char *c=NULL;
//    c=&s[s.length()-1];
//    for (int i{0};i<s.length();i++){
//        cout<<*(c-i)<<"";
//    }

    int arr [9]={1,2,3,4,5,6,7,8,9};
//    cout<<vec.size();
    int *p=NULL;
    int total{0};
    p=arr;
    for (int i=0;i<9;i++){
        total+=*(p+i);
    }
    cout<<total;
    return 0;
}
