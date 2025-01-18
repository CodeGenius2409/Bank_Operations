# Bank_Operations
First you need to register your self and then login. Now, you can view Account Details, Withdraw Money, Deposit money, Exit.
Problem Statement: Banking System Using Classes and Objects in C++
Objective: Create a Banking System in C++ Programming that uses classes and objects.
The program should allow users to register, log in, and perform basic banking operations like viewing account details, withdrawing, and depositing money.
Requirements:
1.
Class BankAccount:
o
The class should contain the following private members:
▪
username (string), email (string), phone (string), age (int), balance (double), password (string), accountType (string).
o
The class should have the following public member functions:
▪
setDetails(): Takes all user details as input and sets the account details.
▪
viewAccountDetails(): Displays the account details such as username, email, phone number, account type, and current balance.
▪
withdraw(): Allows the user to withdraw money from their account. The function should check whether the user has sufficient balance after deducting the minimum balance based on their age.
▪
deposit(): Allows the user to deposit money into their account, ensuring the deposit amount matches the number of notes entered.
▪
authenticate(): Compares the username and password for authentication.
2.
Class BankSystem:
o
This class manages user registration and login and provides a menu-driven interface for banking operations.
o
The first screen should show a welcome message and ask the user to register by entering a username, email, phone, age, and password.
o
The system should check if the username contains spaces. If it does, prompt the user to enter a valid username.
o
After successful registration, the details (username and password) should be saved to a file login.dat.


o
The user can log in using their registered username and password.
o
Once logged in, the user should have the following options:
▪
View account details.
▪
Withdraw money (with minimum balance requirements based on age).
▪
Deposit money.
▪
Exit.
Functionality Breakdown:
1.
Registration:
o
The user provides their username, email, phone, age, and password. Ensure that the username contains no spaces.
o
Save the user's login credentials to login.dat.
2.
Login:
o
The user logs in with their username and password. The system verifies the credentials by reading from login.dat.
3.
Account Operations:
o
View Account Details: The user can view their account details including username, email, phone number, account type, and current balance.
o
Withdraw Money: The system checks if the user has enough balance considering the minimum balance required based on age, and processes the withdrawal.
o
Deposit Money: The system allows the user to deposit money by specifying the number of notes of denominations 100, 200, 500, and 2000, and verifies if the total amount matches the input
Functionality Breakdown:
1.
Registration:
o
The user provides their username, email, phone, age, and password. Ensure that the username contains no spaces.
o
Save the user's login credentials to login.dat.
2.
Login:

o
The user logs in with their username and password. The system verifies the credentials by reading from login.dat.
3.
Account Operations:
o
View Account Details: The user can view their account details including username, email, phone number, account type, and current balance.
o
Withdraw Money: The system checks if the user has enough balance considering the minimum balance required based on age, and processes the withdrawal.
o
Deposit Money: The system allows the user to deposit money by specifying the number of notes of denominations 100, 200, 500, and 2000, and verifies if the total amount matches the input.

