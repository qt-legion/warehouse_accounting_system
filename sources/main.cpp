#include "/home/qt-legion/workspace/warehouse_accounting_system/include/header.hpp"
#include <fstream>
#include <sstream>

int file_print(std::string path, std::vector<tovar> vctr) {
  std::ofstream fo(path);
  if (!fo) {
    std::cout << "File not opened\n";
    return 0;
  }
  fo << vctr.size();
  for (int i = 0; i < vctr.size(); i++) {
    fo << vctr[i];
  }
  return 0;
}

int file_read(std::string path, std::vector<tovar> vctr) {
  std::ifstream fi(path);
  std::string name;
  std::string company;
  int kolvo;
  std::string input_date;
  std::string position;
  bool fragile;

  if (!fi) {
    std::cout << "File not opened\n";
    return 0;
  }
  int n;
  fi >> n;
  char sim;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      while (sim != ' ') {
        fi.get(sim);
      }
      if (j == 0) {
        fi >> name;
      }
      if (j == 1) {
        fi >> company;
      }
      if (j == 2) {
        fi >> kolvo;
      }
      if (j == 3) {
        fi >> input_date;
      }
      if (j == 4) {
        fi >> position;
      }
      if (j == 5) {
        fi >> fragile;
      }
    }
    vctr.push_back(tovar(name, company, kolvo, input_date, position, fragile));
  }
}

