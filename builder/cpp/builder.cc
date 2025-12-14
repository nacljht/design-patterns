#include "builder/cpp/builder.h"
#include <string>

void Director::direct() {
    builder->buildpart1();
    builder->buildpart2();
    builder->buildpart3();
}

void Builder1::buildpart1() {
    result += "1";
}

void Builder1::buildpart2() {
    result += "2";
}

void Builder1::buildpart3() {
    result += "3";
}

std::string Builder1::get_result() {
    return result;
}

void Builder2::buildpart1() {
    result += 1;
}

void Builder2::buildpart2() {
    result += 2;
}

void Builder2::buildpart3() {
    result += 3;
}

int Builder2::get_result() {
    return result;
}
