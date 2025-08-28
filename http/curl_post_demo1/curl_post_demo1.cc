#include <iostream>
#include <curl/curl.h>

size_t write_callback(void *contents, size_t size, size_t nmemb, std::string *output) {
    size_t realsize = size * nmemb;
    output->append(static_cast<char *>(contents), realsize);
    return realsize;
}

int main() {
    CURL *curl;
    CURLcode res;

    // 初始化CURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // 设置请求的URL
        const char *url = "http://localhost:8080/";
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // 设置POST请求
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        // 设置POST数据
        const char *post_data = "This is the data to be sent as text/xml";
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);

        // 设置Content-Type为text/plain
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: text/xml");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // 设置回调函数，用于处理响应数据
        std::string response_data;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

        // 执行POST请求
        res = curl_easy_perform(curl);

        // 检查执行结果
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        else{
            long http_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            std::cout << "Status Code: " << http_code << std::endl;
            std::cout << "Response Body:\n" << response_data << std::endl;
        }

        // 清理CURL资源
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    // 全局清理
    curl_global_cleanup();

    return 0;
}
