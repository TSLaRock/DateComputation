#include <stdlib.h>
#include <stdio.h>
  int main(void)
  { // -- BEGIN FUNCTION 'MAIN'

   // Program that accepts
   // 2 dates as 2 sets of integers separated 
   // by a space in order to compute the 
   // number of days between the two dates in 
   // the year 2014. The first integer will
   // be the month, the second will be the day.
   // The data will be validated. If improper data is
   // entered, the user will be given an error message
   // and the program will terminate. 
   
    // -- BEGIN VARIABLE DECLARATION
    
    int month1, day1;
    int month2, day2; // 
    int daysInMonth[12] = {31 , 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Array holding the number of days in each month for the year 2014
    int monthsBetween; // the number of months between two dates    
    int totalDaysBetween;  // sum of days in months between dates separated by months
    int i; // for loop increment
    
    // -- END VARIABLE DECLARATION -- \\
    
    // -- BEGIN USER DATA ENTRY -- \\

    // Prompt the user for the first date
    printf("Please enter the first date (Month  Day) as 2 integers seperated by a space: \n ");

    // Accept the first date from the user
     scanf("%d %d", &month1, &day1);
     // DO NOT decrement month1 here for data validation purposes
    

    // -- BEGIN DATA VALIDATION FOR DATE 1 -- \\
        
    // if month1 is less than 1 OR month1 is greater than 12
    if((month1 < 1) || (month1 > 12))
       {
       // Tell the user the date was invalid
      printf("The month you entered was invalid. Please try again. \n");
       return 0;
       }
     
    // if day1 is greater than the days in month1 OR less than 1  
    if((day1 < 1) || (day1 > daysInMonth[month1 - 1]))
    {
     // Tell the user the date was invalid
       printf("The date you entered is invalid. \n");
       return 0;
    }

    // -- END DATA VALIDATION FOR DATE 1 -- \\

    // Prompt the user for the date 2
    printf("Please enter the second date in the same format:  \n");


    // Accept date 2 from the user
    scanf("%d %d", &month2, &day2);
    // DO NOT decrement month2 here for data validation purposes
    
    // -- BEGIN DATA VALIDATION FOR DATE 2 -- \\


    // If the second date precedes the first, exit
    // Case 1: Same month, preceding day
    if((month1 == month2) && (day2 < day1))
      {
      printf("Invalid Date: Date 1 must precede Date 2. \n");
      return 0;
      }
      
    // Case 2: Month2 Precedes Month1
    if(month2 < month1)
      {
      printf("Invalid Date: Date 1 must precede Date 2. \n");
       return 0;
      }
    
    // The same validation procedure as described for Date1  
    if((month2 < 1) || (month2 > 12))
      {
       printf("The date you entered is invalid. Please try again. \n");
       return 0;
      }
      
    if((day2 < 1) || (day2 > daysInMonth[month2 - 1]))
      {
       printf("The date you entered is invalid.");
       return 0;
      }
    
    
    // -- END DATA VALIDATION -- \\
    
    // -- END USER DATA ENTRY -- \\

    // -- BEGIN CALCULATION -- \\
    
    // Calculate the number of days between the two dates
    // Case 1: the dates are in the same month
    if(month1 == month2)
      {
        totalDaysBetween = day2 - day1 - 1;
      }

    // Case 2: The dates are in consecutive months
    // day2 + daysinMonth1 - day1 - 2
    else if(month1 + 1 == month2)
      {
        totalDaysBetween = day2 + (daysInMonth[month1 - 1] - day1) - 1;
      }

    // Case 3: The months are separated by monthsBetween
    // (daysInMonth[month1 - 1] - day1) + (INBETWEEN MONTHS before month2) + day2;   
    else
      {
        // calculate the number of months between
        monthsBetween = month2 - month1;
        
        // loop through the daysInMonth array to get all 
        // the days between the two months
         for(i = month1; i < month2 - 1; i++)
          {
          totalDaysBetween = totalDaysBetween + daysInMonth[i];
          }
          
        totalDaysBetween = abs(totalDaysBetween + (daysInMonth[month1 - 1] - day1) + day2) - 2;  
      }
      
      // -- END CALCULATION -- \\


    // Print the answer:
    printf("The number of days between the two dates you entered is: %d \n" , totalDaysBetween);

    // return control to OS
    return 0; 

  } // -- END FUNCTION 'MAIN' -- \\
