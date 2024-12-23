#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Word{
public: 
	vector<string> words = {"hello","computer","table","chair","door","house","bank","cake"}; 

	vector<char> generateWord(){
		srand(time(0)); 
		string wordGenerated = words[rand() % words.size()]; 
		vector<char> charWord (wordGenerated.begin(),wordGenerated.end()); 
		cout << wordGenerated; 
		return charWord;		
	}
}; 
class Game{
public:
	int gameAttempt;
	Word word; 
	vector<char> ans; 
	vector<char> generatedWord;	
	void displayGame(){
		for (char a : ans ) {
			cout << a << " " ; 
		}
		cout << "\n" ;
		cout << "Atempts left: " << gameAttempt << endl; 
	}
	void initializeGame(){
		ans.clear();
		generatedWord =	word.generateWord();
		ans.resize(generatedWord.size(), '_'); 
		gameAttempt = 7 ;
		displayGame();
	}
	void checkGame(bool &gameContinue){
		if (ans == generatedWord){
			gameContinue = false ;
			cout << "Congratulations on guessing the word " << endl ;
			return;
		}	
		if (gameAttempt <= 0 ) {
			gameContinue = false; 
			cout << "You lost " << endl;
		}
	}
	void insertWord(){
		char userInput ; 
		cout << "Please inset a word " << endl; 
		cin >> userInput; 
		for (int i = 0 ; i < ans.size(); i ++){
			if (userInput == generatedWord[i]){
				ans[i] = userInput;
			}
		}
	}
	void playGame(){
		initializeGame(); 
		bool gameContinue = true; 
		while(gameContinue){
			
			insertWord(); 
			gameAttempt -- ;
			displayGame(); 
			checkGame(gameContinue); 
		}
	}	
};

void gameMenu(){
	int userInput;
	Game game; 
	Word word; 
	while(true){
		cin.clear();
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
