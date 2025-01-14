# Macros
COMPILER  = g++
DEBUG  = -g

# Default target: app (creates executable app)

app: Term.o TermArrayList.o app.o TermDblLinkList.o DbblLink.h TermSTLObjList.o
	$(COMPILER) -o app Term.o TermArrayList.o app.o TermDblLinkList.o TermSTLObjList.o $(DEBUG)
testLL: testLL.cpp DbblLinkList.o
	$(COMPILER) -o testLL testLL.cpp $(DEBUG)
DbblLinkList.o: DbblLink.h
	$(COMPILER) -c DbblLink.h $(DEBUG)
Term.o:  Term.cpp Term.h
	$(COMPILER) -c Term.cpp $(DEBUG)
TermDblLinkList.o:  Term.h TermDblLinkList.h TermDblLinkList.cpp TermList.h
	$(COMPILER) -c TermDblLinkList.cpp $(DEBUG)
TermArrayList.o:  Term.h TermArrayList.cpp TermArrayList.h TermList.h
	$(COMPILER) -c TermArrayList.cpp $(DEBUG)
TermSTLObjList.o: Term.h TermSTLObjList.cpp TermSTLObjList.h TermList.h
	$(COMPILER) -c TermSTLObjList.cpp $(DEBUG)
app.o:  TermArrayList.h TermList.h app.cpp TermArrayList.cpp TermArrayList.h TermSTLObjList.h TermSTLObjList.cpp
	$(COMPILER) -c app.cpp $(DEBUG)

clean:
	rm -rf *.o app app.exe





