#include<iostream>
using namespace std;

class vehicle{
    private:
        int speed;
    protected:
        int model;
    public:
        vehicle(int speed,int model){
            this->speed = speed;
            this->model = model;
            cout<<"Vehicle Constructor is called "<<speed<<" "<<model<<endl;
        }
        ~vehicle(){
            cout<<"Vehicle Destructor has been called"<<endl;
        }
};

class Car:virtual public vehicle
{
private:
    int y;
public:
    Car(int y,int z,int l):vehicle(z,l){
        cout<<"Car Constructor executed"<<endl;
        this->y = y;
    }
    ~Car(){
        cout<<"Car Destructor used"<<endl;
    }
};

class Truck:virtual public vehicle
{
private:
    /* data */
    int m;
public:
    Truck(int m,int l,int y):vehicle(l,y){
        cout<<"Truck Constructor has been executed"<<endl;
        this->m = m;
    }
    ~Truck();
};

Truck::~Truck()
{
    cout<<"Truck destructor used"<<endl;
}

class Bus:public Truck,public Car{
    public:
    Bus(int p,int q,int x,int y,int z,int m,int k,int o):Truck(x,y,z),Car(m,k,o),vehicle(p,q){
        cout<<"Bus Constructor Called"<<endl;
    }
    
    ~Bus(){
        cout<<"Bus destructor is called"<<endl;
    }
};


int main(){
    Bus b(1,2,3,4,5,6,7,8);
    return 0;
}