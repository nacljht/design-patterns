#include <gtest/gtest.h>
#include "abstract_factory/cpp/abstract_factory.h"
#include <string>
#include <iostream>
#include <sstream>

std::string captureStdout(std::function<void()> func) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    func();

    std::cout.rdbuf(old);
    return buffer.str();
}

TEST(DAOFACTORYTest, RdbDAOFactorytTEST) {
    DAOFactory *factory = new RdbDAOFactory();
    OrderDetailDAO *order_detail_dao = factory->create_order_detail_dao();
    OrderMainDAO *order_main_dao = factory->create_order_main_dao();
    std::string result = captureStdout([&] () {
        order_detail_dao->save_order_detail();
        order_main_dao->save_order_main();
    });
    delete factory;
    delete order_detail_dao;
    delete order_main_dao;
    EXPECT_EQ(result, "rdb save detail\nrdb save main\n");
}

TEST(DAOFACTORYTest, XmlDAOFactorytTEST) {
    DAOFactory *factory = new XmlDAOFactory();
    OrderDetailDAO *order_detail_dao = factory->create_order_detail_dao();
    OrderMainDAO *order_main_dao = factory->create_order_main_dao();
    std::string result = captureStdout([&] () {
        order_detail_dao->save_order_detail();
        order_main_dao->save_order_main();
    });
    delete factory;
    delete order_detail_dao;
    delete order_main_dao;
    EXPECT_EQ(result, "xml save detail\nxml save main\n");
}
