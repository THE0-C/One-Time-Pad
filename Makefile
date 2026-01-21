gccflags = 
debug: gccflags += -g

all: otpgen otpdec random
debug: otpgen otpdec random


otpgen: otpgen.c parse.c parse.h
	gcc otpgen.c parse.c -o otpgen $(gccflags)

otpdec: otpdec.c parse.c parse.h
	gcc otpdec.c parse.c -o otpdec $(gccflags)

random: random.c
	gcc random.c -o random $(gccflags)

