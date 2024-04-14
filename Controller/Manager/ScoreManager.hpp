#pragma once

#include "iostream"
#include "unordered_map"

namespace managers {
    class ScoreManager {
        private:
            int playerScore;
            int enemyScore;
        
        public:
            void addPlayerScore();
            void addEnemyScore();

            int returnPlayerScore();
            int returnEnemyScore();
            
        private:
            static ScoreManager* P_SHARED_INSTANCE;
            ScoreManager();
            ScoreManager(const ScoreManager&);
            ScoreManager& operator = (const ScoreManager&);

        public:
            static ScoreManager* getInstance();
    };
}
