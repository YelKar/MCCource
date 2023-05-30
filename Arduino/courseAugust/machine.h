namespace ctrl {
    class Motor;
    class Machine;
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
    void go(int speed) {
        limit(&speed);
        digitalWrite(bd_pin, speed < 0);
        analogWrite(fd_pin, speed % 256);
    }
};

class ctrl::Machine {
private:
    Motor *fl, *fr, *bl, *br;
    Motor *all[4];
public:
    Machine(Motor* _fl, Motor* _fr, Motor* _bl, Motor* _br) {
        all[0] = fl = _fl;
        all[1] = fr = _fr;
        all[2] = bl = _bl;
        all[3] = br = _br;
    }
    void y(int speed) {
        
    }
    void x(int speed) {

    }
    void rotate(int speed) {

    }
    void stop() {
        for (Motor * i : all) {
            i->go(0);
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
