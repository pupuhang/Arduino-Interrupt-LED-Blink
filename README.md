# Arduino-Interrupt-LED-Blink
임베디드소프트웨어-Interrupt 점멸 코드

##구현기능
- 인터럽트 기능을 사용해서 버튼을 누른 시간 많큼 LED를 0.2마다 점멸

##사용 기술
-attachInterrupt(CHANGE) 인터럽트 버튼이 눌렸을떄 놓았을 때 작동
-millis(); 현재 시간을 기록

## 동작 원리
1. 버튼을 누르면 인터럽트가 발생하여 시작 시간을 저장
2. 버튼을 떼면 종료 시간을 저장
3. (종료 시간 - 시작 시간)을 계산하여 버튼을 누른 시간을 구함
4. 계산된 시간 동안 LED를 0.2초 간격으로 점멸

##핵심 코드
1. attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, CHANGE);
- 버튼이 눌렸을때 와 놓았을 때 작동시 작동하는 언터럽트
2. unsigned long duration = pressEnd - pressStart;
- 누르기 시작한 시간을 놓은 시간에 빼서 저장(누르고 있던 시간)
3. while (millis() - startTime < duration)
- 점멸을 반복할 조건문 현재 시간에서 loop 코드를 시작할 시간을 뺀 값이 번튼을 누르고 있던 시간보다 작으면 반복 즉,버튼을 누르고 있던 시간만큼 작동
