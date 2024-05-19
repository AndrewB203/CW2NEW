#include "gtest/gtest.h"
#include "Flyweight.h"

TEST(FlyweightFactoryTest, GetFlyweight) {
    FlyweightFactory factory;
    Flyweight* fw1 = factory.GetFlyweight("hello");
    Flyweight* fw2 = factory.GetFlyweight("world");
    Flyweight* fw3 = factory.GetFlyweight("hello");

    EXPECT_NE(fw1, fw2); // Разные состояния должны создавать разные легковесы
    EXPECT_EQ(fw1, fw3); // Одинаковое состояние должно создавать один и тот же легковес

    // Очистка
    delete fw1;
    delete fw2;
    // delete fw3; // fw3 и fw1 - это один и тот же легковес, поэтому не нужно удалять его повторно
}
