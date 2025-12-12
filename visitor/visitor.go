package visitor

import (
	"fmt"
)

type Visitor interface {
	Visit(Custom)
}

type Custom interface {
	Accept(Visitor)
}

type CustomerCol struct {
	customers []Custom
}

func (col *CustomerCol) Add(c Custom) {
	col.customers = append(col.customers, c)
}

func (col *CustomerCol) Accept(v Visitor) {
	for _, custom := range col.customers {
		custom.Accept(v)
	}
}

type baseCustomer struct {
	name string
}

func (bc baseCustomer) Accept(v Visitor) {
	v.Visit(bc)
}

type EnterpriseCustomer struct {
	*baseCustomer
}

func NewEnterpriseCustomer(name string) *EnterpriseCustomer {
	return &EnterpriseCustomer{
		baseCustomer: &baseCustomer{
			name: name,
		},
	}
}

func (ec *EnterpriseCustomer) Accept(v Visitor) {
	v.Visit(ec)
}

type IndividualCustomer struct {
	*baseCustomer
}

func NewIndividualCustomer(name string) *IndividualCustomer {
	return &IndividualCustomer{
		baseCustomer: &baseCustomer{
			name: name,
		},
	}
}

func (ic *IndividualCustomer) Accept(v Visitor) {
	v.Visit(ic)
}

type AnalysisVisitor struct{}

type ServiceRequestVisitor struct{}

func (*AnalysisVisitor) Visit(custom Custom) {
	switch c := custom.(type) {
	case *EnterpriseCustomer:
		fmt.Printf("analysis enterprise customer %s\n", c.name)
	}
}

func (*ServiceRequestVisitor) Visit(custom Custom) {
	switch c := custom.(type) {
	case *EnterpriseCustomer:
		fmt.Printf("serving enterprise customer %s\n", c.name)
	case *IndividualCustomer:
		fmt.Printf("serving individual customer %s\n", c.name)
	}
}
