#include "Track.h"

// creates a track and sets the position of all 4 players at 0
Track::Track() {

    // sets the 4 racers location to 0 on track
    for (int i = 0; i < NUM_RACERS; i++){
        m_track[i] = 0;
    }

    m_length = DEFAULT_LENGTH;
}

// sets the length of the race
void Track::SetLength(int length) {
    m_length = length;
}

// gives every location on the track a random obstacle ranging from speed, agility, and jump
void Track::PopulateObstacles() {

    for (int i = 0; i < m_length; i++) {
        m_obstacle[i] = rand() % 3;
    }

}

// Displays what obstacle the player is at also there current location on the track out of the length of the race
void Track::GetStatus() {

    cout << "You are on a " << OBSTACLE_TYPE[GetObstacle(m_track[0])] << " obstacle (obstacle " << m_track[0]+1 << " of " << m_length << ")" << endl;
    cout << "Player 1 is on a " << OBSTACLE_TYPE[GetObstacle(m_track[1])] << " obstacle in (obstacle " << m_track[1]+1 << " of " << m_length << ")" << endl;
    cout << "Player 2 is on a " << OBSTACLE_TYPE[GetObstacle(m_track[2])] << " obstacle in (obstacle " << m_track[2]+1 << " of " << m_length << ")" << endl;
    cout << "Player 3 is on a " << OBSTACLE_TYPE[GetObstacle(m_track[3])] << " obstacle in (obstacle " << m_track[3]+1 << " of " << m_length << ")" << endl;
}

// if the location of a racer is past length than they win also ties goes to player than if 1 v 2 it goes to to 1
int Track::CheckWin() {

    if (m_track[0] > (m_length-1)) {
        return 0;
    }

    else if (m_track[1] > (m_length-1)) {
        return 1;
    }

    else if (m_track[2] > (m_length-1)) {
        return 2;
    }

    else if (m_track[3] > (m_length-1)) {
        return 3;
    }

    else{
        return -1;
    }
}

// returns a obstacle at a certain location
int Track::GetObstacle(int location) {
    return m_obstacle[location];
}

// if players gets past a obstacle, it increments the location
void Track::IncrementLocation(int player) {
    m_track[player] += 1;
}

// resets the location of the racer after every race back to 0
void Track::ResetLocation() {

    for (int i = 0; i < NUM_RACERS; i++) {
        m_track[i] = {0};
    }

}

// Converts the obstacle the player is at to an obstacle
string Track::ConvertObstacle(int player) {
    // My track takes in a location, my obstacle takes in the obstacle at that location than that obstacle
    // is put into Obstacle type and converted into a string
    return OBSTACLE_TYPE[m_obstacle[m_track[player]]];
}
