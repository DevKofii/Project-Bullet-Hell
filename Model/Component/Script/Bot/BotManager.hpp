#pragma once

#include "../../../../Config/Settings.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include "SFML/Graphics.hpp"
#include "../../Component.hpp"
#include "../../../Enum/ComponentType.hpp"
#include "../../../Enum/BotTag.hpp"
#include "../../../GameObject.hpp"
#include "../../../Entity/TestEnemy.hpp"
#include "../../Input/Bot/BotInput.hpp"

#include "../../../../Controller/Manager/GameObjectManager.hpp"


namespace components {
    using namespace managers;
    using namespace models;
    using namespace entities;
    using namespace std::this_thread;    
    using namespace std::chrono_literals;
    using std::chrono::system_clock;
    class BotManager : public Component {
        protected:
            float fSpeed;
            BotTag ETag;
            sf::Clock delayTimer;
            sf::Int32 delayTimerMax;

            int select;
        
        public:
            BotManager(std::string strName);

        public:
            void perform();

            void checkState();
            void selectState();
            void performState();
            void checkCollision();

            void delay();

        public:
            void setTag(BotTag ETag);

            const bool getDelayTimer();
    };
}