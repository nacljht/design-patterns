#include <string>
#include <memory>

class PaymentContext {
    public:
        std::string sender;
        std::string reciver;
        int money;
        PaymentContext(const std::string &sender_, const std::string &reciver_, const int money_);
        virtual ~PaymentContext() = default;
};

class PaymentStrategy {
    public:
        virtual std::string Pay(std::shared_ptr<PaymentContext> context) const = 0;
        virtual ~PaymentStrategy() = default;
};

class Payment {
    std::shared_ptr<PaymentContext> context;
    std::shared_ptr<PaymentStrategy> strategy;
    public:
        Payment(const std::string &sender_, const std::string &reciver_, const int money_, std::shared_ptr<PaymentStrategy> strategy_);
        virtual ~Payment() = default;
        std::string Pay() const;
};

class CacheStrategy: public PaymentStrategy {
    public:
        std::string Pay(std::shared_ptr<PaymentContext> context) const override;
};

class BanckStrategy: public PaymentStrategy {
    public:
        std::string Pay(std::shared_ptr<PaymentContext> context) const override;
};