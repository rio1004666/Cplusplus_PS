#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using std::cout; using std::endl;
using std::cin; using std::string;
using std::set; using std::vector;

template<typename T>
void printVectorElements(vector<T> &vec)
{
    cout << "{ ";
    for (const auto &item : vec) {
        cout << item << ", ";
    }
    cout << "\b\b }" << endl;
}

int main() {
    set<string> s1 {"array", "vector",
                    "deque", "list",
                    "set", "map",
                    "multimap", "span"};
    set<string> s2(s1);
    s2.insert("stack");
    s2.insert("queue");

    vector<string> s1s2_intsec;

    std::set_intersection(s1.begin(), s1.end(),
                          s2.begin(), s2.end(),
                          std::back_inserter(s1s2_intsec));

    cout << "s1 ¡û s2: ";
    printVectorElements(s1s2_intsec);

    exit(EXIT_SUCCESS);
}
