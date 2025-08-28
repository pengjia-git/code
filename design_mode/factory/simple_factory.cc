#include <iostream>  
#include <string>  
#include <memory> // 用于智能指针  
  
// Product 基类  
class Product {  
public:  
    virtual ~Product() {} // 虚析构函数，保证通过基类指针删除派生类对象时，派生类析构函数被调用  
    virtual void use() = 0; // 纯虚函数，强制派生类实现  
};  
  
// ConcreteProductA 派生类  
class ConcreteProductA : public Product {  
public:  
    void use() override {  
        std::cout << "Using ConcreteProductA" << std::endl;  
    }  
};  
  
// ConcreteProductB 派生类  
class ConcreteProductB : public Product {  
public:  
    void use() override {  
        std::cout << "Using ConcreteProductB" << std::endl;  
    }  
};  
  
// 简单工厂类  
class Factory {  
public:  
    // 静态方法，根据类型创建产品  
    static std::unique_ptr<Product> createProduct(const std::string& type) {  
        if (type == "A") {  
            return std::make_unique<ConcreteProductA>();  
        } else if (type == "B") {  
            return std::make_unique<ConcreteProductB>();  
        }  
  
        // 如果类型不匹配，返回一个空的unique_ptr  
        return nullptr;  
    }  
};  
  
int main() {  
    // 使用工厂创建产品A  
    auto productA = Factory::createProduct("A");  
    if (productA) {  
        productA->use();  
    }  
  
    // 使用工厂创建产品B  
    auto productB = Factory::createProduct("B");  
    if (productB) {  
        productB->use();  
    }  
  
    // 尝试创建不存在的类型，将不会输出任何内容  
    auto nonExistentProduct = Factory::createProduct("C");  
    if (!nonExistentProduct) {  
        std::cout << "Non-existent product type requested." << std::endl;  
    }  
  
    return 0;  
}