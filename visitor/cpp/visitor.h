#include <vector>
#include <string>

class Customer;

class Visitor {
    public:
        virtual ~Visitor() = default;
        virtual void visit(Customer *c) = 0;
};

class Customer {
    public:
        virtual ~Customer() = default;
        virtual void accept(Visitor *v);
};

class CustomerCol : public Customer {
    private:
        std::vector<Customer*> customers;
    public:
        ~CustomerCol() = default;
        void add(Customer *c);
        void accept(Visitor *v) override;
};

class EnterpriseCustomer : public Customer {
    private:
        std::string name;
    public:
        EnterpriseCustomer(const std::string &name_);
        ~EnterpriseCustomer() override;
        // void accept(Visitor *v) override;
        std::string get_name();
};

class IndividualCustomer : public Customer {
    private:
        std::string name;
    public:
        IndividualCustomer(const std::string &name_);
        ~IndividualCustomer() override;
        // void accept(Visitor *v) override;
        std::string get_name();
};

class ServiceRequestVisitor : public Visitor {
    public:
        ~ServiceRequestVisitor() = default;
        void visit(Customer *c) override;
};

class AnalysisVisitor : public Visitor {
    public:
        ~AnalysisVisitor() = default;
        void visit(Customer *c) override;
};
