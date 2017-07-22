#include <gtest/gtest.h>
#include "Api.h"

std::string filePath = "test.jpg";

TEST(APITests, GetInstance)
{
    EXPECT_NO_THROW(Api::GetInstance());
}

TEST(APITests, ProcessFilePathNoOptions)
{
    Api::GetInstance().Process(filePath);
}

