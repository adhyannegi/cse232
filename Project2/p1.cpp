#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <set>

// YOUR FUNCTIONS HERE

std::ifstream OpenFile(std::string file)
{
    std::ifstream in_file(file);

    if (!in_file.is_open())
    {
        std::cerr << "Error: Cannot open '" << file << "'";
        std::exit(1);
    }

    return in_file;
}

void ReadEncodingPairs(std::string enc_pair, std::vector<std::string> &vec1)
{
    if ((enc_pair.size() > 2) || ((enc_pair.size() == 1) && (enc_pair != "q")))
    {
        std::cerr << "Error: Unknown encoding '" << enc_pair << "'.";
        std::exit(1);
    }

    for (auto ele : vec1)
    {
        if (ele.at(0) == enc_pair.at(0))
        {
            std::cerr << "The character '" << enc_pair.at(0) << "' is encoded as both '" << ele.at(1) << "' and '" << enc_pair.at(1) << "'.";
            std::exit(1);
        }
    }

    vec1.push_back(enc_pair);
}

std::string ApplyEncoding(std::string &line, std::vector<std::string> &vec1)
{
    std::string ans;
    for (char ele : line)
    {
        for (std::string letter : vec1)
        {
            if (ele == letter.at(0))
            {
                ele = letter.at(1);
                break;
            }
        }
        ans += ele;
    }
    return ans;
}

int ProcessFile(std::ifstream &file, std::vector<std::string> &vec1, std::vector<std::string> &final_vec)
{
    int count = 0;
    std::string line;
    while (std::getline(file, line))
    {
        std::string val = ApplyEncoding(line, vec1);
        final_vec.push_back(val);
        count += 1;
    }
    return count;
}

int main()
{
    std::string input;
    std::vector<std::string> input_vec;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::string word;
    while (iss >> word)
    {
        input_vec.push_back(word);
    }
    std::vector<std::string> vec1;
    std::vector<std::string> final_vec;

    std::ifstream in_file = OpenFile(input_vec.at(0));
    input_vec.erase(input_vec.begin());

    for (std::string ele : input_vec)
    {
        ReadEncodingPairs(ele, vec1);
    }

    int count = ProcessFile(in_file, vec1, final_vec);
    std::vector<std::string> remove_copies;

    for (auto ele : final_vec)
    {
        auto it = std::find(remove_copies.begin(), remove_copies.end(), ele);
        if (it == remove_copies.end())
        {
            remove_copies.push_back(ele);
        }
    }

    if (count == 1)
    {
        for (auto ele : remove_copies)
        {
            std::cout << ele << " ";
        }
    }

    else
    {
        for (auto ele : remove_copies)
        {
            std::cout << ele << std::endl;
        }
    }
    return 0;
}