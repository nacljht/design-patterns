#include <iostream>
#include "template/cpp/template.h"

void Downloader::download(const std::string &url) {
    std::cout << "prepare downloading" << "\n";
    request(url);
    save();
    std::cout << "finish downloading";
}

void Downloader::save() {
    std::cout << "default save" << "\n";
}

void HttpDownloader::request(const std::string &url) {
    std::cout << "download " << url << " via http,\n";
}

void HttpDownloader::save() {
    std::cout << "http save\n";
}

void FtpDownloader::request(const std::string &url) {
    std::cout << "download " << url << " via ftp,\n";
}
