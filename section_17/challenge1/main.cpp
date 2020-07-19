#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>>&vec);

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
//    std::cout << vec_ptr.get() << std::endl;
    std::cout << "\n^---------- make function completed ----------\n" << std::endl;
    
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
//    std::cout << vec_ptr->at(0)->get_data() << std::endl;
    std::cout << "\n^---------- fill function completed ----------\n" << std::endl;

    display(*vec_ptr);
    std::cout << "\n^---------- display function completed ----------\n" << std::endl;
    return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    int data = 0;
    for (int i=0; i<num; ++i) {
        std::cout << "Enter data point [" << i << "]: ";
        std::cin >> data;
        vec.emplace_back(std::make_shared<Test>(data));
    }
}

void display(const std::vector<std::shared_ptr<Test>>&vec) {
    for (auto v:vec) 
        std::cout << v->get_data() << std::endl;
}