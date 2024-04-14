#include "ScoreManager.hpp"

using namespace managers;

void ScoreManager::addPlayerScore() {
    this->playerScore += 1;
}
void ScoreManager::addEnemyScore() {
    this->enemyScore += 1;
}

int ScoreManager::returnPlayerScore() {
    return this->playerScore;
}

int ScoreManager::returnEnemyScore() {
    return this->enemyScore;
}


ScoreManager* ScoreManager::P_SHARED_INSTANCE = NULL;

ScoreManager::ScoreManager() {
    this->playerScore = 0;
    this->enemyScore = 0;
}

ScoreManager::ScoreManager(const ScoreManager&) {}

ScoreManager* ScoreManager::getInstance() {
    // If instance does not exist, create a new instance of that object by
    // allocating new memory.
    if(P_SHARED_INSTANCE  == NULL) P_SHARED_INSTANCE = new ScoreManager();

    //Return Shared Instance
    return P_SHARED_INSTANCE;
}