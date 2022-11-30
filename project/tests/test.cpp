// #include "square.hpp" // чтобы не ругался на unused functions

#include <gtest/gtest.h>

TEST(Test, MyTest) {
    EXPECT_EQ(1, 1);
} // чтобы не ругался на unused functions

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
