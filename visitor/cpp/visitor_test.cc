#include <gtest/gtest.h>
#include "visitor/cpp/visitor.h"

std::string captureStdout(std::function<void()> func) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    func();

    std::cout.rdbuf(old);
    return buffer.str();
}

TEST(VisitorTest, ServiceRequestVisitor) {
    CustomerCol c;
    c.add(new EnterpriseCustomer("A company"));
    c.add(new EnterpriseCustomer("B company"));
    c.add(new IndividualCustomer("bob"));

    std::string rsp = captureStdout([&]() {
        c.accept(new ServiceRequestVisitor());
    });

    std::string expect =
        "serving enterprise customer A company\n"
        "serving enterprise customer B company\n"
        "serving individual customer bob\n";

    EXPECT_EQ(rsp, expect);
}

TEST(VisitorTest, AnalysisVisitor) {
    CustomerCol c;
    c.add(new EnterpriseCustomer("A company"));
    c.add(new IndividualCustomer("bob"));
    c.add(new EnterpriseCustomer("B company"));

    std::string rsp = captureStdout([&]() {
        c.accept(new AnalysisVisitor());
    });

    std::string expect =
        "analysis enterprise customer A company\n"
        "analysis enterprise customer B company\n";

    EXPECT_EQ(rsp, expect);
}
