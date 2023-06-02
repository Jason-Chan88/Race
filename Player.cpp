#include "Player.h"

// this function is your player for the game
Player::Player() {
    m_name = "Beannie";

    // sets all the stats to the constant START_STAT
    for (int i = 0; i < NUM_STATS; i++) {
        m_stat[i] = START_STAT;
    }

    m_races = 0;
    m_wins = 0;
    m_falls = 0;
}

// this is the overloaded function for player, same thing as above
Player::Player(string name) {

    SetName(name);

    for (int i = 0; i < NUM_STATS; i++) {
        m_stat[i] = START_STAT;
    }

    m_races = 0;
    m_wins = 0;
    m_falls = 0;
}

// returns player name
string Player::GetName() {
    return m_name;
}

// sets player name
void Player::SetName(string name) {
    m_name = name;
}

// returns speed stat
int Player::GetSpeed() {
    return m_stat[0];
}

// returns agility stat
int Player::GetAgility() {
    return m_stat[1];
}

// returns jump stat
int Player::GetJump() {
    return m_stat[2];
}

// returns race stat
int Player::GetRaces() {
    return m_races;
}

// returns fall stat
int Player::GetFalls() {
    return m_falls;
}

//sets number of races
void Player::SetRaces(int races) {
    m_races = races;
}

// sets number of falls
void Player::SetFalls(int falls) {
    m_falls = falls;
}

// Displays all the player info through Getters mostly
void Player::DisplayStatus() {
    cout << "*****The Mighty Racer" << " " << GetName() << " **********" << endl;
    cout << "Races: " << GetRaces() << endl;
    cout << "Wins: " << m_wins << endl;
    cout << "Falls: " << GetFalls() << "\n" << endl;

    cout << "Stats" << endl;
    cout << "Speed: " << GetSpeed() << endl;
    cout << "Agility: " << GetAgility() << endl;
    cout << "Jump: " << GetJump() << endl;
}

// increase the stat you wish up until it hits MAX_stat of 10 than you'll need to choose another
void Player::IncreaseStat() {
    bool one = m_stat[0] == MAX_STAT;  // all the bool are checking if all stats are 10 than it's true
    bool two = m_stat[1] == MAX_STAT;
    bool three = m_stat[2] == MAX_STAT;
    int input = 0;

    // if all stats are 10 it will say you maxed out and take you to main menu
    if (one and two and three) {
        cout << "You are maxed out at stats" << endl;
    }

    // if they don't equal 10 than it ask you what to increase
    else {
        // for reprompting, makes sure input is between 1-3 and giving input
        while (input < 1 || input > 3) {
            cout << "Which stat would you like to increase?" << endl;
            cout << "1. Speed" << endl;
            cout << "2. Agility" << endl;
            cout << "3. Jump" << endl;
            cin >> input;
            // for reprompting when the stat you want to increase is 10, it will force you to choose another
            while (m_stat[input-1] >= MAX_STAT) {
                cout << "Choose another stat to increase" << endl;
                cout << "1. Speed" << endl;
                cout << "2. Agility" << endl;
                cout << "3. Jump" << endl;
                cin >> input;
            }
        }
        // increase the stat you said to by 1
        m_stat[input-1] += 1;
    }
}

// returns a specific stat
int Player::GetStat(int stat) {
    return m_stat[stat];
}

// increments wins
void Player::IncreaseWins() {
    m_wins += 1;
}