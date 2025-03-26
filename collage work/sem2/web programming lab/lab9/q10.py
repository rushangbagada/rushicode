# . A movie theater 
# charges different ticket prices depending on a person’s age. If a person is under the age of 3, 
# the ticket is free; if they are between 3 and 12, the ticket is $10; and if they are over age 12, 
# the ticket is $15. Write a loop in which you ask users their age, and then tell them the cost of 
# their movie ticket  


def ticket_price(age):
    if age < 3:
        return 0    
    elif age >= 3 and age <= 12:
        return 10
    else:
        return 15
a=int(input("Enter age: "))
while 1:
    if a==-1 or a=="":
        break
    print(ticket_price(a))
    a=input("Enter age: ")   
    