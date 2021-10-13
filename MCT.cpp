#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int pos(string s, string a[])
{

    for (int i = 0; i < 37; i++)
    {
        if (s == a[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    string morse[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----",
        ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "/"};

    string letter[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", " "};

    int choice, l;
    string morse_code, t_morse, c, plain, t_plain;

    do
    {
        cout << "1 for Morse code To Plain.\n";
        cout << "2 for Plain To Morse code.\n";
        cout << "3 for Quit.\n\n";

        cout << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Morse code(eg. .... . .-.. .-.. --- / .-- --- .-. .-.. -..):";
            cin.ignore();
            plain.clear();

            getline(cin, morse_code);
            morse_code.append(" ");
            l = morse_code.length();
            for (int i = 0; i < l; i++)
            {
                c = morse_code[i];
                if (!(c == " " || c == "-" || c == "/" || c == "." || c == "\0"))
                {
                    cout << "Morse code is not vaild.";
                    break;
                }

                if (c != " ")
                    t_morse.append(c);
                else if (c == " " || c == "\0")
                {
                    if (pos(t_morse, morse) == -1)
                        cout << "Morse code is not vaild.";
                    else
                    {
                        plain.append(letter[pos(t_morse, morse)]);
                        t_morse.clear();
                    }
                }
            }
            cout << plain << endl;
            break;
        case 2:
            cout << "Enter plain text:";
            cin.ignore();
            getline(cin, plain);
            morse_code.clear();

            transform(plain.begin(), plain.end(), plain.begin(), ::toupper);

            l = plain.length();
            for (int i = 0; i < l; i++)
            {
                c = plain[i];
                if (!((c <= "z" && c >= "a") || (c <= "Z" && c >= "A") || (c <= "9" && c >= "0") || c == " " || c == "\0"))
                {
                    cout << "Plain text is not vaild.";
                    break;
                }

                morse_code.append(morse[pos(c, letter)]);
                morse_code.append(" ");

                c.clear();
            }
            cout << morse_code << endl;

            break;
        default:
            cout << "Entered choice is wrong...";
            break;
        }

    } while (choice != 3);
    return 0;
}