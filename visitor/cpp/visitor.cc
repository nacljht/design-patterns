#include "visitor/cpp/visitor.h"
#include <iostream>

void CustomerCol::add(Customer *c) {
    customers.push_back(c);
}

void CustomerCol::accept(Visitor *v) {
    for(auto c : customers) {
        v->visit(c);
    }
}

void Customer::accept(Visitor *v) {
    v->visit(this);
}

EnterpriseCustomer::EnterpriseCustomer(const std::string &name_):name(name_) {}

// void EnterpriseCustomer::accept(Visitor *v) {
//     v->visit(this);
// }

std::string EnterpriseCustomer::get_name() {
    return this->name;
}

EnterpriseCustomer::~EnterpriseCustomer() = default;

IndividualCustomer::IndividualCustomer(const std::string &name_):name(name_) {}

// void IndividualCustomer::accept(Visitor *v) {
//     v->visit(this);
// }

std::string IndividualCustomer::get_name() {
    return this->name;
}

IndividualCustomer::~IndividualCustomer() = default;

void ServiceRequestVisitor::visit(Customer *c) {
    if(auto ec = dynamic_cast<EnterpriseCustomer*>(c)) {
        std::cout << "serving enterprise customer " << ec->get_name() << "\n";
        return;
    }
    if(auto ic = dynamic_cast<IndividualCustomer*>(c)) {
        std::cout << "serving individual customer " << ic->get_name() << "\n";
        return;
    }
}

void AnalysisVisitor::visit(Customer *c) {
    if(auto ec = dynamic_cast<EnterpriseCustomer*>(c)) {
        // fmt.Printf("serving enterprise customer %s\n", c.name)
        std::cout << "analysis enterprise customer " << ec->get_name() << "\n";
        return;
    }
}