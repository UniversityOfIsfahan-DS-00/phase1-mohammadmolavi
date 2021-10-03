#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

class detailes
{
private:
    string titleId;
    int ordering;
    string title;
    string region;
    string language;
    string types;
    string attributes;
    bool isOriginalTitle;

public:
    //detailes(string = "", int = 0, string = "", string = "", string = "", string = "", string = "", bool = false);
    void set_titleId(string tId) { titleId = tId; };
    string get_titleId() { return titleId; };
    void set_ordering(string order) { ordering = stoi(order); };
    int get_ordering() { return ordering; };
    void set_title(string titl) { title = titl; };
    string get_title() { return title; };
    void set_region(string reg) { region = reg; };
    string get_region() { return region; };
    void set_language(string lang) { language = lang; };
    string get_language() { return language; };
    void set_types(string type) { types = type; };
    string get_types() { return types; };
    void set_attributes(string att) { attributes = att; };
    string get_attributes() { return attributes; };
    void set_isOriginalTitle(char originalTitle) { isOriginalTitle = (int)originalTitle - 48; };
    bool get_isOriginalTitle() { return isOriginalTitle; };
};

class rating
{
private:
    string titleId;
    int count;
    float rate;

public:
    rating(string, int, float);
    void new_rate(int);
    float get_rating() { return rate; };
};

void rating::new_rate(int rat)
{
    rate *= 1.0 * count;
    rate += rat;
    rate /= 1.0 * count;
}

int main()
{
    ifstream inputFile("title.akas.txt", ios::in);
    string line;
    getline(inputFile, line);
    vector <detailes> list;
    while (line[0] = '0')
    {
        detailes mov;
        getline(inputFile, line);
        char *str = &line[0];
        char *token = (char *)strtok(str, "\t");
        if (token[0] == '0')
            break;
        mov.set_titleId(token);
        token = strtok(NULL, "\t");
        mov.set_ordering(token);
        token = strtok(NULL, "\t");
        mov.set_title(token);
        token = strtok(NULL, "\t");
        mov.set_region(token);
        token = strtok(NULL, "\t");
        mov.set_language(token);
        token = strtok(NULL, "\t");
        mov.set_types(token);
        token = strtok(NULL, "\t");
        mov.set_attributes(token);
        token = strtok(NULL, "\t");
        mov.set_isOriginalTitle(token[0]);
        token = strtok(NULL, "\t");
        list.push_back(mov);
    }
    inputFile.close();
}