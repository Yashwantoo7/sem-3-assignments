#include <iostream>
#include <vector>

using namespace std;

class Emp{
    int empNo;
    string name;
    string address;
    string department;
public:
    void setName(string n){
        name=n;
    }
    string getName(){
        return name;
    }
    void setAddress(string a){
        address=a;
    }
    string getAddress(){
        return address;
    }

    void setEmpNo(int no){
        empNo=no;
    }
    int getEmpNo(){
        return empNo;
    }

    void setDepartment(string d){
        department=d;
    }
    string getDepartment(){
        return department;
    }

};

class Manager{
    Emp e;
    static vector <Emp> empList;
public:
    Manager(int en=0 ,string n="noname",string a="noAddress",string d="noDepartment"){
        e.setEmpNo(en);
        e.setName(n);
        e.setAddress(a);
        e.setDepartment(d);
        empList.push_back(e);
    }
    void disPlay(){
        int i=0;
        while(i!=empList.size()){
            cout<<"Emp No. "<<empList.at(i).getEmpNo()<<endl;
            cout<<"Emp Name  "<<empList.at(i).getName()<<endl;
            cout<<"Emp Address "<<empList.at(i).getAddress()<<endl;
            cout<<"Emp Department. "<<empList.at(i).getDepartment()<<endl;
            cout<<endl;
            i+=1;
        }
    }
};

vector <Emp> Manager::empList;

int main(){
    Manager * m=new Manager(1,"yash","jaora","cse");
    m=new Manager (2,"dheeraj","jaora","cse");
    m=new Manager(3,"veeresh","goa","civil");
    m->disPlay();
return 0;}
