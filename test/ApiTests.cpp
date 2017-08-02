#include <gtest/gtest.h>
#include "ApiTestsFixture.h"
#include "Api.h"

TEST_F(ApiTestsFixture, MakeSureFilesExists)
{
    for (const std::string &file : filePaths)
    {
        EXPECT_TRUE(this->exists(file));
    }
}

TEST_F(ApiTestsFixture, ProcessFilePathNoOptions)
{
    for (const std::string &path : filePaths)
    {
        Api api = Api{};
        auto result = api.Process(path);

        EXPECT_EQ("Tesseract-native", result.value);
    }
}
