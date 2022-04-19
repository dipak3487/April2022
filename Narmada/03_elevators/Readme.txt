v01: serve commands in sequence. no matter what. 
	take commands only after the current batch of commands are served. 

v02: serve the commands on the same floor if possible. 
	not required to take user inputs (additional command) after letting the person in. 

v03: take the input after the person enters into the elevator.

v04: Keep the direction unchanged as long as possible.




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


Inside Elevator (Elevator pannel) E0, E1, .. E7
On each floor, there are 2 buttons: Up, Down. F2Up, F3Down


Input from user:
XX  => elevator input (E1..E99)
1XX => 105 => 1-> UP, XX= floor XX Input.  5th floor Up, F5UP
2XX => 205 => 2-> Down, XX=floor number. 5th floor Down, F5Down

0 I
103, 9, 105, 203, 103, 8, 108, 209


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













        [0]-[Idle]:     [ ]
Commands for elevator (-1 to exit) : 5 7 203 105 210 115
        [1]-[UP]:       [ 007 203 105 210 115 ]
        [2]-[UP]:       [ 007 203 105 210 115 ]
        [3]-[UP]:       [ 007 203 105 210 115 ]
        [4]-[UP]:       [ 007 203 105 210 115 ]
        [5]-[UP]:       [ 007 203 105 210 115 ]
        [5]-[Idle]:     [ 007 203 105 210 115 ]
Hey 5th, where you want to go? {008}	 
        [6]-[UP]:       [ 007 203 105 210 115 008 ]
        [7]-[UP]:       [ 007 203 105 210 115 008 ]
        [7]-[Idle]:     [ 203 105 210 115 008 ]
        [7]-[UP]:       [ 203 105 210 115 008 ]
        [8]-[UP]:       [ 203 105 210 115 008 ]
        [9]-[Idle]:     [ 203 210 115 ]
        [10]-[Idle]:     [ 203 210 115 ]
        [10]-[Idle]:     [ 203 210 115 ]
        [10]-[Idle]:     [ 203 210 115 ]
        [15]-[UP]:     [ 203 210 115 ]
        [15]-[Idle]:     [ 203 210 ]
Hey 15th, where you want to go? {010}	 
        [15]-[Down]:     [ 203 210 010 ]
        [10]-[Down]:     [ 203 ]
Hey 10th, where you want to go? {01}	 
        [10]-[Down]:     [ 203 001]
        [3]-[Down]:     [ 001]
Hey 3th, where you want to go? {05}	 
        [2]-[Down]:     [ 001 005]
        [1]-[Down]:     [ 001 005]
        [1]-[Idle]:     [ 005]

