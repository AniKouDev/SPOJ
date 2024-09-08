#include <iostream>
using namespace std;

int main(){
    //Start infinite loop break when 42 is entered
    
    while(1){
        int n;
        cin >> n;
        if(n==42){
            break;
        }
        cout << n << endl;
    }
}