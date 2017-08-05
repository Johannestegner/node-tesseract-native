#include <gtest/gtest.h>
#include "ApiTestsFixture.h"

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
        TesseractNative::Result result = this->api->Process(path);
        EXPECT_FALSE(result.error);
        EXPECT_EQ("Tesseract-native", result.value);
    }
}


