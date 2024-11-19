#include <iostream>
#include"clsLoginScreen.h"

using namespace std;
const string filename = "Clients.txt";



int main()
{
   // clsMainScreen::ShowMainMenue();
    while (true) {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }
    
    system("pause>0");
    return 0;
}

