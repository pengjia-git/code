#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
def single_fund_info_input():
	single_fund_info={}
	index=0
	hint_word=["基金名字","周期","3月开始","3月结束","亮点信息"]
	for hint in hint_word:
		val=raw_input(hint+":")
		print val
		if index == 2:
			pass
	return single_fund_info

single_fund_info_input()
