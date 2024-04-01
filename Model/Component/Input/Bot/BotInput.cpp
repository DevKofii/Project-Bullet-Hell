#include "BotInput.hpp"

using namespace components;

BotInput::BotInput(std::string strName) : GeneralInput(strName) {
    this->bUp = false;
    this->bDown = false;
    this->bLeft = false;
    this->bRight = false;
    this->bShoot = false;
}

void BotInput::perform() {
    // switch(this->CEvent.type) {
    //     case sf::Event::KeyPressed:
    //         this->processKeyInput(true);
    //         break;

    //     case sf::Event::KeyReleased:
    //         this->processKeyInput(false);
    //         break;

    //     default:
    //         break;
    // }
}

void BotInput::resetAll() {
    this->bUp = false;
    this->bDown = false;
    this->bLeft = false;
    this->bRight = false;
    this->bShoot = false;
}

bool BotInput::getUp() {
    return this->bUp;
}

bool BotInput::getDown() {
    return this->bDown;
}

bool BotInput::getLeft() {
    return this->bLeft;
}

bool BotInput::getRight() {
    return this->bRight;
}

bool BotInput::getShoot() {
    return this->bShoot;
}

void BotInput::setUp(bool bPressed) {
    this->bUp = bPressed;
}

void BotInput::setDown(bool bPressed) {
    this->bDown = bPressed;
}

void BotInput::setLeft(bool bPressed) {
    this->bLeft = bPressed;
}

void BotInput::setRight(bool bPressed) {
    this->bRight = bPressed;
}