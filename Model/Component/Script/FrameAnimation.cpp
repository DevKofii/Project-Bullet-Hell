#include "FrameAnimation.hpp"

using namespace components;

FrameAnimation::FrameAnimation(std::string strName) : Component(strName,ComponentType::SCRIPT) {
    this->fFrameInterval = 0.10f;
    this->fTicks = 0.0f;
    this->nFrame = 0;
}

void FrameAnimation::perform() {
    TestUnit* pUnitOwner = (TestUnit*)this->pOwner;
    TestUnitInput* pUnitInput = (TestUnitInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];

    if(pUnitOwner == NULL && pUnitInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        if(pUnitInput->getRight() || pUnitInput->getLeft() || pUnitInput->getUp() || pUnitInput->getDown()) {
            this->fTicks += this->tDeltaTime.asSeconds();
            if(this->fTicks > this->fFrameInterval) {
                this->fTicks = 0.0f;
                this->nFrame += 1;
                if(this->nFrame > 8) this->nFrame = 0;
            }
            pUnitOwner->setFrame(this->nFrame);
        }
        else {
            this->nFrame = 0;
            pUnitOwner->setFrame(this->nFrame);
        }
    }
}