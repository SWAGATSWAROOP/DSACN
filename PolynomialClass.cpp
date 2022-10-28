#include <vector>
#include <climits>
#include <iostream>
using namespace std;


class Polynomial {
    public:
    int *degCoeff;      
    int capacity;
    Polynomial();
    Polynomial(Polynomial const &a);
    void setCoefficient(int degree,int coeff);
    Polynomial operator +(Polynomial const &a) const{
        Polynomial n2;
        int i = 0;
        while(i<capacity && i<a.capacity){
            int k = degCoeff[i] + a.degCoeff[i];
            n2.setCoefficient(i,k);
            i++;
        }
        for(;i<capacity;i++){
            n2.setCoefficient(i,degCoeff[i]);
        }
        for(;i<a.capacity;i++){
            n2.setCoefficient(i,a.degCoeff[i]);
        }
        return n2;
    }
    Polynomial operator -(Polynomial const &a) const{
        Polynomial n2;
        int i = 0;
        while(i<capacity && i<a.capacity){
            int k = degCoeff[i] - a.degCoeff[i];
            n2.setCoefficient(i,k);
            i++;
        }
        for(;i<capacity;i++){
            n2.setCoefficient(i,degCoeff[i]);
        }
        for(;i<a.capacity;i++){
            n2.setCoefficient(i,-a.degCoeff[i]);
        }
        return n2;
    }
    Polynomial operator *(Polynomial const &a) const{
        Polynomial n2;
    	for(int j=0;j<capacity;j++){
            for(int k=0;k<a.capacity;k++){
                int i = j+k;
                int l;
        		if(i<n2.capacity){
                	l = (degCoeff[j])*(a.degCoeff[k])+n2.degCoeff[i];
                }
                else{
                    l = (degCoeff[j])*(a.degCoeff[k]);
                }
                n2.setCoefficient(i,l);
            }
        }
        return n2;
    }
    void operator =(Polynomial const &a){
        capacity = a.capacity;
        degCoeff = new int[a.capacity];
        capacity = a.capacity;
        for(int i=0;i<capacity;i++){
            degCoeff[i] = a.degCoeff[i];
        }
    }
    void print();
};

	Polynomial::Polynomial(){
        degCoeff = new int[10];
        for(int i=0;i<10;i++){
            degCoeff[i] = 0;
        }
        capacity = 10;
    }

	Polynomial::Polynomial(Polynomial const &a){
        capacity = a.capacity;
        degCoeff = new int[a.capacity];
        capacity = a.capacity;
        for(int i=0;i<capacity;i++){
            degCoeff[i] = a.degCoeff[i];
        }
    }

	void Polynomial::setCoefficient(int degree,int coeff){
        if(degree>=capacity){
            int *ne = new int[degree+1];
            int i=0;
            for(;i<capacity;i++){
                ne[i] = degCoeff[i];
            }
            for(;i<=degree;i++){
                ne[i] = 0;
            }
            delete[] degCoeff;
            degCoeff = ne;
            ne = NULL;
            capacity = degree+1;
            degCoeff[degree] = coeff;
        }
        else{
           degCoeff[degree] = coeff; 
        }
    }

	void Polynomial::print(){
        for(int i=0;i<capacity;i++){
            if(degCoeff[i]==0){
                continue;
            }
            cout<<degCoeff[i]<<"x"<<i<<" ";
        }
        cout<<endl;
    }

int main()
{
    int count1,count2,choice;
    cout<<"Enter the number of terms: ";
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    cout<<"Enter the degrees: "<<endl;
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    cout<<"Enter the coefficients: "<<endl;
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cout<<"Enter the number of terms: ";
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    cout<<"Enter the degrees: "<<endl;
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    cout<<"Enter the coefficients: "<<endl;
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    swagat:
    cout<<"Enter your choice: "<<endl;
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            goto swagat;
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            goto swagat;
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            goto swagat;
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            third.print();
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            goto swagat;
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            fourth.print();
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            goto swagat;
            break;
        }
            
    }
    
    return 0;
}