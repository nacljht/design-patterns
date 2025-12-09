#include <string>
#include <map>

class Cloneable {
    protected:
        std::string name;
    public:
        Cloneable(const std::string &name_);
        virtual Cloneable* Clone() = 0;
        std::string get_name();

        virtual ~Cloneable() = default;
};

class Cloneable1 : public Cloneable {
    public:
        using Cloneable::Cloneable;

        Cloneable1* Clone(); 
};

class PrototypeManager {
    std::map<const std::string, Cloneable*> mp;
    public:
        void set(const std::string &key, Cloneable *value);
        Cloneable* get(const std::string &key) const;

        ~PrototypeManager();
};
