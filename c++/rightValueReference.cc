#include <iostream>
#include <utility> // For std::move
#include <cstring> // For std::memset

// 定义一个简单的资源管理类
class Resource {
private:
    char* data; // 存储资源的数组指针
    static const size_t size = 1024; // 数组大小

public:
    Resource() {
        data = new char[size]; // 分配数组内存
        std::memset(data, 'c', size); // 将 'c' 写入数组
        std::cout << "Resource acquired!" << std::endl;
    }

    ~Resource() {
        if(data == nullptr)
            std::cout<<"null prt" <<std::endl;
        delete[] data; // 释放数组内存
        std::cout << "Resource released!" << std::endl;
    }

    // 禁止拷贝构造函数
    Resource(const Resource&) = delete;

    // 允许移动构造函数
    Resource(Resource&& other) noexcept : data(other.data) {
        other.data = nullptr; // 将原始资源指针置为空
        std::cout << "Resource moved!" << std::endl;
    }

    // 禁止拷贝赋值运算符
    Resource& operator=(const Resource&) = delete;

    // 允许移动赋值运算符
    Resource& operator=(Resource&& other) noexcept {
        if (this != &other) {
            delete[] data; // 释放当前资源
            data = other.data; // 转移资源指针
            other.data = nullptr; // 将原始资源指针置为空
            std::cout << "Resource moved via assignment!" << std::endl;
        }
        return *this;
    }
};

// 接受一个右值引用的函数
void processResource(Resource&& resource) {
    // 对资源进行处理
}

int main() {
    // 创建一个资源对象
    Resource r1;
    Resource r2 ;
    // 使用 std::move 将左值转换为右值
    //Resource r2 = std::move(r1); // 调用移动构造函数
    r2 = std::move(r1); // 调用移动构造函数

    // 创建一个临时资源对象，并将其作为右值引用传递给函数
    processResource(Resource()); // 调用移动构造函数

    return 0;
}
