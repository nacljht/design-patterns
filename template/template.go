package template

import "fmt"

type Downloader interface {
	Download(string)
}

type implement interface {
	download()
	save()
}

type template struct {
	implement
	url string
}

func (t *template) Download(url string) {
	t.url = url
	fmt.Println("prepare downloading")
	t.implement.download()
	t.implement.save()
	fmt.Print("finish downloading")
}

func (t template) save() {
	fmt.Println("default save")
}

func newTemplate(impl implement) *template {
	return &template{
		implement: impl,
	}
}

type HTTPDownloader struct {
	*template
}

func (hd HTTPDownloader) download() {
	fmt.Printf("download %s via http,\n", hd.url)
}

func (hd HTTPDownloader) save() {
	fmt.Println("http save")
}

func NewHTTPDownloader() *HTTPDownloader {
	downloader := &HTTPDownloader{}
	downloader.template = newTemplate(downloader)
	return downloader
}

type FTPDownloader struct {
	*template
}

func (hd FTPDownloader) download() {
	fmt.Printf("download %s via ftp,\n", hd.url)
}

func NewFTPDownloader() *FTPDownloader {
	downloader := &FTPDownloader{}
	downloader.template = newTemplate(downloader)
	return downloader
}
