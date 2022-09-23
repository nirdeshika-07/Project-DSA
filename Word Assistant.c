#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    srand(time(NULL));//  without this rand() function might continuously give the same value
    
    while(n--){
        int stringLen = (rand() % m) +1; // getting random length
        string s=""; // taking null string
        for(int i=0; i<stringLen; i++){
            if(rand() % 2 == 0 ){ // capital or small letter
                s += 'A' + (rand() % 26);
            }else{
                s += 'a' + (rand() % 26);
            }
        }
        cout<<s<<" ";
    }
}
