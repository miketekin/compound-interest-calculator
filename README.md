# Cplusplus-Program
C++ Project for CS210 at SNHU


# Summarize the project and what problem it was solving.
An application that allows users to see how their investments will grow over time. From the user, the application takes an initial investment amount, monthly deposit, annual interest(compounded), and the number of years to invest. With this information it produces two reports. One report showing how the investments will grow over time if the monthly deposit is taken into account and a second report that shows how the investment will grow without the monthly deposit.

# What did you do particularly well?
I believe I did a good job at keeping the code organized and well documented. I also believe the output is displayed in a neat and easy to read manner thanks to my work aligning the output.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
When gathering user input, I use try/catch exception handling inside of a while loop with a series of if statements in order to verify user input. What I don't like about this solution is that if a user provides acceptable input for the first prompt but then provides unaccepable input for a subsequent prompt, the user must start over from the first prompt. I wanted to make it so that they would just need to retry the prompt that failed to accept input but was stuck on how to do it and ended up running out of time. Making this change could improve the user experience.

# Did you find writing any piece of this code challenging, and how did you overcome this? What tools and/or resources are you adding to your support network?
The most difficult part of this program for me was getting the report data properly aligned once large numbers were introduced. I overcame this hurdle by carefully considering what needed to happen in order for the output to align properly given the other data that was being output on the same line. Initially I didn't really consider the other data on the line as being variable in length and switching how I thought about it helped me come up with my solution. I also wanted to have an elegant solution for waiting for user input and not doing anything with that input. I came up with my own solutions at first but wasn't happy with them. I decided to search online for solutions that already exist and that's when I found system("pause") which I was happy with and can see myself using in future projects.

# What skills from this project will be particularly transferable to other projects and/or course work?
Focusing on minimizing the amount of code in main(), which is something I had never been taught to do before, could be particularly transferable to other projects - helping keep the code maintainable, readable, and adaptable.

# How did you make this program maintainable, readable, and adaptable?
I made this program maintainable, readable, and adaptable by putting as much of the code as I could into distinct functions. This minimized the amount of code that was in main() and makes it easier to adjust the functions as needed.
