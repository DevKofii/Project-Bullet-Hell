#include "TestUnitInput.hpp"

using namespace components;

TestUnitInput::TestUnitInput(std::string strName) : GeneralInput(strName) {
    this->bUp = false;
    this->bDown = false;
    this->bLeft = false;
    this->bRight = false;
    this->bShoot = false;
}

void TestUnitInput::perform() {
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

void TestUnitInput::processKeyInput(bool bPressed) {
    sf::Keyboard::Key CKey = this->CEvent.key.code;

    switch(CKey) {
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

        case sf::Keyboard::F:
            this->bShoot = bPressed;
            break;

        default:
            break;
    }
}

void TestUnitInput::resetShoot() {
    this->bShoot = false;
}

bool TestUnitInput::getUp() {
    return this->bUp;
}

bool TestUnitInput::getDown() {
    return this->bDown;
}

bool TestUnitInput::getLeft() {
    return this->bLeft;
}

bool TestUnitInput::getRight() {
    return this->bRight;
}

bool TestUnitInput::getShoot() {
    return this->bShoot;
}
