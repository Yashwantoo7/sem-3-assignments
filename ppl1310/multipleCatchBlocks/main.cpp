#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    try{
    throw "some exception";
    throw 20;
    throw runtime_error("runtime error");
    }

    catch(const char *c){
        cout<<c<<endl;
    }

    catch(int e){
        cout<<e<<endl;}

    catch(...){ //can handle all the exceptions
        cout<<"some exception occured"<<endl;
    }
    return 0;
}
