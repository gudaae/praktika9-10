//Практическая работа №9

//Вариант 13.
//Определить структурный тип, описывающий музыкальные альбомы(название
//    альбома, исполнитель, стиль, год выпуска, длительность, название и
//    продолжительность композиций альбома).Заполнить структурный массив 20 - ю
//    записями.Переписать из исходного массива в другой массив, информацию только о
//    тех альбомах, стиль которых фанк или соул.Затем новый массив отсортировать по
//    году выпуска.Вывести все данные по конкретному альбому.Вывести 3 самых
//    длинных альбома.Реализовать функцию изменения альбома.В отдельный массив
//    поместить все альбомы Linkin Park.Реализовать вывод отфильтрованных данных в
//    виде оберточной функции.

#include <iostream>
#include <string>
using namespace std;
struct Track {
    string name;
    int duration;
};
struct Album {
    string name;
    string artist;
    string style;
    int year;
    int duration;
    Track tracks[10];
    int trackCount;
};
void printAlbum(Album a) {
    cout << "\nНазвание: " << a.name << endl;
    cout << "Исполнитель: " << a.artist << endl;
    cout << "Стиль: " << a.style << endl;
    cout << "Год: " << a.year << endl;
    cout << "Длительность: " << a.duration << " сек" << endl;
    for (int i = 0; i < a.trackCount; i++) {
        cout << "  " << a.tracks[i].name << " (" << a.tracks[i].duration << " сек)" << endl;
    }
}
void edAlbum(Album& a) {
    cout << "название: ";
    cin >> a.name;
    cout << "исполнитель: ";
    cin >> a.artist;
    cout << "стиль: ";
    cin >> a.style;
    cout << "год: ";
    cin >> a.year;
}
int main() {
    setlocale(LC_ALL, "Ru");
    Album albums[20];
    int n = 20;
    for (int i = 0; i < n; i++) {
        albums[i].name = "Album" + to_string(i + 1);
        albums[i].artist = "Artist" + to_string(i + 1);

        if (i % 3 == 0) albums[i].style = "Funk";
        else if (i % 3 == 1) albums[i].style = "Soul";
        else albums[i].style = "Rock";

        albums[i].year = 2000 + i;
        albums[i].duration = 2000 + i * 10;
        albums[i].trackCount = 2;

        albums[i].tracks[0].name = "Track1";
        albums[i].tracks[0].duration = 180;
        albums[i].tracks[1].name = "Track2";
        albums[i].tracks[1].duration = 200;
    }
    albums[0].name = "Hybrid Theory";
    albums[0].artist = "Linkin Park";
    albums[1].name = "Meteora";
    albums[1].artist = "Linkin Park";

    Album funkSoul[20];
    int fsCount = 0;

    for (int i = 0; i < n; i++) {
        if (albums[i].style == "Funk" || albums[i].style == "Soul") {
            funkSoul[fsCount] = albums[i];
            fsCount++;
        }
    }
    for (int i = 0; i < fsCount - 1; i++) {
        for (int j = 0; j < fsCount - i - 1; j++) {
            if (funkSoul[j].year > funkSoul[j + 1].year) {
                Album temp = funkSoul[j];
                funkSoul[j] = funkSoul[j + 1];
                funkSoul[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (albums[i].name == "Meteora") {
            printAlbum(albums[i]);
        }
    }
    cout << "\n3 самых длинных альбома:\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (albums[j].duration < albums[j + 1].duration) {
                Album temp = albums[j];
                albums[j] = albums[j + 1];
                albums[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << albums[i].name << " - " << albums[i].duration << " сек" << endl;
    }
    cout << "\nальбом Thriller:\n";
    for (int i = 0; i < n; i++) {
        if (albums[i].name == "Thriller") {
            edAlbum(albums[i]);
        }
    }
    Album linkinPark[20];
    int lpCount = 0;
    for (int i = 0; i < n; i++) {
        if (albums[i].artist == "Linkin Park") {
            linkinPark[lpCount] = albums[i];
            lpCount++;
        }
    }
    cout << "\nАльбомы Funk и Soul (по годам)\n";
    for (int i = 0; i < fsCount; i++) {
        cout << funkSoul[i].name << " - " << funkSoul[i].artist << " (" << funkSoul[i].year << ")" << endl;
    }
    cout << "\nАльбомы Linkin Park\n";
    for (int i = 0; i < lpCount; i++) {
        cout << linkinPark[i].name << " - " << linkinPark[i].year << endl;
    }
    return 0;
    system("pause");
}

//Практическая работа №10

#include <iostream>
#include <fstream>
#include <locale.h>
#include <cstring>
using namespace std;

struct Album {
    char name[50];
    char artist[50];
    char style[20];
    int year;
    int duration;
};
void printAlbum(Album a) {
    cout << a.name << " - " << a.artist << " (" << a.style << ", " << a.year << ", " << a.duration << " сек)\n";
}
int main() {
    setlocale(LC_ALL, "Ru");
    Album albums[20];
    int n = 6;

    strcpy_s(albums[0].name, "Hybrid Theory");
    strcpy_s(albums[0].artist, "Linkin Park");
    strcpy_s(albums[0].style, "Rock");
    albums[0].year = 0;
    albums[0].duration = 2220;

    strcpy_s(albums[1].name, "Meteora");
    strcpy_s(albums[1].artist, "Linkin Park");
    strcpy_s(albums[1].style, "Rock");
    albums[1].year = 0;
    albums[1].duration = 2160;

    strcpy_s(albums[2].name, "Thriller");
    strcpy_s(albums[2].artist, "Michael Jackson");
    strcpy_s(albums[2].style, "Funk");
    albums[2].year = 0;
    albums[2].duration = 2520;

    strcpy_s(albums[3].name, "Superfly");
    strcpy_s(albums[3].artist, "Curtis Mayfield");
    strcpy_s(albums[3].style, "Soul");
    albums[3].year = 0;
    albums[3].duration = 2400;

    strcpy_s(albums[4].name, "Innervisions");
    strcpy_s(albums[4].artist, "Stevie Wonder");
    strcpy_s(albums[4].style, "Soul");
    albums[4].year = 0;
    albums[4].duration = 2640;

    strcpy_s(albums[5].name, "Minutes to Midnight");
    strcpy_s(albums[5].artist, "Linkin Park");
    strcpy_s(albums[5].style, "Rock");
    albums[5].year = 0;
    albums[5].duration = 2700;

  //ЗАДАНИЕ 1
    cout << "ЗАДАНИЕ 1\n";
    ifstream fin("years.txt");
    if (fin.is_open()) {
        char name[50];
        int year;
        for (int i = 0; i < n; i++) {
            fin >> name >> year;
            for (int j = 0; j < n; j++) {
                if (strcmp(albums[j].name, name) == 0) {
                    albums[j].year = year;
                    break;
                }
            }
        }
        fin.close();
    }
    else {
        cout << "Файл years.txt\n\n";
    }
    cout << "Альбомы после загрузки годов:\n";
    for (int i = 0; i < n; i++) {
        printAlbum(albums[i]);
    }
   //ЗАДАНИЕ 2
    cout << "\nЗАДАНИЕ 2\n";
    cout << "ЗАПИСЬ В БИНАРНЫЙ ФАЙЛ\n";

    ofstream fout("albums.bin", ios::binary);
    for (int i = 0; i < n; i++) {
        fout.write((char*)&albums[i], sizeof(Album));
    }
    fout.close();
    cout << "Сохранено " << n << " альбомов в albums.bin\n";
    cout << "\nЧТЕНИЕ ИЗ БИНАРНОГО ФАЙЛА\n";
    Album loaded[20];
    int loadedCount = 0;
    ifstream fin2("albums.bin", ios::binary);
    while (fin2.read((char*)&loaded[loadedCount], sizeof(Album)) && loadedCount < 20) {
        loadedCount++;
    }
    fin2.close();
    cout << "Загружено " << loadedCount << " альбомов из albums.bin\n\n";
    cout << "Проверка загруженных данных:\n";
    for (int i = 0; i < loadedCount; i++) {
        printAlbum(loaded[i]);
    }
    return 0;
}
