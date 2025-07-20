#include <iostream>
using namespace std;

int main (int argc, char** argv) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[1] << " <name> [age]" << std::endl;
        return 1;
    } else {
        if (std::string(argv[2]) ==  "+") { 
            std::cout << std::stoi(argv[1]) + std::stoi(argv[3]) << std::endl;
        } else if (std::string(argv[2]) ==  "-") { 
            std::cout << std::stoi(argv[1]) - std::stoi(argv[3]) << std::endl;
        } else if (std::string(argv[2]) ==  "/") {
            std::cout << std::stoi(argv[1]) * std::stoi(argv[3]) << std::endl;
        } else if (std::string(argv[2]) ==  "*") {
            std::cout << std::stoi(argv[1]) * std::stoi(argv[3]) << std::endl;
        } else {
            std::cout << "Error with calculator." << std::endl;
        }
    }
    return 0;
}