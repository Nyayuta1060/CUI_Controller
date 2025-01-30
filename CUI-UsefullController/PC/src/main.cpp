#include "ASCII_CUI.hpp"    //https://github.com/kazu-321/ASCII_CUIより
#include "main.hpp"

//exeが消失およびC++を更新した時には、reload.batを実行してください

// 事前に設定したい変数を定義
bool myBool = false;

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


// main_layoutを初期状態でUI作成
ASCII_CUI::UI UI(&main_layout);

// 変更時に呼び出される関数を作成
void Don_send(void){
    if(abs(Don_Motor0) >25000 || abs(Don_Motor1) >25000 || abs(Don_Motor2) >25000 || abs(Don_Motor3) >25000){
        UI << "Don_Motor's value is too large" << std::endl;
        }else{
            //ここに送信処理を書く
        UI << "Successfully sent" << std::endl;
        }
}



//ここまで


void setup() {
    main_layout = ASCII_CUI::Layout({
        {"Motor", "Motor's setting", &motor_layout},
        {"etc", "etc menu", &etc_layout}
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
        {"send","Send the changes", ASCII_CUI::Variable(&myBool),&Don_send}
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
        {"about", "about this program", &about_layout},
        {"author", "author", &author_layout}
    },
        "etc menu"
    );
    about_layout = ASCII_CUI::Layout({
        {"Back","->etc", &etc_layout},
    },
        "about"
    );
    author_layout = ASCII_CUI::Layout({
        {"Back","->etc", &etc_layout},
    },
        "Made by Nyayuta1060/ASCII_CUI by kazu-321"
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
