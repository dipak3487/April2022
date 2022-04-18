Elevator has:
//	- Capacity
	- Number of floors
	- Current floor number: 3
	- state (Up, Down, idle, OutOfService)
	- Commands F1Down, F7Up, E10, E5, 
	- 

checkState()
currentFloor()
insertCommand(newCommand)
procecssNextCommand()
returnNextCommand();	//just return what is next command. 





[F,S](C1, C2..)
[F,S](C1, C2..)
[F,S](C1, C2..)



[0, I] (E7)
[1, U] (E7)
[2, U] (E7)
[3, U] (E7)
[4, U] (E7)
[5, U] (E7)
[6, U] (E7)
[7, U] (E7)
[7, I] ()



Inside Elevator (Elevator pannel) E0, E1, .. E7
On each floor, there are 2 buttons: Up, Down. F2Up, F3Down


Input from user:
XX  => elevator input (E1..E99)
1XX => 105 => 1-> UP, XX= floor XX Input.  5th floor Up, F5UP
2XX => 205 => 2-> Down, XX=floor number. 5th floor Down, F5Down


number of floors: 25

Floor: 0, State: Idle, Commands: 
203 105 7 100
Floor: 0, State: UP, Commands: 203, 105, 7, 100
Floor: 1, State: UP, Commands: 203, 105, 7, 100
Floor: 2, State: UP, Commands: 203, 105, 7, 100
Floor: 3, State: Idle, Commands: 105, 7, 100
Floor: 3, State: UP, Commands: 105, 7, 100
Floor: 4, State: UP, Commands: 105, 7, 100
Floor: 5, State: Idle, Commands: 7, 100
Floor: 5, State: UP, Commands: 7, 100
Floor: 6, State: UP, Commands: 7, 100
Floor: 7, State: Idle, Commands: 100
Floor: 7, State: DOWN, Commands: 100
Floor: 6, State: DOWN, Commands: 100
Floor: 5, State: DOWN, Commands: 100
Floor: 4, State: DOWN, Commands: 100
Floor: 3, State: DOWN, Commands: 100
Floor: 2, State: DOWN, Commands: 100
Floor: 1, State: DOWN, Commands: 100
Floor: 0, State: Idle, Commands: 


































getchar()


main
{
	while(1)
	{
		getchar() ==> variable. 
		print variable
		sleep(1);
	}



