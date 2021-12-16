#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>

class tovar {
  std::string name;
  std::string company;
  int kolvo;
  std::string input_date;
  std::string position;
  bool fragile;

public:
  tovar() {
    std::cout << "Enter product name: ";
    std::string name1;
    std::cin >> name1;
    std::cout << "Enter owner company: ";
    std::string company1;
    std::cin >> company1;
    std::cout << "Enter quantity of product: ";
    int kolvo1;
    std::cin >> kolvo1;
    std::cout << "Enter date of product arrival: ";
    std::string input_date1;
    std::cin >> input_date1;
    std::cout << "Enter position on warehouse: ";
    std::string position1;
    std::cin >> position1;
    std::cout << "Is product fragile? (0 or 1): ";
    int fragile1;
    std::cin >> fragile1;
    name = name1;
    company = company1;
    kolvo = kolvo1;
    input_date = input_date1;
    position = position1;
    fragile = fragile1;
  }
  tovar(std::string name, std::string company, int kolvo,
        std::string input_date, std::string position, bool fragile) {
    name = name;
    company = company;
    kolvo = kolvo;
    input_date = input_date;
    position = position;
    fragile = fragile;
  }
  tovar(const tovar &t) {
    name = t.name;
    company = t.company;
    kolvo = t.kolvo;
    input_date = t.input_date;
    position = t.position;
    fragile = t.fragile;
  }
  tovar(tovar &&t) {
    name = std::move(t.name);
    company = std::move(t.company);
    kolvo = std::move(t.kolvo);
    input_date = std::move(t.input_date);
    position = std::move(t.position);
    fragile = std::move(t.fragile);
  }

  auto operator=(const tovar &t) {
    if (this != &t) {
      name = t.name;
      company = t.company;
      kolvo = t.kolvo;
      input_date = t.input_date;
      position = t.position;
      fragile = t.fragile;
    }
    return *this;
  }

  auto operator=(tovar &&t) {
    if (this != &t) {
      name = std::move(t.name);
      company = std::move(t.company);
      kolvo = std::move(t.kolvo);
      input_date = std::move(t.input_date);
      position = std::move(t.position);
      fragile = std::move(t.fragile);
    }
    return *this;
  }

  std::string get_name() { return name; }
  std::string get_company() { return company; }
  int get_kolvo() { return kolvo; }
  std::string get_input_date() { return input_date; }
  std::string get_position() { return position; }
  bool get_fragile() { return fragile; }

  friend std::ostream &operator<<(std::ostream &out, const tovar &t);
};

std::ostream &operator<<(std::ostream &out, const tovar &t) {
  out << "Name: " << t.name << "\n";
  out << "Company: " << t.company << "\n";
  out << "Quantity: " << t.kolvo << "\n";
  out << "Date of input: " << t.input_date << "\n";
  out << "Position: " << t.position << "\n";
  out << "Fragileness: " << t.fragile << "\n";
  return out;
}