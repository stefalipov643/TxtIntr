#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <sstream>

void print_usage() {
    std::cout << "Usage: calculator -o operation operand1 operand2 [operand3] [operand4]\n";
    std::cout << "Supported operations: summa, subtraction\n";
    exit(0);
}

// Проверка, является ли строка допустимым числом (целым или дробным)
bool is_number(const std::string& str) {
    std::istringstream iss(str);
    double d;
    char c;
    if (!(iss >> d) || (iss >> c)) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        print_usage();
    }

    std::string operation;
    std::vector<double> operands;
    bool operation_found = false;

    // Разбор аргументов командной строки
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "-o") == 0 || std::strcmp(argv[i], "--operation") == 0) {
            if (operation_found) {
                std::cerr << "Error: Only one operation can be specified.\n";
                exit(1);
            }
            if (i + 1 < argc) {
                operation = argv[i + 1];
                operation_found = true;
                i++;  // Пропустить имя операции
            } else {
                print_usage();
            }
        } else {
            if (operands.size() < 5) {
                std::string operand_str = argv[i];
                if (is_number(operand_str)) {
                    operands.push_back(std::stod(operand_str));
                } else {
                    std::cerr << "Error: Operand '" << operand_str << "' is not a valid number.\n";
                    exit(1);
                }
            } else {
                print_usage();
            }
        }
    }

    // Проверка, что операция задана и количество операндов корректное
    if (operation.empty() || operands.size() < 3 || operands.size() > 5) {
        print_usage();
    }

    // Выполнение операций
    if (operation == "summa") {
        double result = 0.0;
        for (double operand : operands) {
            result += operand;
        }
        std::cout << "Result: " << result << std::endl;
    } else if (operation == "subtraction") {
        double result = operands[0];
        for (size_t i = 1; i < operands.size(); ++i) {
            result -= operands[i];
        }
        std::cout << "Result: " << result << std::endl;
    } else {
        std::cerr << "Error: Unsupported operation '" << operation << "'.\n";
        print_usage();
    }

    return 0;
}