package abstractfactory

import "testing"

func TestRdbFactory(t *testing.T) {
	var factory DAOFactory
	factory = &RDBDAOFactory{}
	if factory.CreateOrderMainDAO().SaveOrderMain() != "rdb main save" {
		t.Fail()
	}
	if factory.CreateOrderDetailDAO().SaveOrderDetail() != "rdb detail save" {
		t.Fail()
	}
}

func TestXmlFactory(t *testing.T) {
	var factory DAOFactory
	factory = &XMLDAOFactory{}
	if factory.CreateOrderMainDAO().SaveOrderMain() != "xml main save" {
		t.Fail()
	}
	if factory.CreateOrderDetailDAO().SaveOrderDetail() != "xml detail save" {
		t.Fail()
	}
}
