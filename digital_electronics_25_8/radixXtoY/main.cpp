#include <iostream>
#include <string>
#include <math.h>
#include <typeinfo>

using namespace std;

int main()
{   string x;
    int type;
    cout << "Enter a radix system type in integer form : ";
    cin>>type;
    cout << "Enter a number : ";
    cin>>x;
//    cout<<x<<endl;
    string front_radix="";
    string back_radix="";
    int j=0;
    char i=' ';
    while (i!='.' && j!=x.length()){
        front_radix+=x[j];
        i=x[j];
        j+=1;
    }
    while (j!=x.length()){
        back_radix+=x[j];
        j+=1;
    }
    int length_of_back=back_radix.length();
    if(length_of_back){
        front_radix.pop_back();
    }
//    cout<<front_radix<<" "<<back_radix;
    int length_of_front=front_radix.length();
    int indx_for_front=length_of_front-1;
    int indx_for_back=0;
    int front_base_10=0;
    while(indx_for_front>-1){
        front_base_10+= (((int)front_radix[indx_for_front])-48)*pow(type,length_of_front-indx_for_front-1);
        indx_for_front-=1;
    }
//    cout<<front_base_10<<endl;
    double back_base_10=0.0;
    if(length_of_back){
        while(indx_for_back<length_of_back){
            back_base_10+=(((int)back_radix[indx_for_back])-48)*pow(type,-(indx_for_back+1));
            indx_for_back+=1;
        }
    }
//    cout<<back_base_10<<endl;
    double num_in_10=0.0;
    num_in_10=back_base_10+front_base_10;
    cout<<num_in_10<<endl;





















    //convert in to y radix
    string f_b_10="";
    string b_b_10="";
    j=0;
    i=' ';
    string n_i_10=to_string(num_in_10);
    while (i!='.' && j!=n_i_10.length()){
        f_b_10+=n_i_10[j];
        i=n_i_10[j];
        j+=1;
    }
//    cout<<j<<n_i_10.length()<<endl;
    while (j!=n_i_10.length()){
        b_b_10+=n_i_10[j];
        j+=1;
    }
    int length_of_back_base_10=b_b_10.length();
    front_base_10=stoi(f_b_10);
    if(length_of_back_base_10){
    back_base_10=stoi(b_b_10)/(pow(10,length_of_back_base_10));
    }

//cout<<back_base_10<<endl;
    cout<<"Enter the radix type you want to convert into : ";
    int convert_type=0;
    cin>>convert_type;
    string front_convert="";
    string back_convert="";
    int r=0;
    while(front_base_10){
        r=front_base_10%convert_type;
        front_base_10=front_base_10/convert_type;
        front_convert+=to_string(r);
    }
    int rev_str=0;
    int rev_end=front_convert.length()-1;
    while (rev_str<rev_end){
        swap(front_convert[rev_str],front_convert[rev_end]);
        rev_str+=1;
        rev_end-=1;
    }

    int temp=0;
    int max_limit=0;
//    cout<<back_base_10<<endl;
    if(length_of_back_base_10){
            while(max_limit<6 && back_base_10!=1.0){
                back_base_10=back_base_10*convert_type;
                if (back_base_10>=1.0){
                        while(back_base_10>=1.0){
                            temp+=1;
                            back_base_10-=1;
                        }
                        max_limit+=1;
                        back_convert+=to_string(temp);
                        temp=0;
                }
                else{
                  back_convert+=to_string(temp);
                }
//                cout<<back_base_10<<" ";
                max_limit+=1;

            }
    }

    string new_radix="";
    if (back_convert.length()){
    new_radix=front_convert+"."+back_convert;
    }
    else{
    new_radix=front_convert+back_convert;
    }
    cout<<new_radix<<endl;
    return 0;
}
