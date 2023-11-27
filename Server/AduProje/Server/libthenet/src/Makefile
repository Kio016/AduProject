CXX = g++12
BIN_DIR = ../lib
BIN     = $(BIN_DIR)/libthenet.a
INCLUDE = ../include

GCC_VERSION = $(shell $(CXX) --version 2>&1 | grep "(GCC)" | cut -d' ' -f3  | cut -d'.' -f1)

CFLAGS  = -m32 -Wall -O2 -pipe -g -I$(INCLUDE)
CFLAGS += -std=c++20

LIBS    = 

OBJFILES = socket.o

default:
	$(MAKE) $(BIN)

$(BIN): $(OBJFILES)
	if [ ! -d $(BIN_DIR) ]; then mkdir $(BIN_DIR); fi
	ar cru $(BIN) $(OBJFILES) $(LIBS)
	ranlib $(BIN)
	chmod 700 $(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

$(OBJFILES):
	$(CXX) $(CFLAGS) -c $<

include Depend
