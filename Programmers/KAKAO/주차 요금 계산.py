#// 2022 KAKAO BLIND RECRUITMENT level2
import math

def solution(fees, records):
    answer = []
    in_records_cars = dict() # 들어오는 자동차 
    tot_minute = dict()  # 자동차의 총 주차시간
    
    for record in records:
        time, car, state = record.split() # 공백으로 분리
        h, m = time.split(":")
        minute = int(h) * 60 + int(m) # 분으로 환산
        
        if state == "IN":
            in_records_cars[car] = minute;
            
        else:
            # tot_minute 딕셔너리가 존재할 경우
            try:
                tot_minute[car] += minute - in_records_cars[car]
            # 추가 되는 경우
            except:
                tot_minute[car] = minute - in_records_cars[car]
            del in_records_cars[car]
    
    # 0000에 나갔을 경우가 존재
    for car, minute in in_records_cars.items():
        # tot_minute 딕셔너리가 존재할 경우
        try:
            tot_minute[car] += 23 * 60 + 59 - minute
        # 추가 되는 경우
        except:
            tot_minute[car] = 23 * 60 + 59 - minute
    
    # 정렬하면서 총 요금 계산
    for car, minute in sorted(tot_minute.items()):
        # 나머지가 존재하면 +1
        # 음수인 경우는 그냥 기본 요금
        fee = fees[1] + math.ceil(max(0, (minute - fees[0])) / fees[2]) * fees[3]
        answer.append(fee)
        
    return answer