int main() {
  int state = 0;
  std::vector<tovar> vctr;

  while (state != 7) {
    if (state == 0) {
      std::cout << "\n//Main screen//\n";
      std::cout << "\nhome/\n\n";
      std::cout << "1: Add new element\n2: Remove element\n3: Find element "
                   "with specific parameters\n4: Delete all elements "
                   "//CONFIRMATION REQUIRED//\n5: Work with file\n6: Print "
                   "all\n7: Exit "
                   "application\n";
      std::cin >> state;
    }
    if (state == 1) {
      std::cout << "\nhome/add/\n\n";
      vctr.push_back(tovar());
      state = 0;
    }
    if (state == 2) {
      std::cout << "\nhome/remove/\n\n";

      std::cout << "Enter with which parameter you should erase:\nName - "
                   "1\nCompany - 2\nQuantity - 3\nInput date - 4\nPosition - "
                   "5\nFragileness - 6\n";
      int parameter;
      std::cin >> parameter;
      if (parameter == 1) {
        std::cout << "Enter the string: ";
        std::string parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_name() == parameter2) {
            std::cout << "\nConfirm deletion(Y/N):\n\n";
            std::cout << vctr[i];
            std::string add;
            std::cin >> add;
            if (add == "Y") {
              for (int j = i; j < vctr.size() - 1; j++) {
                vctr[i] = vctr[i + 1];
              }
              vctr.pop_back();
              i -= 1;
            }
          }
        }
      }
      if (parameter == 2) {
        std::cout << "Enter the string: ";
        std::string parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_company() == parameter2) {
            std::cout << "\nConfirm deletion(Y/N):\n\n";
            std::cout << vctr[i];
            std::string add;
            std::cin >> add;
            if (add == "Y") {
              for (int j = i; j < vctr.size() - 1; j++) {
                vctr[i] = vctr[i + 1];
              }
              vctr.pop_back();
              i -= 1;
            }
          }
        }
      }
      if (parameter == 3) {
        std::cout << "Enter the string: ";
        int parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_kolvo() == parameter2) {
            std::cout << "\nConfirm deletion(Y/N):\n\n";
            std::cout << vctr[i];
            std::string add;
            std::cin >> add;
            if (add == "Y") {
              for (int j = i; j < vctr.size() - 1; j++) {
                vctr[i] = vctr[i + 1];
              }
              vctr.pop_back();
              i -= 1;
            }
          }
        }
      }
      if (parameter == 4) {
        std::cout << "Enter the string: ";
        std::string parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_input_date() == parameter2) {
            std::cout << "\nConfirm deletion(Y/N):\n\n";
            std::cout << vctr[i];
            std::string add;
            std::cin >> add;
            if (add == "Y") {
              for (int j = i; j < vctr.size() - 1; j++) {
                vctr[i] = vctr[i + 1];
              }
              vctr.pop_back();
              i -= 1;
            }
          }
        }
      }
      if (parameter == 5) {
        std::cout << "Enter the string: ";
        std::string parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_position() == parameter2) {
            std::cout << "\nConfirm deletion(Y/N):\n\n";
            std::cout << vctr[i];
            std::string add;
            std::cin >> add;
            if (add == "Y") {
              for (int j = i; j < vctr.size() - 1; j++) {
                vctr[i] = vctr[i + 1];
              }
              vctr.pop_back();
              i -= 1;
            }
          }
        }
      }
      if (parameter == 6) {
        std::cout << "Enter the string: ";
        int parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_fragile() == parameter2) {
            std::cout << "\nConfirm deletion(Y/N):\n\n";
            std::cout << vctr[i];
            std::string add;
            std::cin >> add;
            if (add == "Y") {
              for (int j = i; j < vctr.size() - 1; j++) {
                vctr[i] = vctr[i + 1];
              }
              vctr.pop_back();
              i -= 1;
            }
          }
        }
      }
      state = 0;
    }

    if (state == 3) {
      std::cout << "\nhome/find/\n\n";
      std::cout << "Enter with which parameter you should search:\nName - "
                   "1\nCompany - 2\nQuantity - 3\nInput date - 4\nPosition - "
                   "5\nFragileness - 6\n";
      int parameter;
      std::cin >> parameter;
      if (parameter == 1) {
        std::cout << "Enter the string: ";
        std::string parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_name() == parameter2) {
            std::cout << vctr[i];
          }
        }
      }
      if (parameter == 2) {
        std::cout << "Enter the string: ";
        std::string parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_company() == parameter2) {
            std::cout << vctr[i];
          }
        }
      }
      if (parameter == 3) {
        std::cout << "Enter the string: ";
        int parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_kolvo() == parameter2) {
            std::cout << vctr[i];
          }
        }
      }
      if (parameter == 4) {
        std::cout << "Enter the string: ";
        std::string parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_input_date() == parameter2) {
            std::cout << vctr[i];
          }
        }
      }
      if (parameter == 5) {
        std::cout << "Enter the string: ";
        std::string parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_position() == parameter2) {
            std::cout << vctr[i];
          }
        }
      }
      if (parameter == 6) {
        std::cout << "Enter the string: ";
        int parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_fragile() == parameter2) {
            std::cout << vctr[i];
          }
        }
      } else {
        std::cout << "Nothing found\n";
      }
      state = 0;
    }

    if (state == 4) {
      std::cout << "\nhome/delete/\n\n";
      std::cout << "Enter Y/y to confirm deletion: ";
      std::string conf;
      std::cin >> conf;
      if (conf == "Y" || conf == "y") {
        for (int i = 0; i < vctr.size(); i++) {
          vctr.pop_back();
        }
      }
      state = 0;
      std::cout << "Whole container erased successfully!\n";
    }
    if (state == 5) {
      std::cout << "\nhome/file/\n\n";
      std::cout << "Write to file - 1\nRead from file - 2\n";
      int state2;
      std::cin >> state2;
      if (state2 == 1) {
        std::cout << "Enter name of file: ";
        std::string path;
        std::cin >> path;
        file_print(path, vctr);
      }
      if (state2 == 2) {
        std::cout << "Enter name of file: ";
        std::string path;
        std::cin >> path;
      }
      state = 0;
    }
    if (state == 6) {
      for (int i = 0; i < vctr.size(); i++) {
        std::cout << vctr[i];
      }
      state = 0;
    }
  }
  return 0;
}