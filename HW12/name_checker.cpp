#include <string>
#include <stdexcept>
// Please note that the CheckName implementation in the tests will be different than in this example.
void CheckName(std::string const & name) {
	std::string::size_type t_pos = name.find('t');
	std::string::size_type s_pos = name.find('S');
	if (t_pos != std::string::npos) {
		throw std::invalid_argument("has a t");
	}
	if (s_pos != std::string::npos) {
		throw std::length_error("has a S");
	}
	if (name.back() == 's') {
		throw std::out_of_range("has an s at the end");
	}
}