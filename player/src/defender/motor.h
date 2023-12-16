#ifndef PLAYER_MOTOR_H
#define PLAYER_MOTOR_H


class Motor {
public:
    Motor(int pwmPin, int dirPin);

    void setup() const;

    void setSpeed(int speed) const;

    void brake() const;

    void stop() const;

private:
    int pwmPin;
    int dirPin;
};


#endif //PLAYER_MOTOR_H
