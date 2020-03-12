#include <iostream>
#include <string>
using namespace std;
int atoi(string a) {
    int res = 0;
    int i = 0;
    while (i < a.size()) {
        int tmp = a[i] - '0';
        res = res * 10 + tmp;
        ++i;
    }
    return res;
}
int main() {
    string input {"W49;W92;A84;W33;A32;A52;D97;S14;S33;D79;A14;W25;D97;D21;D31;A66;S67;S4;A59;S62;W40;S26;S65;A58;S17;A67;D48;W23;D68;S99;S97;W63;W27;D12;D83;W8;S3;W6;A88;D23;W30;S91;D58;W74;D45;W3;D19;S72;D8;S79;S76;S49;W16;A29;W93;W99;W92;D82;A10;A4;D25;A90;D83;W45;W20;S68;D59;S48;A18;S0;W24;S48;W75;A39;W29;S28;W76;W78;D94;A57;A5;D51;S61;A39;W77;S70;A2;D8;S58;D51;S86;W30;A27;S62;D56;A51;D0;S58;W34;S39;A64;A68;A96;D37;S91;S16;A17;D35;A85;W88;S57;S61;A28;D12;A87;S39;A85;W22;D65;D72;A5;A78;A59;D75;D57;S66;A55;D84;D72;W87;S46;W64;D49;S46;W34;D60;S39;A30;W86;D20;W93;D25;W44;W86;A16;D4;A86;S86;S27;W7;W89;W93;S17;S39;W66;W72;D81;W93;A88;D46;S57;W45;S84;S57;D27;A11;D54;S8;W15;A50;A69;A4;D19;D69;A3;A28;D47;W18;A39;D47;W14;D77;W59;S84;A32;D56;S16;D99;A33;A51;A24;D65;W37;D98;A13;W6;D94;D28;A12;S18;W40;S23;W76;D6;S40;D26;W97;W7;W90;W75;S12;A89;S46;S36;D96;A49;A73;S53;D84;A87;D75;D48;W84;S14;W65;W79;W51;S9;S77;D51;S76;W16;W77;A90;S96;D78;S7;W71;D17;W10;W4;D96;S58;A88;S89;D41;W47;W13;S75;S85;W63;W87;S19;S80;W92;W95;W73;D43;D35;W60;S31;D72;A73;W90;S51;A55;S82;W81;S56;W83;W41;A77;S37;D63;A72;D44;W81;S26;S53;W32;A24;S90;S83;W34;D10;S53;D69;A87;W84;S32;D72;S63;D97;W27;D23;D25;D18;W86;D74;D42;A31;S1;D98;D76;S46;D67;W94;S6;S97;S40;W71;W12;D62;W57;A92;W59;W59;D15;A16;D21;S33;S45;S83;D89;W77;A93;S60;S6;W24;S93;D69;D79;S13;S8;W63;D99;S36;D35;W53;S5;S44;S19;D76;S14;A86;A86;W43;W65;D20;S19;W66;A54;A98;A17;D2;W98;W2;D77;A90;S8;S55;S67;W88;W19;S59;D9;S75;S56;W75;W54;A61;W47;S19;D67;S39;D55;S6;A89;A5;W58;W7;W88;W92;D85;S32;S32;A27;S42;D52;A55;S26;D27;W40;D76;A55;D38;W13;A71;D79;W59;A76;A33;A12;D1;D63;W63;W62;D7;W48;A84;D27;A80;D42;D27;D49;D4;D71;W90;W39;D24;W71;D16;S1;W88;W88;D25;D66;S39;S43;A99;A92;W19;W20;A90;A31;A6;A79;D4;D80;A77;D71;D36;S64;"};
    int i = 0, j = 0;
    int x = 0, y = 0;
    while (i <= j && j < input.size()) {
        while (j < input.size() && input[j] != ';') {
            j++;
        }
        // 长度不合法
        if (j - i > 3) {
            i = j+1;
            j = i;
            continue;
        }
        // 内容不合法
        if (input[i] != 'A' && input[i] != 'W' && input[i] != 'D' && input[i] != 'S'){
            i = j+1;
            j = i;
            continue;
        }
        bool flag = false;
        for (int k = i+1; k < j; ++k) {
            if (input[k] < '0' || input[k] > '9'){
                flag = true;
                break;
            }
        }
        if (flag){
            i = j+1;
            j = i;
            continue;
        }
        int move = atoi(input.substr(i+1, j - i - 1));
        if (input[i] == 'A') {
            x -= move;
        }
        if (input[i] == 'W') {
            y += move;
        }
        if (input[i] == 'D') {
            x += move;
        }
        if (input[i] == 'S') {
            y -= move;
        }
        i = j+1;
        j = i;
    }
    cout << x << "," << y;
    return 0;
}