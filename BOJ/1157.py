# 1157 단어 공부
word = input().upper() # 대문자로 변환
set_list = list(set(word)) #중복제거

word_cnt = []
for s in set_list:
    cnt = word.count(s)
    word_cnt.append(cnt)

# 최대 갯수가 중복인 경우
if word_cnt.count(max(word_cnt)) >= 2 :
    print("?")
else:
    print(set_list[word_cnt.index(max(word_cnt))].upper())
