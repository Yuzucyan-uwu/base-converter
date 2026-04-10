#include <graphics.h>
#include <conio.h>
#include <string>
#include <iostream>

using namespace std;

// 将数字转字符
char digitToChar(int x) {
    if (x < 10) return '0' + x;
    else return 'A' + (x - 10);
}

// 十进制转任意进制
string convert(int num, int base) {
    if (num == 0) return "0";

    bool neg = false;
    if (num < 0) {
        neg = true;
        num = -num;
    }

    string res = "";
    while (num > 0) {
        int r = num % base;
        res = digitToChar(r) + res;
        num /= base;
    }

    if (neg) res = "-" + res;
    return res;
}

int main() {
    initgraph(500, 300);

    settextstyle(20, 0, "Consolas");

    string inputNum = "";
    string inputBase = "";
    string result = "";

    bool typingNum = false;
    bool typingBase = false;

    while (true) {
        cleardevice();

        outtextxy(50, 30, "Decimal:");
        rectangle(150, 30, 350, 60);
        outtextxy(160, 35, inputNum.c_str());

        outtextxy(50, 80, "Base (2-35):");
        rectangle(150, 80, 350, 110);
        outtextxy(160, 85, inputBase.c_str());

        // 按钮
        rectangle(150, 140, 250, 180);
        outtextxy(165, 150, "Convert");

        outtextxy(50, 220, "Result:");
        outtextxy(150, 220, result.c_str());

        ExMessage msg;
        if (peekmessage(&msg)) {
            if (msg.message == WM_LBUTTONDOWN) {
                int x = msg.x;
                int y = msg.y;

                if (x > 150 && x < 350 && y > 30 && y < 60) {
                    typingNum = true;
                    typingBase = false;
                }
                else if (x > 150 && x < 350 && y > 80 && y < 110) {
                    typingBase = true;
                    typingNum = false;
                }
               
                else if (x > 150 && x < 250 && y > 140 && y < 180) {
                    if (!inputNum.empty() && !inputBase.empty()) {
                        int num = stoi(inputNum);
                        int base = stoi(inputBase);

                        if (base >= 2 && base <= 35)
                            result = convert(num, base);
                        else
                            result = "Invalid Base!";
                    }
                }
            }
            else if (msg.message == WM_CHAR) {
                char ch = msg.ch;

                if (ch == '\b') {
                    if (typingNum && !inputNum.empty())
                        inputNum.pop_back();
                    else if (typingBase && !inputBase.empty())
                        inputBase.pop_back();
                }
                else if (isdigit(ch) || (typingNum && ch == '-')) {
                    if (typingNum)
                        inputNum += ch;
                    else if (typingBase)
                        inputBase += ch;
                }
            }
        }
    }

    closegraph();
    return 0;
}
