#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;





int main(){
     srand((unsigned int) time(NULL));

     int number = (rand() % 100) + 1;
     int guess = 0;

    do{
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;

        if(guess > number){
            cout << "Too high!" << endl;
        }else if(guess < number){
            cout << "Too low!" << endl;
        }else{
            cout << "You guessed it! congratulations you won!" << endl;
        }
    }while(guess != number);
    
    return 0;
}