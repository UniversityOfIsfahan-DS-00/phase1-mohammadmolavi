#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

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
    detailes(string = "" , int = 0, string = "" , string = "" , string = ""
     , string = "" , string = "" , bool = false);
    void set_titleId(string);
    string get_titleId();
    void set_ordering(string);
    int get_ordering();
    void set_title(string);
    string get_title();
    void set_region(string);
    string get_region();
    void set_language(string);
    string get_language();
    void set_types(string);
    string get_types();
    void set_attributes(string);
    string get_attributes();
    void set_isOriginalTitle(string);
    bool get_isOriginalTitle();
};

class rating
{
private:
    string titleId;
    int count;
    float rate;
public:
    rating(string , int , float);
    void new_rate(bool);
    float get_rating();
};
