OBJS = week1.o cplusplusproject.o stdafx.o
CC = g++
CFLAGS = -c

Test:$(OBJS)
	$(CC) -o Test $(OBJS)
cplusplusprojecn.o:cplusplusprojecn.cpp common.h stdax.h iostream.h
	$(CC) $(CFLAGS) cplusplusprojecn.cpp 
week1.o:week1.cpp stdafx.h 
	$(CC) $(CFLAGS) week1.cpp
stdafx.o: stdafx.cpp stdafx.h
	$(CC) $(CFLAGS) stdafx.cpp

.PHONY:clean
clean:
	rm -rf *.o Test
	@echo "Clean done!"
