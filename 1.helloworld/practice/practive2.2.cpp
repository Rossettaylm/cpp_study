#include <iostream>
#include <vector>
#include <string>
using namespace std;

//p(n) = n(3n - 1) / 2
inline bool is_size_ok(int pos);
bool pentagonal_seq(int, vector<int> &);
void printSeq(const vector<int>, string);

int main()
{
    int pos;
    vector<int> vec;
    const string seq_type = "Pentagonal Numeric Series";
    do
    {
        cout << "Please input a position of pentagonal: ";
        cin >> pos;
        if (pentagonal_seq(pos, vec))
        {
            printSeq(vec, seq_type);
        }
    } while (pos != 0);

    return 0;
}

inline bool is_size_ok(int size)
{
    if (size <= 0 || size > 1024)
    {
        return false;
    }
    return true;
}

bool pentagonal_seq(int pos, vector<int> &vec)
{
    if (!is_size_ok(pos))
    {
        cerr << "Error! Invalid positon: " << pos << endl;
        return false;
    }
    else
    {
        for (int i = vec.size() + 1; i <= pos; i++)
        {
            vec.push_back(i * (3 * i - 1) / 2);
        }
    }
    return true;
}

void printSeq(const vector<int> vec, string seq_type)
{
    cout << seq_type << ":\n\t";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;
}
