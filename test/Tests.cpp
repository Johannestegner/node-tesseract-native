#include <gtest/gtest.h>

using ::testing::InitGoogleTest;

int main(int argc, char **argv) {
    // Run the tests!
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
