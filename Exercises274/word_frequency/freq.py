#--------------------------------------------
#   Name: Zamam Moeez
#   ID: 1665264
#   CMPUT 274
#
#   Weekly Exercise 3: Word Frequency
#-------------------------------------------- 

# function to open, read and sort words from text file

def openreadsort():

    import sys

    #if else statements to check if correct arguments and corresponding error messages

    if len(sys.argv)>2:

        sys.exit("Too many arguments. Usage: python3 freq.py <input file name>")

    elif len(sys.argv)<2:

        sys.exit("Too few arguments. Usage: python3 freq.py <input file name>")

    # file is 2nd element in sys.argv, the first being the python file name

    file = sys.argv[1]

    # opens file and closes
    
    with open(file) as f:

    # reads entire file, spilts into a list of words and sorts them

        words = sorted(f.read().split())

    # returns words list

        return words

# function to find the occurences of each word

def occurence():

    # import collections module

    import collections

    # call openreadsort function and obtain list of words

    words = openreadsort()

    # use Counter to form a dictionary named occurs contating words as keys
    # and occurences as values

    occurs = collections.Counter(words)

    # return occurs

    return occurs

# function to write results in text file in desired format

def printwrite():

    import sys

    # call occurence function to obtain dictionary with occurences

    occurs = occurence()

    # create list of all words/keys from the dictionary

    wortxt = list(occurs.keys())

    # create list of all occurences/values from dictionary

    values = list(occurs.values())

    # create list to store frequency

    freq = []

    for i in range(len(values)):

        freq.append(round(values[i]/sum(values),3))

    # create new text file and write output in desired format 

    with open(sys.argv[1]+".out","w+") as f:

     for i in range(len(values)):

        f.write(str(wortxt[i])+" "+str(values[i])+" "+str(freq[i])+"\n")

         
if __name__ == "__main__":
    # Any code indented under this line will only be run
    # when the program is called directly from the terminal
    # using "python3 freq.py". This is directly relevant to 
    # this exercise, so you should call your code from here.
    printwrite()
    pass