#include "observer/cpp/observer.h"
#include <string>
#include <iostream>

void Subject::attach(Observer *o) {
    observers.push_back(o);
}

void Subject::update_context(const std::string &message) {
    this->message = message;
    for(auto o : observers) {
        o->notify(this);
    }
}

std::string Subject::get_message() {
    return message;
}


void Reader::notify(Subject *s) {
    message = s->get_message();
}

std::string Reader::get_message() {
    return message;
}
