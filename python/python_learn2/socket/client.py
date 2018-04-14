from socket import *

fd=socket(AF_INET,SOCK_STREAM)

fd.connect(("localhost",5000))

while True:
    data=raw_input("> ")
    if not data:
        break
    fd.send(data)
    data=fd.recv(1024)
    print data
fd.close()