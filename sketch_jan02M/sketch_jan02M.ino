int MIC=8;  //聲音感測模組 AO 輸出接至 A0 腳
int LED=13;  //Arduino 板上內建 LED
boolean toggle=false; //紀錄 LED 狀態,預設為熄滅
int micVal;  //紀錄偵測到的音量

unsigned long current=0;  //紀錄目前過門檻時戳
unsigned long last=0;  //紀錄上次過門檻時戳
unsigned long diff=0;  //紀錄前後兩次時間差
unsigned int count=0;  //紀錄已偵測到的次數

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(MIC, INPUT);
  Serial.begin(9600);
  }

void loop() {
  micVal=digitalRead(MIC);  //讀取感測器輸出
  Serial.println(micVal); 
  if (micVal > 30) {  //若超過門檻值
    current=millis();  //紀錄目前時戳
    ++count;  //增量偵測次數
    Serial.print("count=");  //輸出偵測次數
    Serial.println(count);
    if (count >= 2) {  //若次數已達 2 次, 判斷間隔時間是否在 0.3~1.5 秒內
      diff=current-last;  //計算前後兩次時間差
      if (diff > 300 && diff < 1500) {  //判斷間隔時間是否在 0.3~1.5 秒內
        toggle = !toggle;  //反轉 LED 狀態
        count=0;  //計數器歸零
        }
      else {count=1;}  //間隔太短或太長則第二次不算, 計數器還原為 1
      }
    last=current;  //以目前時戳更新上次時戳, 以便下一次偵測時比較之用
    if (toggle) {digitalWrite(LED, HIGH);}  //狀態為 ON 就點亮 LED
    else {digitalWrite(LED, LOW);}  //狀態為 OFF 就點亮 LED
    }
  }
