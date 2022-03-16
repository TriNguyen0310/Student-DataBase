OBJS = Student.o main.o

StudentDatabase: $(OBJS)
	g++ -o StudentDatabase $(OBJS)
	rm -f $(OBJS)

Student.o:
	g++ -c Student.cpp
	
main.o:
	g++ -c main.cpp

clean:
	rm -f core StudentDatabase $(OBJS)