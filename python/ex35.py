from sys import exit

def gold_room():
    print "This room is full of gold. How muc do you take?"

    next = raw_input(">>> ")
    
    if "0" in next or "1" in next:
        how_much = int (next)
    else:
        dead("Man,learn to type a number.")
        
    if how_much < 50:
        print "Nice ,you're not greedy, you win!"
        exit(0)
    else:
        dead("You greedy bastard!")

def dead(why):
    print why,"Good job!"
    exit(0)
