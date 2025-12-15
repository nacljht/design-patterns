#include <iostream>
#include "abstract_factory/cpp/abstract_factory.h"

void XmlOrderMainDAO::save_order_main() {
    std::cout << "xml save main" << '\n';
}

void RdbOrderMainDAO::save_order_main() {
    std::cout << "rdb save main" << '\n';
}

void XmlOrderDetailDAO::save_order_detail() {
    std::cout << "xml save detail" << '\n';
}

void RdbOrderDetailDAO::save_order_detail() {
    std::cout << "rdb save detail" << '\n';
}

OrderMainDAO* XmlDAOFactory::create_order_main_dao() {
    return new XmlOrderMainDAO();
}

OrderDetailDAO* XmlDAOFactory::create_order_detail_dao() {
    return new XmlOrderDetailDAO();
}

OrderMainDAO* RdbDAOFactory::create_order_main_dao() {
    return new RdbOrderMainDAO();
}

OrderDetailDAO* RdbDAOFactory::create_order_detail_dao() {
    return new RdbOrderDetailDAO();
}
