JAVAFLAGS=-J-Xms1024m -J-Xmx1024m -J-Xss512m -encoding UTF-8
JAVARFLAGS=-Xms1024m -Xmx1024m -Xss512m -DFILE.encoding=UTF-8

FILES=Main.java
MAIN=Main

INPUT=in
OUTPUT=out
ANS=ans

all : ${FILES}
	javac ${JAVAFLAGS} ${FILES}

run :
	java ${JAVARFLAGS} ${MAIN} < ${INPUT}

judge :
	java ${JAVARFLAGS} ${MAIN} < ${INPUT} > ${OUTPUT}
	diff -c ${OUTPUT} ${ANS}
	rm -f ${OUTPUT}

xclip :
	xclip -sel c < ${MAIN}.java

clear : 
	rm -rf ./*.class
