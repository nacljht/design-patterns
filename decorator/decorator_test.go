package decorator

import (
	"testing"
)

func TestDecorator(t *testing.T) {
	var c Component = &ConcreteComponent{}
	c = WrapAddDecorator(c, 10)
	c = WrapMulDecorator(c, 8)
	res := c.Calc()

	if res != 80 {
		t.Fatalf("expect 80, get %d", res)
	}
	// Output:
	// res 80
}