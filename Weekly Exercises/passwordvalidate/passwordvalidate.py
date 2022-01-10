# ---------------------------------------------------
# Name : Zamam Moeez
# ID: 1665264
# CMPUT 274 , Fall 2021
#
# Exercise 1: Password Validate
# ---------------------------------------------------

def validate(password): # Defines function named validate with arguement password and returns result


    import string # imports string module for further use in program
 
    password = set(password) # converts password data type from string to set for use in 
                          # intersection function

    result = "" # initializes result variable as an empty string

    poolu = set(string.ascii_uppercase)          # lines 21-25 involve assigning variables to sets of multiple character pools
    pooll = set(string.ascii_lowercase)          # includng uppercase, lowercase, digits, special characters and charaters that render
    poold = set(string.digits)                   # password invalid
    pools = set("!-$%&'()*+,./:;<=>?_[]^`{|}~")
    inval = set(["@", " ", "#"])

    lenu = len(password.intersection(poolu)) # lines 27-31 involve assigning length of intersections between password input and character pools
    lenl = len(password.intersection(pooll))
    lend = len(password.intersection(poold))
    lens = len(password.intersection(pools))
    leni = len(password.intersection(inval))

    if len(password)<8 or leni > 0 : # if the password length is < 8 or intersection b/w invalid pool and password has 1 or more characters

        result = "Invalid"           # the result is considered "Invalid"

    elif lenu>0 and lenl>0 and lend>0 and lens>0: # if intersection b/w uppercase,lowercase,digits,special character pools and password 

        result = "Secure"                         # has 1 or more characters then result is "Secure"

    else:

        result="Insecure" # If it is not Invalid and not Secure then it is considered Insecure

    return result # function returns result

    pass



def generate(n): # Defines function named generate with arguement n and returns secure_password
    
    
    import random # imports random module for further use

    import string # imports string module for further use

    result = ""          # initialzes result as an empty string
    
    secure_password = "" # initializes secure_password as an empty string

    poolu = set(string.ascii_uppercase)         # lines 60-63 involve assigning variables to sets of multiple character pools
    pooll = set(string.ascii_lowercase)         # includng uppercase, lowercase, digits, special characters
    poold = set(string.digits)                  
    pools = set("!-$%&'()*+,./:;<=>?_[]^`{|}~") 

    # determines pool from which secure_password will be generated

    poolf = string.ascii_letters+string.digits+"!-$%&'()*+,./:;<=>?_[]^`{|}~" 

    while result!="Secure": # while loop continues until result is "Secure"

     secure_password = ''.join(random.choice(poolf) for i in range(n)) # randomly generates n characters from poolf and joins them as a string with empty space between 

     lenu = len(set(secure_password).intersection(poolu)) # lines 73-76 involve assigning length of intersections between secure_password and character pools
     lenl = len(set(secure_password).intersection(pooll))
     lend = len(set(secure_password).intersection(poold))
     lens = len(set(secure_password).intersection(pools))

     # if intersection b/w sets of uppercase,lowercase,digits,special characters and secure_password has 1 or more characters

     if lenu>0 and lenl>0 and lend>0 and lens>0 and len(secure_password)>=8: 

      result = "Secure" # then result is "Secure"

      #print(secure_password)

    return secure_password # returns secure_password

    pass 

if __name__ == "__main__":
    # Any code indented under this line will only be run
    # when the program is called directly from the terminal
    # using "python3 validator.py". This can be useful for
    # testing your implementations.
    pass


