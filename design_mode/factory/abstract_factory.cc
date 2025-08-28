#include <iostream>  
#include <memory> // 用于智能指针  
  
// 抽象产品类  
class Button {  
public:  
    virtual ~Button() {}  
    virtual void render() = 0; // 纯虚函数，强制派生类实现  
};  
  
class TextField {  
public:  
    virtual ~TextField() {}  
    virtual void render() = 0; // 纯虚函数，强制派生类实现  
};  
  
// 具体产品类 - Windows实现  
class WindowsButton : public Button {  
public:  
    void render() override {  
        std::cout << "Rendering Windows Button..." << std::endl;  
    }  
};  
  
class WindowsTextField : public TextField {  
public:  
    void render() override {  
        std::cout << "Rendering Windows TextField..." << std::endl;  
    }  
};  
  
// 具体产品类 - MacOS实现  
class MacOSButton : public Button {  
public:  
    void render() override {  
        std::cout << "Rendering MacOS Button..." << std::endl;  
    }  
};  
  
class MacOSTextField : public TextField {  
public:  
    void render() override {  
        std::cout << "Rendering MacOS TextField..." << std::endl;  
    }  
};  
  
// 抽象工厂类  
class UIFactory {  
public:  
    virtual ~UIFactory() {}  
    virtual std::unique_ptr<Button> createButton() = 0;  
    virtual std::unique_ptr<TextField> createTextField() = 0;  
};  
  
// 具体工厂类 - Windows实现  
class WindowsUIFactory : public UIFactory {  
public:  
    std::unique_ptr<Button> createButton() override {  
        return std::make_unique<WindowsButton>();  
    }  
  
    std::unique_ptr<TextField> createTextField() override {  
        return std::make_unique<WindowsTextField>();  
    }  
};  
  
// 具体工厂类 - MacOS实现  
class MacOSUIFactory : public UIFactory {  
public:  
    std::unique_ptr<Button> createButton() override {  
        return std::make_unique<MacOSButton>();  
    }  
  
    std::unique_ptr<TextField> createTextField() override {  
        return std::make_unique<MacOSTextField>();  
    }  
};  
  
// 客户端代码  
int main() {  
    // 使用Windows工厂创建Windows UI组件  
    std::unique_ptr<UIFactory> windowsFactory = std::make_unique<WindowsUIFactory>();  
    std::unique_ptr<Button> windowsButton = windowsFactory->createButton();  
    std::unique_ptr<TextField> windowsTextField = windowsFactory->createTextField();  
    windowsButton->render();  
    windowsTextField->render();  
  
    // 使用MacOS工厂创建MacOS UI组件  
    std::unique_ptr<UIFactory> macOSFactory = std::make_unique<MacOSUIFactory>();  
    std::unique_ptr<Button> macOSButton = macOSFactory->createButton();  
    std::unique_ptr<TextField> macOSTextField = macOSFactory->createTextField();  
    macOSButton->render();  
    macOSTextField->render();  
  
    return 0;  
}