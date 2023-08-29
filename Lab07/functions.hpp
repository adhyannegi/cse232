#ifndef TEST
#define TEST

#include <vector>
#include <string>
#include <sstream>
using std::string, std::vector, std::ostringstream;

vector<string> split(string const &s, char sep=' ');
void print_vector(ostringstream &out, vector<string> const &v);

#endif