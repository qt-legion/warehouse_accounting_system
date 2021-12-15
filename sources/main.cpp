#include "include/header.hpp"

int main() {
  int state = 0;
  std::vector<tovar> vctr;
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  while (state != 5) {
    if (state == 0) {
      for (int i = 0; i < w.ws_col / 4 - 5; i++) {
        std::cout << " ";
      }
      std::cout << "//Main screen//\n";
      std::cout << "\nhome/\n\n";
      std::cout << "1: Add new element\n2: Remove element\n3: Find element "
                   "with specific parameters\n4: Delete all elements "
                   "//CONFIRMATION REQUIRED//\n5: Exit application\n";
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
            for (int j = i; j < vctr.size() - 1; j++) {
              vctr[i] = vctr[i + 1];
            }
            vctr.pop_back();
            i -= 1;
          }
        }
      }
      if (parameter == 2) {
        std::cout << "Enter the string: ";
        std::string parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_company() == parameter2) {
            for (int j = i; j < vctr.size() - 1; j++) {
              vctr[i] = vctr[i + 1];
            }
            vctr.pop_back();
            i -= 1;
          }
        }
      }
      if (parameter == 3) {
        std::cout << "Enter the string: ";
        int parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_kolvo() == parameter2) {
            for (int j = i; j < vctr.size() - 1; j++) {
              vctr[i] = vctr[i + 1];
            }
            vctr.pop_back();
            i -= 1;
          }
        }
      }
      if (parameter == 4) {
        std::cout << "Enter the string: ";
        std::string parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_input_date() == parameter2) {
            for (int j = i; j < vctr.size() - 1; j++) {
              vctr[i] = vctr[i + 1];
            }
            vctr.pop_back();
            i -= 1;
          }
        }
      }
      if (parameter == 5) {
        std::cout << "Enter the string: ";
        std::string parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_position() == parameter2) {
            for (int j = i; j < vctr.size() - 1; j++) {
              vctr[i] = vctr[i + 1];
            }
            vctr.pop_back();
            i -= 1;
          }
        }
      }
      if (parameter == 6) {
        std::cout << "Enter the string: ";
        int parameter2;
        std::cin >> parameter2;
        for (int i = 0; i < vctr.size(); i++) {
          if (vctr[i].get_fragile() == parameter2) {
            for (int j = i; j < vctr.size() - 1; j++) {
              vctr[i] = vctr[i + 1];
            }
            vctr.pop_back();
            i -= 1;
          }
        }
      }
    }
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
    }
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
  return 0;
}
