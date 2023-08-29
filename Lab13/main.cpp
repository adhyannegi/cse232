#include "singlelink.cpp"

int main() {
    SingleLink s;
    s.append_back(3);
    s.append_back(4);
    std::cout << "Two Items: " << s << std::endl;

    SingleLink s2(10);
    s2.append_back(3);
    s2.append_back(4);
    std::cout << "Three Items: " << s2 << std::endl;
    
    s2.del(3);
    std::cout << "Removed 3: " << s2 << std::endl;
    
    SingleLink s3(56);
    s3.append_back(73);
    s3.append_back(345);
    s3.append_back(1);
    s3.append_back(15);
    std::cout << "5 items: " << s3 << std::endl;
    std::cout << "Indexing 0: " << s3[0].data_ << std::endl;
    std::cout << "Indexing 1: " << s3[1].data_ << std::endl;
    std::cout << "Indexing 2: " << s3[2].data_ << std::endl;
    std::cout << "Indexing 3: " << s3[3].data_ << std::endl;
    std::cout << "Indexing 4: " << s3[4].data_ << std::endl;
    
}