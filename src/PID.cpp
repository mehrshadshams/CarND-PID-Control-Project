#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;

    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;

    step = 1;
}

void PID::UpdateError(double cte) {
    if (step == 1) {
        p_error = cte;
    }
    // Derivative
    d_error = cte - p_error;

    // Proportional
    p_error = cte;

    // Integral
    i_error += cte; 

    step++;   
}

double PID::TotalError() {
    double total_error = Kp * p_error + Kd * d_error + Ki * i_error;

    return total_error;
}

