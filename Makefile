SOURCES = \
src/jsoncontexthandler.cpp \
src/jsoncontextmanager.cpp \
src/jsonprocessor.cpp

TEST_SOURCES = \
test/main.cpp

INCLUDES = -I $(HOME)/src/3rdparty/rapidjson/include -I$(HOME)/src/river-level-monitor/src

all: unit_test exe

unit_test: $(TEST_SOURCES)
	g++ --std=c++14 -o bin/river-level-monitor-test $(INCLUDES) $(TEST_SOURCES) $(SOURCES)
	bin/river-level-monitor-test

exe: $(SOURCES) src/main.cpp
	g++ --std=c++14 -o bin/river-level-monitor $(INCLUDES) $(SOURCES) src/main.cpp
	
clean: 
	rm -f bin/river-level-monitor *.o
	rm -f bin/river-level-monitor-test
