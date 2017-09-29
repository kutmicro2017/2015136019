#define LED1_R 12
#define LED1_Y 11
#define LED1_G 10 //상
#define LED2_R 26
#define LED2_Y 28
#define LED2_G 30//하
#define LED3_R 6
#define LED3_Y 5
#define LED3_G 4//좌
#define LED4_R 39
#define LED4_Y 41
#define LED4_G 43 //우
#define buttonA 2
const long interval = 60000; //60초
volatile bool state = true; //스위치가 눌렸는지를 판단하는 변수

void setup() {
  pinMode(LED1_R, OUTPUT);
  pinMode(LED1_G, OUTPUT);
  pinMode(LED1_Y, OUTPUT);
  pinMode(LED2_R, OUTPUT);
  pinMode(LED2_G, OUTPUT);
  pinMode(LED2_Y, OUTPUT);
  pinMode(LED3_R, OUTPUT);
  pinMode(LED3_G, OUTPUT);
  pinMode(LED3_Y, OUTPUT);
  pinMode(LED4_R, OUTPUT);
  pinMode(LED4_G, OUTPUT);
  pinMode(LED4_Y, OUTPUT);
  pinMode(buttonA, INPUT_PULLUP); //기본값이 HIGH
  attachInterrupt(0, tTof, FALLING); //인터럽트0 은 핀 2번, 따라서 스위치를 핀2에 연결, 스위치가 눌리면 실행
}                               //인터럽트 핀의 값이 HIGH에서 LOW로 바뀔 때 함수 실행

void tTof() { //스위치가 눌렸을 때 실행되는 함수
  if (digitalRead(LED3_G) == HIGH) state = false; //스위치가 눌리면 state의 값을 바꿔준다
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1_R, LOW);
  digitalWrite(LED1_G, HIGH);  //상하 신호등이 빨간색
  digitalWrite(LED2_R, HIGH); digitalWrite(LED3_R, HIGH); digitalWrite(LED4_R, HIGH); //좌우 신호등이 초록색
  delay(5000); //1분간 대기
  digitalWrite(LED1_G, LOW);
  //신호를 끈다
  for (int delaytime = 0; delaytime < 10; delaytime++) {
    digitalWrite(LED1_Y, HIGH);  //노란 신호가 들어옴
    delay(500);
    digitalWrite(LED1_Y, LOW);
    delay(500); // 0.5+0.5 해서 1초간 깜빡인다
  }
  digitalWrite(LED3_R, LOW);

  digitalWrite(LED3_G, HIGH);
  digitalWrite(LED1_R, HIGH); digitalWrite(LED2_R, HIGH); digitalWrite(LED4_R, HIGH); //좌우 신호등이 초록색
  unsigned long previousMillis = millis();
  while (millis() - previousMillis <= interval) { //현재 시각과 이전 시각의 차이가 60초가 될 때까지 반복
    //시간 지연 동안에 다른 동작을 해야하므로 delay함수는 사용 못함
    if (state == false) { //스위치가 눌렸으면
      delay(3000); //3초간 대기
      digitalWrite(LED3_G, LOW);
      for (int delaytime = 0; delaytime < 10; delaytime++) { //10초간
        digitalWrite(LED3_Y, HIGH);
        delay(500);
        digitalWrite(LED3_Y, LOW);
        delay(500); //1초 간격으로 깜빡임
      }
      digitalWrite(LED3_R, HIGH);
      state = true; //동작이 끝났으니 변수를 원래 상태로 돌려줌
      delay(5000);
      digitalWrite(LED3_R, LOW);
      digitalWrite(LED3_G, HIGH);
      previousMillis = millis() - 33000; //빨간 신호를 켜서 딜레이 된 만큼 지연 시간을 늘려줌
    }
  }
    digitalWrite(LED3_G, LOW);
    for (int delaytime = 0; delaytime < 10; delaytime++) {
      digitalWrite(LED3_Y, HIGH);  //노란 신호가 들어옴
      delay(500);
      digitalWrite(LED3_Y, LOW);
      delay(500); // 0.5+0.5 해서 1초간 깜빡인다
    }
    digitalWrite(LED3_R, HIGH);


    digitalWrite(LED2_R, LOW);//신호를 끈다
    digitalWrite(LED2_G, HIGH);  //상하 신호등이 빨간색
    digitalWrite(LED1_R, HIGH); digitalWrite(LED3_R, HIGH); digitalWrite(LED4_R, HIGH); //좌우 신호등이 초록색
    delay(5000); //1분간 대기
    digitalWrite(LED2_G, LOW);

    for (int delaytime = 0; delaytime < 10; delaytime++) {
      digitalWrite(LED2_Y, HIGH);  //노란 신호가 들어옴
      delay(500);
      digitalWrite(LED2_Y, LOW);
      delay(500); // 0.5+0.5 해서 1초간 깜빡인다
    }
    digitalWrite(LED2_R, HIGH);

    digitalWrite(LED4_R, LOW);//신호를 끈다
    digitalWrite(LED4_G, HIGH);
    digitalWrite(LED1_R, HIGH); digitalWrite(LED2_R, HIGH); digitalWrite(LED3_R, HIGH); //좌우 신호등이 초록색
    delay(5000); //1분간 대기
    digitalWrite(LED4_G, LOW);
    //신호를 끈다
    for (int delaytime = 0; delaytime < 10; delaytime++) {
      digitalWrite(LED4_Y, HIGH);  //노란 신호가 들어옴
      delay(500);
      digitalWrite(LED4_Y, LOW);
      delay(500); // 0.5+0.5 해서 1초간 깜빡인다
    }
  }
  
