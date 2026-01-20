all: otpgen otpdec random

otpgen: otpgen.c
	gcc otpgen.c parse.c -o otpgen -g

otpdec: otpdec.c
	gcc otpdec.c parse.c -o otpdec -g

random: random.c
	gcc random.c -o random -g
