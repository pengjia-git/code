from socket import *
from time import ctime
fd=socket(AF_INET,SOCK_STREAM)
fd.bind(("127.0.0.1",5000))
fd.listen(5)

while True:
    fd_cli,addr=fd.accept()
    while True:
        data=fd_cli.recv(1024)
        if not data:
            break
        fd_cli.send("%s"%ctime())
    fd_cli.close()
fd.close()