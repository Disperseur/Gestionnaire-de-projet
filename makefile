Task.o: Task.h Task.cpp
	g++ -c Task.cpp

TaskList.o: TaskList.h TaskList.cpp
	g++ -c TaskList.cpp

TaskListsManager.o: TaskListsManager.h TaskListsManager.cpp
	g++ -c TaskListsManager.cpp

main.o: Task.h TaskList.h TaskListsManager.h main.cpp
	g++ -c main.cpp

main: Task.o TaskList.o TaskListsManager.o main.o
	g++ Task.o TaskList.o TaskListsManager.o main.o -o main