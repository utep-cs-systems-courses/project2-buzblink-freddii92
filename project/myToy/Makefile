# makefile configuration
COMMON_OBJECTS =
CPU            = msp430g2553
CFLAGS         = -mmcu=${CPU} -I../h
LDFLAGS        = -L/opt/ti/msp430_gcc/include

# switch the compiler (for the internal make rules)
CC             = msp430-elf-gcc
AS             = msp430-elf-as

all: blink.elf button.elf buzzer.elf
	(cd timerLib && make install)

# additional rules for files
blink.elf: ${COMMON_OBJECTS} main.o stateMachine.o led.o wdInterruptHandler.o p1_interrupt_handler.o switches.o buzzer.o .. /lib/linTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blink.elf button.elf buzzer.elf
	msp430loader.sh blink.elf button.elf

clean: $^
	rm -f *.o *.elf

led.o: led.c led.h

wdInterruptHandler.o: stateMachine.h

stateMachine.o: led.h stateMachine.h

buzzer.c: buzzer.h
