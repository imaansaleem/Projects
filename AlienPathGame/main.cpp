
#include "helper.cpp"
#include <iostream>
#include <string>

using namespace std;

void Caps_to_small(string &a);

int main()
{
    char isPlay = true, choice;
    string input;
    srand(time(0));

    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl << endl;

    do{
        pf::PrintGameSettings();
        do{
            std::cout << "\nDo you wish to change the game settings (y/n)? => ";
            cin >> choice;
            choice |= 32;
            if(choice == 'y')
                pf::ChangeGameSettings();
            else if(choice == 'n')
                break;
            else
                std::cout << "\nInvalid Input!\n";
        }while( !(choice == 'n' || choice == 'y') );

        pf::CreateGameBoard();

        cin.ignore();
        while( !pf::GameOver() )
        {
            pf::ClearScreen();
            pf::ShowGameBoard();
            cout << "Command> ";
            getline(cin, input, '\n');
            Caps_to_small(input);

            if(input=="up") {
                pf::AlienMove(input);
            }
            else if(input=="down") {
                pf::AlienMove(input);
            }
            else if(input=="left") {
                pf::AlienMove(input);
            }
            else if(input=="right") {
                pf::AlienMove(input);
            }
            else if(input=="arrow") {
                pf::ChangeArrow();
            }
            else if(input=="help") {
                pf::Help();
            }
            else if(input=="save") {
                cout << "saving\n";
            }
            else if(input=="load") {
                cout << "loading\n";
            }
            else if(input=="quit") {
                cout << "\nAre you sure? (y/n) : ";
                cin >> choice;
                std::cin.ignore();
                choice |= 32;
                if(choice == 'y') {
                    cout << "Goodbye!\n";
                    break;
                }
                else
                    cout << "Aborting...\n";
                pf::Pause();
            }
            else {
                cout << "\nInvalid Input!\n\n";
                pf::Pause();
            }
        }

        pf::DeleteGameBoard();
        cout << "\nDo you want to Play Again? (y/n) : ";
        cin >> choice;

        choice |= 32;

        if(choice == 'y')
            isPlay = true;
        else
            isPlay = false;

    }while( isPlay );
    return 0;
}

void Caps_to_small(string &a){
    for(int i=0;i<a.size();i++){
        if(a[i]>=65 && a[i]<=90)
            a=a[i]+32;
    }
}

