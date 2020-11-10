#include <iostream>

using namespace std;

int main()
{   // question 1
    use of pointer (initialize,access,assign and access a pointer)
    int num=5;
    int *ptr=NULL;
    ptr=&num;
    cout<<"adress : "<<ptr<<" Value : "<<*ptr ;

//question 2
    int num1=5;
    int num2=10;
    int *ptr1=NULL;
    int *ptr2=NULL;
    cout<<num1<<" "<<num2<<endl;
    ptr1=&num1;
    ptr2=&num2;
    *ptr1=*ptr1+*ptr2;
    *ptr2=*ptr1-*ptr2;
    *ptr1=*ptr1-*ptr2;
    cout<<num1<<" "<<num2;

//question 3
    string str="hello there";
    char *ptr=NULL;
    ptr=&str[0];
    int vowels {0};
    int consonants {0};
    for(int i=0;i<str.length();i++){
        if(*(ptr+i)=='a'||*(ptr+i)=='e'||*(ptr+i)=='i'||*(ptr+i)=='o'||*(ptr+i)=='u'){
            vowels+=1;
        }
        else if (*(ptr+i)!=' '){
            consonants+=1;
        }
    }
    cout<<"vowels "<<vowels<<" consonants "<<consonants<<endl;

//question 4
    int arr[5] {1,2,3,4,5};
    int s=sizeof(arr)/sizeof(arr[0]);
    int *ptr;
    ptr=arr;
    for (int i=0;i<s;i++)
        {
            cout<<"Address is : "<<(ptr+i)<<" Value is : "<<*(ptr+i)<<endl;
        }
    return 0;
}
