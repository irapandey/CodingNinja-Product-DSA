#include <iostream>
using namespace std;
class ComplexNumbers {
    // Complete this class
    int real, img;
    
    public:
    
    ComplexNumbers(int real, int img){
        this -> real = real;
        this -> img = img;
    }
    
    void print(){
        cout<<this -> real<<" + i"<<this -> img<<endl; 
    }
    void plus(ComplexNumbers const &c2){
        // cout<<"ADD"<<endl;
        this -> real = this -> real + c2.real;
        this -> img = this -> img + c2.img;
    }
    
    void multiply(ComplexNumbers const &c2){
        // cout<<"MUL"<<endl;
        int temp1 = (this -> real * c2.real) - (this -> img * c2.img);
        int temp2 = (this -> real * c2.img) + (c2.real * this -> img);
        
        this -> real = temp1;
        this -> img = temp2;
    }
    
};
int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }   
}