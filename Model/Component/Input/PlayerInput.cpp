#include "PlayerInput.hpp"

using namespace components;

PlayerInput::PlayerInput(std::string strName) : GeneralInput(strName){
    this->bMovingLeft = false;
    this->bMovingRight = false;
    this->bMovingUp = false;
    this->bMovingDown = false;
}

void PlayerInput::perform() {
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

void PlayerInput::processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed) {
    switch(CKey) {
        case sf::Keyboard::A:
            this->bMovingLeft = bPressed;
            break;
        
        case sf::Keyboard::D:
            this->bMovingRight = bPressed;
            break;

        case sf::Keyboard::W:
            this->bMovingUp = bPressed;
            break;

        case sf::Keyboard::S:
            this->bMovingDown = bPressed;
            break;

        default:
            break;
    }
}

bool PlayerInput::getMovingLeft() {
    return this->bMovingLeft;
}

bool PlayerInput::getMovingRight() {
    return this->bMovingRight;
}

bool PlayerInput::getMovingUp() {
    return this->bMovingUp;
}

bool PlayerInput::getMovingDown() {
    return this->bMovingDown;
}