/* L9110s 모터드라이버
   오른쪽모터
   L9110s A_1A
   L9110s A_1B 
   왼쪽모터
   L9110s B_1A 8
   L9110s B_1B 10
*/
int A_1A = 13; 
int A_1B = 12;
int A_S = 11;
int B_1A = 8;
int B_1B = 9;
int B_S = 10;


/*
   TCRT5000 라인센서
   왼쪽 라인센서 DO - D2
   오른쪽 라인센서 DO - D3
*/


int leftLineSensor =  6;
int rightLineSensor = 7;

int Speed = 255;

void setup() {
  //핀을 초기화합니다.
  //L298 모터드라이버의 핀들을 출력으로 변경합니다.
  pinMode(A_1A, OUTPUT);
  pinMode(A_1B, OUTPUT);
  pinMode(A_S, OUTPUT);
  pinMode(B_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
  pinMode(B_S, OUTPUT);
 
 
  //TCRT5000 라인센서를 입력으로 변경합니다.
  pinMode(leftLineSensor, INPUT);
  pinMode(rightLineSensor, INPUT);
}


/**
   함수내 코드가 무한히 실행됩니다.
*/
void loop() {
  //양쪽 센서가 모두 선을 감지하지 않았을 경우 전진합니다.
  if (!digitalRead(leftLineSensor) && !digitalRead(rightLineSensor)) {
    //모터A 정회전
    analogWrite(A_S, Speed-20);
    digitalWrite(A_1A, HIGH);
    digitalWrite(A_1B, LOW);
    //모터B 정회전
    analogWrite(B_S, Speed);
    digitalWrite(B_1A, HIGH);
    digitalWrite(B_1B, LOW);
    
  } else if (!digitalRead(leftLineSensor) && digitalRead(rightLineSensor)) {
    //모터A 역회전
    analogWrite(A_S, Speed-30);
    digitalWrite(A_1A, HIGH);
    digitalWrite(A_1B, LOW);
    //모터B 정회전 
    //-20을 하는 이유는 전진하다 역회전하는 반대 바퀴보다 가속도가 붙기 때문입니다.
    analogWrite(B_S, Speed);
    digitalWrite(B_1A, LOW);
    digitalWrite(B_1B, HIGH);

  } else if (digitalRead(leftLineSensor) && !digitalRead(rightLineSensor)) {
    analogWrite(A_S, Speed);
    digitalWrite(A_1A, LOW);
    digitalWrite(A_1B, HIGH);
    analogWrite(B_S, Speed-20);
    digitalWrite(B_1A, HIGH);
    digitalWrite(B_1B, LOW);
    //양쪽모두 선을 감지했을 경우 정지합니다.
  }else if (digitalRead(leftLineSensor) && digitalRead(rightLineSensor)) {
    analogWrite(A_S, Speed-120);
    digitalWrite(A_1A, HIGH);
    digitalWrite(A_1B, LOW);;
    analogWrite(B_S, Speed-140);
    digitalWrite(B_1A, HIGH);
    digitalWrite(B_1B, LOW);;
  }
}
