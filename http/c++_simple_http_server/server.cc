// http_server.cpp
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

void handle_request(http::request<http::string_body> req, http::response<http::string_body> &res)
{
    if (req.method() == http::verb::get)
    {
        // 处理GET请求
        res.result(http::status::ok);
        res.set(http::field::content_type, "text/html");
        res.body() = "<html><body><h1>Hello, World! root</h1></body></html>";
    }
    else if (req.method() == http::verb::post)
    {
        auto content_type_field = req.find(http::field::content_type);
        bool is_plain = false;
        if (content_type_field != req.end() && content_type_field->value() == "text/plain")
        {
            // Handle the case where the request method is POST and Content-Type is text/plain
            std::cout << "POST request with Content-Type text/plain" << std::endl;
            is_plain = true;
        }
        // 处理POST请求
        // 每次请求到来存储的文件名后缀依次加1
        static int post_file_index = 0;
        if (is_plain)
        {
            std::ofstream outfile("post_data_" + std::to_string(post_file_index++) + ".txt");
            outfile << req.body();
            outfile.close();

            res.result(http::status::ok);
            std::cout << "POST request" << std::endl;
        }
        else{
            res.result(http::status::unsupported_media_type);
        }
    }
    /*if (req.target() == "/") {
        res.result(http::status::ok);
        res.set(http::field::content_type, "text/html");
        res.body() = "<html><body><h1>Hello, World! root</h1></body></html>";
    }
    else {
        res.result(http::status::not_found);
        res.set(http::field::content_type, "text/plain");
        res.body() = "404 Not Found";
    }
    */
}

void session(tcp::socket socket)
{
    try
    {
        beast::flat_buffer buffer;
        http::request<http::string_body> req;
        http::read(socket, buffer, req);

        http::response<http::string_body> res;
        handle_request(req, res);

        http::write(socket, res);

        socket.shutdown(tcp::socket::shutdown_send);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main()
{
    try
    {
        net::io_context ioc;
        tcp::acceptor acceptor(ioc, {net::ip::make_address("127.0.0.1"), 8080});

        for (;;)
        {
            tcp::socket socket(ioc);
            acceptor.accept(socket);
            std::thread(session, std::move(socket)).detach();
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
