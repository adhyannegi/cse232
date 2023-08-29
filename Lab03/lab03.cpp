#include <iostream>

int main(){
    int num;
    int count = 0;
    int root = 10;
    while (std::cin >> num){
        int count = 0;
        int root = 10;
        if (num < 0){
            break;
        }
        else if ((num) < 10){
            root = num;
        }
        else {
            while (root > 9){
                root = 0;
                while (num != 0){
                    root += num % 10;
                    num /= 10;
                }
                count += 1;
                num = root;
            }
        }
        std::cout << count << " " << root << std::endl;
    }

    return 0;
}