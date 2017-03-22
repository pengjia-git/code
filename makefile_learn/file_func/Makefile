file_name=a b c d e
tar:
#	@echo $(pwd)
#	@echo $(dir $(pwd))$(notdir $(pwd))
#	@echo $(addsuffix .a, $(pwd))
	@touch $(foreach file,$(file_name),$(file).c)
