#include "ASCII_CUI.hpp"    //https://github.com/kazu-321/ASCII_CUIより
//#include <mbed.h>

/*
exeファイルの作成方法 <-更新するときとか、消えたときとか
（もしexeファイルがあるなら、削除してから)
➀code runnerの設定を開く
➁Run in Terminalのチェックを外す
➂実行
➃exeファイルの出現を確認出来たら、設定を外す
*/


// 事前に設定したい変数を定義
float Don_Motor0 = 0;
float Don_Motor1 = 0;
float Don_Motor2 = 0;
float Don_Motor3 = 0;

// float FP0 = 0;
// float FP1 = 0;

// float brushless0 = 0;
// float brushless1 = 0;

// float servo0 = 0;
// float servo1 = 0;
// float servo2 = 0;
// float servo3 = 0;

// 画面のレイアウトを定義
ASCII_CUI::Layout main_layout, 
                  motor_layout, Don_motor_layout, FP_layout, servo_layout, brushless_layout,
                  Don_setting_layout, FP_setting_layout, servo_setting_layout, brushless_setting_layout,
                  etc_layout;

// main_layoutを初期状態でUI作成
ASCII_CUI::UI UI(&main_layout);

// 変更時に呼び出される関数を作成


//ここまで


void setup() {
    main_layout = ASCII_CUI::Layout({
        {"Motor", "Motor's setting", &motor_layout},
        {"etc", "etc's setting", &etc_layout}
    },
        "Main menu"
    );

    motor_layout = ASCII_CUI::Layout({
        {"Back","->main", &main_layout},
        {"Don_motor", "Don_motor's setting", &Don_motor_layout},
        {"FP", "FP's setting", &FP_layout},
        {"brushless", "brushless's setting", &brushless_layout},
        {"servo", "servo's setting", &servo_layout}
    },
        "Motor menu"
    );

    Don_motor_layout = ASCII_CUI::Layout({
        {"Back","->motor", &motor_layout},
        {"Setting","Speed set", &Don_setting_layout},
        {"send","Send the changes", &Don_motor_layout}
    },
        "Don_motor menu"
    );
    Don_setting_layout = ASCII_CUI::Layout({
        {"Back","->Don_motor", &Don_motor_layout},
        {"Don_Motor0","Don_Motor0", ASCII_CUI::Variable(&Don_Motor0)},
        {"Don_Motor1","Don_Motor1", ASCII_CUI::Variable(&Don_Motor1)},
        {"Don_Motor2","Don_Motor2", ASCII_CUI::Variable(&Don_Motor2)},
        {"Don_Motor3","Don_Motor3", ASCII_CUI::Variable(&Don_Motor3)}
    },
        "Don_motor setting"
    );


    FP_layout = ASCII_CUI::Layout({
        {"Back","->motor", &motor_layout},
    },
        "FP menu"
    );

    brushless_layout = ASCII_CUI::Layout({
        {"Back","->motor", &motor_layout},
    },
        "brushless menu"
    );

    servo_layout = ASCII_CUI::Layout({
        {"Back","->motor", &motor_layout},
    },
        "servo menu"
    );



    etc_layout = ASCII_CUI::Layout({
        {"Back","->main", &main_layout},
    },
        "etc menu"
    );
}

int main() {
    setup();
    while (true) {
        UI.print(); // 画面更新
        int c = getchar();
        if (c == 'w') {
            UI.up();    // 上
        } else if (c == 's') {
            UI.down();  // 下
        } else if (c == 'e') {
            UI.enter(); // 確定
        }
    }
    return 0;
}
