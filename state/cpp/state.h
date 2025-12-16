#include <string>

class Context;

class State {
    public:
        virtual ~State() = default;
        virtual std::string Get() const = 0;
        virtual void Handle(Context *ctx) = 0;
};

class Context {
    protected:
        State *state;
    public:
        virtual ~Context();
        virtual void Set(State *state);
        virtual void Next();
};

class DayState : public State {
    private:
        std::string day;
    public:
        DayState(const std::string &day_):day(day_){}
        ~DayState() override = default;
        std::string Get() const override;
        void Handle(Context *ctx) override;
};

class DayContext : public Context {
    public:
        DayContext();
        std::string Today() const;
        ~DayContext() override = default;
};