#include "Race.h"

// does nothing but be a default constructor
Race::Race() {

}

// deals with controlling the race from beginning to end
void Race::StartRace() {

    m_track.ResetLocation();

    int length = 0; // starts the while loop immediately as it's below 1
    // everytime a race start plus 1 to race stat
    m_myPlayer.SetRaces(m_myPlayer.GetRaces()+1);
    // makes sure they in put a length between 1 - 100
    while (length < 1 || length > MAX_LENGTH) {
        cout << "how long would you like the race?" << endl;
        cin >> length;
    }

    m_track.SetLength(length);
    m_track.PopulateObstacles();

    bool race = true;
    // keep the race going while race bool equals true, ends race when it's false
    while (race ) {

        int option = RaceOptions(); // RaceOptions returns a number which goes into a race variable
        // calls GetStatus if option 1
        if (option == 1) {
            m_track.GetStatus();
        }
        // runs progress race if 2,3,4 are the option
        else {
            ProgressRace(option);

            double countPlayer = m_track.CheckWin(); // CheckWin returns the number of the racer that won
            // says the winner and if it's the player than increment stat and wins, also race is false so race over
            if (countPlayer == 0) {
                race = false;
                cout << "You won the race!" << endl;
                m_myPlayer.IncreaseStat();
                m_myPlayer.IncreaseWins();

            } else if (countPlayer == 1) {
                race = false;
                cout << "Player 1 won the race!" << endl;

            } else if (countPlayer == 2) {
                race = false;
                cout << "Player 2 won the race!" << endl;

            } else if (countPlayer == 3) {
                race = false;
                cout << "Player 3 won the race!" << endl;
            }
        }
    }
}

// Gets the racer's name and puts it in SetName
void Race::GetRacerInfo() {
    string name = "";

    cout << "What is your racer's name?" << endl;
    // get line for if you want to have space between names
    getline(cin,name);

    m_myPlayer.SetName(name);
}

// controls the flow of the race for player
void Race::ProgressRace(int choice) {
    cout << "You are trying to progress the race!" << endl;


    int difficultyObstacle = (rand() % BASE_DIFFICULTY+1); // random difficulty from 1-100
    int playerSkill = 0;

    // if your choice equals the obstacle you are on than you get the boost if not than you don't
    // we compare with the string of the obstacle by using Convert Obstacle and we just put in the obstacle number
    if (OBSTACLE_TYPE[choice-2] == m_track.ConvertObstacle(0)) {
        playerSkill = 5 * m_myPlayer.GetStat(choice-2);
    }

    // we add the base skill and player skill than compare it to obstacle difficulty, if skill is greater you pass
    if ((BASE_SKILL + (playerSkill))  > (difficultyObstacle)) {
        cout << (BASE_SKILL + (playerSkill)) << endl;
        cout << (difficultyObstacle) << endl;
        cout << "You made it through the " << m_track.ConvertObstacle(0) << " obstacle!" << endl;
        m_track.IncrementLocation(0);
    }
    // if skill is less than difficulty than you fall
    else {
        cout << (BASE_SKILL + (playerSkill)) << endl;
        cout << (difficultyObstacle) << endl;
        cout << "You fell!" << endl;
        // using getter and setter to increment falls
        m_myPlayer.SetFalls(m_myPlayer.GetFalls()+1);
    }
    ProgressComputer(difficultyObstacle);
}

// control the flow of the race for computers
void Race::ProgressComputer(int obstacleDifficulty) {
    int dum = ((rand() % (COMP_MAX - COMP_MIN +1)) + COMP_MIN);
    // looping through the racer 2-4
    for (int i = 1; i < NUM_RACERS; i++){

    // calculate skill of computer than compare it to obstacle difficulty that we got from progress race
    if (dum  > (obstacleDifficulty)) {
        cout << dum << endl;
        cout << obstacleDifficulty << endl;
        cout << "Player " << i << " made it through the " << m_track.ConvertObstacle(i) << " obstacle!" << endl;
        m_track.IncrementLocation(i);
    }
    // if skill doesn't trump difficulty computer fall
    else
    {
        cout << dum << endl;
        cout << obstacleDifficulty << endl;
        cout << "player " << i <<" fell!" << endl;
        }
    }
}

// displays the main menu and give the user choices and executes the choices
bool Race::MainMenu() {
    int choice = 0;
    // for reprompting and taking choice
    while (choice < 1 || choice > 3) {
        cout << "What would you like to do?" << endl;
        cout << "1. Start New Race" << endl;
        cout << "2. View Racer History" << endl;
        cout << "3. Quit" << endl;
        cin >> choice;
    }
    // executing your choice
   if (choice == 1) {
       StartRace();
   }
   else if (choice == 2){
       m_myPlayer.DisplayStatus();
   }
   // it returns true to Main Menu so it keeps running until choice equal three and returns false
   else if (choice == 3) {
       return false;
   }
    return true;
}

// the option you have during the race and executes your choices
int Race::RaceOptions() {
    int race = 0;
    // for reprompting and taking in you input
    while (race < 1 || race > 4) {
        cout << "1. Get Race Status" << endl;
        cout << "2. Try to Sprint (Speed)" << endl;
        cout << "3. Try to Dodge (Agility)" << endl;
        cout << "4. Try to Jump (Jump)" << endl;
        cin >> race;
        // returns your choice for ProgressRace and Get status
        if (race == 1) {
            return race;
        }

        else if (race == 2){
            return race;
        }

        else if (race == 3){
            return race;
        }

        else if (race == 4) {
            return race;
        }
    }
}

// this gives the race time, prints out your name and keep main menu running
void Race::ManageGame() {
    bool num = true;

    RaceTitle(); // call the race title function

    GetRacerInfo();
    // ends when MainMenu returns false
    while (num != false) {
        num = MainMenu();
    }
    cout << "Thanks for playing UMBC Race!" << endl;
}
