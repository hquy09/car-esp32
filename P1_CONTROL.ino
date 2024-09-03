#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Độ rộng của màn hình OLED
#define SCREEN_HEIGHT 64 // Chiều cao của màn hình OLED

// Địa chỉ I2C của màn hình OLED, thường là 0x3C hoặc 0x3D
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

// Khai báo chân cho joystick
int VRx = 34; // Chân kết nối với VRx
int VRy = 35; // Chân kết nối với VRy
int SW = 32;  // Chân kết nối với SW

// Khai báo màn hình OLED SSD1306
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Khởi động Serial Monitor để debug
  Serial.begin(115200);

  // Khởi tạo màn hình OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Dừng chương trình nếu không khởi tạo được màn hình
  }

  display.clearDisplay(); // Xóa màn hình lần đầu
  display.display(); // Cập nhật màn hình lần đầu

  // Cấu hình chân cho joystick
  pinMode(SW, INPUT_PULLUP); // Cấu hình chân SW như input với pull-up
}

void loop() {
  // Đọc giá trị từ joystick
  int xValue = analogRead(VRx); // Đọc giá trị trục X từ chân GPIO 34
  int yValue = analogRead(VRy); // Đọc giá trị trục Y từ chân GPIO 35
  int buttonState = digitalRead(SW); // Đọc trạng thái nút nhấn từ chân GPIO 32

  // Ghi dữ liệu lên Serial Monitor
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  Serial.print(" | Button: ");
  Serial.println(!buttonState); // !buttonState đảo ngược giá trị, LOW khi nhấn, HIGH khi thả

  // Hiển thị dữ liệu lên màn hình OLED
  printJoystickData(xValue, yValue, !buttonState);

  delay(100); // Chờ 100ms trước khi đọc lại
}

// Chương trình con để hiển thị dữ liệu joystick lên màn hình OLED
void printJoystickData(int x, int y, int button) {
  display.clearDisplay(); // Xóa nội dung hiện tại trên màn hình
  display.setTextSize(1); // Cỡ chữ
  display.setTextColor(SSD1306_WHITE); // Màu chữ (trắng)
  
  // In giá trị trục X lên dòng đầu tiên
  display.setCursor(0, 0); // Đặt vị trí con trỏ ở dòng đầu tiên
  display.print("X: ");
  display.println(x);

  // In giá trị trục Y lên dòng thứ hai
  display.setCursor(0, 10); // Đặt vị trí con trỏ ở dòng thứ hai
  display.print("Y: ");
  display.println(y);

  // In trạng thái nút nhấn lên dòng thứ ba
  display.setCursor(0, 20); // Đặt vị trí con trỏ ở dòng thứ ba
  display.print("Button: ");
  display.println(button);

  display.display(); // Cập nhật nội dung mới lên màn hình
}
