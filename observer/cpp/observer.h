#include <string>
#include <vector>

class Observer;
class Subject {
    std::string message;
    std::vector<Observer*> observers;
    public:
        void attach(Observer *o);
        void update_context(const std::string &message);
        std::string get_message();
};

class Observer {
    public:
        virtual ~Observer() = default;
        virtual void notify(Subject *s) = 0;
};

class Reader : public Observer {
    std::string message;
    public:
        ~Reader() override = default;
        void notify(Subject *s) override;
        std::string get_message();
};
