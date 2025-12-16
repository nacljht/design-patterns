#include <gtest/gtest.h>
#include "state/cpp/state.h"

TEST(TestState, TestDayState) {
    DayContext ctx = DayContext();
     const std::string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
     for(int i=0; i<8; ++i) {
        EXPECT_EQ(ctx.Today(), days[i%7]);
        ctx.Next();
     }
}
