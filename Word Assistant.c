#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    srand(time(NULL));//  without this rand() function might continuously give the same value
	int N = 10;
  
    // Function Call
    randomPasswordGeneration(N);
    
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
	while(!done)
	{
		std::cin >> input;
		if(input == '1')
		{
			sentence += temp + ' ';
			word = "";
			std::cout << sentence << std::endl;
		}
		else if(input == '2')
		{
			sentence += word + ' ';
			word = "";
			std::cout << sentence << std::endl;
		}
		else if(input != '0')
		{
			word += input;
			for(it = dict.begin(); it != dict.end(); ++it)
			{
				if(word == (*it).substr(0, word.length()))
				{
					std::cout << (*it) << std::endl;
					temp = (*it);
					break;
				}
			}
		}
		else
			done = true;
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
	
}
void randomPasswordGeneration(int N)
{
    // Initialize counter
    int i = 0;
  
    int randomizer = 0;
  
    // Seed the random-number generator
    // with current time so that the
    // numbers will be different every time
    srand((unsigned int)(time(NULL)));
  
    
    
  
    // Array of small alphabets
    char letter[] = "abcdefghijklmnoqprstuvwyzx";
  
    // Array of capital alphabets
    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
  
  
    // Stores the random password
    char password[N];
  
    // To select the randomizer
    // inside the loop
    randomizer = rand() % 4;
  
    // Iterate over the range [0, N]
    for (i = 0; i < N; i++) {
  
        
         
        
         if (randomizer == 3) {
            password[i] = LETTER[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else {
            password[i] = letter[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
    }
}

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
