#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
//  note point: when we make an entry of string but we dont have int value so by default zero  will be set that int value

int main()
{
    // creation of unordered_map
    unordered_map<string, int> umap;

    // first way of insertion
    pair<string, int> p1 = make_pair("anurag", 1);
    umap.insert(p1);

    // second way of insertion (corrected variable name)
    pair<string, int> p2("kya", 2);
    umap.insert(p2);

    // third way of insertion
    umap["name"] = 3;
    umap["na"] = 8;
    umap["nae"] = 5;
    umap["nroy"] = 3;

    //   searching
    cout << umap["kya"] << endl;
    cout << umap.at("anurag") << endl;

    //   size of the mapp
    cout << umap.size() << endl;

    //  check entity is present ?
    // if present return 1 otherwise return 0
    cout << umap.count("anurag");
    //   erase or delete or remove
    umap.erase("anurag");
    cout << umap.size() << endl;

    //  iterater

    for (auto i : umap)
    {
        cout << i.first << i.second << endl;
    }

    //   using while loop
    unordered_map<string, int>::iterator it = umap.begin();

    while (it != umap.end())
    {
        cout << it->first << " " << it->second;
        it++;
    }

    return 0;
}
