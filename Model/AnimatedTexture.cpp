#include "AnimatedTexture.hpp"

using namespace models;

AnimatedTexture::AnimatedTexture(std::vector<sf::Texture*> vecFrames) {
    this->vecFrames = vecFrames;
    this->nCurrentFrame = 0;
}

void AnimatedTexture::incrementFrame() {
    this->setCurrentFrame(this->nCurrentFrame + 1);
    
}

sf::Texture* AnimatedTexture::getFrame() {
    return this->vecFrames[this->nCurrentFrame];
}

void AnimatedTexture::setCurrentFrame(int nCurrentFrame) {
    if(nCurrentFrame >= 0 && nCurrentFrame < this->vecFrames.size()) {
        this->nCurrentFrame = nCurrentFrame;
        //std::cout << "Increment" << std::endl;
    }
    else this->nCurrentFrame = 0;
}