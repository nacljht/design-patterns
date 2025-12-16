#include "state/cpp/state.h"

void Context::Next() {
    State *old_state = state;
    old_state->Handle(this);
    delete old_state;
}

Context::~Context() {
    if(state != nullptr) {
        delete state;
    }
}

void DayState::Handle(Context *ctx) {
    const std::string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for(int i=0; i<7; ++i) {
        if(days[i] == day) {
            ctx->Set(new DayState(days[(i+1)%7]));
        }
    }
}

std::string DayState::Get() const {
    return day;
}

void Context::Set(State *state_) {
    state = state_;
}

DayContext::DayContext() {
    state = new DayState("Sunday");
}

std::string DayContext::Today() const {
    if(state == nullptr) {
        return "Can not get today";
    }
    return state->Get();
}
