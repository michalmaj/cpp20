#include <iostream>
#include <string>

int main()
{
    
	for(size_t i{0} ; i  < 1000 ; ++i){
	   std::cout << "Hello\n";
	}

	std::cout << "\n=========================================\n\n";

	std::cout << "He said \"Get out of here immediately!\"" << std::endl;
	    
	 std::string todo_list{ "\tClean the house\n\tWalk the dog\n\tDo laundry\n\tPick groceries" };
	 std::string windows_path{ "D:\\sandbox\\testProject\\hello.txt" };
	 std::string linux_path{ "/home/username/files/hello.txt" };
	 std::string hint{ " \"\\\\\" escapes a backslash character like \\." };
	 std::cout << "todo_list : " << std::endl;
	 std::cout << todo_list << std::endl;
	 std::cout << "windows_path : " << windows_path << std::endl;
	 std::cout << "linux_path : " << linux_path << std::endl;
	 std::cout << "hint : " << hint << std::endl;

	 std::cout << "\n=========================================\n\n";

	std::cout << "Play sound: " << "\a" << std::endl;
	return 0;
}