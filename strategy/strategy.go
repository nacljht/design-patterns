package strategy

import "fmt"

type Payment struct {
	context  *paymentContext
	strategy payStrategy
}

func NewPayment(receiver, sender string, money int, strategy payStrategy) *Payment {
	return &Payment{
		context: &paymentContext{
			sender:   sender,
			receiver: receiver,
			money:    money,
		},
		strategy: strategy,
	}
}

type paymentContext struct {
	sender   string
	receiver string
	money    int
}

type payStrategy interface {
	Pay(*paymentContext) string
}

func (p *Payment) Pay() string {
	return p.strategy.Pay(p.context)
}

type Cash struct{}

func (*Cash) Pay(ctx *paymentContext) string {
	return fmt.Sprintf("Pay $%d to %s by cash", ctx.money, ctx.receiver)
}

type Bank struct{}

func (*Bank) Pay(ctx *paymentContext) string {
	return fmt.Sprintf("Pay $%d to %s by bank account %s", ctx.money, ctx.receiver, ctx.sender)
}
