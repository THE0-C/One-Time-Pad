gccflags = 
debug: gccflags += -g

all: otpgen otpdec random
debug: otpgen otpdec random


otpgen: otpgen.c
	gcc otpgen.c parse.c -o otpgen $(gccflags)

otpdec: otpdec.c
	gcc otpdec.c parse.c -o otpdec $(gccflags)

random: random.c
	gcc random.c -o random $(gccflags)

