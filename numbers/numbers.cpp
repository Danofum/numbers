#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

// Функция проверки ввода числа в заданном диапазоне
int megacheck(int zzz, int sizzzze) {
    while (cin.fail() || zzz < 1 || zzz > sizzzze) { // Пока ввод некорректен или число вне диапазона
        cin.clear(); // Очистка состояния потока
        cin.ignore(1000, '\n'); // Игнорирование лишних символов
        cout << "Ошибка ввода данных." << endl << "Введите число заново: ";
        cin >> zzz; // Повторный ввод числа
    }
    return zzz; // Возвращение корректного числа
}

// Функция проверки ввода числа 1 или 2
int onetwocheck(int zzz) {
    while (cin.fail() || zzz < 1 || zzz > 2) { // Пока ввод некорректен или число не равно 1 или 2
        cin.clear(); // Очистка состояния потока
        cin.ignore(1000, '\n'); // Игнорирование лишних символов
        cout << "Ошибка ввода данных." << endl << "Введите число заново: ";
        cin >> zzz; // Повторный ввод числа
    }
    return zzz; // Возвращение корректного числа
}

int main() {
    setlocale(LC_ALL, "Ru"); // Установка локализации на русский язык
    using std::string;

    cout << "Введите строку: " << endl;
    string str; // Входная строка
    getline(cin, str); // Считывание строки
    int length = str.length(); // Длина строки
    vector<string> chars; // Массив для хранения цифр из строки

    // Извлечение цифр из строки
    for (int i = 0; i < length; i++) {
        switch (str[i]) {
            // Проверка символов на соответствие цифрам
        case '1': chars.push_back("1"); continue;
        case '2': chars.push_back("2"); continue;
        case '3': chars.push_back("3"); continue;
        case '4': chars.push_back("4"); continue;
        case '5': chars.push_back("5"); continue;
        case '6': chars.push_back("6"); continue;
        case '7': chars.push_back("7"); continue;
        case '8': chars.push_back("8"); continue;
        case '9': chars.push_back("9"); continue;
        case '0': chars.push_back("0"); continue;
        }
    }

    cout << "Вы хотите вывести одну цифру, или диапазон? (1 - одна, 2 - диапазон) :" << endl;
    bool checkbox = false; // Флаг выбора режима
    int checkn;
    cin >> checkn; // Ввод выбора режима
    checkn = onetwocheck(checkn); // Проверка корректности ввода

    if (checkn == 1) {
        checkbox = true; // Один символ
    }
    else {
        checkbox = false; // Диапазон символов
    }

    if (checkbox) {
        // Вывод одной цифры
        cout << "Введите номер цифры, которую желаете вывести: " << endl;
        int askedNumber;
        cin >> askedNumber; // Ввод номера цифры
        askedNumber = megacheck(askedNumber, chars.size()); // Проверка корректности ввода
        cout << "Цифровой номер " << askedNumber << " является " << chars[askedNumber - 1] << endl;
    }
    else {
        // Вывод диапазона цифр
        cout << "Введите начало диапазон цифр, которые желаете вывести: " << endl;
        int askedNumber1;
        cin >> askedNumber1; // Ввод начала диапазона
        askedNumber1 = megacheck(askedNumber1, chars.size()); // Проверка корректности ввода

        cout << "Введите конец диапазон цифр, которые желаете вывести: " << endl;
        int askedNumber2;
        cin >> askedNumber2; // Ввод конца диапазона
        askedNumber2 = megacheck(askedNumber2, chars.size()); // Проверка корректности ввода

        if (askedNumber1 > askedNumber2) {
            // Если начало больше конца, меняем местами
            int x = askedNumber1;
            askedNumber1 = askedNumber2;
            askedNumber2 = x;
        }

        // Вывод диапазона цифр
        cout << "Цифровой диапазон " << askedNumber1 << "-" << askedNumber2 << " соответствуем цифрам: " << endl;
        for (unsigned int f = askedNumber1 - 1; f < askedNumber2; f++) {
            cout << chars[f] << " "; // Вывод цифр в диапазоне
        }
    }

    return 0; // Завершение программы
}
