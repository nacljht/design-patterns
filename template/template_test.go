package template

import (
	"bytes"
	"fmt"
	"io"
	"os"
	"strings"
	"testing"
)

func captureStdout(f func()) string {
	old := os.Stdout
	r, w, _ := os.Pipe()
	os.Stdout = w

	f()

	w.Close()
	os.Stdout = old

	var buf bytes.Buffer
	io.Copy(&buf, r)

	return buf.String()
}

func TestHTTPDownloader(t *testing.T) {
	var downloader Downloader = NewHTTPDownloader()

	rsp := captureStdout(func() { downloader.Download("http://example.com/abc.zip") })

	expectRsp := strings.TrimSpace(`prepare downloading
download http://example.com/abc.zip via http,
http save
finish downloading`)
	if rsp != expectRsp {
		fmt.Println(expectRsp)
		fmt.Println(rsp)
		t.Fail()
	}
}

func TestFTPDownloader(t *testing.T) {
	var downloader Downloader = NewFTPDownloader()

	rsp := captureStdout(func() { downloader.Download("ftp://example.com/abc.zip") })
	expectRsp := strings.TrimSpace(`prepare downloading
download ftp://example.com/abc.zip via ftp,
default save
finish downloading`)

	if rsp != expectRsp {
		t.Fail()
	}
}
