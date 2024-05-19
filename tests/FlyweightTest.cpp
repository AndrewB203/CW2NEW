#include "gtest/gtest.h"
#include "Flyweight.h"

class FlyweightTest : public ::testing::Test {
protected:
    Flyweight* flyweight;

    void SetUp() override {
        flyweight = new ConcreteFlyweight("test");
    }

    void TearDown() override {
        delete flyweight;
    }
};

TEST_F(FlyweightTest, GetState) {
    EXPECT_EQ(flyweight->GetState(), "test");
}

TEST_F(FlyweightTest, Operation) {
    testing::internal::CaptureStdout();
    flyweight->Operation("operation");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "ConcreteFlyweight test \\ operation\n");
}
