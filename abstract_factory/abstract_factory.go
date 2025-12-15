package abstractfactory

type OrderMainDAO interface {
	SaveOrderMain() string
}

type OrderDetailDAO interface {
	SaveOrderDetail() string
}

type DAOFactory interface {
	CreateOrderMainDAO() OrderMainDAO
	CreateOrderDetailDAO() OrderDetailDAO
}

type RDBOrderMainDAO struct{}

func (RDBOrderMainDAO) SaveOrderMain() string {
	return "rdb main save"
}

type RDBOrderDetailDAO struct{}

func (RDBOrderDetailDAO) SaveOrderDetail() string {
	return "rdb detail save"
}

type XMLOrderMainDAO struct{}

func (XMLOrderMainDAO) SaveOrderMain() string {
	return "xml main save"
}

type XMLOrderDetailDAO struct{}

func (XMLOrderDetailDAO) SaveOrderDetail() string {
	return "xml detail save"
}

type RDBDAOFactory struct{}

func (RDBDAOFactory) CreateOrderMainDAO() OrderMainDAO {
	return RDBOrderMainDAO{}
}

func (RDBDAOFactory) CreateOrderDetailDAO() OrderDetailDAO {
	return RDBOrderDetailDAO{}
}

type XMLDAOFactory struct{}

func (XMLDAOFactory) CreateOrderMainDAO() OrderMainDAO {
	return XMLOrderMainDAO{}
}

func (XMLDAOFactory) CreateOrderDetailDAO() OrderDetailDAO {
	return XMLOrderDetailDAO{}
}
