#include <iostream>
#include <stack>
#include <string>

using namespace std;

 string bn(int num){
    stack <int> stk;
    string b="";
    int r;
    while(num){
        r=num%2;

        stk.push(r);
        num=num/2;
    }
    while (stk.size()){
        b=b+to_string(stk.top());
        stk.pop();
    }
    return b;
}

int main(){
    int decimalNumber=7883784;
    cout<<"binary representation of "<<decimalNumber<<" in binary is "<<bn(decimalNumber)<<endl;

return 0;}
