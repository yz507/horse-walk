CPPFLAGS += -Wall -Werror -g --std=c++11

OBJS = main.o path.o horse_walk.o

horse_walk: $(OBJS)
	g++ -o $@ $(OBJS)

path.o: horse_walk.h path.h
horse_walk.o: horse_walk.h path.h
main.o: horse_walk.h path.h

.PHONY: clean
clean:
	-rm -f $(OBJS) horse_walk
