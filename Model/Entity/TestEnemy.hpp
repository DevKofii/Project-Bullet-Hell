#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Enum/BotTag.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../Component/Script/Bot/BotManager.hpp"
#include "../Component/Script/Bot/FrameAnimationBot.hpp"

namespace entities {
    using namespace models;
    class TestEnemy : public GameObject {
        private:
            const int nFrameStart = 0;
            const int nFrameEnd = 8;
            BotTag ETag;
            int random;
            int ID;
            bool move;
            bool attack;

        public:
            TestEnemy(std::string strName, AnimatedTexture* pTexture, int ID);

        public:
            void initialize();

        public:
            int getRandom();
            void setRandom();

            bool getMove();
            void setMove(bool move);

            BotTag getTag();
            void setTag(BotTag ETag);

            int getID();

            bool getAttack();
            void setAttack(bool attack);
    };
}