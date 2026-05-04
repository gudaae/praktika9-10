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
#include <string>
#include <locale.h>
using namespace std;

enum Style { FUNK, SOUL, ROCK, OTHER };
struct Track {
    string name;
    int duration;
};
struct Album {
    string name;
    string artist;
    Style style;
    int year;
    int totalDuration;
    Track tracks[10];
    int trackCount;
};
string styleToString(Style s) {
    switch (s) {
    case FUNK: return "Funk";
    case SOUL: return "Soul";
    case ROCK: return "Rock";
    default: return "Other";
    }
}
Style stringToStyle(string s) {
    if (s == "Funk") return FUNK;
    if (s == "Soul") return SOUL;
    if (s == "Rock") return ROCK;
    return OTHER;
}
void printAlbum(Album a) {
    cout << "\nНазвание: " << a.name << endl;
    cout << "Исполнитель: " << a.artist << endl;
    cout << "Стиль: " << styleToString(a.style) << endl;
    cout << "Год: " << a.year << endl;
    cout << "Длительность: " << a.totalDuration << " сек" << endl;
    for (int i = 0; i < a.trackCount; i++) {
        cout << "  " << a.tracks[i].name << " (" << a.tracks[i].duration << " сек)" << endl;
    }
}

// Задание 1: чтение года выпуска из текстового файла


void readYearsFromFile(Album albums[], int n, const char* filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    string albumName;
    int year;
    while (fin >> albumName >> year) {
        for (int i = 0; i < n; i++) {
            if (albums[i].name == albumName) {
                albums[i].year = year;
                break;
            }
        }
    }
    fin.close();
    cout << "Данные о годах выпуска загружены из файла " << filename << endl;
}


// Задание 2: запись массива структур в бинарный файл


void saveToBinaryFile(Album albums[], int n, const char* filename) {
    ofstream fout(filename, ios::binary);
    if (!fout.is_open()) {
        cout << "Не удалось создать файл " << filename << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        char name[100] = { 0 };
        char artist[100] = { 0 };
        strcpy_s(name, albums[i].name.c_str());
        strcpy_s(artist, albums[i].artist.c_str());

        fout.write((char*)name, sizeof(name));
        fout.write((char*)artist, sizeof(artist));
        fout.write((char*)&albums[i].style, sizeof(albums[i].style));
        fout.write((char*)&albums[i].year, sizeof(albums[i].year));
        fout.write((char*)&albums[i].totalDuration, sizeof(albums[i].totalDuration));
        fout.write((char*)&albums[i].trackCount, sizeof(albums[i].trackCount));

        for (int j = 0; j < albums[i].trackCount; j++) {
            char trackName[100] = { 0 };
            strcpy_s(trackName, albums[i].tracks[j].name.c_str());
            fout.write((char*)trackName, sizeof(trackName));
            fout.write((char*)&albums[i].tracks[j].duration, sizeof(albums[i].tracks[j].duration));
        }
    }

    fout.close();
    cout << "Массив альбомов сохранён в бинарный файл " << filename << endl;
}
void loadFromBinaryFile(Album albums[], int& n, const char* filename) {
    ifstream fin(filename, ios::binary);
    if (!fin.is_open()) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }
    n = 0;
    while (!fin.eof() && n < 20) {
        char name[100] = { 0 };
        char artist[100] = { 0 };

        fin.read((char*)name, sizeof(name));
        if (fin.eof()) break;

        fin.read((char*)artist, sizeof(artist));
        fin.read((char*)&albums[n].style, sizeof(albums[n].style));
        fin.read((char*)&albums[n].year, sizeof(albums[n].year));
        fin.read((char*)&albums[n].totalDuration, sizeof(albums[n].totalDuration));
        fin.read((char*)&albums[n].trackCount, sizeof(albums[n].trackCount));

        albums[n].name = string(name);
        albums[n].artist = string(artist);

        for (int j = 0; j < albums[n].trackCount; j++) {
            char trackName[100] = { 0 };
            fin.read((char*)trackName, sizeof(trackName));
            fin.read((char*)&albums[n].tracks[j].duration, sizeof(albums[n].tracks[j].duration));
            albums[n].tracks[j].name = string(trackName);
        }
        n++;
    }
    fin.close();
    cout << "Массив альбомов загружен из бинарного файла " << filename << endl;
}

int main() {
    setlocale(LC_ALL, "Ru");

    Album albums[20];
    int n = 6;
    albums[0].name = "Hybrid Theory";
    albums[0].artist = "Linkin Park";
    albums[0].style = ROCK;
    albums[0].totalDuration = 2220;
    albums[0].trackCount = 3;
    albums[0].tracks[0] = { "Papercut", 185 };
    albums[0].tracks[1] = { "One Step Closer", 156 };
    albums[0].tracks[2] = { "In the End", 216 };

    albums[1].name = "Meteora";
    albums[1].artist = "Linkin Park";
    albums[1].style = ROCK;
    albums[1].totalDuration = 2160;
    albums[1].trackCount = 3;
    albums[1].tracks[0] = { "Somewhere I Belong", 214 };
    albums[1].tracks[1] = { "Numb", 187 };
    albums[1].tracks[2] = { "Breaking the Habit", 193 };

    albums[2].name = "Minutes to Midnight";
    albums[2].artist = "Linkin Park";
    albums[2].style = ROCK;
    albums[2].totalDuration = 2700;
    albums[2].trackCount = 3;
    albums[2].tracks[0] = { "What I've Done", 215 };
    albums[2].tracks[1] = { "Bleed It Out", 171 };
    albums[2].tracks[2] = { "Shadow of the Day", 256 };

    albums[3].name = "Thriller";
    albums[3].artist = "Michael Jackson";
    albums[3].style = FUNK;
    albums[3].totalDuration = 2520;
    albums[3].trackCount = 3;
    albums[3].tracks[0] = { "Wanna Be Startin' Somethin'", 363 };
    albums[3].tracks[1] = { "Thriller", 357 };
    albums[3].tracks[2] = { "Beat It", 258 };

    albums[4].name = "Superfly";
    albums[4].artist = "Curtis Mayfield";
    albums[4].style = SOUL;
    albums[4].totalDuration = 2400;
    albums[4].trackCount = 3;
    albums[4].tracks[0] = { "Little Child Runnin' Wild", 300 };
    albums[4].tracks[1] = { "Pusherman", 300 };
    albums[4].tracks[2] = { "Freddie's Dead", 300 };

    albums[5].name = "Innervisions";
    albums[5].artist = "Stevie Wonder";
    albums[5].style = SOUL;
    albums[5].totalDuration = 2640;
    albums[5].trackCount = 3;
    albums[5].tracks[0] = { "Living for the City", 259 };
    albums[5].tracks[1] = { "Higher Ground", 204 };
    albums[5].tracks[2] = { "Don't You Worry 'bout a Thing", 284 };
    readYearsFromFile(albums, n, "years.txt");

    cout << "\n===== Альбомы после загрузки годов выпуска =====" << endl;
    for (int i = 0; i < n; i++) {
        cout << albums[i].name << " - " << albums[i].artist << " (" << albums[i].year << ")" << endl;
    }
    saveToBinaryFile(albums, n, "albums.bin");
    Album loadedAlbums[20];
    int loadedCount = 0;
    loadFromBinaryFile(loadedAlbums, loadedCount, "albums.bin");
    cout << "\n===== Загружено из бинарного файла =====" << endl;
    for (int i = 0; i < loadedCount; i++) {
        printAlbum(loadedAlbums[i]);
    }
    return 0;
}