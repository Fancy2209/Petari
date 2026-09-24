# Grabs just undefined and multiple reference linker errors 
# and turns them into a sorted list with only unique lines
# From file with what is presumed to be output of "make 2>&1 | tee log.txt" or something of the sort
# At least when using GNU LD
# Useful for Porting Decomps :D
# By Fancy2209	

import re
from collections import Counter, OrderedDict    

# Add more patterns to the array if needed
PATTERN_UNDEFINED_REFERENCE = "(.*?): undefined reference"
PATTERN_MULTIPLE_REFERENCE = "(.*?): multiple definition" 
PATTERNS = [PATTERN_UNDEFINED_REFERENCE, PATTERN_MULTIPLE_REFERENCE]

f = open("log.txt", "rt")
str = f.readlines()
f.close()

split_lines = []

for line in str:
	for pattern in PATTERNS:
		if re.match(pattern, line) is not None:
			split_lines.append(re.sub(pattern, pattern.replace("(.*?): ", ""), line))

split_lines = set(split_lines)
split_lines = sorted(split_lines)

out_string = "".join(split_lines).strip()
print(out_string)

f = open("errors.txt", "wt")
f.write(out_string)
f.close()
