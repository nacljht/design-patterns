#include <gtest/gtest.h>
#include "strategy/cpp/strategy.h"
#include <string>

TEST(PaymentTest, CashPay) {
    Payment p("alice", "bob", 100, std::make_shared<CacheStrategy>());

    std::string out = p.Pay();
    std::string want = "Pay $100 to bob by cash";

    EXPECT_EQ(out, want);
}

TEST(PaymentTest, BankPay) {
    Payment p("alice-bank", "bob", 200, std::make_shared<BanckStrategy>());

    std::string out = p.Pay();
    std::string want = "Pay $200 to bob by bank account alice-bank";

    EXPECT_EQ(out, want);
}
