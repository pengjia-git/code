from re import *
from sys import *
from string import *

str='From: Foo Fie <foo@bar.baz>'
pat="^From:(.*)<.*"
s=search(pat,str)
print strip(s.group(1))
