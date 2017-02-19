#include <iostream>
#include <string>
#include <sstream>
#include <istream>



using namespace std;

int main()
{
	int width;
	int height;
	int e = 1;
	int i = 0;
	bool Control;
	int InputLength;
	stringstream ss;
	string Dimension;
	string Input;
	string CleanInput;
	char c; 



	while (e < 3)
	{
		Control = true;

		while (Control == true) 
		{
/*if a */
			if (e == 1) //this condition is true, so it sets the Dimension variable to the following.
			{
				Dimension = "width";
			}
/*DONE else a*/
			else if (e == 2) //when e is incremented later in the code, e will no longer be 1, but will now be 2, so the "else" statement will execute. 
			{
				Dimension = "height";
			}

			cout << "Enter " + Dimension + " : ";
			getline(cin, Input); //getline is used to read the entire line entered, until it hits a newline (reads whitespace, decimals, etc.)
			InputLength = (Input.length());  //setting variable InputLength to the amount of characters entered into the variable Input--using the .length statement to count the entire amount of charcters picked up by getline
/*DONE if b*/
			if (InputLength > 0) //if the amount of characters entered is bigger than 0 --meaning something was entered, continue to the next statement
			{
				while (i < (InputLength)) //since i is initially set to 0, i will be less than input length, ensuring the next loop to run. ALSO, i needs to be one less than inputlength because it starts at position 0, not position 1. CAT for example (input length of 3), i = 0 (gives you C), i = 1 (gives you A), i = 2 (gives you T), so input length is 3, but i finishes at 2. if you look for i <= inputlength, it will look for a character that isn't there, causing your program to crash. 
				{
					c = Input.at(i); //as a char, c will only read one character. the function VARIABLENAME.at(i) tells it to read the character in the position of (i), so currently i = 0, and it will evaluate the contents of the first positioned character. As i is incremented in subsequent loops, the char c will evaluate the sequential positions. 

/*DONE if c*/
					if (isdigit(c)) //since we are inside the length check while loop, the function isdigit(VARIABLENAME) will evaluate the value of c to see if it IS a digit. 
					{
						CleanInput = CleanInput + c; //once the value of c is deteremined to be a digit, this statement executes, which is used to take the value of each digit being evaluated, and reassemble them into the whole string, as opposed to the separated c values. So the new variable, CLEANINPUT is set to equal itself, CLEANINPUT + c. So c is checked at position i, found to be a digit, then passed down to the reassembling CLEANINPUT variable. 
						++i; //this jumps the position check .at  to the next  character--but only if it IS  digit, otherwise skip to the error message
						//since ++i is at the end of the isdigit loop, it will first check inside that isdigit loop to make sure that i is one less than InputLength, then if it IS a digit, it will continue to execute the next step, which is to add ++i, thus eventually making i into the same value as InputLength (ie. CAT -- i is 2 (at position T), and inputlength is 3. but when we do the ++i at the end, i becomes 3, which breaks us out of the (i < inputlength) loop, and goes down into the (i == inputlength) check.
					}
					
/*DONE else c*/
					else //this else is connected to the "isdigit" function, so if a character is found that ISNT a digit, it will pass to this line, which states that it is an invalid input.
					{
						i = 0; //when it is found to be invalid, we have to set i back to 0, in order to have the .at(i) position checker begin at the first input again, once new input is entered.
						cout << "Invalid input. Try again." << endl;
						break; //break allows us to break out of this first if-while loop--the one that checks if input length is bigger than 0. So now we are jumped back to the beginnning. ALSO--NOTICE IT PRINTS THE SECOND ERROR MESSAGE, SO WE KNOW WE'RE STILL IN THAT LOOP--REMEMBER TO DELETE
					}
						
					

				} //this ends the while loop that is inside the first if * while (i < (inputlength))


/* DONE if d*/
				if (i == InputLength) //this allows us to make sure that we've counted every character in the input length.
				{
					ss << CleanInput; //turns the string CLEANINPUT into a stringstream, which will allow us to put the cleaned value back into an integer variable, so that we can use it like an integer again (like do calculations, or comparisons)...because strings cannot be turned into integers, but strings can be turned into stringstreams, and stringstreams, in turn, can be turned into integers. (string -> stringstream -> integer)

/* DONE if e*/
					if (e == 1) //if we set e == 0, it will loop the height prompt once more than we need--because our first while loop is while e < 3, AND, since e doesn't equal 1 (as the first if statement asks), it will execute the first "else" statement. 
					{
						ss >> width; //string stream (which is carrying the value of CleanInput, from the previous if statement) now pushes it's value into an integer variable, "width."
						if (width <= 0)
						{
							cout << "You must enter a width greater than 0. Try again." << endl;
							break;
						}
						if (width >= 25)
						{
							cout << "You must enter a width less than 25. Try again. " << endl;
							break;
						}

					}
					
					/* DONE else e*/
					else
					{
						ss >> height; //stringstream (which was given the cleaninput value previously) is now pushing it's value into an integer variable (height). this executes once e has been incremented (below), because e no longer equals 1. 
						if (height <= 0)
						{
							cout << "You must enter a height greater than 0. Try again." << endl;
							break;
						}
						if (height >= 25)
						{
							cout << "You must enter a height less than 25. Try again. " << endl;
							break;
						}
						

					}

				/*	if ((width <= 0 || height <= 0))
					{
					cout << "You must enter a " + Dimension + " greater than 0. Try again." << endl;
						break;


					}
					if ((width >= 25) || (height >= 25))
					{

						cout << "You must enter a " + Dimension + " less than 25. Try again." << endl;

					}
					else
					{
						break;
					}
				
*/	


					i = 0; //This executes after the if (i == inputlength) statement, not dependent on which of the two above statements (width or height loops) executes . this basically resets everything we've entered
					cin.clear();
					ss.clear();
					ss.str("");
					Input = "";
					CleanInput = "";
					InputLength = 0;
					e++; //everything in the block above is reset, except for e will increment, which gets us to the "else" in most of the e-contingent if/else statements. 
					Control = false; //without this, it repeats the "Enter height: " prompt infinitely. because it acts like a break statement, but it breaks us ALL the way out to start the entire FIRST while statement over again...so it's like an escape to THIS section type of function in this case

				}

/*DONE else b*/
				else //this else statement executes if isdigit "else" test fails. clears everything.
				{
					i = 0;
					cin.clear();
					ss.clear();
					ss.str("");
					Input = "";
					CleanInput = "";
					InputLength = 0;
					break;
				} 
	/*			
			*/
				//QUESITON: Are all these checks and value resets necessary?
			}
/* DONE else d*/

			else //executes if input length doesn't equal i, for some reason.
			{
				cout << endl;
			}
		}
	}
	cout << endl;


	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			cout << "X";
		}
		cout << endl;
	}
	cout << endl;
		system("pause");
}



