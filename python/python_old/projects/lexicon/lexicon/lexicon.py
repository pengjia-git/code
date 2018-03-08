def create_lexicon_lib(words):
    lexicon_lib={}
    length=len(words)
    i=0
    while  i < length:
        if i != 0:
            lexicon_lib[words[i]]=words[0]
        i=i+1
    return lexicon_lib

def create_lexicon(sentence):
    lexicon_lib={}
    for s in sentence:
       lexicon_part= create_lexicon_lib(s)
       lexicon_lib.update(lexicon_part)
    return lexicon_lib


def search_word(words,lexicon_lib):
    res=[]
    for word in words:
        val=lexicon_lib.get(word)
        if val != None:
            res.append((val,word))
        else:
            try:
                number=int(word)
                res.append(('number',number))
            except ValueError:
                res.append(('error',None))
    return res

class lexicon(object):
    direction=['direction','north','south','east','weast','up','down','left','right','back']
    verbs=['verb','go','stop','kill','eat']
    stops=['stops','the','in','of','from','at','it']
    nouns=['nouns','door','bear','princess','cabinet']
    def __init__(self):
        self.lexicon_lib=create_lexicon([self.direction,self.verbs,self.stops,self.nouns])
        
    def scan(self,sentence):

        words=sentence.split()
        return search_word(words,self.lexicon_lib)
