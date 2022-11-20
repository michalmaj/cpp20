#include <memory>
#include <string>

class Person
{
public:
    Person() = default;
    Person(std::string name);
    ~Person();

    //Member functions
    std::string get_name() const
    {
        return m_name;
    }

    void set_friend(std::shared_ptr<Person> p) {
        //The assignment creates a weak_ptr out of p
        m_friend = p;
    }

    std::shared_ptr<Person> get_friend() const
    {
        return m_friend.lock();
    }

private:
    //std::shared_ptr<Person> m_friend; // Circular dependencies
    std::weak_ptr<Person> m_friend; // now everything is fine
    std::string m_name{ "Unnamed" };
};