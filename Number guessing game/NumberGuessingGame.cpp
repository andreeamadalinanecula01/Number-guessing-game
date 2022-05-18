/*

Classic Guessing Game C++

The Program will choose a random number based on the configuration file.
If you are close to the number the program will let you know by two messages (Low, High)

*/

#include <iostream>
#include <string>
#include <stdint.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <limits>
using namespace std;


class Game{

    public:
        int load_settings(){
            string data;
            fstream fin("settings.conf",ios::in);

            while (fin >> data)
            	max = stoi(data.substr(6, data.length() - 2));
            return max;
        }

        // Global variable !
        int max = load_settings();

        // This Function run all the main functions (Save time) !
        void run_all(){
            Game().load_settings(), Game().clean_banner(), Game().game();
        }

        // Generate random number and return it!
        int random_int(int max){
            srand(time(0));
            int number = 1 + rand() % max;
            return number;
        }

        void clean_banner(){
            system("clear");
            cout << "\a\a\a*** WELCOME TO THE GUESSING GAME ***\a\a\a\n" << endl;
            cout << "         By RedMad :$ v1.0\n\n\n" << endl;
        }

            
        // The main game function!
        void game(){
            // Some needed variabels :$
            int random_number = random_int(max), counter = 0;;
            long long number_input;
            string main_input;
                      
            // Main while loop
            while (true) {
                cout << "[?] Enter Number: "; 
                cin >> number_input;             
                counter++;

                if(number_input == random_number){
                    
                    Game().clean_banner();
                    cout << "[$] YOU WIN THE GAME !! ";

                    cout << "\n\n[$] NUMBER: " << random_number;

                    cout << "\n\n[$] TRYS: " << counter;
		    
		    // if you want to play again press y or n
                    cout << "\n\n[?] Play Again? (y/n): ";
                    cin >> main_input;

                    // while loop to choose if you want to play again
                    while (true) {
			// ig you enter y, replay the game
                        if (main_input == "y") {

                            Game().run_all();
                            random_number = random_int(100);
                            break;
                        }
                        else if(main_input == "n") {
			    // if you enter n, you donțt want to play again, good bye message
                            cout << "\n\n[$] Bye Bye :$" ;
			    exit(1);
                        }
                        else {
                            cout << "[?] Play Again? (y/n): ";
                            cin >> main_input;
                        }   
                    }
                }
                else if (number_input > max){
                    cin.clear();
                    cin.ignore();
		
		    // if your guess is higher than max number, give a hint
                    Game().clean_banner();
                    cout << "[!] The value you enter is Higher than " << max << "\n\n";
                }
                else if (number_input > random_number){
                    cin.clear();
                    cin.ignore();
		    
		    // if your guess is higher than actual number, give a hint
                    Game().clean_banner();
                    cout << "[$] Try Low!" << "\n\n";
                }
                else if (number_input < random_number && number_input != 0){
                    
                    cin.clear();
                    cin.ignore();
		    
		    // if your guess is lower than actual number, give a hint
                    Game().clean_banner();
                    cout << "[$] Try High!" << "\n\n";
                }
                else {

                    cin.clear();
                    cin.ignore();
		   
		    // if your guess is not a number, give a hint
                    Game().clean_banner();
                    cout << "[!] The value you entered is not a number !" << "\n\n";
                }
            }

        }
};


int main(){

    // Call the RUN game function !
    Game().run_all();
    return 0;
}


