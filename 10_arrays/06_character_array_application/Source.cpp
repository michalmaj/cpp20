#include <iostream>
#include <ctime>

int main()
{
	// srand() has to run once per program tun
	std::srand(std::time(nullptr)); // Seed

    char prediction0[]{ "a lot of kinds running in the backyard!" };
    char prediction1[]{ "a lot of empty beer bottles on your work table." };
    char prediction2[]{ "you Partying too much with kids wearing weird clothes." };
    char prediction3[]{ "you running away from something really scary" };
    char prediction4[]{ "clouds gathering in the sky and an army standing ready for war" };
    char prediction5[]{ "dogs running around in a deserted empty city" };
    char prediction6[]{ "a lot of cars stuck in a terrible traffic jam" };
    char prediction7[]{ "you sitting in the dark typing lots of lines of code on your dirty computer" };
    char prediction8[]{ "you yelling at your boss. And oh no! You get fired!" };
    char prediction9[]{ "you laughing your lungs out. I've never seen this before." };

    bool end{ false };

    const int max_length{ 45 };
    char name[max_length]{};

    std::cout << "What is your name dear: " << std::endl;
    std::cin.getline(name, max_length); // Get an input with spaces

    while(!end)
    {
        std::cout << "Oh dear " << name << ", I see ";

        size_t rand_num = static_cast<size_t>(std::rand() % 11);

        switch (rand_num) // [0~10]
        {
        case 0:
            std::cout << prediction0 << std::endl;
            break;
        case 1:
            std::cout << prediction1 << std::endl;
            break;
        case 2:
            std::cout << prediction2 << std::endl;
            break;
        case 3:
            std::cout << prediction3 << std::endl;
            break;
        case 4:
            std::cout << prediction4 << std::endl;
            break;
        case 5:
            std::cout << prediction5 << std::endl;
            break;
        case 6:
            std::cout << prediction6 << std::endl;
            break;
        case 7:
            std::cout << prediction7 << std::endl;
            break;
        case 8:
            std::cout << prediction8 << std::endl;
            break;
        case 9:
            std::cout << prediction9 << std::endl;
            break;
        default:
            std::cout << ", huum, I don't see anything" << std::endl;
            break;
        }

        std::cout << "Do you want me to try again? (Y | N): ";
        char go_on;
        std::cin >> go_on;
        go_on = toupper(go_on);

        end = (go_on == 'Y') ? false : true;
    }

    std::cout << "That's all I have for you today dear. Best wishes" << std::endl;

	return 0;
}