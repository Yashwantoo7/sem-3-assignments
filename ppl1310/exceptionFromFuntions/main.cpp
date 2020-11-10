#include <iostream>
#include <stdexcept>

using namespace std;

void test() throw(int,char,const char* ,runtime_error){
//    throw 20;
//    throw 'c';
    throw "fdjk";
throw runtime_error ("what the hack");
}

int main()
{
    try{
        test();
    }
    catch(int e){
        cout<<"integer type "<<e<<endl;
        }
    catch( char c){
        cout<<"char type "<<c<<endl;
        }
    catch(const char *s){
        cout<<"string type "<<s<<endl;
        }
     catch(runtime_error r){
        cout<<"run type "<<r.what()<<endl;
        }


    return 0;
}
