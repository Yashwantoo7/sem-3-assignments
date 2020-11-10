#include <iostream>
#include <exception>

using namespace std;

class  OverSpeed: public exception{
int speed;
public:
    const char * what(){
    return "check out ur car speed \n you are  in the car not in the aeroplane";
    }
    void getSpeed(){
    cout<<"your car speed is "<<speed<<endl;}
    void setSpeed(int s){
        speed=s;
    }
    };

class Car{
int speed;
public:
    Car(){
    speed=0;
    cout<<"speed is "<<speed<<endl;
    }
    void accelerate(){
    for(;;){
        speed+=10;
        cout<<"speed is "<<speed<<endl;
        if(speed >=250){
            OverSpeed s;
            s.setSpeed(speed);
            throw s;
        }
    }
    }};
int main()
{
    Car anilsCar;
    try{
    anilsCar.accelerate();
    }
    catch(OverSpeed s){
    cout<<s.what()<<endl;
    s.getSpeed();}
    return 0;
}
