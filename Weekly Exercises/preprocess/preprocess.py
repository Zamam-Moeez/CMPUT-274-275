#--------------------------------------------
#   Name: Zamam Moeez
#   ID: 1665264
#   CMPUT 274, Fall 2021
#
#   Weekly Exercise #4: Text Preprocessor
#-------------------------------------------- 

def inputlow(wordstring):

    import string

    wordlist = wordstring.split()

    for i in range(len(wordlist)):

        wordlist[i] = wordlist[i].lower()

    return wordlist


def rempunc(wordlist):

    import string

    for i in range(len(wordlist)):

        remdic = str.maketrans('', '', string.punctuation)

        wordlist[i] = wordlist[i].translate(remdic)

    if "" in wordlist:

        wordlist.remove("")

    return wordlist


def remnum(wordlist):

    import string

    for i in range(len(wordlist)):

        if wordlist[i].isdigit()==False:

            remdic = str.maketrans('', '', string.digits)

            wordlist[i] = wordlist[i].translate(remdic)

    if "" in wordlist:

        wordlist.remove("")


    return wordlist


def remstop(wordlist):

    import string

    stop = ["i", "me", "my", "myself", "we", "our", "ours", "ourselves", "you", "your", 
            "yours", "yourself", "yourselves", "he", "him", "his", "himself", "she", "her", 
            "hers", "herself", "it", "its", "itself", "they", "them", "their", "theirs", 
            "themselves", "what", "which","who", "whom", "this", "that", "these", "those", 
            "am", "is", "are", "was", "were", "be","been", "being", "have", "has", "had", 
            "having", "do", "does", "did", "doing", "a", "an","the", "and", "but", "if", 
            "or", "because", "as", "until", "while", "of", "at", "by", "for", "with", 
            "about", "against", "between", "into", "through", "during", "before", "after", 
            "above", "below", "to", "from", "up", "down", "in", "out", "on", "off", "over",
            "under", "again", "further", "then", "once", "here", "there", "when", "where", 
            "why", "how", "all", "any", "both", "each", "few", "more", "most", "other", 
            "some", "such", "no", "nor", "not", "only", "own", "same", "so", "than", 
            "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"]

    for word in wordlist[:]:

        if word in stop:

            wordlist.remove(word)

    if "" in wordlist:

        wordlist.remove("")

    return wordlist


def masterfunc():

    import sys

    import string

    cases = ["keep-digits", "keep-stops", "keep-symbols"]

    if len(sys.argv)==2 and sys.argv[1] not in cases or len(sys.argv)>2:
        print("ERROR: Incorrect mode entered")
        print("Please run program as preprocessor.py <mode> input")
        print("Where mode is: keep-digits, keep-stops, keep-symbols")
        sys.exit()

    wordstring = input()

    wordlist = inputlow(wordstring)

    

    if len(sys.argv)==1:

        newlist = remstop(remnum(rempunc(wordlist)))

        print(' '.join(newlist))

    elif sys.argv[1] == cases[0] and len(sys.argv)==2:

        newlist = remstop(rempunc(wordlist))

        print(' '.join(newlist))

    elif sys.argv[1]== cases[1] and len(sys.argv)==2:

        newlist = remnum(rempunc(wordlist))

        print(' '.join(newlist))

    elif sys.argv[1]== cases[2] and len(sys.argv)==2:

        newlist = remstop(remnum(wordlist))

        print(' '.join(newlist))


if __name__ == "__main__":

    masterfunc()

    # Any code indented under this line will only be run
    # when the program is called directly from the terminal
    # using "python3 preprocess.py". This is directly relevant 
    # to this exercise, so you should call your code from here.