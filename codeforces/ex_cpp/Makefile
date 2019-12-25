CPPFLAGS=-O2 -Wall -lm -static -std=gnu++14 -DONLINE_JUDGE -DBOJ

TARGET=sol
FILE=sol.cpp
INPUT=in
OUTPUT=out
ANS=ans

${TARGET} : ${FILE}
	g++ -o ${TARGET} ${FILE} ${CPPFLAGS}

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
