#include "ApiTests.h"
#include "Api.h"

TEST_F(ApiTest, MakeSureFilesExists)
{
    for (const std::string &file : filePaths)
    {
        EXPECT_TRUE(this->exists(file));
    }
}

TEST_F(ApiTest, GetInstance)
{
    EXPECT_NO_THROW(Api::GetInstance());
}

TEST_F(ApiTest, ProcessFilePathNoOptions)
{
    for (const std::string &path : filePaths)
    {
        Api& api = Api::GetInstance();
        auto result = api.Process(path);

        EXPECT_EQ("Tesseract-native", result.value);
    }
}
