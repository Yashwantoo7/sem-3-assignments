#include <iostream>
#include <stdexcept>


using namespace std;

int main()
{
    try{

        try{
        throw "a character exception";
        }
        catch(const char *c){
                cout<<"character type in inner block ---> "<<c<<endl;
            cout<<"rethrowing the exception"<<endl;
            throw runtime_error("sjdjfk");
        }
        catch(...){
            cout<<"unexpected exception in inner block"<<endl;
        }

    }

    catch(const char *c){
    cout<<"character type in outer block ---> "<<c<<endl;
    }
    catch(...){
    cout<<"unexpected exception in outer block"<<endl;}

    return 0;
}
