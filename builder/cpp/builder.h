#include <string>

class Builder {
    public:
        virtual ~Builder() = default;
        virtual void buildpart1() = 0;
        virtual void buildpart2() = 0;
        virtual void buildpart3() = 0;
};

class Director {
    Builder *builder;
    public:
        Director(Builder *b):builder(b) {}
        void direct();
};

class Builder1 : public Builder {
    std::string result;
    public:
        virtual ~Builder1() override = default;
        void buildpart1() override;
        void buildpart2() override;
        void buildpart3() override;
        std::string get_result();
};

class Builder2 : public Builder {
    int result;
    public:
        virtual ~Builder2() override = default;
        void buildpart1() override;
        void buildpart2() override;
        void buildpart3() override;
        int get_result();
};
