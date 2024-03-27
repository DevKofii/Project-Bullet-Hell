#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string strName, AnimatedTexture* pTexture) {
    this->bEnabled = true;
    this->strName = strName;
    this->pSprite = new sf::Sprite();
    this->pTexture = pTexture;
    this->setFrame(1);
    this->nCurrentFrame = 0;
    this->pParent = NULL;
    this->vecChildren = {};
}

GameObject::GameObject(std::string strName, float fSpeed, AnimatedTexture* pTexture) {
    this->bEnabled = true;
    this->strName = strName;
    this->fSpeed = fSpeed;
    this->pSprite = new sf::Sprite();
    this->pTexture = pTexture;
    this->setFrame(0);
    this->nCurrentFrame = 0;
    this->pParent = NULL;
    this->vecChildren = {};
}

void GameObject::processEvents(sf::Event CEvent) {
    std::vector<Component*> vecInputs = this->getComponents(ComponentType::INPUT);

    for(Component* pComponent : vecInputs) {
        GeneralInput* pGeneralInput = (GeneralInput*)pComponent;
        pGeneralInput->assignEvent(CEvent);
        pGeneralInput->perform();
    }
}

void GameObject::update(sf::Time tDeltaTime) {
    std::vector<Component*> vecScripts = this->getComponents(ComponentType::SCRIPT);

    for(Component* pComponent : vecScripts) {
        pComponent->setDeltaTime(tDeltaTime);
        pComponent->perform();
    }
}

void GameObject::draw(sf::RenderWindow* pWindow) {
    std::vector<Component*> vecRenderers = this->getComponents(ComponentType::RENDERER);

    for(Component* pComponent : vecRenderers) {
        Renderer* pRenderer = (Renderer*)pComponent;
        pRenderer->assignTargetWindow(pWindow);
        pRenderer->perform();
    }
}

void GameObject::attachComponent(Component* pComponent) {
    this->vecComponents.push_back(pComponent);
    pComponent->attachOwner(this);
}

void GameObject::detachComponent(Component* pComponent) {
    int nIndex = -1;
    for(int i = 0; i < this->vecComponents.size(); i++) {
        if(this->vecComponents[i] == pComponent) {
            nIndex = i;
            break;
        }
    }

    if(nIndex != -1) {
        this->vecComponents[nIndex]->detachOwner();
        this->vecComponents.erase(this->vecComponents.begin() + nIndex);
    }

}

void GameObject::attachChild(GameObject* pChild) {
    this->vecChildren.push_back(pChild);
    pChild->setParent(this);
    pChild->initialize();
}

void GameObject::detachChild(GameObject* pChild) {
    int nIndex = -1;
    for(int i = 0; i < this->vecChildren.size() && nIndex == -1; i++) {
        if(this->vecChildren[i] == pChild) {
            nIndex = i;
        }
    }

    if(nIndex != -1)
        this->vecChildren.erase(this->vecChildren.begin() + nIndex);
}

Component* GameObject::findComponentByName(std::string strName) {
    // for(int i = -1; i < this->vecComponents.size(); i++) {
    //      if(this->vecComponents[i]->getName() == strName) { 
    //          return this->vecComponents[i];
    //      }
    //  }
    // //return NULL;

    for(Component* pComponent : this->vecComponents) {
        if(pComponent->getName() == strName)
            return pComponent;
    }
    
    std::cout << "[ERROR] : Component [" << strName << "] NOT found." << std::endl;
    return NULL;
}

std::vector<Component*> GameObject::getComponents(ComponentType EType) {
    std::vector <Component*> vecFound = {};
    for(Component* pComponent : this->vecComponents) {
        if(pComponent->getType() == EType) {
            vecFound.push_back(pComponent);
        }
    }
    return vecFound;
}

void GameObject::centerOrigin() {
    if(this->pTexture != NULL) {
        int nWidth = this->pSprite->getTexture()->getSize().x;
        int nHeight = this->pSprite->getTexture()->getSize().y;

        this->pSprite->setOrigin(nWidth/2,nHeight/2);
    }
}

bool GameObject::getEnabled() {
    return this->bEnabled;
}

std::string GameObject::getName() {
    return this->strName;
}

sf::Sprite* GameObject::getSprite() {
    return this->pSprite;
}

void GameObject::setTexture(AnimatedTexture* pTexture) {
    this->pTexture = pTexture;
    //this->pSprite->setTexture(*this->pTexture->getFrame());
}

void GameObject::setSpeed(float fSpeed) {
    this->fSpeed = fSpeed;
}

float GameObject::getSpeed() {
    return this->fSpeed;
}

void GameObject::setFrame(int nFrame) {
    int nWidth = this->pTexture->getFrame()->getSize().x;
    int nHeight = this->pTexture->getFrame()->getSize().y;

    if(this->pTexture != NULL) {
        this->pTexture->setCurrentFrame(nFrame);
        this->pSprite->setTexture(*this->pTexture->getFrame());
        this->pSprite->setTextureRect(sf::IntRect(0,0,nWidth,nHeight));
    }
}

void GameObject::setEnabled(bool bEnabled) {
    this->bEnabled = bEnabled;
}

void GameObject::setOrientationRight(bool bRight) {
    this->bOrientRight = bRight;
}

void GameObject::setOrientationLeft(bool bLeft) {
    this->bOrientLeft = bLeft;
}

bool GameObject::getOrientationRight() {
    return this->bOrientRight;
}

bool GameObject::getOrientationLeft() {
    return this->bOrientLeft;
}

GameObject* GameObject::getParent() {
    return this->pParent;
}

void GameObject::setParent(GameObject* pParent) {
    this->pParent = pParent;
}

sf::Vector2f GameObject::getPosition() {
    return this->pSprite->getPosition();
}

void GameObject::setPosition(sf::Vector2f vecPosition) {
    this->pSprite->setPosition(vecPosition);
}

void GameObject::setScale(sf::Vector2f vecScale) {
    this->pSprite->setScale(vecScale);
}