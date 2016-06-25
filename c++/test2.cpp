#include <iostream>
#include <string>
int main()
{
	std::cout << "dame tu nombre:\n";
	std::string nombre;
	std::cin >> nombre;

	std::string greeting = "holi "+nombre+"!";
	std::string bla(greeting.size(), ' ');
	std::string bla2 = '*'+bla+'*';

	std::cout << '\n'+bla2 << std::endl;
	std::cout << greeting + '\n';

	const std::string exclam = "!";
	const std::string msg = ", tomi"+exclam+"!";

	return 0;
}