/*					if (width <= 0 || height <= 0)
					{

						cout << "You must enter a " + Dimension + " greater than 0. Try again." << endl;


					}
					else if (width >= 25 || height >= 25)
					{

						cout << "You must enter a " + Dimension + "less than 25. Try again." << endl;

					}
					*/
	/*
		For this assignment you will create a program to print a box of Xs on
		the screen.Your program must use user - defined functions as a part of
		the solution.

		There are a couple tricky parts in this assignment so give yourself
		plenty of time to work on it.

		Details
		------ -

		You program should first prompt the user to enter a width and a
		height.It should validate that both the width and height are greater
		than 0 and less than 25.  Then it should generate a rectangle of Xs
		with the given width and height.

		For example consider the following run :

		---- -
		Enter width : 0
		You must enter a width greater than 0.  Try again.
		Enter width : zz
		Invalid input.Try again.
		Enter width : 5
		Enter height : -10
		You must enter a height greater than 0.  Try again.
		Enter height : -8
		You must enter a height greater than 0.  Try again.
		Enter height : 3

		XXXXX
		XXXXX
		XXXXX

		Exiting...
		---- -

		Notice that the validation will continue until a valid number is entered.

		Your program must include a function that will take in an integer for
		width and height and draw the rectangle with that.It should also
		have a function to request the user input and return the valid value.
		This input function will take a string parameter that is set to
		"width" or "height" by the caller and then use that parameter to
		generate the correct text to the user.The input function will return
		an integer, which is the correct value.
*/