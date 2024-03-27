#include "PlayerInput.hpp"

using namespace components;

PlayerInput::PlayerInput(std::string strName) : GeneralInput(strName) {
    /* [TODO] :
       Initialize ALL fields here. */
}

void PlayerInput::perform() {
    /* [TODO] :
       Switch [this->CEvent.type] and call [processKeyboardInput()]
       accordingly. */
}

void PlayerInput::processKeyboardInput(sf::Keyboard::Key inKey, bool bPressed) {
    /* [TODO] : 
       Fill this up accordingly. */
}

bool PlayerInput::getMovingLeft() {
    return this->bMovingLeft;
}

bool PlayerInput::getMovingRight() {
    return this->bMovingRight;
}
