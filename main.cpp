#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <fstream>
#include <iostream>

#include "DSVector.h"
#include "DSList.h"
#include "DSString.h"


using namespace std;

int main(int argc, char** argv) {


    Catch::Session().run();



    /*
       else {


   //    std::ofstream outputstream(argv[2]);
   //    outputstream << "Hello, World!" << std::endl;
           //   outputstream.close();
           std::cout << "Hello and wrote sample output file." << std::endl;





           ifstream inFile(argv[2]);
   //ofstream conversion("../converstion.txt");
   //DSString wholething;
           cout << endl;

           if (!inFile)
               cout << "We have a problem" << endl;

           char buff[80];
           DSString pageNum;
           DSString word;

           DSVector<DSString> pages;
           DSVector<DSString> phrases;


           DSVector<DSString> testVector;

           DSVector<DSVector<DSString>> test;


           while (inFile.getline(buff, 80)) {
   //inFile.getline(buff,80)

   //cout << buff << endl;



               // DSString buffer(buff);


               //  std::string rX = "\\[\\w.*?\\]";
               std::regex phrase("\\[\\w.*?\\]");
               try {
                   std::cregex_iterator next(buff, buff + strlen(buff), phrase);
                   std::cregex_iterator end;
                   while (next != end) {
                       std::cmatch match = *next;
                       int length = match.str().length();
                       char array[length];
                       strcpy(array, match.str().c_str());
                       //       for(int i = 0; i < length; i++) {
                       //           array[i] = match.str()[i];
                       //           cout << array[i];
                       //       }



                       DSString phraseHolder(array);
                       int j;
                       for (j = 0; j < phraseHolder.getSize(); j++) {
                           if (phraseHolder[j] != ']')
                               continue;
                           else
                               break;
                       }
                       DSString temporaray(phraseHolder.substring(1, j));

                       cout << endl;
                       //std::cout << array << "\n";

                       phrases.push_back(temporaray.GetData());

                       next++;
                   }
               } catch (std::regex_error &e) {
   // in case of an error xD


               }







               //  std::string rX = "\\[\\w.*?\\]";
               std::regex page("\\<\\w.*?\\>");
               try {
                   std::cregex_iterator next(buff, buff + strlen(buff), page);
                   std::cregex_iterator end;
                   while (next != end) {
                       std::cmatch match = *next;
                       int length = match.str().length();
                       char array[length];
                       strcpy(array, match.str().c_str());
                       //       for(int i = 0; i < length; i++) {
                       //           array[i] = match.str()[i];
                       //           cout << array[i];
                       //       }


                       DSString pageNumHolder(array);
                       int j;
                       for (j = 0; j < pageNumHolder.getSize(); j++) {
                           if (buff[j] != '>')
                               continue;
                           else
                               break;
                       }
                       DSString temporaray(pageNumHolder.substring(1, j));

                       cout << endl;
                       //std::cout << array << "\n";

                       pages.push_back(temporaray.GetData());

                       next++;
                   }
               } catch (std::regex_error &e) {
   // in case of an error xD


               }





   ///////SUB WORDS


               //  std::string rX = "\\[\\w.*?\\]";
               std::regex subwords("\\(\\w.*?\\)");
               try {
                   std::cregex_iterator next(buff, buff + strlen(buff), subwords);
                   std::cregex_iterator end;
                   while (next != end) {
                       std::cmatch match = *next;
                       int length = match.str().length();
                       char array[length];
                       strcpy(array, match.str().c_str());
                       //       for(int i = 0; i < length; i++) {
                       //           array[i] = match.str()[i];
                       //           cout << array[i];
                       //       }


                       DSString subwordsholder(array);
                       int k;
                       for (k = 0; k < subwordsholder.getSize(); k++) {
                           if (subwordsholder[k] != ')')
                               continue;
                           else
                               break;
                       }
                       DSString temporaray(subwordsholder.substring(1, k));

                       cout << endl;
                       //std::cout << array << "\n";

                       phrases.push_back(temporaray.GetData());

                       next++;
                   }
               } catch (std::regex_error &e) {
   // in case of an error xD


               }



   ////////REG WORDS

               std::regex regwords("\\w.*?\\s");
               try {
                   std::cregex_iterator next(buff, buff + strlen(buff), regwords);
                   std::cregex_iterator end;
                   while (next != end) {
                       std::cmatch match = *next;
                       int length = match.str().length();
                       char array[length];
                       strcpy(array, match.str().c_str());
                       //  for(int i = 0; i < length; i++) {
                       //     array[i] = match.str()[i];
                       //     cout << array[i];
                       //  }



                       //  cout << endl;
                       //std::cout << match.str() << "\n";


                       DSString wordsHolder(array);

                       bool isWord = true;
                       int z;
                       for (z = 0; z < wordsHolder.getSize(); z++) {
                           if (wordsHolder[z] == '<' || wordsHolder[z] == '>' ||
                               wordsHolder[z] == '[' || wordsHolder[z] == ']' ||
                               wordsHolder[z] == '(' || wordsHolder[z] == ')') {

                               isWord = false;
                           }
                       }

                       if (isWord == true) {
                           phrases.push_back(array);
                       }

                       next++;
                   }
               } catch (std::regex_error &e) {
   // in case of an error xD


               }





   ///////////////////////////uncomment above this



               /*
                 regex e ("/[.*?\]");
                 cmatch cm;


                  regex_match(testString, cm, e, regex_constants::match_default);

                  for(int i = 0; i < cm.size(); i++) {
                      cout <<  cm[i] << endl;
                  }
              */

/*
    std::string s = "<15>\n"
                    "algorithm [binary tree] analysis heap\n"
                    "<1>\n"
                    "[binary search tree] analysis\n"
                    "complexity algorithm [2-3 tree]\n"
                    "<5>\n"
                    "[b+ tree] [Binary Tree]\n"
                    "<8>\n"
                    "graph clique Tree\n"
                    "<5>\n"
                    "tree [full binary tree]\n"
                    "[complete binary tree]\n"
                    "<-1>";
                    */
    //  std::string rX = "\\[\\w.*?\\]";
//  int size = 0;
//  for(size = 0; size < buffer.getSize(); size++) {
//      if (!buffer[size])
//          break;





/*

    if(buff[0] == '<') {    //page number
        DSString pageNumHolder(buff);

       // char* pagesubstring;

        int i;
        for(i = 0; i < pageNumHolder.getSize(); i++) {
            if(buff[i] != '>')
                continue;
            else
                break;
        }
        DSString temporaray(pageNumHolder.substring(1, i));

        pageNum = temporaray;
        pages.push_back(pageNum.GetData());

        } //end if

  //      testVector.push_back(buffer.GetData());

    if(buff[0] == '[') {
        char temp[80];
        inFile >> temp;

        strcat(buff, temp);
    }
*/
////////////////////
//cout << buffer << endl;
    // conversion << buff << "  " << pageNum.GetData() << endl;
    //   cout << buff << "  " << pageNum.GetData() << endl;





    //  cout << wholething.GetData() << endl;
    //wholething = buff + " " + pageNum);

    //  while(inFile >> buff) {

    //       cout << buff << endl;
    //   }

/*
        }
        cout << endl;
        cout << "This is my array" << endl;

        for (int i = 0; i < phrases.size(); i++) {
            cout << phrases[i] << endl;
        }
///////////////////////    unncommment above and below this

        cout << endl;
        cout << "These are my pages" << endl;
        for (int i = 0; i < pages.size(); i++) {
            cout << pages[i].GetData() << endl;
        }

        cout << endl << "These are my lines" << endl;
        for (int i = 0; i < testVector.size(); i++) {
            cout << testVector[i].GetData() << endl;
        }


        ifstream inConversion("../converstion.txt");
        DSString conversionword;
        DSString conversionpage;

        DSVector<DSString> conversionwords;
        DSVector<DSString> conversionpages;

        while (inConversion >> conversionword.GetData() >> conversionpage.GetData()) {
            conversionwords.push_back(conversionword.GetData());
            conversionpages.push_back(conversionpage.GetData());
        }
        cout << endl << "conversion" << endl;
        for (int i = 0; i < conversionwords.size(); i++) {
            cout << conversionwords[i] << " " << conversionpages[i] << endl;
        }





//cout << wholething << endl;

        cout << endl << endl;

        cout << endl << "Pages" << endl;

        for (int i = 0; i < pages.size(); i++) {
            cout << pages[i].GetData() << endl;
        }

        cout << endl << "Phrases" << endl;

        for (int i = 0; i < phrases.size(); i++) {
//    cout << phrases[i].GetData() << endl;
        }
*/
/*

cout << endl << "PULL FROM FILE" << endl;

/////for(int i = 1; i < 4; i++) {

    //  ofstream output("../output.txt");
    ifstream input(argv[2]);


    //  DSList<int> strings;

    char buffer[50];
    char temps[50];


    vector<DSString> testVector;
    ////////fix the vector to show the dsstring

    DSList<char *> LL;
    ////////fix the linked list to show dsstring


    vector<DSString> numbers;

int i = 0;
    char* pageNos;
    while (input.getline(buffer, 50, '\n')) {



        if(buffer[0] == '<'){
            char *tempo = strtok(buffer, " ");
            tempo = strtok(tempo, "<");
            tempo = strtok(tempo, ">");
            pageNos = tempo;
            testVector.push_back(tempo);
            numbers.push_back(pageNos);
        }
    //    else if(buffer[10] == '[') {
    //        cout << "HEREEEEEEEE" << endl;
    //    }
        else if(buffer[0] != '<') {
            stringstream ss(buffer);    //get each word
            while (ss >> temps) {

                if(temps[0] == '[') {       //find words that start with "["
                    char tempo[50];
                    ss >> tempo;
                    char* temporary;
                    temporary = strcat(temps, " ");
                    temporary = strcat(temporary, tempo);
                    testVector.push_back(temporary);
                 //   numbers.push_back(pageNos);
                }
                else{
                    testVector.push_back(temps);
                   // numbers.push_back(pageNos);
                }


            }
        }


        i++;
        }



    for (int i = 0; i < testVector.size(); i++) {
        cout << testVector[i] << endl;
    }

    cout << endl << endl;
    cout << "NUMBERS" << endl;

    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << endl;
    }

    cout << endl << "LL" << endl;


/////}
*/


//        ifstream input(argv[2]);


/*
    // Read all the words into a setstd::
    multiset<std::string> wordsList =
    std::multiset<std::string>( std::istream_iterator<std::string>(input),
                                std::istream_iterator<std::string>());

    // Iterate over every word
    for(auto word = wordsList.begin(); word != wordsList.end(); word=wordsList.upper_bound(*word))
    std::cout << *word << ": " << wordsList.count(*word) << std::endl;

    // Done
   // system("pause");
   // return 0;


   DSString Kian = "Kian";
   DSString Rahimi = "Rahimi";


   cout << Kian << endl;
   cout << Rahimi << endl;

   cout << endl << Kian+" "+Rahimi << endl;


    }

*/



    return 0;
}
