This is the top-level directory for all source code in the QuadSolver project


In order to run the main.c, run this command:

gcc main.c ./qsolve/qsolve.c ./IO/Input.c ./Log/OpenLog.c ./Log/CloseLog.c ./Log/WriteLog.c -o demo -lm -Wall

./demo
or 
./demo < input.txt

In order to run the Driver.c, run this command after running ./demo < input.txt :

gcc Driver.c -o Driver -Wall -lcunit
./Driver

