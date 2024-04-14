#include "BackgroundAction.hpp"

using namespace components;

BackgroundAction::BackgroundAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void BackgroundAction::perform() {
    BackgroundInput* pBackgroundInput = (BackgroundInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0]; 

    if(pBackgroundInput == NULL) std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    else {
        if(pBackgroundInput->getInteract()) {
            //std::cout << "Loading Test Scene" << std::endl;
            SceneManager::getInstance()->loadScene(SceneTag::TEST_SCENE);
        }
        if(pBackgroundInput->getQuit()) {
            //SceneManager::getInstance()->loadScene(SceneTag::MAIN_MENU_SCENE);
        }
    }
}