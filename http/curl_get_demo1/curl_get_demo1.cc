#include <iostream>
#include <fstream>
#include <curl/curl.h>

// 回调函数，用于处理CURL的响应数据
size_t write_callback(void *contents, size_t size, size_t nmemb, std::string *output) {
    size_t realsize = size * nmemb;
    output->append(static_cast<char*>(contents), realsize);
    return realsize;
}

int main() {
    CURL *curl;
    CURLcode res;

    // 初始化CURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        // 设置请求的URL
        const char *url = "http://localhost:8080/jia/jia";
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_1);
        // 设置自定义请求头
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "User-Agent: PostmanRuntime/7.36.0");
        headers = curl_slist_append(headers, "Accept: */*");
        headers = curl_slist_append(headers, "Postman-Token: 2219b6a0-0345-4ba5-ac33-cb39406efcb5");
        headers = curl_slist_append(headers, "www.runoob.com");
        headers = curl_slist_append(headers, "Accept-Encoding: gzip, deflate, br");
        headers = curl_slist_append(headers, "Connection: keep-alive");
        headers = curl_slist_append(headers, "Cookie: dc_session_id=10_1705026558668.640756; uuid_tt_dd=10_20059925300-1705026558668-860993; https_waf_cookie=fc7215f3-aa56-47eed28ca5c77b0795720b3841ea9294cabb");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // 设置回调函数，用于处理响应数据
        std::string response_data;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

         // 设置为不接收响应头
        curl_easy_setopt(curl, CURLOPT_HEADER, 0L);

        // 执行GET请求
        res = curl_easy_perform(curl);

        // 检查执行结果
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        else
        {

            std::cout << "Response:\n" << response_data << std::endl;
            std::cout<<"response ok"<<std::endl;
            //将resource_data存为html后缀的文件
            std::ofstream outfile("resource_data.html");
            outfile << response_data;
            outfile.close();
        }
        //std::cout << "Compile Time: " << __TIME__ << std::endl;
        //std::cout << "Compile Date: " << __DATE__ << std::endl;
        // 清理CURL资源
        curl_easy_cleanup(curl);
    }

    // 全局清理
    curl_global_cleanup();

    return 0;
}
