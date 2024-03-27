#include "BackgroundInput.hpp"

using namespace components;

BackgroundInput::BackgroundInput(std::string strName) : GeneralInput(strName) {
    this->bInteract = false;
    this->bQuit = false;
}
void BackgroundInput::perform() {
    switch(CEvent.type) {
        case sf::Event::KeyPressed:
            this->processKeyboardInput(CEvent.key.code, true);
            break;
        case sf::Event::KeyReleased:
            this->processKeyboardInput(CEvent.key.code, false);
            break;
        default:
            break;
    }
}
void BackgroundInput::processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed) {
    switch(CKey) {
        case sf::Keyboard::Space:
            this->bInteract = bPressed;
            break;

        case sf::Keyboard::Q:
            this->bQuit = bPressed;
            break;

        default:
            break;
    }
}

bool BackgroundInput::getInteract() {
    return this->bInteract;
}

bool BackgroundInput::getQuit() {
    return this->bQuit;
}