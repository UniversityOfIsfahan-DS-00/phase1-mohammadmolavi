#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
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
    void new_rate(int);
    void set_count(int c) { count = c; };
    int get_count() { return count; };
    void set_rate(float rat) { rate = rat; };
    float get_rating() { return rate; };
};

void rating::new_rate(int rat)
{
    rate *= 1.0 * count;
    rate += rat;
    count++;
    rate /= 1.0 * count;
    rate *= 10;
    rate = (int)rate;
    rate /= 1.0 * 10;
}

vector<detailes> list;
vector<rating> ratelist;
map<int, string> numToTitle;
map<int, string> numToId;
map<string, int> userToNum;
class User
{
private:
    long int password[100];

public:
    string username[100];
    int count;
    int rated[100][50];
    int count_rated[100];
    void set_password(string user, long int pass) { password[userToNum[user]] = pass; };
    long int get_password(string user) { return password[userToNum[user]]; }
};

void do_rate(int c)
{
    User users;
    users.count = 0;
    string temp_user;
    long int temp_pass;
    int select;
L1:
    cout << "!!for rate you must sign in or sign up!!\n"
         << "for sign in enter 1 else enter 2 : ";
    cin >> select;
    if (select == 2)
    {
        cout << "enter your username : ";
        cin >> temp_user;
        users.username[users.count] = temp_user;
        userToNum[temp_user] = users.count;
        cout << "enter password : ";
        cin >> temp_pass;
        users.set_password(temp_user, temp_pass);
        users.count_rated[userToNum[temp_user]] = 0;
        users.count++;
    }
    else if (select = 1)
    {
        while (true)
        {
            cout << "enter your username : ";
            cin >> temp_user;
            cout << "enter password : ";
            cin >> temp_pass;
            if (users.get_password(temp_user) == temp_pass)
                break;
            else
                cout << "user or password is incorrect\n";
        }
    }
    int num, grade;
    while (num != -1)
    {
        bool is_rated = false;
        cout << "<<for rate to every movie type its number>>\n";
        for (int i = 0; i < c; i++)
            cout << i << ": " << numToTitle[i] << endl;
        cin >> num;
        if (num == -1)
            break;
        for (int i = 0; i < 50 && is_rated == false; i++)
        {
            if (num == users.rated[userToNum[temp_user]][i])
            {
                cout << "\n\nyou already rate this movie!\n\n\n";
                is_rated = true;
            }
        }
        if (is_rated == false)
        {
            cout << "enter your desired grade : ";
            cin >> grade;
            (ratelist.data() + num - 1)->new_rate(grade);
            users.rated[userToNum[temp_user]][users.count_rated[userToNum[temp_user]]] = num;
            users.count_rated[userToNum[temp_user]] += 1;
        }
    }
    if (num == -1)
    {
        cout << "\n\nsign in or sign up with another acount : 1\n"
             << "exit : 2\n";
        cin >> num;
        if (num == 1)
            goto L1;
    }
}

void saveInfo(int);

int main()
{
    ifstream inputFile1("title.akas.txt", ios::in);
    ifstream inputFile2("title.ratings.txt", ios::in);
    string line;
    string rate;
    getline(inputFile1, line);
    cout << line << endl;
    getline(inputFile2, rate);
    int count = 0;
    while (line[0] = '0')
    {
        detailes mov;
        rating ra;
        getline(inputFile1, line);
        getline(inputFile2, rate);

        char *str1 = &line[0];
        char *token1 = (char *)strtok(str1, "\t");

        stringstream temp(rate);
        if (token1[0] == '0')
            break;
        cout << line << endl;
        mov.set_titleId(token1);
        numToId[count] = token1;
        token1 = strtok(NULL, "\t");
        mov.set_ordering(token1);
        token1 = strtok(NULL, "\t");
        mov.set_title(token1);
        numToTitle[count] = token1;
        token1 = strtok(NULL, "\t");
        mov.set_region(token1);
        token1 = strtok(NULL, "\t");
        mov.set_language(token1);
        token1 = strtok(NULL, "\t");
        mov.set_types(token1);
        token1 = strtok(NULL, "\t");
        mov.set_attributes(token1);
        token1 = strtok(NULL, "\t");
        mov.set_isOriginalTitle(token1[0]);
        token1 = strtok(NULL, "\t");
        list.push_back(mov);

        getline(temp, rate, '\t');
        getline(temp, rate, '\t');
        ra.set_rate(stof(rate));
        getline(temp, rate, '\t');
        ra.set_count(stoi(rate));
        ratelist.push_back(ra);
        count++;
    }
    do_rate(count);
    inputFile1.close();
    saveInfo(count);
}

void saveInfo(int c)
{
    ofstream outputFile("title.rating.dat", ios::out);
    outputFile << "tconst	averageRating	numVotes\n";
    for (int i = 0; i < c; i++)
    {
        outputFile << numToId[i] << '\t' << (ratelist.data() + i)->get_rating()
                   << '\t' << (ratelist.data() + i)->get_count() << endl;
    }
}