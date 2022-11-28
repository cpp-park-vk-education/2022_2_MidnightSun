// #include "square.hpp" // чтобы не ругался на unused functions

#include <gtest/gtest.h>

// TEST(MyMatrix, MatrixSubstractCol) {
//     EXPECT_EQ(square(2), 4);
// } // чтобы не ругался на unused functions

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
