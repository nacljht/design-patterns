package decorator

type Component interface {
	Calc() int
}

type ConcreteComponent struct{}

func (*ConcreteComponent) Calc() int {
	return 0
}

type addDecorator struct {
	Component
	num int
}

func (w *addDecorator) Calc() int {
	return w.Component.Calc() + w.num
}

func WrapAddDecorator(c Component, num int) Component {
	return &addDecorator{
		Component: c,
		num:       num,
	}
}

type mulDecorator struct {
	Component
	num int
}

func (m *mulDecorator) Calc() int {
	return m.Component.Calc() * m.num
}

func WrapMulDecorator(c Component, num int) Component {
	return &mulDecorator{
		Component: c,
		num:       num,
	}
}
