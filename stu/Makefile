CC=gcc
AFLAGS=-Wall -g
LDFLAGS= -lmysqlclient
OBJS= add.cgi del.cgi mod.cgi sel.cgi add_class.cgi sel_class.cgi mod_class.cgi del_class.cgi add_score.cgi

all:$(OBJS)

$(OBJS):%.cgi:%.c
	$(CC) $(AFLAGS) $< cgic.c -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	rm ./*.cgi
install:
	cp *.cgi /usr/lib/cgi-bin/sx

cpa:
	sudo cp head.html footer.html /usr/lib/cgi-bin/sx/
	sudo cp add_score.html /var/www/html/
	sudo cp index.html /var/www/html/
