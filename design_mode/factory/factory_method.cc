#include <iostream>  
#include <string>  
#include <memory> // 用于智能指针  
  
// Document 接口  
class Document {  
public:  
    virtual ~Document() {}  
    virtual void load() = 0; // 纯虚函数，强制派生类实现  
    virtual void save() = 0; // 纯虚函数，强制派生类实现  
};  
  
// TextDocument 类，实现了 Document 接口  
class TextDocument : public Document {  
public:  
    void load() override {  
        std::cout << "Loading text document..." << std::endl;  
    }  
  
    void save() override {  
        std::cout << "Saving text document..." << std::endl;  
    }  
};  
  
// PDFDocument 类，实现了 Document 接口  
class PDFDocument : public Document {  
public:  
    void load() override {  
        std::cout << "Loading PDF document..." << std::endl;  
    }  
  
    void save() override {  
        std::cout << "Saving PDF document..." << std::endl;  
    }  
};  
  
// DocumentFactory 抽象类  
class DocumentFactory {  
public:  
    virtual ~DocumentFactory() {}  
    // 工厂方法，声明为纯虚函数，强制派生类实现  
    virtual std::unique_ptr<Document> createDocument() = 0;  
};  
  
// TextDocumentFactory 类，继承自 DocumentFactory  
class TextDocumentFactory : public DocumentFactory {  
public:  
    std::unique_ptr<Document> createDocument() override {  
        return std::make_unique<TextDocument>();  
    }  
};  
  
// PDFDocumentFactory 类，继承自 DocumentFactory  
class PDFDocumentFactory : public DocumentFactory {  
public:  
    std::unique_ptr<Document> createDocument() override {  
        return std::make_unique<PDFDocument>();  
    }  
};  
  
// 客户端代码  
int main() {  
    // 使用 TextDocumentFactory 创建 TextDocument 对象  
    std::unique_ptr<DocumentFactory> factory1 = std::make_unique<TextDocumentFactory>();  
    std::unique_ptr<Document> doc1 = factory1->createDocument();  
    doc1->load();  
    doc1->save();  
  
    // 使用 PDFDocumentFactory 创建 PDFDocument 对象  
    std::unique_ptr<DocumentFactory> factory2 = std::make_unique<PDFDocumentFactory>();  
    std::unique_ptr<Document> doc2 = factory2->createDocument();  
    doc2->load();  
    doc2->save();  
  
    return 0;  
}