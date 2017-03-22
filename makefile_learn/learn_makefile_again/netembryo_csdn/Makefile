#bar:=$(patsubst %.c,%.a,a.c b.c c.c)
bar=$(origin bar)
CFLAGS=-g
objects=main.o Sock.o socket.o sock_ntop_host.o url.o\
	rtsp.o multicast.o get_info.o 
main: $(objects)
ifdef CFLAGS
	@echo $(bar)
	gcc $(CFLAGS) -o main $(objects)
#	$(error a error happend)
	$(warning a warning happened)
else
	echo "not eq"
endif

%.o:%.c
	gcc -c  $< -o $@
#main.o:  rtsp.h
#
#Sock.o:
#socket.o:  wsocket.h wsocket-internal.h
#
#sock_ntop_host.o:  wsocket.h
#
#url.o:  url.h
#
#rtsp.o:rtsp.h	
#
#multicast.o: config.h wsocket.h
#
#
#get_info.o:  wsocket.h wsocket-internal.h

.PHONY: clean

clean:
	-rm -rf main *.o

