#include "template/cpp/template.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <sstream>

std::string captureStdout(std::function<void()> func) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    func();

    std::cout.rdbuf(old);
    return buffer.str();
}

TEST(DownloaderTest, HTTPDownloader) {
    Downloader* downloader = new HttpDownloader();

    std::string rsp = captureStdout([&]() {
        downloader->download("http://example.com/abc.zip");
    });

    std::string expect =
        "prepare downloading\n"
        "download http://example.com/abc.zip via http,\n"
        "http save\n"
        "finish downloading";

    EXPECT_EQ(rsp, expect);

    delete downloader;
}

TEST(DownloaderTest, FTPDownloader) {
    Downloader* downloader = new FtpDownloader();

    std::string rsp = captureStdout([&]() {
        downloader->download("ftp://example.com/abc.zip");
    });

    std::string expect =
        "prepare downloading\n"
        "download ftp://example.com/abc.zip via ftp,\n"
        "default save\n"
        "finish downloading";

    EXPECT_EQ(rsp, expect);

    delete downloader;
}
