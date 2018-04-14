width=80

def display_tb():
	print "+"+"-"*(width-2)+"+"

def display_middle(sen_len):
	print " "*((width-sen_len-2)/2)+"|"+" "*sen_len+"|"

def display_sen(sen):
	print " "*((width-len(sen)-2-2)/2)+"|" +" "+sen+" "+"|" 

def display(str):
	display_tb()
	display_middle(len(str)+2)
	display_sen(str)
	display_middle(len(str)+2)
	display_tb()

	

sentence=raw_input()
display(sentence)
