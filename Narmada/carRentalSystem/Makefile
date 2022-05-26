crSystem: date.o car.o customer.o rentals.o main.o
		g++ date.o car.o customer.o rentals.o main.o -l sqlite3 -l ncurses -Wall -Wextra -g -o crSystem

date.o:	Date/date.cpp
		g++ -Wall -Wextra -g -c Date/date.cpp

car.o:	Car/car.cpp
		g++ -Wall -Wextra -g -c Car/car.cpp

customer.o:	Customer/customer.cpp
		g++ -Wall -Wextra -g -c Customer/customer.cpp

rentals.o: Rental/rentals.cpp
		g++ -Wall -Wextra -g -c Rental/rentals.cpp

main.o: main.cpp
		g++ -Wall -Wextra -g -c main.cpp

clean:
		rm -r *.o crSystem
