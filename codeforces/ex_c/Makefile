CFLAGS=-O2 -Wall -lm -static -std=c11 -DONLINE_JUDGE -DBOJ

TARGET=sol
FILE=sol.c
INPUT=in
OUTPUT=out
ANS=ans

${TARGET} : ${FILE}
	gcc -o ${TARGET} ${FILE} ${CFLAGS}

def :
	./sol

run :
	./sol < ${INPUT}

output :
	./sol < ${INPUT} > ${OUTPUT}

print :
	./sol < ${INPUT} > ${OUTPUT}
	cat ${INPUT}
	cat ${OUTPUT}

judge :
	./sol < ${INPUT} > ${OUTPUT}
	diff -c ${OUTPUT} ${ANS}
	rm -f ${OUTPUT}

xclip :
	xclip -sel c < ${FILE}

clear : 
	rm -f ${TARGET}
