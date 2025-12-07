package strategy

import (
	"testing"
)

func TestCashPay(t *testing.T) {
	p := NewPayment("alice", "bob", 100, &Cash{})

	want := "Pay $100 to alice by cash"
	out := p.Pay()

	if out != want {
		t.Fatalf("expected %q, got %q", want, out)
	}
}

func TestBankPay(t *testing.T) {
	p := NewPayment("alice-bank", "bob", 200, &Bank{})

	out := p.Pay()

	want := "Pay $200 to alice-bank by bank account bob"

	if out != want {
		t.Fatalf("expected %q, got %q", want, out)
	}
}
