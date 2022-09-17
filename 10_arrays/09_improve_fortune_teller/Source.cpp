#include <iostream>
#include <ctime>

int main()
{
    // srand() has to run once per program tun
    std::srand(std::time(nullptr)); // Seed

    char predictions[][90]
    {
        {"a lot of kinds running in the backyard!"},
        { "a lot of empty beer bottles on your work table." },
        { "you Partying too much with kids wearing weird clothes." },
        { "you running away from something really scary" },
        { "clouds gathering in the sky and an army standing ready for war" },
        { "dogs running around in a deserted empty city" },
        { "a lot of cars stuck in a terrible traffic jam" },
        { "you sitting in the dark typing lots of lines of code on your dirty computer" },
        { "you yelling at your boss. And oh no! You get fired!" },
        { "you laughing your lungs out. I've never seen this before." },
        {"Uhm, I don't see anything!"},
    };

    bool end{ false };

    const int max_length{ 45 };
    char name[max_length]{};

    std::cout << "What is your name dear: " << std::endl;
    std::cin.getline(name, max_length); // Get an input with spaces

    while (!end)
    {
        std::cout << "Oh dear " << name << ", I see ";

        size_t rand_num = static_cast<size_t>(std::rand() % std::size(predictions));

        std::cout << predictions[rand_num] << std::endl;

        std::cout << "Do you want me to try again? (Y | N): ";
        char go_on;
        std::cin >> go_on;
        go_on = toupper(go_on);

        end = (go_on == 'Y') ? false : true;
    }

    std::cout << "That's all I have for you today dear. Best wishes" << std::endl;

    return 0;
}