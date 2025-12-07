package factory

type Operator interface {
	SetA(int)
	SetB(int)
	Result() int
}

type OperatorFactory interface {
	Create() Operator
}

type baseOperator struct {
	a, b int
}

func (o *baseOperator) SetA(n int) {
	o.a = n
}

func (o *baseOperator) SetB(n int) {
	o.b = n
}

type addOperator struct {
	*baseOperator
}

func (o *addOperator) Result() int {
	return o.baseOperator.a + o.baseOperator.b
}

type minuxOperator struct {
	*baseOperator
}

func (o *minuxOperator) Result() int {
	return o.baseOperator.a - o.baseOperator.b
}

type PlusOperatorFactory struct{}

func (PlusOperatorFactory) Create() Operator {
	return &addOperator{
		baseOperator: &baseOperator{},
	}
}

type MinusOperatorFactory struct{}

func (MinusOperatorFactory) Create() Operator {
	return &minuxOperator{
		baseOperator: &baseOperator{},
	}
}
