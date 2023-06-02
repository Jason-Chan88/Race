#include "Race.h"
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main () {
    srand(time(NULL)); //Seeds the random number generator (Do NOT seed again)
    Race newRace; //Creates a new instance of the game
    newRace.ManageGame(); //Starts the game
    return 0;
}

