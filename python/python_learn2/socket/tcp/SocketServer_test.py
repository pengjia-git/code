from SocketServer import (TCPServer as TCP,
    StreamRequestHandler as SRH)
from time import ctime

HOST=''
PORT=5000
ADDR=(HOST,PORT)

class MyRequestHandler(SRH):
    def handle(self):
        print '...connected from:',self.client_address
        self.wfile.write('[%s] %s'%(ctime(),
            self.rfile.readline()))

tcpServ=TCP(ADDR,MyRequestHandler)
tcpServ.serve_forever()
