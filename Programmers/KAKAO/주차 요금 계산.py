#// 2022 KAKAO BLIND RECRUITMENT level2
import math

def solution(fees, records):
    answer = []
    records_dic = {} # 테이블 표  딕셔너리 변환
    accum_cars = {} # 요금 환산
    
    for record in records:
        time, number, state = record.split()
        h, m = time.split(":")
        
        # 분으로 환산
        minute = int(h) * 60 + int(m)
        if state == "IN":
            records_dic[number] = minute
        else:
            # accum_car 딕셔너리가 존재할 경우
            try:
                accum_cars[number] += minute - records_dic[number]
            except:
                accum_cars[number] = minute - records_dic[number]
            # 기록 딕셔너리에 key 삭제
            del records_dic[number]
    
    # 남은 차량
    for car, tot_minue in records_dic.items():
        try:
            accum_cars[car] += (23 * 60  + 59 - tot_minue)
        except:
            accum_cars[car] = (23 * 60  + 59 - tot_minue)
    
    # 요금 계산
    for car, minute in sorted(accum_cars.items()):
        answer.append(fees[1] + math.ceil(max(0, (minute - fees[0])) / fees[2]) * fees[3])
    return answer