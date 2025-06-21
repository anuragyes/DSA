vector<int> vec = {1, 2, 3, 4, 3, 4, 2, 4, 3};

    map<int, int> s;
    for (int element : vec)
    {
        s[element]++;
    }

    for (const auto &pair : s)
    {
        std::cout << "Element " << pair.first << ": " << pair.second << " times\n";
    }