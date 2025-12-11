#include <string>

class Downloader {
    protected:
        virtual void request(const std::string &url) = 0;
        virtual void save();
    public:
        void download(const std::string &url);
        virtual ~Downloader() = default;
};

class HttpDownloader : public Downloader {
    protected:
        void request(const std::string &url) override;
        virtual void save() override;
};

class FtpDownloader : public Downloader {
    protected:
        void request(const std::string &url) override;
};