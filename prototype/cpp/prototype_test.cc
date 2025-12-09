#include <gtest/gtest.h>
#include "prototype/cpp/prototype.h"
#include <string>

TEST(PrototypeTest, PrototypeManager) {
    PrototypeManager manager;
    manager.set("1", new Cloneable1("type1"));

    Cloneable1 *proto1 = static_cast<Cloneable1*>(manager.get("1"));
    Cloneable1 *proto2 = static_cast<Cloneable1*>(manager.get("1"));


    EXPECT_EQ(proto1->get_name(), proto2->get_name());
    ASSERT_EQ(proto1, proto2);
}
