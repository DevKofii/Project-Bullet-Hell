#include "ShipInput.hpp"

using namespace components;

ShipInput::ShipInput(std::string strName) : GeneralInput(strName) {
    this->bSpace = false;
    this->bUp = false;
    this->bDown = false;
    this->bLeft = false;
    this->bRight = false;
}

void ShipInput::perform() {
    switch(this->CEvent.type) {
        case sf::Event::KeyPressed:
            this->processKeyInput(true);
            break;
            
        case sf::Event::KeyReleased:
            this->processKeyInput(false);
            break;

        default:
            break;
    }
}

void ShipInput::processKeyInput(bool bPressed) {
    sf::Keyboard::Key CKey = this->CEvent.key.code;

    switch(CKey) {
        case sf::Keyboard::F:
            this->bSpace = bPressed;
            break;

        case sf::Keyboard::W:
            this->bUp = bPressed;
            break;

        case sf::Keyboard::S:
            this->bDown = bPressed;
            break;

        case sf::Keyboard::A:
            this->bLeft = bPressed;
            break;

        case sf::Keyboard::D:
            this->bRight = bPressed;
            break;

        default:
            break;
    }
}

void ShipInput::resetSpace() {
    this->bSpace = false;
}

bool ShipInput::getSpace() {
    return this->bSpace;
}

bool ShipInput::getUp() {
    return this->bUp;
}

bool ShipInput::getDown() {
    return this->bDown;
}

bool ShipInput::getLeft() {
    return this->bLeft;
}

bool ShipInput::getRight() {
    return this->bRight;
}
