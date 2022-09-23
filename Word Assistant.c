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
    struct node{
	int size ,end;
	long long int maxfreq;
	node* next[26];
	node(){
		size = 0,end = 0, maxfreq=0;
		for(int i=0;i<26;i++)
			next[i] = nullptr;
	}
  };
	void insert(string x){
  	// Starting from the root node
	node *temp = root;
	for(int i=0;i<x.size();i++){
 		 //  Using numbers 0-25 to represent alphabets
		int t = x[i] - 'a';
  		// Making a new node,if it doesn't exist
		if(temp->next[t]==nullptr)
			temp->next[t]=new node();
		temp = temp->next[t];
		  //  Increasing size of sub-graph rooted at this node
		temp->size++;
	}
	// Increasing the frequency of this node as the word ends here
	temp->end++;
	
	insertWithFreq(x,temp->end);
} 
}
