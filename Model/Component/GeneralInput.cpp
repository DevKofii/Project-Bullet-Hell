#include "GeneralInput.hpp"

using namespace components;

/* [TODO] :
   Fill this up according to the lecture. */

GeneralInput::GeneralInput(std::string strName) : Component(strName, ComponentType::INPUT) {}

void GeneralInput::assignEvent(sf::Event CEvent) {
    this->CEvent = CEvent;
}