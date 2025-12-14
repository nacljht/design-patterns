#include <gtest/gtest.h>
#include "observer/cpp/observer.h"
#include <vector>

TEST(ObserverTest, ReaderTest) {
    Subject subject = Subject();
    // 这里不能用Reader然后emplace_back(&readers[i])，vector动态扩容的时候地址会变！
    std::vector<Reader*> readers;
    for(int i=0; i<3; ++i) {
        readers.emplace_back(new Reader());
        subject.attach(readers[i]);
    }
    subject.update_context(std::string("hello reader"));
    for(int i=0; i<3; ++i) {
        EXPECT_EQ(readers[i]->get_message(), "hello reader");
        delete readers[i];
    }
}
