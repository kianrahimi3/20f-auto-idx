#include <fstream>
#include <iostream>


#include "DSVector.h"
#include "DSList.h"

using namespace std;

int main(int argc, char** argv) {
    std::ofstream outputstream(argv[2]);
    outputstream << "Hello, World!" << std::endl;
    outputstream.close();
    std::cout << "Hello and wrote sample output file." << std::endl;


    DSVector<int> temp;
    temp.push_back(0);
    temp.push_back(5);
    cout << temp[0] << endl;
    cout << temp[1] << endl;
    temp[1] = 4;
    temp[0] = 1;
    cout << temp[0] << endl;
    cout << temp[1] << endl;

    cout << endl << endl;

    DSList<int> list;
 //   list.push_front(5);
list.push_back(5);
list.push_front(15);
list.push_back(03);
list.push_back(01);


cout << list << endl;
cout << list[0] << endl;
cout << list[1] << endl;
cout << list[2] << endl;
cout << list[3] << endl;

    //return 0;
}
