#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <random>
#include <iomanip>

using namespace std;

vector<string> get_words(istream& stm)
{

    return { istream_iterator<string>(stm),
             istream_iterator<string>{} };
}

std::string random_word_from_file(const string& file_name)
{
  
    static std::mt19937 rng(random_device{}());

    std::ifstream file(file_name);
    const auto words = get_words(file);
    if (words.empty()) return {};

   
    std::uniform_int_distribution<size_t> distrib(0, words.size() - 1);
    return words[distrib(rng)];
}

int main() // usage example
{


    const string path = "Listofitems.txt";
    cout << "You should watch this anime!: " << quoted(random_word_from_file(path)) << '\n';
}