//
// Created by kianr on 9/5/2020.
//

#include "DSString.h"
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;


DSString::DSString() {
    size = 1;
    data = new char[size];
    data[0] = '\0';
}

DSString::DSString(char* word) {
    size = 0;

   while(word[size] != '\0') {
       size++;
   }

   data = new char[size + 1];
   for(int i = 0; i < size; i++) {
       data[i] = word[i];
   }
   data[size] = '\0';
}

DSString::DSString(const DSString& myString) {
   size = myString.size;
    data = new char[myString.size + 1];

  //  strcpy(data, myString.data);
int index = 0;
while(myString.data[index]) {
    data[index] = myString.data[index];
    index++;
}

}

DSString::~DSString() {
    delete[] data;
}

ostream& operator<<(std::ostream& out, const DSString& output) {

    out << output.data;
    return out;
}
/*
DSString operator+(const DSString &first, const DSString &second) {
    int length = first.size + second.size;

    char *temp = new char[length + 1];

    strcpy(temp, first.data);
    strcpy(temp, second.data);

    DSString temporary(temp);
    delete[] temp;

    return temporary;
}
*/
DSString & DSString::operator=(const char *s) {
    if(this->data != s) {
        delete [] data;

        if(s != nullptr) {
            data = new char[strlen(s) + 1];
            strcpy(data, s);
        } else
            data = nullptr;
    }
}
DSString & DSString::operator=(const DSString& string) {
   if(this != &string) {
       delete [] data;

       if(string.data != nullptr) {
           data = new char[strlen(string.data) + 1];
           strcpy(data, string.data);
       }
       else {
           data = nullptr;
       }
   }
    return *this;
}

DSString DSString::operator+(const DSString &rhs) {
   int length = size + rhs.size;

   char temp[length + 1];
   strcpy(temp, data);
   strcat(temp, rhs.data);

   return DSString(temp);

    }

bool DSString::operator==(const char *word) const {
    if(strcmp(this->data, word) == 0) {
        return true;
    } else
        return false;
}
bool DSString::operator==(const DSString &string) const {
    if(strcmp(this->data, string.data) == 0) {
        return true;
    } else
        return false;
}
bool DSString::operator>(const DSString &string) {
   for(int i = 0; i < min(size, string.size); i++) {
       if(charAt(i) > string.data[i]) {
           return true;
       }
       if(string.data[i] > charAt(i)) {
           return false;
       }
   }
   //if they are equal
   return size >= string.size;
}
//use for > operator
char DSString::get(int num) {
    if(num > getLength()) {
        this->data[num] = '\0';

    }

    return data[num];
}

char & DSString::operator[](int index) {
    int loc = 0;

    if(index < 0) {
        loc = size + index;
    }
    else {
        loc = index;
    }

    return data[loc];
}
int DSString::getLength() {
    size = strlen(data);
    return size;
}
DSString DSString::substring(int start, int end) {
    int length = end - start + 1;
    char* string = new char[length];
    if(end >= 0) {
        for(int i = 0; i < length - 1; i++) {
            string[i] = data[start +1];
        }
    }
    string[length-1] = '\0';
    DSString temp(string);

    return temp;
}

char * DSString::c_str() {
    return data;
}
int DSString::find(char character) {
    size = strlen(data);

     for(int i = 0; i < size; i++) {
         if(data[i] == character)
             return i;
         else
             return 0;
     }
}
char* DSString::GetData() {
    return data;
}
int DSString::getSize() {
    return size;
}
char * DSString::strtok(char *str, const char *delim) {
    return strtok(str, delim);
}

void swap(DSString& first, DSString& second) {
    swap(first.size, second.size);
    swap(first.data, second.data);
}

char DSString::charAt(int index) const {
    if(size == 0 || index >= size) {
        char s = 0;
        return s;
    }
    if(index < 0) {
        index = size + index;
    }
    return data[index];
}

