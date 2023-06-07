namespace ctrl {
    class Motor;
    class Machine;
    typedef Motor** Motors;
    void limit(int * x);
    int limit(int x);
}

class ctrl::Motor {
protected:
    int8_t fd_pin, bd_pin;
public:
    Motor(const int8_t pwd_fd, const int8_t dig_bd) {
        fd_pin = pwd_fd;
        bd_pin = dig_bd;
    }
    void go(int speed) const {
        limit(&speed);
        digitalWrite(bd_pin, speed < 0);
        analogWrite(fd_pin, speed % 256);
    }
};

class ctrl::Machine {
private:
    Motor *fl, *fr, *bl, *br;
    Motors all;
public:
    Machine(Motor* _fl, Motor* _fr, Motor* _bl, Motor* _br) {
        all = (Motor*[]){
            fl = _fl,
            fr = _fr,
            bl = _bl,
            br = _br
        };
    }
    void y(int speed) const {
        Motors mtr = all;
        for (int i = 0; i < 4; mtr++, i++) {
            (*mtr)->go(speed);
        }
    }
    void x(int speed) const {
        fr->go(speed);
        fl->go(speed);
        br->go(-speed);
        bl->go(-speed);
    }
    void rotate(int speed) const {
        fr->go(-speed);
        fl->go(speed);
        br->go(-speed);
        bl->go(speed);
    }
    void stop() const {
        Motors mtr = all;
        for (int i = 0; i < 4; mtr++, i++) {
            (*mtr)->go(0);
        }
    }
};



void ctrl::limit(int * x) {
    if (abs(*x) >= 256) {
        *x = 255 * (abs(*x) / *x);
    }
}
int ctrl::limit(int x) {
    if (abs(x) >= 256) {
        return 255 * (abs(x) / x);
    }
    return x;
}
