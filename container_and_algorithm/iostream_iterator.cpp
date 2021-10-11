#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void cin_to_cout(vector<string> &);
void infile_to_outfile(ifstream &, ofstream &, vector<string> &);

int main(int argc, char const *argv[])
{
    /* 普通的输入输出方法 */
    // string word;
    // vector<string> text;

    // while (cin >> word)
    // {
    //     text.push_back(word);
    // }
    // sort(text.begin(), text.end());
    // for (int i = 0; i < text.size(); i++)
    // {
    //     cout << text[i] << ' ';
    // }

    /* 对cin，cout采用iostream iterator的输入输出 */
    vector<string> text;
    cin_to_cout(text);

    /* 对文件采用iostream iterator的输入输出 */
    ifstream infile("input_file.txt");
    ofstream outfile("output_file.txt");
    // ofstream outfile("output_file.txt", ios_base::app);
    infile_to_outfile(infile, outfile, text);

    return 0;
}

void cin_to_cout(vector<string> &text)
{
    istream_iterator<string> is(cin);   // first iterator，将is定义为一个绑定至标准输入设备cin的istream_iterator，
    istream_iterator<string> eof;       // last iterator，定义eof不绑定对象，将eof定义为指向end-of-file，即要读取的最后一个元素的下一位置
    copy(is, eof, back_inserter(text)); // 采用back_inserter的方法来插入到text中

    sort(text.begin(), text.end());

    ostream_iterator<string> os(cout, " "); // os绑定至cout，同时以一个空格为间隔输出
    copy(text.begin(), text.end(), os);
}

void infile_to_outfile(ifstream &infile, ofstream &outfile, vector<string> &text)
{

    if (!infile || !outfile)
    {
        cerr << "!! unable to open the necessary files.\n";
    }

    istream_iterator<string> is(infile);
    istream_iterator<string> eof;
    copy(is, eof, back_inserter(text));

    sort(text.begin(), text.end());

    ostream_iterator<string> os(outfile, " ");
    copy(text.begin(), text.end(), os);
}