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
        private:
            float fSpeed;
            BotTag ETag;
        
        public:
            BotManager(std::string strName);

        public:
            void perform();

            void checkState();
            void selectState();
            void performState();
            void checkCollision();

            void delay(int ms);

        public:
            void setTag(BotTag ETag);
    };
}