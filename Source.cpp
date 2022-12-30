#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
using namespace std;
using namespace sf;
int main() {
    srand(time(0));
    RenderWindow win(VideoMode(500, 500), "Happy New Year 2023!");
    while (win.isOpen()) {
        Event event;
        while (win.pollEvent(event)) {
            if (event.type == Event::Closed) {
                win.close();
            }
        }
        Color colors[] = { Color{255,0,0}, Color{0,100,0}, Color{0,0,255}, Color{255,255,0} };
        time_t t = time(NULL);
        struct tm* now = localtime(&t);

        unsigned int year, month, day, hour, minute, second;
        year = (now->tm_year) + 1900;
        month = (now->tm_mon) + 1;
        day = now->tm_yday;
        hour = (now->tm_hour);
        minute = now->tm_min;
        second = now->tm_sec;

        int daysInMon = now->tm_mday;

        int outMon = 12 - month;
        int outDay = 30 - daysInMon;
        int outHour = (24 - hour) - 1;
        int outMin = 60 - minute;
        int outSec = 60 - second;
        if (month == 12)
        {
            outDay = (365 - day) - 1;
        }
        string a = to_string(outDay) + " days" + " " + to_string(outHour) + " hours" + " " + to_string(outMin) + " minutes" + " " + to_string(outSec) + " seconds";

        if (!outMon == 0 || !outDay == 0 || !outHour == 0 || !outMin == 0 || outSec > 1) {
            win.clear(Color{ 75,0,130 });

            Font font;
            font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

            Text text;
            Text text2;
            text2.setFont(font);
            text2.setString("Countdown to New Year 2023");
            text2.setFillColor(Color::White);
            text2.setCharacterSize(24);
            text2.setPosition(85, 0);
            text.setFont(font);
            text.setString(a);
            text.setFillColor(Color::White);
            text.setCharacterSize(24);
            text.setPosition(40, 470);

            CircleShape triangle(50, 3);
            CircleShape triangle2(60, 3);
            CircleShape triangle3(70, 3);
            triangle.setPosition(200, 100);
            triangle2.setPosition(190, 160);
            triangle3.setPosition(180, 220);
            triangle.setFillColor(Color::Green);
            triangle2.setFillColor(Color::Green);
            triangle3.setFillColor(Color::Green);

            RectangleShape rectangle(Vector2f(500, 150));
            rectangle.setPosition(0, 350);
            rectangle.setFillColor(Color{ 147,112,219 });

            RectangleShape rectangle2(Vector2f(50, 80));
            rectangle2.setPosition(225, 290);
            rectangle2.setFillColor(Color{ 139,69,19 });

            CircleShape light(10);
            light.setFillColor(colors[rand()%4]);
            light.setPosition(210, 300);

            CircleShape light2(10);
            light2.setFillColor(colors[rand() % 4]);
            light2.setPosition(250, 260);

            CircleShape light3(10);
            light3.setFillColor(colors[rand() % 4]);
            light3.setPosition(220, 220);

            CircleShape light4(10);
            light4.setFillColor(colors[rand() % 4]);
            light4.setPosition(240, 180);

            CircleShape light5(10);
            light5.setFillColor(colors[rand() % 4]);
            light5.setPosition(250, 140);

            win.draw(rectangle);
            win.draw(text);
            win.draw(text2);
            win.draw(rectangle2);
            win.draw(triangle);
            win.draw(triangle2);
            win.draw(triangle3);
            win.draw(light);
            win.draw(light2);
            win.draw(light3);
            win.draw(light4);
            win.draw(light5);
            for (int i = 0; i < 35; i++) {
                CircleShape circle(8);
                circle.setPosition((rand() % 500), (rand() % 500));
                win.draw(circle);
            }
            win.display();
        } else {
            while (1 > 0) {
                Font font;
                font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
                win.clear(Color{ 75,0,130 });
                Text textNY2023;
                textNY2023.setFont(font);
                textNY2023.setString("Happy New Year 2023!!!");
                textNY2023.setFillColor(Color::White);
                textNY2023.setCharacterSize(40);
                textNY2023.setPosition(30, 220);
                win.draw(textNY2023);
                win.display();
            }
            Sleep(60000);
        }

        Sleep(1000);
    }
    return 0;
}