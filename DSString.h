#ifndef String
#define String

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class DSString{

private:

    char** words; //stores words
    char** pages; //stores pages

    char* data;
    int size;
    int capacity;
    int capIncrease = 15;



public:

    /**
     * Constructors and destructor
     *
     * Make sure you do proper memory management.
     **/
    DSString();
    DSString(char*);
    DSString(const DSString&);
    DSString(DSString&);
    ~DSString();

    /**
     * Standard relational operators.  You are free to expand this
     * list if you'd like.
     *
     * Note that for each operator, there are two overloaded versions:
     *    one that takes a DSString object
     *    one that takes a null-terminated c-string
     *
     **/
    DSString& operator= (const char* word);
    DSString& operator= (const DSString& string);
    DSString operator+ (const DSString &rhs);
    bool operator== (const char* word) const ;
    bool operator== (const DSString& string) const ;
    bool operator> (const DSString&);
    char& operator[] (const int);


    /**
     * getLength() returns the number (count) of characters in the string.
     **/
    int getLength();

    /**
     * The substring method returns a string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     **/
    DSString substring(int start, int end);

    /**
     * the c_str function returns a null-terminated c-string holding the
     * contents of this object.
     **/
    char* c_str();

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument.
     **/
    friend std::ostream& operator<< (std::ostream& out, const DSString& output);

    //swapping will allow for copying data
    friend void swap(DSString& first, DSString& second);

    //You are free to add more functionality to the class.  For example,
    //you may want to add a find(...) function that will search for a
    //string within a string.  (just an example)
    //
    //Further - you will be able to update and modify this class as the
    //semester progresses.




    //  int TestPositive(const char* fileString);
    //  int CheckIfSentPositive(const char* fileString);
    int find(char character);
    char get(int num);
    void GetReviews(char* in, char* out);
    int TestPositive(const char *fileString);

    int CheckIfSentPositive(char *fileString);
    int getSize();
    char* strtok(char *str, const char *delim);

    char* GetData();

    char charAt(int index) const;

//added for program 2
    void sortWords(int, ostream&, char**);
    char* getPages(char*, int, char**);
    void getWords(char*, char**);



};


DSString operator+ (const DSString& lhs, const DSString& rhs);
DSString operator+ (const DSString& lhs, const char*   rhs);
DSString operator+ (const char*   lhs, const DSString& rhs);
DSString operator+ (const DSString& lhs, char rhs);
DSString operator+ (char lhs, const DSString& rhs);


#endif