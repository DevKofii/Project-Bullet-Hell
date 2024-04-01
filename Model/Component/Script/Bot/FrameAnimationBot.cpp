#include "FrameAnimationBot.hpp"

using namespace components;

FrameAnimationBot::FrameAnimationBot(std::string strName) : Component(strName,ComponentType::SCRIPT) {
    this->fFrameInterval = 0.10f;
    this->fTicks = 0.0f;
    this->nFrame = 0;
}

void FrameAnimationBot::perform() {
    TestEnemy* pEnemy = (TestEnemy*)this->pOwner;
    BotInput* pInput = (BotInput*) this->getOwner()->getComponents(ComponentType::INPUT)[0];

    if(pEnemy == NULL && pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        if(pInput->getRight() || pInput->getLeft() || pInput->getUp() || pInput->getDown()) {
            this->fTicks += this->tDeltaTime.asSeconds();
            if(this->fTicks > this->fFrameInterval) {
                this->fTicks = 0.0f;
                this->nFrame += 1;
                if(this->nFrame > 8) this->nFrame = 0;
            }
            pEnemy->setFrame(this->nFrame);
        }
        else {
            this->nFrame = 0;
            pEnemy->setFrame(this->nFrame);
        }
    }
}