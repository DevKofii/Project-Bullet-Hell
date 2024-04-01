#pragma once

#include <iostream>
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
    class BotManager : public Component {
        private:
            float fSpeed;
            BotTag ETag;
        
        public:
            BotManager(std::string strName);

        public:
            void perform();

            void checkState();
            void performState();
            void checkCollision();

        public:
            void setTag(BotTag ETag);
    };
}