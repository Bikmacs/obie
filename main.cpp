#include <algorithm>
#include <iostream>

struct Woman {
    int childCount;
};
struct Man {
    bool military;
    char address;
};
union Pers {
    Woman woman;
    Man man;
};
struct Person {
    char name[100];
    char gender;
    Pers pers;
};

bool bolshe(const Person &a, const Person &b) {
    return a.pers.woman.childCount == b.pers.woman.childCount;
}


int main() {
    system("chcp 65001");
    int n;
    int count = 0;
    std::cout << "Введите количество людей: ";
    std::cin >> n;

    Person* persons = new Person[n]; // динамический массив

    for (int i = 0; i < n; i++) {
        std::cout << "Введите Ф.И.О.: ";
        std::cin.ignore();
        std::cin.getline(persons[i].name, 100);

        std::cout << "Введите пол (m, w): ";
        std::cin >> persons[i].gender;

        if(persons[i].gender == 'w') {
            std::cout << "Введите количество детей: ";
            std::cin >> persons[i].pers.woman.childCount;
            count++;
        } else if(persons[i].gender == 'm') {
            std::cout << "Военнообязанный (1 - ДА, 0 - НЕТ): ";
            std::cin >> persons[i].pers.man.military;

            std::cout << "Введите адрес проживания: ";
            std::cin.ignore();
            std::cin.getline(&persons[i].pers.man.address, 100);
        }
    }

    Person* woman = new Person[count];
    int index =0;
    for (int i = 0; i < count; i++) {
        if(persons[i].gender == 'w') {
            woman[index++] = persons[i];
        }
    }


    std::cout << "\nСписок женщин\n";
    for (int i = 0; i < count; i++) {
        std::cout << woman[i].name<<std::endl;
        std::cout << persons->pers.woman.childCount <<std::endl;
    }

    std::sort(woman, woman + count, bolshe);

    std::cout << "\nСписок женщин, отсортированный по убыванию количества детей:\n";
    for (int i = 0; i < count; i++) {
        std::cout << woman[i].name << " - " << woman[i].pers.woman.childCount << std::endl;
    }

    delete [] woman;
    delete [] persons;
    return 0;

    return 0;
}
