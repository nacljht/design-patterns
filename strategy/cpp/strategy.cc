#include "strategy/cpp/strategy.h"
#include <string>
#include <memory>

PaymentContext::PaymentContext(
    const std::string &sender_, const std::string &reciver_, const int money_
):sender(sender_), reciver(reciver_), money(money_) {}

Payment::Payment(const std::string &sender_,
    const std::string &reciver_,
    const int money_,
    std::shared_ptr<PaymentStrategy> strategy_) {
    context = std::make_shared<PaymentContext>(sender_, reciver_, money_);
    strategy = strategy_;
}

std::string Payment::Pay() const {
    return strategy->Pay(context);
}

std::string CacheStrategy::Pay(std::shared_ptr<PaymentContext> context) const {
    return "Pay $" + std::to_string(context->money) + " to " + context->reciver + " by cash";
}

std::string BanckStrategy::Pay(std::shared_ptr<PaymentContext> context) const {
    return "Pay $" + std::to_string(context->money) + " to " + context->reciver + " by bank account " + context->sender;
}
