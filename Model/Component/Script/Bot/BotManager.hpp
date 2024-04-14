#pragma once

#include "../../../../Config/Settings.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "../../Component.hpp"
#include "../../../Enum/ComponentType.hpp"
#include "../../../Enum/BotTag.hpp"
#include "../../../Enum/StateTag.hpp"
#include "../../../GameObject.hpp"
#include "../../../Entity/TestEnemy.hpp"
#include "../../../Entity/TestUnit.hpp"
#include "../../../Entity/Collider.hpp"
#include "../../../Entity/Shadow.hpp"

#include "../../../../Controller/Manager/GameObjectManager.hpp"

namespace components {
    using namespace managers;
    using namespace models;
    using namespace entities;
    using namespace poolables;
    using namespace std::this_thread;    
    using namespace std::chrono_literals;
    using std::chrono::system_clock;
    class BotManager : public Component {
        protected:
            float fSpeed;
            BotTag ETag;
            sf::Clock delayTimer;
            float delayTimerMax;
            float delayTimerMaxLonger;
            int select;

            StateTag curState;

        public:
            BotManager(std::string strName);

        public:
            void perform();

            void selectState();            
            void performState();
            void checkCollision();

        public:

            bool isValidFOV();
            bool isValidCollider();
            void chaseTarget();
            void attack();
            void setTag(BotTag ETag);
            sf::Vector2f normalize(sf::Vector2f vec);
            const bool getDelayTimer();
            const bool getDelayTimerLonger();

            StateTag getState();
            void setState(StateTag ETag);
    };
}