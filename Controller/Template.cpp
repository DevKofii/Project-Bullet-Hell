#include "Template.hpp"
using namespace Singleton;

void Template::test() {
    std::cout  << "test()" << std::endl;
}

Template* Template::P_SHARED_INSTANCE = NULL;

Template::Template() {

}

Template::Template(const Template&) {

}

Template* Template::getInstance() {
    // If instance does not exist, create a new instance of that object by
    // allocating new memory.
    if(P_SHARED_INSTANCE  == NULL) P_SHARED_INSTANCE = new Template();

    //Return Shared Instance
    return P_SHARED_INSTANCE;
}