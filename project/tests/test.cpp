#include "square.hpp"

#include <gtest/gtest.h>

// TEST(MyMatrix, MatrixSubstractCol) {
//     EXPECT_EQ(square(2), 4);
// }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    auto num = square(2); // чтобы не ругался на unused functions
    ++num; //
    num -= 2; //
    num *= 3; //
}
