
class OrderMainDAO {
    public:
        virtual ~OrderMainDAO() = default;
        virtual void save_order_main() = 0;
};

class OrderDetailDAO {
    public:
        virtual ~OrderDetailDAO() = default;
        virtual void save_order_detail() = 0;
};

class DAOFactory {
    public:
        virtual ~DAOFactory() = default;
        virtual OrderMainDAO* create_order_main_dao() = 0;
        virtual OrderDetailDAO* create_order_detail_dao() = 0;
};

class XmlOrderMainDAO : public OrderMainDAO {
    public:
        ~XmlOrderMainDAO() override = default;
        void save_order_main() override;
};

class XmlOrderDetailDAO : public OrderDetailDAO {
    public:
        ~XmlOrderDetailDAO() override = default;
        void save_order_detail() override;
};

class RdbOrderMainDAO : public OrderMainDAO {
    public:
        ~RdbOrderMainDAO() override = default;
        void save_order_main() override;
};

class RdbOrderDetailDAO : public OrderDetailDAO {
    public:
        ~RdbOrderDetailDAO() override = default;
        void save_order_detail() override;
};

class XmlDAOFactory : public DAOFactory {
    public:
        ~XmlDAOFactory() override = default;
        OrderMainDAO* create_order_main_dao() override;
        OrderDetailDAO* create_order_detail_dao() override;
};

class RdbDAOFactory : public DAOFactory {
    public:
        ~RdbDAOFactory() override = default;
        OrderMainDAO* create_order_main_dao() override;
        OrderDetailDAO* create_order_detail_dao() override;
};
