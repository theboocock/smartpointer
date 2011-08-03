CXX	:= g++

MAIN_FLAGS      := -W -Wall -ansi -pedantic

OUTPUT  := pointers

SRCS    := main.cpp

SRCS    := ${SRCS}

OBJS    := $(addsuffix .o,$(basename ${SRCS}))

${OUTPUT}: ${SRCS}
	${CXX} ${MAIN_FLAGS} $< -o $@

clean:
	-rm -f core ${OBJS} ${OUTPUT}

