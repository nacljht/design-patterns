package visitor

import (
	"bytes"
	"fmt"
	"io"
	"os"
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

func TestRequestVisitor(t *testing.T) {
	c := &CustomerCol{}
	c.Add(NewEnterpriseCustomer("A company"))
	c.Add(NewEnterpriseCustomer("B company"))
	c.Add(NewIndividualCustomer("bob"))
	rsp := captureStdout(func() { c.Accept(&ServiceRequestVisitor{}) })
	expectRsp := (`serving enterprise customer A company
serving enterprise customer B company
serving individual customer bob
`)
	if rsp != expectRsp {
		fmt.Println(expectRsp)
		fmt.Println(rsp)
		t.Fail()
	}
}

func TestAnalysis(t *testing.T) {
	c := &CustomerCol{}
	c.Add(NewEnterpriseCustomer("A company"))
	c.Add(NewIndividualCustomer("bob"))
	c.Add(NewEnterpriseCustomer("B company"))
	rsp := captureStdout(func() { c.Accept(&AnalysisVisitor{}) })
	expectRsp := (`analysis enterprise customer A company
analysis enterprise customer B company
`)
	if rsp != expectRsp {
		fmt.Println(len(expectRsp))
		fmt.Println(len(rsp))
		t.Fail()
	}
}
