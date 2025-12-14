package observer

import "testing"

func TestObserver(t *testing.T) {
	subject := NewSubject()
	reader1 := NewReader("reader1")
	reader2 := NewReader("reader2")
	reader3 := NewReader("reader3")
	subject.Attach(reader1)
	subject.Attach(reader2)
	subject.Attach(reader3)

	if reader1.GetMessage() == "observer mode" {
		t.Fail()
	}

	if reader2.GetMessage() == "observer mode" {
		t.Fail()
	}

	if reader3.GetMessage() == "observer mode" {
		t.Fail()
	}

	subject.UpdateContext("observer mode")

	if reader1.GetMessage() != "observer mode" {
		t.Fail()
	}

	if reader2.GetMessage() != "observer mode" {
		t.Fail()
	}

	if reader3.GetMessage() != "observer mode" {
		t.Fail()
	}
}
