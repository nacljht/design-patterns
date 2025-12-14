#include <gtest/gtest.h>
#include "builder/cpp/builder.h"

TEST(BuilderTest, Builder1Test) {
    Builder1 builder1 = Builder1();
    Director director = Director(&builder1);
    director.direct();
    EXPECT_EQ("123", builder1.get_result());
}

TEST(BuilderTest, Builder2Test) {
    Builder2 builder2 = Builder2();
    Director director = Director(&builder2);
    director.direct();
    EXPECT_EQ(6, builder2.get_result());
}
