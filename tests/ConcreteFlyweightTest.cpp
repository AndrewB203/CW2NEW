#include "gtest/gtest.h"
#include "Flyweight.h"

TEST(ConcreteFlyweightTest, Construction) {
    testing::internal::CaptureStdout();
    ConcreteFlyweight flyweight("test");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "ConcreteFlyweight Build...test\n");
}

TEST(ConcreteFlyweightTest, Operation) {
    ConcreteFlyweight flyweight("test");
    testing::internal::CaptureStdout();
    flyweight.Operation("operation");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "ConcreteFlyweight test \\ operation\n");
}