/*

void DSString::GetReviews(char* in, char* out) {

    ifstream myFile(in);
    ofstream fout(out);


    DSString csvTest;
    char headers[100];
    myFile.getline(headers,100,'\n');  //find out way to not worry about the char length
    cout << endl << endl;

    vector<DSString> reviews;

    char csv[20000] ;
    // DSString csvvv;
    while (myFile.getline(csv, 20000, '\n')) {
        DSString csvvv(csv);
        reviews.push_back(csvvv);

    }
    //   fout << reviews.size() << endl;

//Looks for key words
// Output(fout, reviews);
//myFile.close();


    int noPositive = 0;
    int sentPositive = 0;
    int j = 0;
    for (int i = 0; i < reviews.size(); i++) {
        noPositive += TestPositive(reviews[i].data);
        sentPositive += CheckIfSentPositive(reviews[i].data);

    }

    //show results
    fout << "No. Positive Reviews Based on Program = " << noPositive << endl;
    fout << "Actual Positive Reviews = " << sentPositive << endl;
    fout <<  "Total Reviews = " << reviews.size() << endl;
    fout << endl <<"My Test: " << fixed << setprecision(4) << (double)(noPositive) / reviews.size() << endl;
    fout << "Actual: " << fixed << setprecision(4) << (double)(sentPositive) / reviews.size() << endl << endl;

    fout << "Incorrect Review Numbers: " << endl;

    //int count = 0;
    for(int i = 0; i < reviews.size(); i++) {
        if( TestPositive(reviews[i].data) == 1 && CheckIfSentPositive(reviews[i].data) == 0) {
            fout << i+1 << endl;
            //  count++;
            //  output <<"\t" << count << endl;
        }
    }

//    fout << endl << endl << "READ ME" << endl << "CHECK ME OUT" << endl;
    //  fout.close();


}

int DSString::TestPositive(const char *fileString) {
    int count = 0;
    //check for value for positive or negative
    if( strstr(fileString, "wonderful")  ||
        strstr(fileString, "fantastic") ||  strstr(fileString, "alive") ||  strstr(fileString, "sophisticated") ||
        strstr(fileString, "stunning") || strstr(fileString, "organic") ||
        strstr(fileString, "marvelous") || strstr(fileString, "Brilliant") || strstr(fileString, "praise") ||
        strstr(fileString, "masterpiece") || strstr(fileString, "fresh") || strstr(fileString, "invested") ||
        strstr(fileString, "expert") || strstr(fileString, "rocks") ||
        strstr(fileString, "pleasant") ||
        strstr(fileString, "organic") || strstr(fileString, "hilarious") || strstr(fileString, "speechless") ||
        strstr(fileString, "dream come true") || strstr(fileString, "must-see") || strstr(fileString, "intrig") ||
        strstr(fileString, "touching") || strstr(fileString, "Excellent") || strstr(fileString, "Cute") || strstr(fileString, "amazed")  || strstr(fileString, "remarkable") ||
        strstr(fileString, "essential") || strstr(fileString, "giggle") || strstr(fileString, "sweet") || strstr(fileString, "extraordinary") ||
        strstr(fileString, "loving") || strstr(fileString, "gem ") ||
        strstr(fileString, "incredible") || strstr(fileString, "fascin") || strstr(fileString, "aesthetic") ||
        strstr(fileString, "Attractive") ||
        strstr(fileString, "amazing") || strstr(fileString, "realism") || strstr(fileString, "dream") ||
        strstr(fileString, "reward") || strstr(fileString, "Amazing") || strstr(fileString, "superb") || strstr(fileString, "Superb") || strstr(fileString, "spectacular") ||
        strstr(fileString, "courageous") || strstr(fileString, "redemption") ||
        strstr(fileString, "faithful") || strstr(fileString, "authentic") || strstr(fileString, "enlight") || strstr(fileString, "Memorable") ||
        strstr(fileString, "with style") ||
        strstr(fileString, "subtle") || strstr(fileString, "beauty") || strstr(fileString, "nostalgia") || strstr(fileString, "really like") ||
        strstr(fileString, "smile") || strstr(fileString, "FANTASTIC") || strstr(fileString, "fantastic") || strstr(fileString, "award") || //strstr(fileString, "FINALLY") ||
        strstr(fileString, "inspiration") || strstr(fileString, "Inspiration") || strstr(fileString, "unforgetttable") || strstr(fileString, "Unforgettable") ||
        strstr(fileString, "diamond") || strstr(fileString, "genuin") || strstr(fileString, "Nice") ||
        strstr(fileString, "memorable") || strstr(fileString, "Beautiful")  ||
        strstr(fileString, "purity") || strstr(fileString, "mind-blowing") || strstr(fileString, ":-)") ||
        strstr(fileString, "recognize") || strstr(fileString, "Impress") || strstr(fileString, "LOVE") || strstr(fileString, "superior") ||
        strstr(fileString, "knockout")  || strstr(fileString, "satisfy") || strstr(fileString, "keeps you guessing") || strstr(fileString, "significant") ||
        //strstr(fileString, "Best") || strstr(fileString, "best") ||
        strstr(fileString, "creative") || strstr(fileString, "lucky") ||
        strstr(fileString, "outburst") || //strstr(fileString, "I like") ||
        strstr(fileString, "blown away") || strstr(fileString, "look forward") ||
        strstr(fileString, "genius") || strstr(fileString, "flavor") || strstr(fileString, "overtake") ||
        strstr(fileString, "life altering") || strstr(fileString, "exceptional") || strstr(fileString, "never boring") ||
        strstr(fileString, "rare ") || strstr(fileString, "heart warming") || strstr(fileString, "warmed") ||
        strstr(fileString, "insightful")||  strstr(fileString, "soaring") ||
        strstr(fileString, "rising star") || strstr(fileString, "timeless")  || strstr(fileString, "gorgeous") || strstr(fileString, "stands out") ||
        strstr(fileString, "definitive") || strstr(fileString, "brings to light") ||
        strstr(fileString, "must see") || strstr(fileString, "delight")

            ) {

        return 1;
    } else
        return 0;
//    cout << count<< endl << "Look above" << endl;
}

int DSString::CheckIfSentPositive(char *fileString) {
    //check for value for positive or negative
    if (strstr(fileString, ",positive")) {
        return 1;
    } else
        return 0;
}
*/

//got help
//added new variable in header file == char** words
//pointer array to hold words




