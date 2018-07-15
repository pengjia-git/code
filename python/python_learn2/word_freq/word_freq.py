#coding=utf-8
#读取一个文件（ascii），大约几十k，统计每个单词的次数，
#并按频次从大到小排列出来。
#单词定义：连续不包含非字母的组合

file='test.txt'
word_dict={}
def split_to_words(line):
	line_len=len(line)
	i=0
	start=end=0

	while i< line_len:
		if not line[i].isalpha():
			end=i
			if end > start:
				#store_word(line[start:end])
				print line[start:end]
				start=end
				pass
			else:
				start=end
		i+=1

fd=open(file,"r")
for line in fd:
	#print line
	split_to_words(line)

