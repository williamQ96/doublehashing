# doublehashing

1) You will read in a file that contains the price for the Dow Jones Industrial Average (DJIA) for dates between 1970 and 2022.

The file is available here: DJIADownload DJIA

You can see the format of the data by looking at the file.

2) As you read in the data, you will store the data in a dictionary that is implemented using an array.  The key in the dictionary will be the date.  The value will be the close price for that date.  ("Close price" = price at the end of the day)

3) After you have read in all the data, you will then do 91 fetches for 91 dates I have picked out.  For each of these dates, you will fetch the close price for that day from your dictionary.  Your ultimate job is to print an average price for the DJIA index for the 91 days.  So you should keep some sort of "sum" variable and add the fetched close price to that sum.

The starter code should make this prompt more clear: proj3A.cDownload proj3A.c

The functions from the C standard library you are allowed to use are: printf, fprintf, malloc, exit, fopen, getline, strcmp, sscanf, and strdup.  There may be other functions that would be helpful -- don't use them.   I want you to use only the functions that are listed above.  (I suppose fclose and free are fine too -- but I didn't do it.)

Finally, you must store all of the entries and then do the fetches (like I have in the starter code).  Don't do fetches as you are storing, since that doesn't stress your code in the same way.

Extend your 3A code to implement a dictionary using a hash table 

The hash table should use double hashing and you choose the hash functions.  I expect most of you will google hash functions and implement a solution you find on the internet.

There is no checker code.  You will verify it works as you do Part 2 which is writing a report.

I expect most people will write the code, do the analysis for the report, and then submit the code to this Canvas entry when they have finished the report.  So your code will probably be a reflection of the last experiments you ran for your report -- that is fine.
