#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

class SerialDemo {
public:
    SerialDemo(const char* portName) : portName(portName), serialPortFd(-1) {}

    bool openSerialPort() {
        serialPortFd = open(portName, O_RDWR | O_NOCTTY);

        if (serialPortFd == -1) {
            std::cerr << "Error opening serial port " << portName << std::endl;
            return false;
        }

        struct termios options;
        tcgetattr(serialPortFd, &options);
        cfsetispeed(&options, B9600);
        cfsetospeed(&options, B9600);
        options.c_cflag |= (CLOCAL | CREAD);
        tcsetattr(serialPortFd, TCSANOW, &options);

        return true;
    }

    void writeData(const unsigned char* data) {
        if (serialPortFd != -1) {
            size_t length = std::strlen((const char*)data);
            ssize_t bytes_written = write(serialPortFd, data, length);

            if (bytes_written == -1) {
                std::cerr << "Error writing to serial port." << std::endl;
            } else {
                std::cout << "Data written to serial port: " << data << std::endl;
            }
        } else {
            std::cerr << "Serial port not open." << std::endl;
        }
    }

    void readData() {
        if (serialPortFd != -1) {
            char buffer[256];
            ssize_t bytes_read = read(serialPortFd, buffer, sizeof(buffer) - 1);

            if (bytes_read == -1) {
                std::cerr << "Error reading from serial port." << std::endl;
            } else {
                buffer[bytes_read] = '\0';
                std::cout << "Data read from serial port: " << buffer << std::endl;
            }
        } else {
            std::cerr << "Serial port not open." << std::endl;
        }
    }

    void closeSerialPort() {
        if (serialPortFd != -1) {
            close(serialPortFd);
            std::cout << "Serial port closed." << std::endl;
        }
    }

    ~SerialDemo() {
        closeSerialPort();
    }

private:
    const char* portName;
    int serialPortFd;
};

//A0 01 01 A2 开
//A0 01 00 A1  关
int main(int argc, char** argv) {
    const char* portName = "/dev/ttyUSB";
    char buf[100]={0};
    unsigned char relay_on[]={0xA0, 0x01, 0x01, 0xA2};
    unsigned char relay_off[]={0xA0, 0x01, 0x00, 0xA1};
    unsigned char *p;
    if(argc !=3){
        std::cout<<"用法：serial_demo  ttyusb编号  1(开)/0(关)"<<std::endl;
        std::cout<<"eg   : serial_demo  0 1"<<std::endl;
    }
    else{
        snprintf(buf,sizeof(buf),"%s%s",portName,argv[1]);
        if(argv[2][0]=='1') p=relay_on; else p=relay_off;
    }
    //SerialDemo serialDemo(buf);
    SerialDemo serialDemo("/dev/ttyUSB0");

    if (serialDemo.openSerialPort()) {
        serialDemo.writeData(p);
        serialDemo.closeSerialPort();
    }

    return 0;
}

