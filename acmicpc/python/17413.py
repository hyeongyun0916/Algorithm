import re
text = input()
regex = re.compile("<[^<>]*>")
results = regex.finditer(text)
index = 0
answer = []
for m in results:
	answer.append(text[index:m.start()].split())
	answer.append(m.group())
	index = m.end()

answer.append(text[index:].split())

for item in answer:
	if type(item) is list:
		reverseList = []
		for word in item:
			reverseList.append(word[::-1])
		print(' '.join(reverseList), end='')
	else:
		print(item, end='')
	