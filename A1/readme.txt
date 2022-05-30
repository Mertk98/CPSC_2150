This is a documentation for Assignment 1 by Mert Kilic(100334228).

====Class Customer====
Customer class stores the customer information an used by Room class.
It has 3 variables: 
customerID_(string) => Stores the customer id
requestedBeds_(int) => Stores the number of beds the customer requested
customerCount(int) => This is a static class variable to keep track of the number of customers 
who have been serviced by our hotel.

====Class Room====
Room class stores the details about the rooms in our hotel.
It has 6 variables:
customer_(Customer*) => This is a pointer to an instance of a customer class.
checkInDate_(Date) => Stores the date information of check-in date of a customer.
checkOutDate_(Date) => Stores the date information of check-out date of a customer.
daysOfStay(int) => Stores the number of days that the customer would like to stay in our hotel.
numOfBeds(int) => Stores the total number of beds that are in the room.
bedsInUse_(int) => Stores the number of beds that the customer would like to use in the room.

====Class Date====
Date class converts the date from string to integer and helps the program to perform operations efficiently.
At the same time, class Room and Customer are friend classes of the Date class for simplicity reasons.
It has 4 variables:
day_(int) => Stores the day information.
month_(int) => Stores the month information.
year_(int) => Stores the year information.
months_(vector<int>) => Stores the months in a year with respect to leap years.

Date class uses overloaded operators such as "+", "<=" and "=".
"+" operator calculates the customers check-out date.
"<=" operator compares two dates and returns true if left hand side is a past date or equals to other date.
"=" operator performs a shallow copy of the other object. Since there are no pointers, shallow copy is okay.

====Hotel.cpp====
This is the main file which handles all the customer requests, hotel tasks and input files.

1) std::string* parseInput(std::string) :

Takes the line input from the txt file, seperates the input by "," and pushes them into an array.
Returns an array of strings for the rest of the program.

2) std::vector<std::vector<int>> findAvailableRooms(int cap3, int cap2, int cap1, int requested):

This function calculates the best available combination of the rooms based on the customers request.
Returns a 2D vector of the combinations.

Ex: if the customer is requesting 5 beds, returns [{3,3},{2,2}]. First number represents 
the rooms with <int> beds and the second number represents the number of beds that the customer
is going to use in the room.

The reason for this is that sometimes, there are no available rooms with the requested number of beds.
In this case, we might have to give a room with 3 bedrooms to our customers who bed request less beds than
the room has. Ex: if the customer is requesting 5 bedrooms and we don't have any rooms with 2 or 1 beds then,
the only option is giving 2 room with 3 beds. However, for the program to run bug free, describing how many beds
that the customer is using in those rooms are imnportant.
 
The function takes 4 parameters:
cap3(int) => current capacity of rooms with 3 bedrooms.
cap2(int) => current capacity of rooms with 2 bedrooms.
cap1(int) => current capacity of rooms with 1 bedrooms.
requested(int) => number of beds that the customer has requested.


3) int  findRoomIndex(int low, int high, Room* rooms, bool& found):

This recursive function is a modified binary search. Checks the rooms by performing a modified binary search
and finds an empty room as fast as possible and returns the index of the empty number. Else, returns -1.

It first checks the left half of the array. If the empty room hasn't been found on the left half, checks
the right half of the array.

Takes 4 parameters: 
low(int) => lowest index of the array.
high(int) => highest index of the array.
rooms(Room*) => the array of rooms to perform the search.
found(bool&) => a referance to a boolean which simplifies the searching.

Best case: O(1), Average Case:(logn), Worst Case: O(n)

4) void cleanRooms(const int* totalRooms, int* capacity, Room* rooms3, Room* rooms2, Room* rooms1, Date currentDate):

This function handles the room cleaning. If the customers customer has checked out before or on the same date as
the current date, it empties the room for new customers. After the room has been emptied, increases the capacity of
number rooms with the same amount of beds.

Unfortunately, since to use this kind of functionality, all the rooms in the hotel have to be checked every time
there is a new customer. This makes it a little expensive function.

Takes 6 parameters:
totalRooms(const int*) => Array of total number of rooms that are in the hotel.
capacity(int*) => Array capacity of rooms in the hotel.
rooms3(Room*) => Array of rooms with 3 beds.
rooms2(Room*) => Array of rooms with 2 beds.
rooms1(Room*) => Array of rooms with 1 bed.
currentDate(Date) => Stores the current date.

Best case = O(n), Average case = O(n), Worst Case = O(n)

5) void setRoom(std::string date, int bedsInUse, int stay, Customer* cus, Room& room):

This function updates the room information with the customer information.

Takes 5 parameters:
date(string) => Check-in date of the customer.
bedsInUse(int) => number of beds that the customer is going to use in the room
stay(int) => number of days that the customer will stay in the hotel
room(Room&) => The room that the customer will stay

6) void roomHandler(const int* totalRooms, int* capacity, Room* rooms3, Room* rooms2, Room* rooms1, const std::string* details):

This function handles all the room request of the customers.

totalRooms(const int*) => Array of total number of rooms that are in the hotel.
capacity(int*) => Array capacity of rooms in the hotel.
rooms3(Room*) => Array of rooms with 3 beds.
rooms2(Room*) => Array of rooms with 2 beds.
rooms1(Room*) => Array of rooms with 1 bed.
details(const string*) => An string array of detail of the customer from the txt file.


7) main():

All the rooms are initialized in the main function. I have decided to use dynamic arrays for the rooms since, they are more 
efficient than vectors in terms of space and time complexity. For the efficiency purposes, I have kept track of capacity and size
of the room arrays. At the end, all the arrays are deallocated.


====Part B====
I have used dynamic arrays for roooms, since allocation and access is more efficient. I also have used 2D vectors for to keep track of available rooms.
However, these vectors do not store large data.

====Part C====
In my opinion, I would keep using dynamic arrays as well to store more rooms with different numbers of beds. To clarify, I would allocate a main array to store all the sub-arrays.
For the index 0, I would add a nullptr. For the index 1, I would put the array of rooms with 1, for the index 2, array of rooms with 2 beds, etc.
Ex: RoomsArr = [nullptr, {1beds}, {2beds}, {3beds},....,{Nbeds}]. That way, I would access those arrays in constant time(O(1)).