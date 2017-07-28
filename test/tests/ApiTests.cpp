#include <gtest/gtest.h>
#include "Api.h"
#if defined(_WIN32) || defined(__CYGWIN__)
#include <Windows.h>
#endif

#include <fstream>

std::string GetExeDir()
{
#if defined(_WIN32) || defined(__CYGWIN__)
    CHAR buf[1024] = { 0 };
    auto ret = GetModuleFileName(nullptr, buf, sizeof(buf));
    auto res = std::string(buf);

#elif defined(__linux)
#include <limits.h>
#include <unistd.h>
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    auto res std::wstring(result, (count > 0) ? count : 0);
#else
#error Invalid OS version. Currently the Test application only supports Windows and Linux.
#endif
    return res.substr(0, res.find_last_of('\\'));
}

struct ApiTest : public ::testing::Test
{
protected:
    void SetUp() override {
         std::string exeDir = GetExeDir();
         filePaths.push_back(exeDir + "\\resources\\test.bmp");
         filePaths.push_back(exeDir + "\\resources\\test.jpg");
         filePaths.push_back(exeDir + "\\resources\\test.png");
         filePaths.push_back(exeDir + "\\resources\\test.tif");
     }

     std::vector<std::string > filePaths;
};

inline bool exists(const std::string& name) {

    std::ifstream file(name.c_str());
    bool result = file.good();
    file.close();
    return result;
}

TEST_F(ApiTest, MakeSureFilesExists)
{
    for (const std::string &file : filePaths)
    {
        EXPECT_TRUE(exists(file));
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

