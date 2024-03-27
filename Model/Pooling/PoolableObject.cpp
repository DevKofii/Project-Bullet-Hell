#include "PoolableObject.hpp"

using namespace poolables;

PoolableObject::PoolableObject(PoolTag ETag, std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
    this->ETag = ETag;
}

PoolableObject::~PoolableObject() {}

void PoolableObject::attachOwner(GameObject* pOwner) {
    this->pOwner = pOwner;
}

void PoolableObject::detachOwner() {
    delete this;
}

GameObject* PoolableObject::getOwner() {
    return this->pOwner;
}

PoolTag PoolableObject::getTag() {
    return this->ETag;
}

