#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    char str[100];
    ofstream outfile("test.txt", ios_base::out);
    cout << "Please input your name: ";
    cin.getline(str, 100);
    outfile << str << endl;
    outfile.close();

    ifstream infile("test.txt", ios_base::in);
    cout << "The data in the file is: ";
    infile >> str;
    cout << str << endl;
    infile.close();

    return 0;
}
