#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Word{
public: 
	string wordGenerated; 
	vector<string> words = {"hello","computer","table","chair","door","house","bank","cake"}; 

	void generateWord(){
		srand(time(0)); 
		wordGenerated = words[rand() % words.size()]; 
	       	cout << wordGenerated; 	
	}
}; 
class Game{
public:
	Word word; 
	void playGame(){
		word.generateWord();
	}	
};

void gameMenu(){
	int userInput;
	Game game; 
	while(true){
		cout << "What would you like to do? " << endl; 
		cout << "1.Play hangman" << endl; 
		cout << "2.Exit"<< endl; 
		cin >> userInput; 
		switch(userInput){
			case 1: 
				game.playGame(); 
				break;
			case 2: 
				cout << "Goodbye . . . " << endl; 
				return ;
			default: 
				cout << "Invalid input " << endl; 
		}
	}
}
int main(){
	gameMenu();
	return 0 ; 
}
