# 알고리즘 과제에 세가지의 비트처리 함수를 이용한 재귀함수의 시간 복잡도에 대한 문제가 나왔다
# 세 함수 모두 총 비트(문자열의 길이)를 최소한 절반으로 줄이고
# a와 c함수의 경우 특정 조건시 문자열의 길이 즉 재귀의 대상이 더 짧아짐이 명확하기에 최선의 경우가 선형이지 않을까 싶었다.
# 근데 해보니깐 걍 nlogn임 ㅋㅋㅋ 그래서 교수님이 어캐 푸시는 지 보니깐 걍 T(n) <= 2T(n/2) +Cn 하고 끝나셨어용
# 이건 최악의 경우로 O(nlogn)을 구하신건데 음 중요한건 일정 비율만큼 계속 감소 
# 즉 T(n) <= T(an) + T(bn) +Cn, (a+b < 1) 이거지 T(n) <= T(a) + T(b) +Cn, (a+b < n)이 아니라는 거....
# 인정 내가 바보였음 
# 아쉬운 점은 O()즉 최악의 경우만 보시는 건데... 시험에 나오면 걍 최악만 봐야겠다! O()명시가 안되서 다 구하라는 줄
# 다시 돌아와서 최선의 경우도 선형이 아니다. 결국 최악으로 간다 ???  


def a(bit_string):
    if bit_string == "00":
        return ""
    elif bit_string == "01":
        return "0"
    elif bit_string == "10":
        return "1"
    elif bit_string == "11":
        return ""
    else:
        return ""
    
def b(bit_string):
    if bit_string == "00":
        return "0"
    elif bit_string == "01":
        return "1"
    elif bit_string == "10":
        return "1"
    elif bit_string == "11":
        return "0"
    else:
        return ""
    
def c(bit_string):
    if bit_string == "00":
        return "0"
    elif bit_string == "01":
        return ""
    elif bit_string == "10":
        return ""
    elif bit_string == "11":
        return "1"
    else:
        return ""
    
def split_and_apply_function(function, bit_string):
    # 홀수 길이 문자열일 경우 마지막 문자 제거
    if len(bit_string) % 2 != 0:
        bit_string = bit_string[:-1]
    
    result = ""
    for i in range(0, len(bit_string), 2):
        result += function(bit_string[i:i+2])
    return result

def f1(x):
    global call_cnt
    call_cnt += 1
    if x == "":
        return ""
    # 각각의 변환 함수를 적용한 결과를 합쳐서 반환
    result = a(x) + f1(split_and_apply_function(b, x)) + f1(split_and_apply_function(c, x))
    return result

import random
def make_bit_string_len_of(n):
    string = ""
    for _ in range(n):
        string += str(random.randint(0, 1))
    return string

call_cnt

def aver_call_time(n,function):
    call_buffer = 0
    for _ in range(100):
        string = make_bit_string_len_of(n)
        global call_cnt 
        call_cnt = 0
        result = function(string)
        #print(f"{n}: {call_cnt}: {result}")
        call_buffer += call_cnt
    return call_buffer

pre_aver = 0
for n in range(500, 3001, 500):
    aver = aver_call_time(n,f1)
    print(f"{n} : measure_time(n) : {aver} : call_rate_increase : {aver - pre_aver} ")
    pre_aver = aver


