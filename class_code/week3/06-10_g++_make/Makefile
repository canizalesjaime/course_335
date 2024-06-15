
output: main.o message.o # target_name: files to compile. make target_name
	g++ main.o message.o -o output

main.o: main.cpp
	g++ -c main.cpp

message.o: message.cpp
	g++ -c message.cpp

clean:
	rm -f *.o output*