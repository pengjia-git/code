import re

def is_email_valid(email):
	if not type(email) == type(""):
		return False
	if not email:
		return False
	if not re.match("..*@.*\...*",email):
		return False
	return True